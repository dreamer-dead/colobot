// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// * Copyright (C) 2012, Polish Portal of Colobot (PPC)
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

/**
 * \file graphics/engine/model_io.h
 * \brief Model input/output routines - CModelIO class
 */

#pragma once


#include "graphics/core/vertex.h"
#include "graphics/core/material.h"

#include "graphics/engine/model.h"

#include "math/vector.h"

#include <string>
#include <vector>
#include <iostream>



// Graphics module namespace
namespace Gfx {

/**
 * \class CModelIO
 * \brief Model file reader/writer
 *
 * Allows reading and writing model objects. Models are collections of ModelTriangle structs.
 */
class CModelIO
{
public:
    //! Reads a model in text format from file
    static bool                 ReadTextModel(const std::string& fileName, CModel& model);
    //! Reads a model in text format from stream
    static bool                 ReadTextModel(std::istream& stream, CModel& model);

    //! Writes the model in text format to a file
    static bool                 WriteTextModel(const std::string& fileName, const CModel& model);
    //! Writes the model in text format to a stream
    static bool                 WriteTextModel(std::ostream& stream, const CModel& model);

    //! Reads a model in new binary format from file
    static bool                 ReadBinaryModel(const std::string& fileName, CModel& model);
    //! Reads a model in new binary format from stream
    static bool                 ReadBinaryModel(std::istream& stream, CModel& model);

    //! Writes the model in binary format to a file
    static bool                 WriteBinaryModel(const std::string &fileName, const CModel& model);
    //! Writes the model in binary format to a stream
    static bool                 WriteBinaryModel(std::ostream &stream, const CModel& model);

    //! Reads a binary Colobot model from file
    //! @deprecated
    static bool                 ReadModel(const std::string &fileName, CModel& model);
    //! Reads a binary Colobot model from stream
    //! @deprecated
    static bool                 ReadModel(std::istream &stream, CModel& model);
    //! Writes the model to Colobot binary model file
    //! @deprecated
    static bool                 WriteModel(const std::string &fileName, const CModel& model);
    //! Writes the model to Colobot binary model file
    //! @deprecated
    static bool                 WriteModel(std::ostream &stream, const CModel& model);

    //! Controls printing of debug information
    static void SetPrintDebugInfo(bool printDebugInfo);

private:
    //@{
    //! @deprecated min, max conversions
    static LODLevel MinMaxToLodLevel(float min, float max);
    static void LODLevelToMinMax(LODLevel lodLevel, float& min, float& max);
    //@}

private:
    static bool m_printDebugInfo;
};

} // namespace Gfx

