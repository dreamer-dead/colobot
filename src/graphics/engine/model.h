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

#pragma once

#include "graphics/core/device.h"
#include "graphics/core/material.h"
#include "graphics/core/vertex.h"

#include <vector>
#include <boost/concept_check.hpp>

// Graphics module namespace
namespace Gfx {

/**
 * \struct RawModelPart
 * \brief Description of part of 3D model as raw data read from model file
 */
struct RawModelPart
{
    //! Number of this part
    int partNumber;
    //! Number of parent part (=0 if it has no parent)
    int parentPartNumber;
    //! Position
    Math::Vector position;
    //! Rotation along major axes in degrees
    Math::Vector rotation;
    //! Zoom along major axes
    Math::Vector zoom;

    RawModelPart()
     : partNumber(0)
     , parentPartNumber(-1)
     , zoom(1.0, 1.0, 1.0)
    {}
};

/**
 * \struct RawModelTriangle
 * \brief Triangle of a 3D model as raw data read from model file
 */
struct RawModelTriangle
{
    //! 1st vertex
    VertexTex2  p1;
    //! 2nd vertex
    VertexTex2  p2;
    //! 3rd vertex
    VertexTex2  p3;
    //! Material
    Material    material;
    //! Name of 1st texture
    std::string tex1Name;
    //! Name of 2nd texture
    std::string tex2Name;
    //! If true, 2nd texture will be taken from current engine setting
    bool variableTex2;
    //! Rendering state to be set
    int state;
    //! Model part
    int part;

    RawModelTriangle()
     : variableTex2(true)
     , state(0)
     , part(0)
    {}
};

/**
 * \struct ModelGeometry
 * \brief Static geometry data of model
 */
struct ModelGeometry
{
    std::vector<VertexNor> vertices;
};

/**
 * \struct ModelUvMap
 * \brief UV map data
 */
struct ModelUvMap
{
    std::vector<Math::Point> uvs;
};

/**
 * \enum ModelMaterialTextureMode
 * \brief Modes (flag array) of texturing model material
 */
enum class ModelMaterialTextureMode
{
    Normal                    = 0,
    Alpha                     = 1,
    BlackTransparent          = 2,
    WhiteTransparent          = 3
};

/**
 * \enum ModelMaterial
 * \brief Material of model
 */
struct ModelMaterial
{
    //! Lighting material
    Material material;
    //! Primary texture
    std::string tex1Name;
    //! Secondary texture
    std::string tex2Name;
    //! Primary texture mode
    ModelMaterialTextureMode tex1Mode;
    //! Secondary texture mode
    ModelMaterialTextureMode tex2Mode;
    //! If true, 2nd texture will be taken from current engine setting
    bool variableTex2;

    ModelMaterial()
     : tex1Mode(ModelMaterialTextureMode::Normal)
     , tex2Mode(ModelMaterialTextureMode::Normal)
     , variableTex2(false)
    {}

    friend bool operator==(const ModelMaterial& left, const ModelMaterial& right)
    {
        return left.material == right.material &&
               left.tex1Name == right.tex1Name &&
               left.tex1Mode == right.tex1Mode &&
               left.tex2Mode == right.tex2Mode &&
               left.variableTex2 == right.variableTex2;
    }
};

/**
 * \class CModelSubpart
 * \brief Block of a part of model - chunk of geometry with one material
 */
class CModelBlock
{
    friend class CModelPart;

private:
    CModelBlock(const ModelMaterial& material);

public:
    //! Returns associated model material
    inline const ModelMaterial& GetMaterial() const { return m_material; }

    //! Add new triangle to block
    void AddTriangle(const RawModelTriangle& triangle);

    //! Reverse-engineers raw triangles from model blocks
    void CollectRawTriangles(std::vector<RawModelTriangle>& rawTriangles, int partNumber) const;

    //! Returns number of triangles
    int GetTriangleCount() const;

private:
    ModelMaterial m_material;
    ModelGeometry m_geometry;
    BufferId m_geometryBufferId;
    ModelUvMap m_primaryUvMap;
    BufferId m_primaryUvMapBufferId;
    ModelUvMap m_secondaryUvMap;
    BufferId m_secondaryUvMapBufferId;
};

/**
 * \class CModelPart
 * \brief Independent part of model
 */
class CModelPart
{
    friend class CModel;
    friend class CModelBlock;

private:
    CModelPart(const RawModelPart& rawPart, const std::vector<RawModelTriangle>& rawTriangles);

public:
    //! Returns the part number
    inline int GetNumber() const { return m_number; }

    //! Returns the parent part number
    inline int GetParentNumber() const { return m_parentNumber; }

    //! Returns number of triangles
    int GetTriangleCount() const;

    //! Reverse-engineers raw triangles from model blocks
    void CollectRawTriangles(std::vector<RawModelTriangle>& rawTriangles) const;

    //! Returns model subparts
    const std::vector<CModelBlock*>& GetBlocks() { return m_blocks; }

private:
    static ModelMaterial ExtractMaterial(const RawModelTriangle& triangle);
    CModelBlock* AddNewBlock(const ModelMaterial& modelMaterial);
    CModelBlock* GetBlockForMaterial(const ModelMaterial& modelMaterial);

private:
    int m_number;
    int m_parentNumber;
    std::vector<CModelBlock*> m_blocks;
};

/**
 * \class CModel
 * \brief Whole model = collection of parts
 */
class CModel
{
public:
    CModel();
    ~CModel();

    //! Clear all model data
    void Clear();

    //! Returns the number of triangles in model
    int GetTriangleCount() const;

    //! Collects raw model triangles from all parts
    std::vector<RawModelTriangle> GetRawTriangles() const;

    //! Sets new model data from raw triangles
    void SetRawTriangles(const std::vector<RawModelTriangle>& rawTriangles);

    //! Sets new model data from raw triangles and parts data
    void SetRawTriangles(const std::vector<RawModelTriangle>& rawTriangles, const std::vector<RawModelPart>& rawParts);

    //! Returns number of model parts
    int GetNumberOfParts() const;

    //! Returns part at given number
    CModelPart* GetPart(int partNumber);

private:
    //! Model parts
    std::vector<CModelPart*> m_parts;
};

} // namespace Gfx
