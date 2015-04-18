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


#include "script/cmdtoken.h"

#include "common/global.h"

#include <string.h>
#include <cstdio>


// TODO: Remove these functions


// Skips spaces.

char* SkipSpace(char *line)
{
    while ( *line == ' ' )
    {
        line ++;
    }
    return line;
}

std::string GetCmd(char* line)
{
    line = SkipSpace(line);

    int len = 0;
    for(char* x = line; *x != 0 && *x != ' ' && *x != '\t' && *x != '\n'; x++, len++);

    return std::string(line, len);
}

// Checks if a line contains a command.

bool Cmd(char *line, const char *token)
{
    char*   p;

    line = SkipSpace(line);
    
    p = strstr(line, token);
    if(p != line) return false;  // command at the beginning?
    
    unsigned int len = 0;
    for(char* x = p; *x != 0 && *x != ' ' && *x != '\t' && *x != '\n'; x++, len++);
    if(len != strlen(token)) return false; // ends with space?
    
    return true;
}

// Seeking an operator.

char* SearchOp(char *line, const char *op)
{
    char    opeq[50];
    char*   p;

    strcpy(opeq, " ");
    strcat(opeq, op);
    strcat(opeq, "=");

    p = strstr(line, opeq);
    if ( p == 0 )  // not found?
    {
        return line+strlen(line);  // point zero terminator
    }
    return p+strlen(opeq);  // after the point "="
}

// Seeks the argument.

char* SearchArg(char *line, int rank)
{
    int     i;
    char    c;

    for ( i=0 ; i<rank ; i++ )
    {
        while ( true )
        {
            c = *line++;
            if ( c == ';' )  break;
            if ( c == '=' ||
                 c ==  0  )  return line+strlen(line);
        }
    }

    line = SkipSpace(line);
    return line;
}

// Reads an integer, eventually hexadecimal.

int GetInt(char *line, int rank, int def)
{
    char*   p;
    int     n = 0;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return def;

    if ( p[0] == '0' &&
         p[1] == 'x' )  // begins with "0x" (hexadecimal)?
    {
        p += 2;
        while ( true )
        {
            if ( *p >= '0' && *p <= '9' )
            {
                n *= 16;
                n += (*p++)-'0';
                continue;
            }
            if ( *p >= 'a' && *p <= 'f' )
            {
                n *= 16;
                n += (*p++)-'a'+10;
                continue;
            }
            break;
        }
    }
    else    // integer?
    {
        sscanf(p, "%d", &n);
    }
    return n;
}

// Reads a float number.

float GetFloat(char *line, int rank, float def)
{
    char*   p;
    float   n = 0.0f;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return def;

    sscanf(p, "%f", &n);
    return n;
}

// Reads a string.

void GetString(char *line, int rank, char *buffer)
{
    char*   p;

    p = SearchArg(line, rank);
    *buffer = 0;
    if ( *p++ != '"' )  return;

    while ( p[0] != 0 )
    {
        if ( p[0] == '"' &&
             p[1] == '"' )
        {
            *buffer++ = *p++;
            p++;
            continue;
        }
        if ( p[0] == '"' )  break;

        *buffer++ = *p++;
    }
    *buffer = 0;
}

// Returns the type of water.

Gfx::WaterType GetTypeWater(char *line, int rank, Gfx::WaterType def)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return def;

    if ( Cmd(p, "NULL" ) )  return Gfx::WATER_NULL;
    if ( Cmd(p, "TT"   ) )  return Gfx::WATER_TT;
    if ( Cmd(p, "TO"   ) )  return Gfx::WATER_TO;
    if ( Cmd(p, "CT"   ) )  return Gfx::WATER_CT;
    if ( Cmd(p, "CO"   ) )  return Gfx::WATER_CO;

    return def;
}

// Returns the type of terrain.

Gfx::EngineObjectType GetTypeTerrain(char *line, int rank, Gfx::EngineObjectType def)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return def;

    if ( Cmd(p, "Terrain" ) )  return Gfx::ENG_OBJTYPE_TERRAIN;
    if ( Cmd(p, "Object"  ) )  return Gfx::ENG_OBJTYPE_FIX;
    if ( Cmd(p, "Quartz"  ) )  return Gfx::ENG_OBJTYPE_QUARTZ;
    if ( Cmd(p, "Metal"   ) )  return Gfx::ENG_OBJTYPE_METAL;

    return def;
}

// Returns the type of a building.

int GetBuild(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return 0;

    if ( Cmd(p, "BotFactory"    ) )  return BUILD_FACTORY;
    if ( Cmd(p, "Derrick"       ) )  return BUILD_DERRICK;
    if ( Cmd(p, "Converter"     ) )  return BUILD_CONVERT;
    if ( Cmd(p, "RadarStation"  ) )  return BUILD_RADAR;
    if ( Cmd(p, "PowerPlant"    ) )  return BUILD_ENERGY;
    if ( Cmd(p, "NuclearPlant"  ) )  return BUILD_NUCLEAR;
    if ( Cmd(p, "FuelCellPlant" ) )  return BUILD_NUCLEAR;
    if ( Cmd(p, "PowerStation"  ) )  return BUILD_STATION;
    if ( Cmd(p, "RepairCenter"  ) )  return BUILD_REPAIR;
    if ( Cmd(p, "DefenseTower"  ) )  return BUILD_TOWER;
    if ( Cmd(p, "ResearchCenter") )  return BUILD_RESEARCH;
    if ( Cmd(p, "AutoLab"       ) )  return BUILD_LABO;
    if ( Cmd(p, "PowerCaptor"   ) )  return BUILD_PARA;
    if ( Cmd(p, "ExchangePost"  ) )  return BUILD_INFO;
    if ( Cmd(p, "Destroyer"     ) )  return BUILD_DESTROYER;
    if ( Cmd(p, "FlatGround"    ) )  return BUILD_GFLAT;
    if ( Cmd(p, "Flag"          ) )  return BUILD_FLAG;

    return 0;
}

// Returns the type of search.

int GetResearch(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return 0;

    if ( Cmd(p, "TRACKER" ) )  return RESEARCH_TANK;
    if ( Cmd(p, "WINGER"  ) )  return RESEARCH_FLY;
    if ( Cmd(p, "THUMPER" ) )  return RESEARCH_THUMP;
    if ( Cmd(p, "SHOOTER" ) )  return RESEARCH_CANON;
    if ( Cmd(p, "TOWER"   ) )  return RESEARCH_TOWER;
    if ( Cmd(p, "PHAZER"  ) )  return RESEARCH_PHAZER;
    if ( Cmd(p, "SHIELDER") )  return RESEARCH_SHIELD;
    if ( Cmd(p, "ATOMIC"  ) )  return RESEARCH_ATOMIC;
    if ( Cmd(p, "iPAW"    ) )  return RESEARCH_iPAW;
    if ( Cmd(p, "iGUN"    ) )  return RESEARCH_iGUN;
    if ( Cmd(p, "RECYCLER") )  return RESEARCH_RECYCLER;
    if ( Cmd(p, "SUBBER"  ) )  return RESEARCH_SUBM;
    if ( Cmd(p, "SNIFFER" ) )  return RESEARCH_SNIFFER;

    return 0;
}

// Returns the type of pyrotechnic effect.

Gfx::PyroType GetPyro(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return Gfx::PT_NULL;

    if ( Cmd(p, "FRAGt"  ) )  return Gfx::PT_FRAGT;
    if ( Cmd(p, "FRAGo"  ) )  return Gfx::PT_FRAGO;
    if ( Cmd(p, "FRAGw"  ) )  return Gfx::PT_FRAGW;
    if ( Cmd(p, "EXPLOt" ) )  return Gfx::PT_EXPLOT;
    if ( Cmd(p, "EXPLOo" ) )  return Gfx::PT_EXPLOO;
    if ( Cmd(p, "EXPLOw" ) )  return Gfx::PT_EXPLOW;
    if ( Cmd(p, "SHOTt"  ) )  return Gfx::PT_SHOTT;
    if ( Cmd(p, "SHOTh"  ) )  return Gfx::PT_SHOTH;
    if ( Cmd(p, "SHOTm"  ) )  return Gfx::PT_SHOTM;
    if ( Cmd(p, "SHOTw"  ) )  return Gfx::PT_SHOTW;
    if ( Cmd(p, "EGG"    ) )  return Gfx::PT_EGG;
    if ( Cmd(p, "BURNt"  ) )  return Gfx::PT_BURNT;
    if ( Cmd(p, "BURNo"  ) )  return Gfx::PT_BURNO;
    if ( Cmd(p, "SPIDER" ) )  return Gfx::PT_SPIDER;
    if ( Cmd(p, "FALL"   ) )  return Gfx::PT_FALL;
    if ( Cmd(p, "RESET"  ) )  return Gfx::PT_RESET;
    if ( Cmd(p, "WIN"    ) )  return Gfx::PT_WIN;
    if ( Cmd(p, "LOST"   ) )  return Gfx::PT_LOST;

    return Gfx::PT_NULL;
}

// Returns the type of camera.

Gfx::CameraType GetCamera(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return Gfx::CAM_TYPE_NULL;

    if ( Cmd(p, "BACK"    ) )  return Gfx::CAM_TYPE_BACK;
    if ( Cmd(p, "PLANE"   ) )  return Gfx::CAM_TYPE_PLANE;
    if ( Cmd(p, "ONBOARD" ) )  return Gfx::CAM_TYPE_ONBOARD;
    if ( Cmd(p, "FIX"     ) )  return Gfx::CAM_TYPE_FIX;

    return Gfx::CAM_TYPE_NULL;
}

// Returns the name of a camera.

const char* GetCamera(Gfx::CameraType type)
{
    if ( type == Gfx::CAM_TYPE_ONBOARD )  return "ONBOARD";
    if ( type == Gfx::CAM_TYPE_FIX     )  return "FIX";
    return "BACK";
}

// Returns the type of drive.

DriveType GetDrive(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return DRIVE_OTHER;

    if ( Cmd(p, "Wheeled" ) )  return DRIVE_WHEELED;
    if ( Cmd(p, "Tracked" ) )  return DRIVE_TRACKED;
    if ( Cmd(p, "Winged"  ) )  return DRIVE_WINGED;
    if ( Cmd(p, "Legged"  ) )  return DRIVE_LEGGED;

    return DRIVE_OTHER;
}

// Returns the name of a drive.

const char* GetDrive(DriveType type)
{
    if ( type == DRIVE_WHEELED )  return "Wheeled";
    if ( type == DRIVE_TRACKED )  return "Tracked";
    if ( type == DRIVE_WINGED  )  return "Winged";
    if ( type == DRIVE_LEGGED  )  return "Legged";
    return "Other";
}

// Returns the type of tool.

ToolType GetTool(char *line, int rank)
{
    char*   p;

    p = SearchArg(line, rank);
    if ( *p == 0 )  return TOOL_OTHER;

    if ( Cmd(p, "Grabber"     ) )  return TOOL_GRABBER;
    if ( Cmd(p, "Sniffer"     ) )  return TOOL_SNIFFER;
    if ( Cmd(p, "Shooter"     ) )  return TOOL_SHOOTER;
    if ( Cmd(p, "OrgaShooter" ) )  return TOOL_ORGASHOOTER;

    return TOOL_OTHER;
}

// Returns the name of a tool.

const char* GetTool(ToolType type)
{
    if ( type == TOOL_GRABBER     )  return "Grabber";
    if ( type == TOOL_SNIFFER     )  return "Sniffer";
    if ( type == TOOL_SHOOTER     )  return "Shooter";
    if ( type == TOOL_ORGASHOOTER )  return "OrgaShooter";
    return "Other";
}

// Returns an integer.

int OpInt(char *line, const char *op, int def)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return def;
    return GetInt(line, 0, def);
}

// Returns a float number.

float OpFloat(char *line, const char *op, float def)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return def;
    return GetFloat(line, 0, def);
}

// Returns a string.

void OpString(char *line, const char *op, char *buffer)
{
    line = SearchOp(line, op);
    if ( *line == 0 )
    {
        buffer[0] = 0;
    }
    else
    {
        GetString(line, 0, buffer);
    }
}

// Returns the type of a water.

Gfx::WaterType OpTypeWater(char *line, const char *op, Gfx::WaterType def)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return def;
    return GetTypeWater(line, 0, def);
}

// Returns the type of a terrain.

Gfx::EngineObjectType OpTypeTerrain(char *line, const char *op, Gfx::EngineObjectType def)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return def;
    return GetTypeTerrain(line, 0, def);
}

// Returns the type of research.

int OpResearch(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return 0;
    return GetResearch(line, 0);
}

// Returns the type of pyrotechnic effect.

Gfx::PyroType OpPyro(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return Gfx::PT_NULL;
    return GetPyro(line, 0);
}

// Returns the type of camera.

Gfx::CameraType OpCamera(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return Gfx::CAM_TYPE_NULL;
    return GetCamera(line, 0);
}

// Returns the type of drive.

DriveType OpDrive(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return DRIVE_OTHER;
    return GetDrive(line, 0);
}

// Returns the type of tool.

ToolType OpTool(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return TOOL_OTHER;
    return GetTool(line, 0);
}

// Returns the type of a building.

int OpBuild(char *line, const char *op)
{
    line = SearchOp(line, op);
    if ( *line == 0 )  return 0;
    return GetBuild(line, 0);
}

// Returns a position in the XZ plane (top view).

Math::Vector OpPos(char *line, const char *op)
{
    Math::Vector    pos;

    line = SearchOp(line, op);
    if ( *line == 0 )
    {
        pos = Math::Vector(0.0f, 0.0f, 0.0f);
        return pos;
    }
    pos.x = GetFloat(line, 0, 0.0f);
    pos.y = 0.0f;
    pos.z = GetFloat(line, 1, 0.0f);
    return pos;
}

// Returns a direction.

Math::Vector OpDir(char *line, const char *op)
{
    Math::Vector    dir;

    line = SearchOp(line, op);
    if ( *line == 0 )
    {
        dir = Math::Vector(0.0f, 0.0f, 0.0f);
        return dir;
    }
    dir.x = GetFloat(line, 0, 0.0f);
    dir.y = GetFloat(line, 1, 0.0f);
    dir.z = GetFloat(line, 2, 0.0f);
    return dir;
}

// Reads a color (-1 .. 1).
Gfx::Color  OpColor(char *line, const char *op, Gfx::Color def)
{
    Gfx::Color color;

    line = SearchOp(line, op);
    if ( *line == 0 )  return def;

    color.r = GetFloat(line, 0, 0.0f);
    color.g = GetFloat(line, 1, 0.0f);
    color.b = GetFloat(line, 2, 0.0f);
    color.a = GetFloat(line, 3, 0.0f);
    return color;
}

