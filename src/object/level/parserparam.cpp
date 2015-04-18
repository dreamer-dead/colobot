/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2014, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsiteс.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */

#include "object/level/parserline.h"


#include "app/app.h"
#include "common/logger.h"
#include "common/pathman.h"
#include "common/resources/resourcemanager.h"
#include "object/level/parser.h"
#include "object/robotmain.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CLevelParserParam::CLevelParserParam(std::string name, std::string value)
{
    m_name = name;
    m_value = value;
    m_empty = false;
}

CLevelParserParam::CLevelParserParam(std::string name, bool empty)
{
    assert(empty == true); // we need a second argument because we don't want to create param with value "name"
    m_name = name;
    m_value = "";
    m_empty = true;
}

CLevelParserParam::~CLevelParserParam()
{
    for(auto& a : m_array)
        delete a;
}

void CLevelParserParam::SetLine(CLevelParserLine* line)
{
    m_line = line;
}

CLevelParserLine* CLevelParserParam::GetLine()
{
    return m_line;
}

std::string CLevelParserParam::GetName()
{
    return m_name;
}

std::string CLevelParserParam::GetValue()
{
    return m_value;
}

bool CLevelParserParam::IsDefined()
{
    return !m_empty;
}

template<typename T>
T CLevelParserParam::Cast(std::string value, std::string requestedType)
{
    try {
        return boost::lexical_cast<T>(value);
    }
    catch(...)
    {
        throw CLevelParserExceptionBadParam(this, requestedType);
    }
}

template<typename T>
T CLevelParserParam::Cast(std::string requestedType)
{
    return Cast<T>(m_value, requestedType);
}


int CLevelParserParam::AsInt()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return Cast<int>("int");
}


int CLevelParserParam::AsInt(int def)
{
    if(m_empty)
        return def;
    return AsInt();
}


float CLevelParserParam::AsFloat()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return Cast<float>("float");
}

float CLevelParserParam::AsFloat(float def)
{
    if(m_empty)
        return def;
    return AsFloat();
}


std::string CLevelParserParam::AsString()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    if((m_value[0] == '\"' && m_value[m_value.length()-1] == '\"') || (m_value[0] == '\'' && m_value[m_value.length()-1] == '\''))
    {
        return m_value.substr(1, m_value.length()-2);
    } else {
        throw CLevelParserExceptionBadParam(this, "string");
    }
}

std::string CLevelParserParam::AsString(std::string def)
{
    if(m_empty)
        return def;
    return AsString();
}


bool CLevelParserParam::AsBool()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    std::string value = m_value;
    boost::to_lower(value);
    if(value == "true") return true;
    if(value == "false") return false;
    return Cast<bool>("bool");
}

bool CLevelParserParam::AsBool(bool def)
{
    if(m_empty)
        return def;
    return AsBool();
}


std::string CLevelParserParam::ToPath(std::string path, const std::string defaultDir)
{
    if(defaultDir == "" && path.find("%lvl%") != std::string::npos)
        throw CLevelParserException("TODO: Param "+m_name+" does not yet support %lvl%! :(");
    
    return CPathManager::InjectLevelDir(path, defaultDir);
}

std::string CLevelParserParam::AsPath(const std::string defaultDir)
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    
    return ToPath(AsString(), defaultDir);
}

std::string CLevelParserParam::AsPath(const std::string defaultDir, std::string def)
{
    if(m_empty)
        return CPathManager::InjectLevelDir(def, defaultDir);
    
    return ToPath(AsString(def), defaultDir);
}


Gfx::Color CLevelParserParam::AsColor()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    
    ParseArray();
    
    if(m_array.size() == 3) { //RGB
        return Gfx::Color(m_array[0]->AsFloat(), m_array[1]->AsFloat(), m_array[2]->AsFloat());
    } else if(m_array.size() == 4) { //RGBA
        return Gfx::Color(m_array[0]->AsFloat(), m_array[1]->AsFloat(), m_array[2]->AsFloat(), m_array[3]->AsFloat());
    } else {
        throw CLevelParserExceptionBadParam(this, "color");
    }
}

Gfx::Color CLevelParserParam::AsColor(Gfx::Color def)
{
    if(m_empty)
        return def;
    return AsColor();
}


Math::Vector CLevelParserParam::AsPoint()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    
    ParseArray();
    
    if(m_array.size() == 2) { //XZ
        return Math::Vector(m_array[0]->AsFloat(), 0.0f, m_array[1]->AsFloat());
    } else if(m_array.size() == 3) { //XYZ
        return Math::Vector(m_array[0]->AsFloat(), m_array[1]->AsFloat(), m_array[2]->AsFloat());
    } else {
        throw CLevelParserExceptionBadParam(this, "point");
    }
}

Math::Vector CLevelParserParam::AsPoint(Math::Vector def)
{
    if(m_empty)
        return def;
    return AsPoint();
}


CObjectType* CLevelParserParam::ToObjectType(std::string value)
{
    if(value == "All") return OBJECT_NULL;
    if(value == "Any") return OBJECT_NULL;
    if(value == "Null") return OBJECT_NULL;

    CObjectType* type = CTypeRegistry::GetInstancePointer()->GetByName(value);
    if(type != nullptr) return type;

    return CTypeRegistry::GetInstancePointer()->GetByUniqueID(Cast<int>(value, "object"));
}

const std::string CLevelParserParam::FromObjectType(CObjectType* value)
{
    if(value == nullptr) return "Null";
    return value->GetName();
}

CObjectType* CLevelParserParam::AsObjectType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToObjectType(m_value);
}

CObjectType* CLevelParserParam::AsObjectType(CObjectType* def)
{
    if(m_empty)
        return def;
    return AsObjectType();
}


DriveType CLevelParserParam::ToDriveType(std::string value)
{
    if(value == "Wheeled") return DRIVE_WHEELED;
    if(value == "Tracked") return DRIVE_TRACKED;
    if(value == "Winged" ) return DRIVE_WINGED;
    if(value == "Legged" ) return DRIVE_LEGGED;
    if(value == "Other"  ) return DRIVE_OTHER;
    return static_cast<DriveType>(Cast<int>(value, "drive"));
}

DriveType CLevelParserParam::AsDriveType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToDriveType(m_value);
}

DriveType CLevelParserParam::AsDriveType(DriveType def)
{
    if(m_empty)
        return def;
    return AsDriveType();
}


ToolType CLevelParserParam::ToToolType(std::string value)
{
    if(value == "Grabber"    ) return TOOL_GRABBER;
    if(value == "Shiffer"    ) return TOOL_SNIFFER;
    if(value == "Shooter"    ) return TOOL_SHOOTER;
    if(value == "OrgaShooter") return TOOL_ORGASHOOTER;
    if(value == "Other"      ) return TOOL_OTHER;
    return static_cast<ToolType>(Cast<int>(value, "tool"));
}

ToolType CLevelParserParam::AsToolType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToToolType(m_value);
}

ToolType CLevelParserParam::AsToolType(ToolType def)
{
    if(m_empty)
        return def;
    return AsToolType();
}


Gfx::WaterType CLevelParserParam::ToWaterType(std::string value)
{
    if(value == "NULL") return Gfx::WATER_NULL;
    if(value == "TT"  ) return Gfx::WATER_TT;
    if(value == "TO"  ) return Gfx::WATER_TO;
    if(value == "CT"  ) return Gfx::WATER_CT;
    if(value == "CO"  ) return Gfx::WATER_CO;
    return static_cast<Gfx::WaterType>(Cast<int>(value, "watertype"));
}

Gfx::WaterType CLevelParserParam::AsWaterType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToWaterType(m_value);
}

Gfx::WaterType CLevelParserParam::AsWaterType(Gfx::WaterType def)
{
    if(m_empty)
        return def;
    return AsWaterType();
}


Gfx::EngineObjectType CLevelParserParam::ToTerrainType(std::string value)
{
    if(value == "Terrain") return Gfx::ENG_OBJTYPE_TERRAIN;
    if(value == "Object" ) return Gfx::ENG_OBJTYPE_FIX;
    if(value == "Quartz" ) return Gfx::ENG_OBJTYPE_QUARTZ;
    if(value == "Metal"  ) return Gfx::ENG_OBJTYPE_METAL;
    return static_cast<Gfx::EngineObjectType>(Cast<int>(value, "terraintype"));
}

Gfx::EngineObjectType CLevelParserParam::AsTerrainType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToTerrainType(m_value);
}

Gfx::EngineObjectType CLevelParserParam::AsTerrainType(Gfx::EngineObjectType def)
{
    if(m_empty)
        return def;
    return AsTerrainType();
}


int CLevelParserParam::ToBuildFlag(std::string value)
{
    if(value == "BotFactory"    ) return BUILD_FACTORY;
    if(value == "Derrick"       ) return BUILD_DERRICK;
    if(value == "Converter"     ) return BUILD_CONVERT;
    if(value == "RadarStation"  ) return BUILD_RADAR;
    if(value == "PowerPlant"    ) return BUILD_ENERGY;
    if(value == "NuclearPlant"  ) return BUILD_NUCLEAR;
    if(value == "FuelCellPlant" ) return BUILD_NUCLEAR;
    if(value == "PowerStation"  ) return BUILD_STATION;
    if(value == "RepairCenter"  ) return BUILD_REPAIR;
    if(value == "DefenseTower"  ) return BUILD_TOWER;
    if(value == "ResearchCenter") return BUILD_RESEARCH;
    if(value == "AutoLab"       ) return BUILD_LABO;
    if(value == "PowerCaptor"   ) return BUILD_PARA;
    if(value == "ExchangePost"  ) return BUILD_INFO;
    if(value == "Destroyer"     ) return BUILD_DESTROYER;
    if(value == "FlatGround"    ) return BUILD_GFLAT;
    if(value == "Flag"          ) return BUILD_FLAG;
    return Cast<int>(value, "buildflag");
}

int CLevelParserParam::AsBuildFlag()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToBuildFlag(m_value);
}

int CLevelParserParam::AsBuildFlag(int def)
{
    if(m_empty)
        return def;
    return AsBuildFlag();
}


int CLevelParserParam::ToResearchFlag(std::string value)
{
    if(value == "TRACKER" ) return RESEARCH_TANK;
    if(value == "WINGER"  ) return RESEARCH_FLY;
    if(value == "THUMPER" ) return RESEARCH_THUMP;
    if(value == "SHOOTER" ) return RESEARCH_CANON;
    if(value == "TOWER"   ) return RESEARCH_TOWER;
    if(value == "PHAZER"  ) return RESEARCH_PHAZER;
    if(value == "SHIELDER") return RESEARCH_SHIELD;
    if(value == "ATOMIC"  ) return RESEARCH_ATOMIC;
    if(value == "iPAW"    ) return RESEARCH_iPAW;
    if(value == "iGUN"    ) return RESEARCH_iGUN;
    if(value == "RECYCLER") return RESEARCH_RECYCLER;
    if(value == "SUBBER"  ) return RESEARCH_SUBM;
    if(value == "SNIFFER" ) return RESEARCH_SNIFFER;
    return Cast<int>(value, "researchflag");
}

int CLevelParserParam::AsResearchFlag()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToResearchFlag(m_value);
}

int CLevelParserParam::AsResearchFlag(int def)
{
    if(m_empty)
        return def;
    return AsResearchFlag();
}


Gfx::PyroType CLevelParserParam::ToPyroType(std::string value)
{
    if(value == "FRAGt" ) return Gfx::PT_FRAGT;
    if(value == "FRAGo" ) return Gfx::PT_FRAGO;
    if(value == "FRAGw" ) return Gfx::PT_FRAGW;
    if(value == "EXPLOt") return Gfx::PT_EXPLOT;
    if(value == "EXPLOo") return Gfx::PT_EXPLOO;
    if(value == "EXPLOw") return Gfx::PT_EXPLOW;
    if(value == "SHOTt" ) return Gfx::PT_SHOTT;
    if(value == "SHOTh" ) return Gfx::PT_SHOTH;
    if(value == "SHOTm" ) return Gfx::PT_SHOTM;
    if(value == "SHOTw" ) return Gfx::PT_SHOTW;
    if(value == "EGG"   ) return Gfx::PT_EGG;
    if(value == "BURNt" ) return Gfx::PT_BURNT;
    if(value == "BURNo" ) return Gfx::PT_BURNO;
    if(value == "SPIDER") return Gfx::PT_SPIDER;
    if(value == "FALL"  ) return Gfx::PT_FALL;
    if(value == "RESET" ) return Gfx::PT_RESET;
    if(value == "WIN"   ) return Gfx::PT_WIN;
    if(value == "LOST"  ) return Gfx::PT_LOST;
    return static_cast<Gfx::PyroType>(Cast<int>(value, "pyrotype"));
}

Gfx::PyroType CLevelParserParam::AsPyroType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToPyroType(m_value);
}

Gfx::PyroType CLevelParserParam::AsPyroType(Gfx::PyroType def)
{
    if(m_empty)
        return def;
    return AsPyroType();
}


Gfx::CameraType CLevelParserParam::ToCameraType(std::string value)
{
    if(value == "BACK"   ) return Gfx::CAM_TYPE_BACK;
    if(value == "PLANE"  ) return Gfx::CAM_TYPE_PLANE;
    if(value == "ONBOARD") return Gfx::CAM_TYPE_ONBOARD;
    if(value == "FIX"    ) return Gfx::CAM_TYPE_FIX;
    return static_cast<Gfx::CameraType>(Cast<int>(value, "camera"));
}

const std::string CLevelParserParam::FromCameraType(Gfx::CameraType value)
{
    if(value == Gfx::CAM_TYPE_ONBOARD) return "ONBOARD";
    if(value == Gfx::CAM_TYPE_FIX    ) return "FIX";
    return boost::lexical_cast<std::string>(static_cast<int>(value));
}

Gfx::CameraType CLevelParserParam::AsCameraType()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    return ToCameraType(m_value);
}

Gfx::CameraType CLevelParserParam::AsCameraType(Gfx::CameraType def)
{
    if(m_empty)
        return def;
    return AsCameraType();
}


void CLevelParserParam::ParseArray()
{
    if(m_array.size() != 0)
        return;
    
    std::vector<std::string> values;
    boost::split(values, m_value, boost::is_any_of(";"));
    int i = 0;
    for(auto& value : values) {
        boost::algorithm::trim(value);
        if(value.empty()) continue;
        CLevelParserParam* param = new CLevelParserParam(m_name+"["+boost::lexical_cast<std::string>(i)+"]", value);
        param->SetLine(m_line);
        m_array.push_back(param);
        i++;
    }
}

void CLevelParserParam::LoadArray()
{
    m_value = "";
    bool first = true;
    for(auto& value : m_array) {
        if(!first)
            m_value += ";";
        m_value += value->GetValue();
        first = false;
    }
}

const std::vector<CLevelParserParam*>& CLevelParserParam::AsArray()
{
    if(m_empty)
        throw CLevelParserExceptionMissingParam(this);
    
    ParseArray();
    
    return m_array;
}

CLevelParserParam::CLevelParserParam(int value)
{
    m_value = boost::lexical_cast<std::string>(value);
}
CLevelParserParam::CLevelParserParam(float value)
{
    m_value = boost::lexical_cast<std::string>(value);
}
CLevelParserParam::CLevelParserParam(std::string value)
{
    m_value = "\""+value+"\"";
}
CLevelParserParam::CLevelParserParam(bool value)
{
    m_value = value ? "1" : "0";
}
CLevelParserParam::CLevelParserParam(Gfx::Color value)
{
    m_array.push_back(new CLevelParserParam(value.r));
    m_array.push_back(new CLevelParserParam(value.g));
    m_array.push_back(new CLevelParserParam(value.b));
    m_array.push_back(new CLevelParserParam(value.a));
    LoadArray();
}
CLevelParserParam::CLevelParserParam(Math::Point value)
{
    m_array.push_back(new CLevelParserParam(value.x));
    m_array.push_back(new CLevelParserParam(value.y));
    LoadArray();
}
CLevelParserParam::CLevelParserParam(Math::Vector value)
{
    m_array.push_back(new CLevelParserParam(value.x));
    m_array.push_back(new CLevelParserParam(value.y));
    m_array.push_back(new CLevelParserParam(value.z));
    LoadArray();
}
CLevelParserParam::CLevelParserParam(CObjectType* value)
{
    m_value = FromObjectType(value);
}
CLevelParserParam::CLevelParserParam(Gfx::CameraType value)
{
    m_value = FromCameraType(value);
}
CLevelParserParam::CLevelParserParam(const std::vector<CLevelParserParam*>& value)
{
    m_array = value;
    LoadArray();
}

