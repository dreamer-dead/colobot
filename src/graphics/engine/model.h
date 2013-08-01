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
 * \enum LODLevel
 * \brief Level-of-detail
 *
 * A quantified replacement for older values of min/max.
 */
enum LODLevel
{
    LOD_Constant = -1, //!< triangle is always visible, no matter at what distance
    LOD_Low      =  1, //!< triangle is visible at farthest distance (lowest quality)
    LOD_Medium   =  2, //!< triangle is visible at medium distance (medium quality)
    LOD_High     =  4  //!< triangle is visible at closest distance (highest quality)
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
    //! LOD level
    LODLevel lodLevel;
    //! Rendering state to be set
    int state;
    //! Model part
    int part;

    RawModelTriangle()
    {
        variableTex2 = true;
        lodLevel = LOD_Constant;
        state = 0;
        part = 0;
    }
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
 * \enum ModelMaterialTextureModes
 * \brief Modes (flag array) of texturing model material
 */
enum class ModelMaterialTextureModes
{
    Normal = (1<<0),
    Alpha = (1<<5),
    VariableSecondary = (1<<6),
    BlackTransparent = (1<<1),
    WhiteTransparent = (1<<2),
    SecondaryBlackTransparent = (1<<3),
    SecondaryWhiteTransparent = (1<<4)
};

typedef unsigned int ModelMaterialTextureMode;

/**
 * \enum ModelMaterial
 * \brief Material of model
 */
struct ModelMaterial
{
    //! Lighting material
    Material material;
    //! Primaty texture
    std::string tex1Name;
    //! Secondary texture
    std::string tex2Name;
    //! Texturing mode (flag set)
    ModelMaterialTextureMode textureMode;
    //! Custom part for changeable parts of model
    unsigned int customPart;

    ModelMaterial()
     : textureMode(static_cast<ModelMaterialTextureMode>(ModelMaterialTextureModes::Normal))
     , customPart(0)
    {}
};

/**
 * \class CModelSubpart
 * \brief Subpart of model - chunk of geometry with one material
 */
class CModelSubpart
{
    friend class CModelPart;

private:
    CModelSubpart();

public:
    //! Returns associated model material
    const ModelMaterial& GetMaterial() const;

    //! Change model material
    void SetMaterial(const ModelMaterial& material);

private:
    ModelMaterial m_material;
    ModelGeometry m_geometry;
    BufferId m_geometryBufferId;
    ModelUvMap m_uvMap;
    BufferId m_uvMapBufferId;
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

private:
    CModelPart();

public:
    //! Returns the part number
    int GetNumber() const;

    //! Returns model subparts
    std::vector<CModelSubpart*> GetSubparts();

private:
    int m_number;
    std::vector<CModelSubpart*> m_subparts;
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

    //! Update buffers (re-pack data into buffers)
    void Update();

    //! Returns the number of triangles in model
    int GetTriangleCount() const;

    //! Collects raw model triangles from all parts
    std::vector<RawModelTriangle> GetRawTriangles() const;

    //! Sets new model data from raw triangles
    void SetRawTriangles(const std::vector<RawModelTriangle>& rawTriangles);

    //! Returns number of model parts
    int GetNumberOfParts() const;

    //! Returns part at given number
    CModelPart* GetPart(int partNumber);

private:
    //! Raw model triangles
    std::vector<RawModelTriangle> m_rawTriangles;
    //! Model parts
    std::vector<CModelPart*> m_parts;
};

} // namespace Gfx
