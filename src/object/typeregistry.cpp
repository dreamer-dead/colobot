/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2015, Daniel Roux, EPSITEC SA & TerranovaTeam
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

#include "object/typeregistry.h"

template<> CTypeRegistry* CSingleton<CTypeRegistry>::m_instance = nullptr;

CTypeRegistry::CTypeRegistry()
{
	InitStandardTypes();
}

CTypeRegistry::~CTypeRegistry()
{
}

const std::vector<CObjectType*>& CTypeRegistry::GetAll()
{
	return m_types;
}

CObjectType* CTypeRegistry::RegisterType(CObjectType* type)
{
	m_types.push_back(type);
	type->SetUniqueID(m_types.size());
	return type;
}

CObjectType* CTypeRegistry::GetByName(const std::string& name)
{
	for(CObjectType* type : m_types)
	{
		if(type->GetName() == name)
			return type;
	}
	return nullptr;
}

CObjectType* CTypeRegistry::GetByScriptableName(const std::string& name)
{
	for(CObjectType* type : m_types)
	{
		if(type->GetBaseType() != type) continue;
		if(type->GetScriptableName() == name)
			return type;
	}
	return nullptr;
}

CObjectType* CTypeRegistry::GetByUniqueID(int uid)
{
	for(CObjectType* type : m_types)
	{
		if(type->GetUniqueID() == uid)
			return type;
	}
	return nullptr;
}

CObjectType* OBJECT_NULL = nullptr;
CObjectType* OBJECT_FIX = nullptr;
CObjectType* OBJECT_PORTICO = nullptr;
CObjectType* OBJECT_BASE = nullptr;
CObjectType* OBJECT_DERRICK = nullptr;
CObjectType* OBJECT_FACTORY = nullptr;
CObjectType* OBJECT_STATION = nullptr;
CObjectType* OBJECT_CONVERT = nullptr;
CObjectType* OBJECT_REPAIR = nullptr;
CObjectType* OBJECT_TOWER = nullptr;
CObjectType* OBJECT_NEST = nullptr;
CObjectType* OBJECT_RESEARCH = nullptr;
CObjectType* OBJECT_RADAR = nullptr;
CObjectType* OBJECT_ENERGY = nullptr;
CObjectType* OBJECT_LABO = nullptr;
CObjectType* OBJECT_NUCLEAR = nullptr;
CObjectType* OBJECT_START = nullptr;
CObjectType* OBJECT_END = nullptr;
CObjectType* OBJECT_INFO = nullptr;
CObjectType* OBJECT_PARA = nullptr;
CObjectType* OBJECT_TARGET1 = nullptr;
CObjectType* OBJECT_TARGET2 = nullptr;
CObjectType* OBJECT_SAFE = nullptr;
CObjectType* OBJECT_HUSTON = nullptr;
CObjectType* OBJECT_DESTROYER = nullptr;
CObjectType* OBJECT_FRET = nullptr;
CObjectType* OBJECT_STONE = nullptr;
CObjectType* OBJECT_URANIUM = nullptr;
CObjectType* OBJECT_METAL = nullptr;
CObjectType* OBJECT_POWER = nullptr;
CObjectType* OBJECT_ATOMIC = nullptr;
CObjectType* OBJECT_BULLET = nullptr;
CObjectType* OBJECT_BBOX = nullptr;
CObjectType* OBJECT_TNT = nullptr;
CObjectType* OBJECT_SCRAP1 = nullptr;
CObjectType* OBJECT_SCRAP2 = nullptr;
CObjectType* OBJECT_SCRAP3 = nullptr;
CObjectType* OBJECT_SCRAP4 = nullptr;
CObjectType* OBJECT_SCRAP5 = nullptr;
CObjectType* OBJECT_MARKPOWER = nullptr;
CObjectType* OBJECT_MARKSTONE = nullptr;
CObjectType* OBJECT_MARKURANIUM = nullptr;
CObjectType* OBJECT_MARKKEYa = nullptr;
CObjectType* OBJECT_MARKKEYb = nullptr;
CObjectType* OBJECT_MARKKEYc = nullptr;
CObjectType* OBJECT_MARKKEYd = nullptr;
CObjectType* OBJECT_BOMB = nullptr;
CObjectType* OBJECT_WINFIRE = nullptr;
CObjectType* OBJECT_SHOW = nullptr;
CObjectType* OBJECT_BAG = nullptr;
CObjectType* OBJECT_PLANT0 = nullptr;
CObjectType* OBJECT_PLANT1 = nullptr;
CObjectType* OBJECT_PLANT2 = nullptr;
CObjectType* OBJECT_PLANT3 = nullptr;
CObjectType* OBJECT_PLANT4 = nullptr;
CObjectType* OBJECT_PLANT5 = nullptr;
CObjectType* OBJECT_PLANT6 = nullptr;
CObjectType* OBJECT_PLANT7 = nullptr;
CObjectType* OBJECT_PLANT8 = nullptr;
CObjectType* OBJECT_PLANT9 = nullptr;
CObjectType* OBJECT_PLANT10 = nullptr;
CObjectType* OBJECT_PLANT11 = nullptr;
CObjectType* OBJECT_PLANT12 = nullptr;
CObjectType* OBJECT_PLANT13 = nullptr;
CObjectType* OBJECT_PLANT14 = nullptr;
CObjectType* OBJECT_PLANT15 = nullptr;
CObjectType* OBJECT_PLANT16 = nullptr;
CObjectType* OBJECT_PLANT17 = nullptr;
CObjectType* OBJECT_PLANT18 = nullptr;
CObjectType* OBJECT_PLANT19 = nullptr;
CObjectType* OBJECT_TREE0 = nullptr;
CObjectType* OBJECT_TREE1 = nullptr;
CObjectType* OBJECT_TREE2 = nullptr;
CObjectType* OBJECT_TREE3 = nullptr;
CObjectType* OBJECT_TREE4 = nullptr;
CObjectType* OBJECT_TREE5 = nullptr;
CObjectType* OBJECT_MOBILEwt = nullptr;
CObjectType* OBJECT_MOBILEtt = nullptr;
CObjectType* OBJECT_MOBILEft = nullptr;
CObjectType* OBJECT_MOBILEit = nullptr;
CObjectType* OBJECT_MOBILEwa = nullptr;
CObjectType* OBJECT_MOBILEta = nullptr;
CObjectType* OBJECT_MOBILEfa = nullptr;
CObjectType* OBJECT_MOBILEia = nullptr;
CObjectType* OBJECT_MOBILEwc = nullptr;
CObjectType* OBJECT_MOBILEtc = nullptr;
CObjectType* OBJECT_MOBILEfc = nullptr;
CObjectType* OBJECT_MOBILEic = nullptr;
CObjectType* OBJECT_MOBILEwi = nullptr;
CObjectType* OBJECT_MOBILEti = nullptr;
CObjectType* OBJECT_MOBILEfi = nullptr;
CObjectType* OBJECT_MOBILEii = nullptr;
CObjectType* OBJECT_MOBILEws = nullptr;
CObjectType* OBJECT_MOBILEts = nullptr;
CObjectType* OBJECT_MOBILEfs = nullptr;
CObjectType* OBJECT_MOBILEis = nullptr;
CObjectType* OBJECT_MOBILErt = nullptr;
CObjectType* OBJECT_MOBILErc = nullptr;
CObjectType* OBJECT_MOBILErr = nullptr;
CObjectType* OBJECT_MOBILErs = nullptr;
CObjectType* OBJECT_MOBILEsa = nullptr;
CObjectType* OBJECT_MOBILEtg = nullptr;
CObjectType* OBJECT_MOBILEdr = nullptr;
CObjectType* OBJECT_CONTROLLER = nullptr;
CObjectType* OBJECT_WAYPOINT = nullptr;
CObjectType* OBJECT_FLAGb = nullptr;
CObjectType* OBJECT_FLAGr = nullptr;
CObjectType* OBJECT_FLAGg = nullptr;
CObjectType* OBJECT_FLAGy = nullptr;
CObjectType* OBJECT_FLAGv = nullptr;
CObjectType* OBJECT_KEYa = nullptr;
CObjectType* OBJECT_KEYb = nullptr;
CObjectType* OBJECT_KEYc = nullptr;
CObjectType* OBJECT_KEYd = nullptr;
CObjectType* OBJECT_HUMAN = nullptr;
CObjectType* OBJECT_TOTO = nullptr;
CObjectType* OBJECT_TECH = nullptr;
CObjectType* OBJECT_BARRIER0 = nullptr;
CObjectType* OBJECT_BARRIER1 = nullptr;
CObjectType* OBJECT_BARRIER2 = nullptr;
CObjectType* OBJECT_BARRIER3 = nullptr;
CObjectType* OBJECT_MOTHER = nullptr;
CObjectType* OBJECT_EGG = nullptr;
CObjectType* OBJECT_ANT = nullptr;
CObjectType* OBJECT_SPIDER = nullptr;
CObjectType* OBJECT_BEE = nullptr;
CObjectType* OBJECT_WORM = nullptr;
CObjectType* OBJECT_RUINmobilew1 = nullptr;
CObjectType* OBJECT_RUINmobilew2 = nullptr;
CObjectType* OBJECT_RUINmobilet1 = nullptr;
CObjectType* OBJECT_RUINmobilet2 = nullptr;
CObjectType* OBJECT_RUINmobiler1 = nullptr;
CObjectType* OBJECT_RUINmobiler2 = nullptr;
CObjectType* OBJECT_RUINfactory = nullptr;
CObjectType* OBJECT_RUINdoor = nullptr;
CObjectType* OBJECT_RUINsupport = nullptr;
CObjectType* OBJECT_RUINradar = nullptr;
CObjectType* OBJECT_RUINconvert = nullptr;
CObjectType* OBJECT_RUINbase = nullptr;
CObjectType* OBJECT_RUINhead = nullptr;
CObjectType* OBJECT_TEEN0 = nullptr;
CObjectType* OBJECT_TEEN1 = nullptr;
CObjectType* OBJECT_TEEN2 = nullptr;
CObjectType* OBJECT_TEEN3 = nullptr;
CObjectType* OBJECT_TEEN4 = nullptr;
CObjectType* OBJECT_TEEN5 = nullptr;
CObjectType* OBJECT_TEEN6 = nullptr;
CObjectType* OBJECT_TEEN7 = nullptr;
CObjectType* OBJECT_TEEN8 = nullptr;
CObjectType* OBJECT_TEEN9 = nullptr;
CObjectType* OBJECT_TEEN10 = nullptr;
CObjectType* OBJECT_TEEN11 = nullptr;
CObjectType* OBJECT_TEEN12 = nullptr;
CObjectType* OBJECT_TEEN13 = nullptr;
CObjectType* OBJECT_TEEN14 = nullptr;
CObjectType* OBJECT_TEEN15 = nullptr;
CObjectType* OBJECT_TEEN16 = nullptr;
CObjectType* OBJECT_TEEN17 = nullptr;
CObjectType* OBJECT_TEEN18 = nullptr;
CObjectType* OBJECT_TEEN19 = nullptr;
CObjectType* OBJECT_TEEN20 = nullptr;
CObjectType* OBJECT_TEEN21 = nullptr;
CObjectType* OBJECT_TEEN22 = nullptr;
CObjectType* OBJECT_TEEN23 = nullptr;
CObjectType* OBJECT_TEEN24 = nullptr;
CObjectType* OBJECT_TEEN25 = nullptr;
CObjectType* OBJECT_TEEN26 = nullptr;
CObjectType* OBJECT_TEEN27 = nullptr;
CObjectType* OBJECT_TEEN28 = nullptr;
CObjectType* OBJECT_TEEN29 = nullptr;
CObjectType* OBJECT_TEEN30 = nullptr;
CObjectType* OBJECT_TEEN31 = nullptr;
CObjectType* OBJECT_TEEN32 = nullptr;
CObjectType* OBJECT_TEEN33 = nullptr;
CObjectType* OBJECT_TEEN34 = nullptr;
CObjectType* OBJECT_TEEN35 = nullptr;
CObjectType* OBJECT_TEEN36 = nullptr;
CObjectType* OBJECT_TEEN37 = nullptr;
CObjectType* OBJECT_TEEN38 = nullptr;
CObjectType* OBJECT_TEEN39 = nullptr;
CObjectType* OBJECT_TEEN40 = nullptr;
CObjectType* OBJECT_TEEN41 = nullptr;
CObjectType* OBJECT_TEEN42 = nullptr;
CObjectType* OBJECT_TEEN43 = nullptr;
CObjectType* OBJECT_TEEN44 = nullptr;
CObjectType* OBJECT_QUARTZ0 = nullptr;
CObjectType* OBJECT_QUARTZ1 = nullptr;
CObjectType* OBJECT_QUARTZ2 = nullptr;
CObjectType* OBJECT_QUARTZ3 = nullptr;
CObjectType* OBJECT_ROOT0 = nullptr;
CObjectType* OBJECT_ROOT1 = nullptr;
CObjectType* OBJECT_ROOT2 = nullptr;
CObjectType* OBJECT_ROOT3 = nullptr;
CObjectType* OBJECT_ROOT4 = nullptr;
CObjectType* OBJECT_ROOT5 = nullptr;
CObjectType* OBJECT_MUSHROOM1 = nullptr;
CObjectType* OBJECT_MUSHROOM2 = nullptr;
CObjectType* OBJECT_APOLLO1 = nullptr;
CObjectType* OBJECT_APOLLO2 = nullptr;
CObjectType* OBJECT_APOLLO3 = nullptr;
CObjectType* OBJECT_APOLLO4 = nullptr;
CObjectType* OBJECT_APOLLO5 = nullptr;
CObjectType* OBJECT_HOME1 = nullptr;

/* Macro to mark which texts are translatable by gettext
 * It doesn't do anything at compile-time, as all texts represented here are used later
 * in explicit call to gettext(), but it is used by xgettext executable to filter extracted
 * texts from this file.
 */
#define TR(x) x

void CTypeRegistry::InitStandardTypes()
{
	//TODO: This will be loaded from files at some point
	OBJECT_NULL = nullptr;

	OBJECT_PORTICO = RegisterType(CObjectTypeHardcoded::Create("Portico", TR("Gantry crane"), { CAP_BUILDING }));
	OBJECT_BASE = RegisterType(CObjectTypeHardcoded::Create("SpaceShip", TR("Spaceship"), { CAP_BUILDING }));
	OBJECT_DERRICK = RegisterType(CObjectTypeHardcoded::Create("Derrick",TR("Derrick"), { CAP_BUILDING }));
	OBJECT_FACTORY = RegisterType(CObjectTypeHardcoded::Create("BotFactory", TR("Bot factory"), { CAP_BUILDING }));
	OBJECT_STATION = RegisterType(CObjectTypeHardcoded::Create("PowerStation", TR("Power station"), { CAP_BUILDING }));
	OBJECT_CONVERT = RegisterType(CObjectTypeHardcoded::Create("Converter", TR("Converts ore to titanium"), { CAP_BUILDING }));
	OBJECT_REPAIR = RegisterType(CObjectTypeHardcoded::Create("RepairStation", TR("Repair center"), { CAP_BUILDING }));
	OBJECT_TOWER = RegisterType(CObjectTypeHardcoded::Create("DefenseTower", TR("Defense tower"), { CAP_BUILDING }));
	OBJECT_RESEARCH = RegisterType(CObjectTypeHardcoded::Create("ResearchCenter", TR("Research center"), { CAP_BUILDING }));
	OBJECT_RADAR = RegisterType(CObjectTypeHardcoded::Create("RadarStation", TR("Radar station"), { CAP_BUILDING }));
	OBJECT_ENERGY = RegisterType(CObjectTypeHardcoded::Create("PowerPlant", TR("Power cell factory"), { CAP_BUILDING }));
	OBJECT_LABO = RegisterType(CObjectTypeHardcoded::Create("AutoLab", TR("Autolab"), { CAP_BUILDING }));
	OBJECT_NUCLEAR = RegisterType(CObjectTypeHardcoded::Create("NuclearPlant", TR("Nuclear power station"), { CAP_BUILDING }));
	OBJECT_INFO = RegisterType(CObjectTypeHardcoded::Create("ExchangePost", TR("Information exchange post"), { CAP_BUILDING }));
	OBJECT_PARA = RegisterType(CObjectTypeHardcoded::Create("PowerCaptor", TR("Lightning conductor"), { CAP_BUILDING }));
	OBJECT_SAFE = RegisterType(CObjectTypeHardcoded::Create("Vault", TR("Vault"), { CAP_BUILDING }));
	OBJECT_HUSTON = RegisterType(CObjectTypeHardcoded::Create("Houston", TR("Houston Mission Control"), { CAP_BUILDING }));
	OBJECT_DESTROYER = RegisterType(CObjectTypeHardcoded::Create("Destroyer", TR("Destroyer"), { CAP_BUILDING }));
	OBJECT_START = RegisterType(CObjectTypeHardcoded::Create("StartArea", TR("Start"), { CAP_BUILDING }));
	OBJECT_END = RegisterType(CObjectTypeHardcoded::Create("GoalArea", TR("Finish"), { CAP_BUILDING }));
	OBJECT_TARGET1 = RegisterType(CObjectTypeHardcoded::Create("Target1", TR("Target"), { CAP_BUILDING })); // (gate)
	OBJECT_TARGET2 = RegisterType(CObjectTypeHardcoded::Create("Target2", TR("Target"), { CAP_BUILDING })); // (center)
	OBJECT_NEST = RegisterType(CObjectTypeHardcoded::Create("AlienNest", TR("Nest"), { CAP_BUILDING }));

	OBJECT_FIX = RegisterType(CObjectTypeHardcoded::Create("Fix", "", { CAP_TRANSPORTABLE })); // TODO: ??????
	OBJECT_FRET = RegisterType(CObjectTypeHardcoded::Create("Fret", "", { CAP_TRANSPORTABLE })); // TODO: ??????

	OBJECT_STONE = RegisterType(CObjectTypeHardcoded::Create("TitaniumOre", TR("Titanium ore"), { CAP_TRANSPORTABLE }));
	OBJECT_URANIUM = RegisterType(CObjectTypeHardcoded::Create("UraniumOre", TR("Uranium ore"), { CAP_TRANSPORTABLE }));
	OBJECT_METAL = RegisterType(CObjectTypeHardcoded::Create("Titanium", TR("Titanium"), { CAP_TRANSPORTABLE }));
	OBJECT_POWER = RegisterType(CObjectTypeHardcoded::Create("PowerCell", TR("Power cell"), { CAP_TRANSPORTABLE }));
	OBJECT_ATOMIC = RegisterType(CObjectTypeHardcoded::Create("NuclearCell", TR("Nuclear power cell"), { CAP_TRANSPORTABLE }));
	OBJECT_BULLET = RegisterType(CObjectTypeHardcoded::Create("OrgaMatter", TR("Organic matter"), { CAP_TRANSPORTABLE }));
	OBJECT_BBOX = RegisterType(CObjectTypeHardcoded::Create("BlackBox", TR("Black box"), { CAP_TRANSPORTABLE }));
	OBJECT_TNT = RegisterType(CObjectTypeHardcoded::Create("TNT", TR("Explosive"), { CAP_TRANSPORTABLE }));
	OBJECT_SCRAP1 = RegisterType(CObjectTypeHardcoded::Create("Scrap1", "", { CAP_TRANSPORTABLE })); // (metal)
	OBJECT_SCRAP2 = RegisterType(CObjectTypeHardcoded::Create("Scrap2", "", { CAP_TRANSPORTABLE })); // (metal)
	OBJECT_SCRAP3 = RegisterType(CObjectTypeHardcoded::Create("Scrap3", "", { CAP_TRANSPORTABLE })); // (metal)
	OBJECT_SCRAP4 = RegisterType(CObjectTypeHardcoded::Create("Scrap4", "", { CAP_TRANSPORTABLE })); // (plastic)
	OBJECT_SCRAP5 = RegisterType(CObjectTypeHardcoded::Create("Scrap5", "", { CAP_TRANSPORTABLE })); // (plastic)
	OBJECT_KEYa = RegisterType(CObjectTypeHardcoded::Create("KeyA", TR("Key A"), { CAP_TRANSPORTABLE }));
	OBJECT_KEYb = RegisterType(CObjectTypeHardcoded::Create("KeyB", TR("Key B"), { CAP_TRANSPORTABLE }));
	OBJECT_KEYc = RegisterType(CObjectTypeHardcoded::Create("KeyC", TR("Key C"), { CAP_TRANSPORTABLE }));
	OBJECT_KEYd = RegisterType(CObjectTypeHardcoded::Create("KeyD", TR("Key D"), { CAP_TRANSPORTABLE }));

	OBJECT_BOMB = RegisterType(CObjectTypeHardcoded::Create("Mine", TR("Fixed mine")));
	OBJECT_WINFIRE = RegisterType(CObjectTypeHardcoded::Create("Firework"));

	OBJECT_SHOW = RegisterType(CObjectTypeHardcoded::Create("VisitArrow")); // should not be created directly

	OBJECT_BAG = RegisterType(CObjectTypeHardcoded::Create("Bag", TR("Survival kit")));
	OBJECT_PLANT0 = RegisterType(CObjectTypeHardcoded::Create("Greenery0"));
	OBJECT_PLANT1 = RegisterType(CObjectTypeHardcoded::Create("Greenery1"));
	OBJECT_PLANT2 = RegisterType(CObjectTypeHardcoded::Create("Greenery2"));
	OBJECT_PLANT3 = RegisterType(CObjectTypeHardcoded::Create("Greenery3"));
	OBJECT_PLANT4 = RegisterType(CObjectTypeHardcoded::Create("Greenery4"));
	OBJECT_PLANT5 = RegisterType(CObjectTypeHardcoded::Create("Greenery5"));
	OBJECT_PLANT6 = RegisterType(CObjectTypeHardcoded::Create("Greenery6"));
	OBJECT_PLANT7 = RegisterType(CObjectTypeHardcoded::Create("Greenery7"));
	OBJECT_PLANT8 = RegisterType(CObjectTypeHardcoded::Create("Greenery8"));
	OBJECT_PLANT9 = RegisterType(CObjectTypeHardcoded::Create("Greenery9"));
	OBJECT_PLANT10 = RegisterType(CObjectTypeHardcoded::Create("Greenery10"));
	OBJECT_PLANT11 = RegisterType(CObjectTypeHardcoded::Create("Greenery11"));
	OBJECT_PLANT12 = RegisterType(CObjectTypeHardcoded::Create("Greenery12"));
	OBJECT_PLANT13 = RegisterType(CObjectTypeHardcoded::Create("Greenery13"));
	OBJECT_PLANT14 = RegisterType(CObjectTypeHardcoded::Create("Greenery14"));
	OBJECT_PLANT15 = RegisterType(CObjectTypeHardcoded::Create("Greenery15"));
	OBJECT_PLANT16 = RegisterType(CObjectTypeHardcoded::Create("Greenery16"));
	OBJECT_PLANT17 = RegisterType(CObjectTypeHardcoded::Create("Greenery17"));
	OBJECT_PLANT18 = RegisterType(CObjectTypeHardcoded::Create("Greenery18"));
	OBJECT_PLANT19 = RegisterType(CObjectTypeHardcoded::Create("Greenery19"));
	OBJECT_TREE0 = RegisterType(CObjectTypeHardcoded::Create("Tree0"));
	OBJECT_TREE1 = RegisterType(CObjectTypeHardcoded::Create("Tree1"));
	OBJECT_TREE2 = RegisterType(CObjectTypeHardcoded::Create("Tree2"));
	OBJECT_TREE3 = RegisterType(CObjectTypeHardcoded::Create("Tree3"));
	OBJECT_TREE4 = RegisterType(CObjectTypeHardcoded::Create("Tree4"));
	OBJECT_TREE5 = RegisterType(CObjectTypeHardcoded::Create("Tree5"));


	OBJECT_MOBILEwa = RegisterType(CObjectTypeHardcoded::Create("WheeledGrabber", TR("Wheeled grabber"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED, CAP_GRAB, CAP_GRAB_EX, CAP_BUILD }));
	OBJECT_MOBILEta = RegisterType(CObjectTypeHardcoded::Create("TrackedGrabber", TR("Tracked grabber"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED, CAP_GRAB, CAP_GRAB_EX, CAP_BUILD }));
	OBJECT_MOBILEfa = RegisterType(CObjectTypeHardcoded::Create("WingedGrabber", TR("Winged grabber"), { CAP_MOTOR, CAP_PROGRAM, CAP_WINGED, CAP_FLY, CAP_GRAB, CAP_GRAB_EX, CAP_BUILD }));
	OBJECT_MOBILEia = RegisterType(CObjectTypeHardcoded::Create("LeggedGrabber", TR("Legged grabber"), { CAP_MOTOR, CAP_PROGRAM, CAP_LEGGED, CAP_GRAB, CAP_GRAB_EX, CAP_BUILD }));

	OBJECT_MOBILEws = RegisterType(CObjectTypeHardcoded::Create("WheeledSniffer", TR("Wheeled sniffer"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED, CAP_SNIFF }));
	OBJECT_MOBILEts = RegisterType(CObjectTypeHardcoded::Create("TrackedSniffer", TR("Tracked sniffer"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED, CAP_SNIFF }));
	OBJECT_MOBILEfs = RegisterType(CObjectTypeHardcoded::Create("WingedSniffer", TR("Winged sniffer"), { CAP_MOTOR, CAP_PROGRAM, CAP_WINGED, CAP_FLY, CAP_SNIFF }));
	OBJECT_MOBILEis = RegisterType(CObjectTypeHardcoded::Create("LeggedSniffer", TR("Legged sniffer"), { CAP_MOTOR, CAP_PROGRAM, CAP_LEGGED, CAP_SNIFF }));

	OBJECT_MOBILEwc = RegisterType(CObjectTypeHardcoded::Create("WheeledShooter", TR("Wheeled shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED, CAP_SHOOT }));
	OBJECT_MOBILEtc = RegisterType(CObjectTypeHardcoded::Create("TrackedShooter", TR("Tracked shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED, CAP_SHOOT }));
	OBJECT_MOBILEfc = RegisterType(CObjectTypeHardcoded::Create("WingedShooter", TR("Winged shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_WINGED, CAP_FLY, CAP_SHOOT }));
	OBJECT_MOBILEic = RegisterType(CObjectTypeHardcoded::Create("LeggedShooter", TR("Legged shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_LEGGED, CAP_SHOOT }));

	OBJECT_MOBILEwi = RegisterType(CObjectTypeHardcoded::Create("WheeledOrgaShooter", TR("Wheeled orga shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED, CAP_SHOOT, CAP_SHOOT_ORGA }));
	OBJECT_MOBILEti = RegisterType(CObjectTypeHardcoded::Create("TrackedOrgaShooter", TR("Tracked orga shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED, CAP_SHOOT, CAP_SHOOT_ORGA }));
	OBJECT_MOBILEfi = RegisterType(CObjectTypeHardcoded::Create("WingedOrgaShooter", TR("Winged orga shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_WINGED, CAP_FLY, CAP_SHOOT, CAP_SHOOT_ORGA }));
	OBJECT_MOBILEii = RegisterType(CObjectTypeHardcoded::Create("LeggedOrgaShooter", TR("Legged orga shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_LEGGED, CAP_SHOOT, CAP_SHOOT_ORGA }));

	OBJECT_MOBILErt = RegisterType(CObjectTypeHardcoded::Create("Thumper", TR("Thumper"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG }));
	OBJECT_MOBILErc = RegisterType(CObjectTypeHardcoded::Create("PhazerShooter", TR("Phazer shooter"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG, CAP_SHOOT, CAP_SHOOT_PHAZER }));
	OBJECT_MOBILErr = RegisterType(CObjectTypeHardcoded::Create("Recycler", TR("Recycler"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG }));
	OBJECT_MOBILErs = RegisterType(CObjectTypeHardcoded::Create("Shielder", TR("Shielder"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG }));
	OBJECT_MOBILEsa = RegisterType(CObjectTypeHardcoded::Create("Subber", TR("Subber"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG }));

	OBJECT_MOBILEdr = RegisterType(CObjectTypeHardcoded::Create("Scribbler", TR("Drawer bot"), { CAP_MOTOR, CAP_PROGRAM, CAP_TRACKED_BIG }));
	OBJECT_MOBILEwt = RegisterType(CObjectTypeHardcoded::Create("PracticeBot", TR("Practice bot"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED }));
	//OBJECT_MOBILEtt = RegisterType(CObjectTypeHardcoded::Create("TrackedPracticeBot", TR("Practice bot"), { CAP_MOTOR, CAP_PROGRAM }));
	//OBJECT_MOBILEft = RegisterType(CObjectTypeHardcoded::Create("WingedPracticeBot", TR("Practice bot"), { CAP_MOTOR, CAP_PROGRAM }));
	//OBJECT_MOBILEit = RegisterType(CObjectTypeHardcoded::Create("LeggedPracticeBot", TR("Practice bot"), { CAP_MOTOR, CAP_PROGRAM }));
	OBJECT_MOBILEtg = RegisterType(CObjectTypeHardcoded::Create("TargetBot", TR("Target bot"), { CAP_MOTOR, CAP_PROGRAM, CAP_WHEELED }));
	OBJECT_CONTROLLER = RegisterType(CObjectTypeHardcoded::Create("MissionController", "", { CAP_MOTOR, CAP_PROGRAM, CAP_WINGED }));


	OBJECT_MARKPOWER = RegisterType(CObjectTypeHardcoded::Create("PowerSpot", TR("Energy deposit (site for power station)"), { CAP_MARK }));
	OBJECT_MARKSTONE = RegisterType(CObjectTypeHardcoded::Create("TitaniumSpot", TR("Titanium deposit (site for derrick)"), { CAP_MARK }));
	OBJECT_MARKURANIUM = RegisterType(CObjectTypeHardcoded::Create("UraniumSpot", TR("Uranium deposit (site for derrick)"), { CAP_MARK }));
	OBJECT_MARKKEYa = RegisterType(CObjectTypeHardcoded::Create("KeyASpot", TR("Found key A (site for derrick)"), { CAP_MARK }));
	OBJECT_MARKKEYb = RegisterType(CObjectTypeHardcoded::Create("KeyBSpot", TR("Found key B (site for derrick)"), { CAP_MARK }));
	OBJECT_MARKKEYc = RegisterType(CObjectTypeHardcoded::Create("KeyCSpot", TR("Found key C (site for derrick)"), { CAP_MARK }));
	OBJECT_MARKKEYd = RegisterType(CObjectTypeHardcoded::Create("KeyDSpot", TR("Found key D (site for derrick)"), { CAP_MARK }));
	OBJECT_WAYPOINT = RegisterType(CObjectTypeHardcoded::Create("WayPoint", TR("Checkpoint"), { CAP_MARK }));

	OBJECT_FLAGb = RegisterType(CObjectTypeHardcoded::Create("BlueFlag", TR("Blue flag"), { CAP_FLAG }));
	OBJECT_FLAGr = RegisterType(CObjectTypeHardcoded::Create("RedFlag", TR("Red flag"), { CAP_FLAG }));
	OBJECT_FLAGg = RegisterType(CObjectTypeHardcoded::Create("GreenFlag", TR("Green flag"), { CAP_FLAG }));
	OBJECT_FLAGy = RegisterType(CObjectTypeHardcoded::Create("YellowFlag", TR("Yellow flag"), { CAP_FLAG }));
	OBJECT_FLAGv = RegisterType(CObjectTypeHardcoded::Create("VioletFlag", TR("Violet flag"), { CAP_FLAG }));

	OBJECT_HUMAN = RegisterType(CObjectTypeHardcoded::Create("Me", "", { CAP_GAMER_NAME, CAP_MOTOR, CAP_BUILD, CAP_FLY }));
	OBJECT_TOTO = RegisterType(CObjectTypeHardcoded::Create("Robby", TR("Robbie"))); // (toto) - should not be created directly
	OBJECT_TECH = RegisterType(CObjectTypeHardcoded::Create("Tech", TR("Engineer"), { CAP_MOTOR, CAP_PROGRAM, CAP_BUILD, CAP_FLY }));

	OBJECT_BARRIER0 = RegisterType(CObjectTypeHardcoded::Create("Barrier0"));
	OBJECT_BARRIER1 = RegisterType(CObjectTypeHardcoded::Create("Barrier1"));
	OBJECT_BARRIER2 = RegisterType(CObjectTypeHardcoded::Create("Barrier2"));
	OBJECT_BARRIER3 = RegisterType(CObjectTypeHardcoded::Create("Barrier3"));

	OBJECT_MOTHER = RegisterType(CObjectTypeHardcoded::Create("AlienQueen", TR("Alien Queen"), { CAP_MOTOR, CAP_PROGRAM }));
	OBJECT_EGG = RegisterType(CObjectTypeHardcoded::Create("AlienEgg", TR("Egg")));
	OBJECT_ANT = RegisterType(CObjectTypeHardcoded::Create("AlienAnt", TR("Ant"), { CAP_MOTOR, CAP_PROGRAM }));
	OBJECT_SPIDER = RegisterType(CObjectTypeHardcoded::Create("AlienSpider", TR("Spider"), { CAP_MOTOR, CAP_PROGRAM }));
	OBJECT_BEE = RegisterType(CObjectTypeHardcoded::Create("AlienWasp", TR("Wasp"), { CAP_MOTOR, CAP_PROGRAM, CAP_FLY, CAP_GRAB, CAP_GRAB_FLY }));
	OBJECT_WORM = RegisterType(CObjectTypeHardcoded::Create("AlienWorm", TR("Worm"), { CAP_MOTOR, CAP_PROGRAM }));

	OBJECT_RUINmobilew1 = RegisterType(CObjectTypeHardcoded::Create("WreckBotw1", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINmobilew2 = RegisterType(CObjectTypeHardcoded::Create("WreckBotw2", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINmobilet1 = RegisterType(CObjectTypeHardcoded::Create("WreckBott1", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINmobilet2 = RegisterType(CObjectTypeHardcoded::Create("WreckBott2", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINmobiler1 = RegisterType(CObjectTypeHardcoded::Create("WreckBotr1", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINmobiler2 = RegisterType(CObjectTypeHardcoded::Create("WreckBotr2", TR("Wreckage"), { CAP_WRECK }));
	OBJECT_RUINfactory = RegisterType(CObjectTypeHardcoded::Create("RuinBotFactory", TR("Ruin"), { CAP_RUIN }));
	OBJECT_RUINdoor = RegisterType(CObjectTypeHardcoded::Create("RuinDoor", TR("Ruin"), { CAP_RUIN }));
	OBJECT_RUINsupport = RegisterType(CObjectTypeHardcoded::Create("RuinSupport", TR("Waste"), { CAP_RUIN }));
	OBJECT_RUINradar = RegisterType(CObjectTypeHardcoded::Create("RuinRadar", TR("Ruin"), { CAP_RUIN }));
	OBJECT_RUINconvert = RegisterType(CObjectTypeHardcoded::Create("RuinConvert", TR("Ruin"), { CAP_RUIN }));
	OBJECT_RUINbase = RegisterType(CObjectTypeHardcoded::Create("RuinBaseCamp", TR("Spaceship ruin"), { CAP_RUIN }));
	OBJECT_RUINhead = RegisterType(CObjectTypeHardcoded::Create("RuinHeadCamp", TR("Spaceship ruin"), { CAP_RUIN }));

	OBJECT_TEEN0 = RegisterType(CObjectTypeHardcoded::Create("Teen0"));
	OBJECT_TEEN1 = RegisterType(CObjectTypeHardcoded::Create("Teen1"));
	OBJECT_TEEN2 = RegisterType(CObjectTypeHardcoded::Create("Teen2"));
	OBJECT_TEEN3 = RegisterType(CObjectTypeHardcoded::Create("Teen3"));
	OBJECT_TEEN4 = RegisterType(CObjectTypeHardcoded::Create("Teen4"));
	OBJECT_TEEN5 = RegisterType(CObjectTypeHardcoded::Create("Teen5"));
	OBJECT_TEEN6 = RegisterType(CObjectTypeHardcoded::Create("Teen6"));
	OBJECT_TEEN7 = RegisterType(CObjectTypeHardcoded::Create("Teen7"));
	OBJECT_TEEN8 = RegisterType(CObjectTypeHardcoded::Create("Teen8"));
	OBJECT_TEEN9 = RegisterType(CObjectTypeHardcoded::Create("Teen9"));
	OBJECT_TEEN10 = RegisterType(CObjectTypeHardcoded::Create("Teen10"));
	OBJECT_TEEN11 = RegisterType(CObjectTypeHardcoded::Create("Teen11"));
	OBJECT_TEEN12 = RegisterType(CObjectTypeHardcoded::Create("Teen12"));
	OBJECT_TEEN13 = RegisterType(CObjectTypeHardcoded::Create("Teen13"));
	OBJECT_TEEN14 = RegisterType(CObjectTypeHardcoded::Create("Teen14"));
	OBJECT_TEEN15 = RegisterType(CObjectTypeHardcoded::Create("Teen15"));
	OBJECT_TEEN16 = RegisterType(CObjectTypeHardcoded::Create("Teen16"));
	OBJECT_TEEN17 = RegisterType(CObjectTypeHardcoded::Create("Teen17"));
	OBJECT_TEEN18 = RegisterType(CObjectTypeHardcoded::Create("Teen18"));
	OBJECT_TEEN19 = RegisterType(CObjectTypeHardcoded::Create("Teen19"));
	OBJECT_TEEN20 = RegisterType(CObjectTypeHardcoded::Create("Teen20"));
	OBJECT_TEEN21 = RegisterType(CObjectTypeHardcoded::Create("Teen21"));
	OBJECT_TEEN22 = RegisterType(CObjectTypeHardcoded::Create("Teen22"));
	OBJECT_TEEN23 = RegisterType(CObjectTypeHardcoded::Create("Teen23"));
	OBJECT_TEEN24 = RegisterType(CObjectTypeHardcoded::Create("Teen24"));
	OBJECT_TEEN25 = RegisterType(CObjectTypeHardcoded::Create("Teen25"));
	OBJECT_TEEN26 = RegisterType(CObjectTypeHardcoded::Create("Teen26"));
	OBJECT_TEEN27 = RegisterType(CObjectTypeHardcoded::Create("Teen27"));
	OBJECT_TEEN28 = RegisterType(CObjectTypeHardcoded::Create("Teen28"));
	OBJECT_TEEN29 = RegisterType(CObjectTypeHardcoded::Create("Teen29"));
	OBJECT_TEEN30 = RegisterType(CObjectTypeHardcoded::Create("Teen30"));
	OBJECT_TEEN31 = RegisterType(CObjectTypeHardcoded::Create("Teen31"));
	OBJECT_TEEN32 = RegisterType(CObjectTypeHardcoded::Create("Teen32"));
	OBJECT_TEEN33 = RegisterType(CObjectTypeHardcoded::Create("Teen33"));
	OBJECT_TEEN34 = RegisterType(CObjectTypeHardcoded::Create("Teen34")); // (Stone)
	OBJECT_TEEN35 = RegisterType(CObjectTypeHardcoded::Create("Teen35"));
	OBJECT_TEEN36 = RegisterType(CObjectTypeHardcoded::Create("Teen36"));
	OBJECT_TEEN37 = RegisterType(CObjectTypeHardcoded::Create("Teen37"));
	OBJECT_TEEN38 = RegisterType(CObjectTypeHardcoded::Create("Teen38"));
	OBJECT_TEEN39 = RegisterType(CObjectTypeHardcoded::Create("Teen39"));
	OBJECT_TEEN40 = RegisterType(CObjectTypeHardcoded::Create("Teen40"));
	OBJECT_TEEN41 = RegisterType(CObjectTypeHardcoded::Create("Teen41"));
	OBJECT_TEEN42 = RegisterType(CObjectTypeHardcoded::Create("Teen42"));
	OBJECT_TEEN43 = RegisterType(CObjectTypeHardcoded::Create("Teen43"));
	OBJECT_TEEN44 = RegisterType(CObjectTypeHardcoded::Create("Teen44"));

	OBJECT_QUARTZ0 = RegisterType(CObjectTypeHardcoded::Create("Quartz0"));
	OBJECT_QUARTZ1 = RegisterType(CObjectTypeHardcoded::Create("Quartz1"));
	OBJECT_QUARTZ2 = RegisterType(CObjectTypeHardcoded::Create("Quartz2"));
	OBJECT_QUARTZ3 = RegisterType(CObjectTypeHardcoded::Create("Quartz3"));
	OBJECT_ROOT0 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk0"));
	OBJECT_ROOT1 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk1"));
	OBJECT_ROOT2 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk2"));
	OBJECT_ROOT3 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk3"));
	OBJECT_ROOT4 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk4"));
	OBJECT_ROOT5 = RegisterType(CObjectTypeHardcoded::Create("MegaStalk5"));

	OBJECT_MUSHROOM1 = RegisterType(CObjectTypeHardcoded::Create("Mushroom1"));
	OBJECT_MUSHROOM2 = RegisterType(CObjectTypeHardcoded::Create("Mushroom2"));

	OBJECT_APOLLO1 = RegisterType(CObjectTypeHardcoded::Create("ApolloLEM", TR("Remains of Apollo mission")));
	OBJECT_APOLLO2 = RegisterType(CObjectTypeHardcoded::Create("ApolloJeep", TR("Lunar Roving Vehicle"), { CAP_MOTOR }));
	OBJECT_APOLLO3 = RegisterType(CObjectTypeHardcoded::Create("ApolloFlag", TR("Remains of Apollo mission")));
	OBJECT_APOLLO4 = RegisterType(CObjectTypeHardcoded::Create("ApolloModule", TR("Remains of Apollo mission")));
	OBJECT_APOLLO5 = RegisterType(CObjectTypeHardcoded::Create("ApolloAntenna", TR("Remains of Apollo mission")));

	OBJECT_HOME1 = RegisterType(CObjectTypeHardcoded::Create("Home"));
}