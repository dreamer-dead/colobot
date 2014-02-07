// * This file is part of the COLOBOT source code
// * Copyright (C) 2013, Polish Portal of Colobot (PPC)
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see  http://www.gnu.org/licenses/.

#include "graphics/engine/model.h"

#include "graphics/engine/engine.h"


// Graphics module namespace
namespace Gfx {

ModelMaterialTextureMode StateToPrimaryTextureMode(int state)
{
    ModelMaterialTextureMode textureMode = ModelMaterialTextureMode::Normal;

    if (state & ENG_RSTATE_ALPHA)
    {
        textureMode = ModelMaterialTextureMode::Alpha;
    }
    else if (state & ENG_RSTATE_TTEXTURE_BLACK)
    {
        textureMode = ModelMaterialTextureMode::BlackTransparent;
    }
    else if (state & ENG_RSTATE_TTEXTURE_WHITE)
    {
        textureMode = ModelMaterialTextureMode::WhiteTransparent;
    }

    return textureMode;
}

ModelMaterialTextureMode StateToSecondaryTextureMode(int state)
{
    ModelMaterialTextureMode textureMode = ModelMaterialTextureMode::Normal;

    if (state & ENG_RSTATE_DUAL_BLACK)
    {
        textureMode = ModelMaterialTextureMode::BlackTransparent;
    }
    else if (state & ENG_RSTATE_DUAL_WHITE)
    {
        textureMode = ModelMaterialTextureMode::WhiteTransparent;
    }

    return textureMode;
}

int TextureModesToState(ModelMaterialTextureMode tex1Mode, ModelMaterialTextureMode tex2Mode)
{
    int state = 0;

    if (tex1Mode == ModelMaterialTextureMode::Alpha)
    {
        state |= ENG_RSTATE_ALPHA;
    }
    else if (tex1Mode == ModelMaterialTextureMode::BlackTransparent)
    {
        state |= ENG_RSTATE_TTEXTURE_BLACK;
    }
    else if (tex1Mode == ModelMaterialTextureMode::WhiteTransparent)
    {
        state |= ENG_RSTATE_TTEXTURE_WHITE;
    }

    if (tex2Mode == ModelMaterialTextureMode::BlackTransparent)
    {
        state |= ENG_RSTATE_DUAL_BLACK;
    }
    else if (tex2Mode == ModelMaterialTextureMode::WhiteTransparent)
    {
        state |= ENG_RSTATE_DUAL_WHITE;
    }

    return state;
}

// --------------


CModelBlock::CModelBlock(const ModelMaterial& material)
 : m_material(material)
 , m_geometryBufferId(0)
 , m_primaryUvMapBufferId(0)
 , m_secondaryUvMapBufferId(0)
{}

void CModelBlock::AddTriangle(const RawModelTriangle& triangle)
{
    m_geometry.vertices.emplace_back(triangle.p1.coord, triangle.p1.normal);
    m_geometry.vertices.emplace_back(triangle.p2.coord, triangle.p2.normal);
    m_geometry.vertices.emplace_back(triangle.p3.coord, triangle.p3.normal);

    m_primaryUvMap.uvs.emplace_back(triangle.p1.texCoord);
    m_primaryUvMap.uvs.emplace_back(triangle.p2.texCoord);
    m_primaryUvMap.uvs.emplace_back(triangle.p3.texCoord);

    m_secondaryUvMap.uvs.emplace_back(triangle.p1.texCoord2);
    m_secondaryUvMap.uvs.emplace_back(triangle.p2.texCoord2);
    m_secondaryUvMap.uvs.emplace_back(triangle.p3.texCoord2);
}

int CModelBlock::GetTriangleCount() const
{
    return m_geometry.vertices.size() / 3;
}

void CModelBlock::CollectRawTriangles(std::vector<RawModelTriangle>& rawTriangles, int partNumber) const
{
    const int triangleCount = GetTriangleCount();

    for (int i = 0; i < triangleCount; ++i)
    {
        RawModelTriangle triangle;
        triangle.p1 = VertexTex2(m_geometry.vertices[3*i+0].coord, m_geometry.vertices[3*i+0].normal,
                                 m_primaryUvMap.uvs[3*i+0], m_secondaryUvMap.uvs[3*i+0]);
        triangle.p2 = VertexTex2(m_geometry.vertices[3*i+1].coord, m_geometry.vertices[3*i+1].normal,
                                 m_primaryUvMap.uvs[3*i+1], m_secondaryUvMap.uvs[3*i+1]);
        triangle.p3 = VertexTex2(m_geometry.vertices[3*i+2].coord, m_geometry.vertices[3*i+2].normal,
                                 m_primaryUvMap.uvs[3*i+2], m_secondaryUvMap.uvs[3*i+2]);

        triangle.material = m_material.material;
        triangle.tex1Name = m_material.tex1Name;
        triangle.tex2Name = m_material.tex2Name;
        triangle.variableTex2 = m_material.variableTex2;

        triangle.state = TextureModesToState(m_material.tex1Mode, m_material.tex2Mode);

        triangle.part = partNumber;

        rawTriangles.push_back(triangle);
    }
}


// --------------

CModelPart::CModelPart(const RawModelPart& rawPart, const std::vector<RawModelTriangle>& rawTriangles)
 : m_number(rawPart.partNumber)
 , m_parentNumber(rawPart.parentPartNumber)
{
    for (const auto& triangle : rawTriangles)
    {
        if (triangle.part == rawPart.partNumber)
        {
            ModelMaterial material = ExtractMaterial(triangle);
            CModelBlock* block = GetBlockForMaterial(material);
            if (block == nullptr)
            {
                block = AddNewBlock(material);
            }

            block->AddTriangle(triangle);
        }
    }
}

void CModelPart::CollectRawTriangles(std::vector<RawModelTriangle>& rawTriangles) const
{
    for (auto* block : m_blocks)
    {
        block->CollectRawTriangles(rawTriangles, m_number);
    }
}

CModelBlock* CModelPart::GetBlockForMaterial(const ModelMaterial& modelMaterial)
{
    for (auto* block : m_blocks)
    {
        if (block->GetMaterial() == modelMaterial)
        {
            return block;
        }
    }

    return nullptr;
}

CModelBlock* CModelPart::AddNewBlock(const ModelMaterial& modelMaterial)
{
    CModelBlock* block = new CModelBlock(modelMaterial);
    m_blocks.push_back(block);
    return block;
}

int CModelPart::GetTriangleCount() const
{
    int triangleCount = 0;
    for (auto* block : m_blocks)
    {
        triangleCount += block->GetTriangleCount();
    }
    return triangleCount;
}

ModelMaterial CModelPart::ExtractMaterial(const RawModelTriangle& triangle)
{
    ModelMaterial material;
    material.material = triangle.material;
    material.tex1Name = triangle.tex1Name;
    material.tex2Name = triangle.tex2Name;
    material.tex1Mode = StateToPrimaryTextureMode(triangle.state);
    material.tex2Mode = StateToSecondaryTextureMode(triangle.state);
    material.variableTex2 = triangle.variableTex2;
    return material;
}

// --------------

CModel::CModel()
{
}

CModel::~CModel()
{
    Clear();
}

void CModel::Clear()
{
    for (auto* part : m_parts)
    {
        delete part;
    }
    m_parts.clear();
}

int CModel::GetTriangleCount() const
{
    int triangleCount = 0;
    for (auto* part : m_parts)
    {
        triangleCount += part->GetTriangleCount();
    }
    return triangleCount;
}

std::vector<RawModelTriangle> CModel::GetRawTriangles() const
{
    std::vector<RawModelTriangle> rawTriangles;
    for (auto* part : m_parts)
    {
        part->CollectRawTriangles(rawTriangles);
    }
    return rawTriangles;
}

void CModel::SetRawTriangles(const std::vector<RawModelTriangle>& rawTriangles)
{
    std::vector<RawModelPart> parts;
    parts.push_back(RawModelPart());
    SetRawTriangles(rawTriangles, parts);
}

void CModel::SetRawTriangles(const std::vector<RawModelTriangle>& rawTriangles, const std::vector<RawModelPart>& rawParts)
{
    Clear();

    for (const auto& rawPart : rawParts)
    {
        m_parts.push_back(new CModelPart(rawPart, rawTriangles));
    }
}

int CModel::GetNumberOfParts() const
{
    return m_parts.size();
}

CModelPart* CModel::GetPart(int partNumber)
{
    if (partNumber < 0 || partNumber >= static_cast<int>( m_parts.size() ))
        return nullptr;

    return m_parts[partNumber];
}


} // namespace Gfx
