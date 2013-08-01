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


// Graphics module namespace
namespace Gfx {

CModelSubpart::CModelSubpart()
{
    // TODO
}

const ModelMaterial& CModelSubpart::GetMaterial() const
{
    return m_material;
}

void CModelSubpart::SetMaterial(const ModelMaterial& material)
{
    m_material = material;
    // TODO
}

// --------------

CModelPart::CModelPart()
{
    // TODO
}

int CModelPart::GetNumber() const
{
    return m_number;
}

std::vector<CModelSubpart*> CModelPart::GetSubparts()
{
    return m_subparts;
}


// --------------

CModel::CModel()
{
    // TODO
}

CModel::~CModel()
{
    // TODO
}

void CModel::Clear()
{
    // TODO
}

void CModel::Update()
{
    // TODO
}

int CModel::GetTriangleCount() const
{
    // TODO
    return m_rawTriangles.size();
}

std::vector<RawModelTriangle> CModel::GetRawTriangles() const
{
    // TODO
    return m_rawTriangles;
}

void CModel::SetRawTriangles(const std::vector<RawModelTriangle>& triangles)
{
    // TODO
    m_rawTriangles = triangles;
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
