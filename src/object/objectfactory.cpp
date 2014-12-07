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


#include "object/objectfactory.h"

#include "graphics/engine/model_manager.h"
#include "graphics/engine/terrain.h"
#include "object/robotmain.h"
#include "script/cmdtoken.h"

CObjectFactory::CObjectFactory(ObjectType type) : CObjectFactory("objects/"+std::string(GetTypeObject(type))+".txt")
{
}

CObjectFactory::CObjectFactory(std::string filename)
{
    m_file = new CLevelParser(filename);
    m_file->Load();
}

CObjectFactory::~CObjectFactory()
{
    if(m_file != nullptr)
    {
        delete m_file;
        m_file = nullptr;
    }
}

CObject* CObjectFactory::Create(Math::Vector pos, float angle, ObjectType type, float power, float zoom, float height, bool trainer, bool toy, int option)
{
    Gfx::CEngine* engine = Gfx::CEngine::GetInstancePointer();
    Gfx::CModelManager* modelManager = Gfx::CModelManager::GetInstancePointer();
    Gfx::CTerrain* terrain = CRobotMain::GetInstancePointer()->GetTerrain();
    
    CObject* object = new CObject();
    object->SetType(type);
    
    for(auto line : m_file->GetLines())
    {
        if(line->GetCommand() == "Part")
        {
            int id = line->GetParam("id")->AsInt();
            int parent;
            if(id != 0)
                parent = line->GetParam("parent")->AsInt();
            
            Gfx::EngineObjectType objtype = (id == 0 ? Gfx::ENG_OBJTYPE_FIX : Gfx::ENG_OBJTYPE_DESCENDANT);
            
            Math::Vector ppos;
            if(id != 0)
                ppos = line->GetParam("pos")->AsPoint();
            else
                ppos = pos;
            
            Math::Vector pangle;
            if(id != 0)
                pangle = line->GetParam("angle")->AsPoint()*(Math::PI/180.0f);
            else
                pangle = Math::Vector(0.0f, angle, 0.0f);
            
            Math::Vector pzoom;
            if(id != 0)
                pzoom = line->GetParam("zoom")->AsPoint(Math::Vector(1.0f, 1.0f, 1.0f));
            else
                pzoom = Math::Vector(zoom, zoom, zoom);
            
            std::string model = line->GetParam("model")->AsString()+".mod";
            bool mirrored = line->GetParam("mirrored")->AsBool(false);
            
            int rank = engine->CreateObject();
            engine->SetObjectType(rank, objtype);
            object->SetObjectRank(id, rank);
            if(id != 0)
                object->SetObjectParent(id, parent);
            modelManager->AddModelReference(model, mirrored, rank);
            object->SetPosition(id, ppos);
            object->SetAngle(id, pangle);
            object->SetZoom(id, pzoom);
            if(id == 0)
                object->SetFloorHeight(0.0f); //TODO: can it be != 0?
        }
        
        if(line->GetCommand() == "CrashSphere")
        {
            Math::Vector ppos = line->GetParam("pos")->AsPoint();
            float radius = line->GetParam("radius")->AsFloat();
            Sound sound = line->GetParam("sound")->AsSoundType(SOUND_NONE);
            float hardness = line->GetParam("hardness")->AsFloat(0.45f);
            
            object->CreateCrashSphere(ppos, radius, sound, hardness);
        }
        
        if(line->GetCommand() == "ShadowCircle")
        {
            float radius = line->GetParam("radius")->AsFloat();
            float intensity = line->GetParam("intensity")->AsFloat();
            
            object->CreateShadowCircle(radius, intensity);
        }
        
        if(line->GetCommand() == "BuildingLevel")
        {
            Math::Vector ppos = line->GetParam("pos")->AsPoint();
            float min = line->GetParam("min")->AsFloat();
            float max = line->GetParam("max")->AsFloat();
            float height = line->GetParam("height")->AsFloat();
            float factor = line->GetParam("factor")->AsFloat();
            
            terrain->AddBuildingLevel(ppos, min, max, height, factor);
        }
    }
    
    pos = object->GetPosition(0);
    pos.y += height;
    object->SetPosition(0, pos);  // to display the shadows immediately
    
    object->CreateOtherObject(type); //TODO: This should be also moved to text file (somehow)
    engine->LoadAllTextures();
    
    return object;
}