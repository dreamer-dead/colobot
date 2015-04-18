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

#include "common/singleton.h"

#include "object/objecttype.h"

#include <vector>

class CTypeRegistry : public CSingleton<CTypeRegistry>
{
public:
	CTypeRegistry();
	virtual ~CTypeRegistry();

	CObjectType* RegisterType(CObjectType* type);
	const std::vector<CObjectType*>& GetAll();
	CObjectType* GetByName(const std::string& name);
	CObjectType* GetByScriptableName(const std::string& name);
	CObjectType* GetByUniqueID(int uid);

protected:
	void InitStandardTypes();

	std::vector<CObjectType*> m_types;
};

// TODO: To be removed
extern CObjectType* OBJECT_NULL;
extern CObjectType* OBJECT_FIX;
extern CObjectType* OBJECT_PORTICO;
extern CObjectType* OBJECT_BASE;
extern CObjectType* OBJECT_DERRICK;
extern CObjectType* OBJECT_FACTORY;
extern CObjectType* OBJECT_STATION;
extern CObjectType* OBJECT_CONVERT;
extern CObjectType* OBJECT_REPAIR;
extern CObjectType* OBJECT_TOWER;
extern CObjectType* OBJECT_NEST;
extern CObjectType* OBJECT_RESEARCH;
extern CObjectType* OBJECT_RADAR;
extern CObjectType* OBJECT_ENERGY;
extern CObjectType* OBJECT_LABO;
extern CObjectType* OBJECT_NUCLEAR;
extern CObjectType* OBJECT_START;
extern CObjectType* OBJECT_END;
extern CObjectType* OBJECT_INFO;
extern CObjectType* OBJECT_PARA;
extern CObjectType* OBJECT_TARGET1;
extern CObjectType* OBJECT_TARGET2;
extern CObjectType* OBJECT_SAFE;
extern CObjectType* OBJECT_HUSTON;
extern CObjectType* OBJECT_DESTROYER;
extern CObjectType* OBJECT_FRET;
extern CObjectType* OBJECT_STONE;
extern CObjectType* OBJECT_URANIUM;
extern CObjectType* OBJECT_METAL;
extern CObjectType* OBJECT_POWER;
extern CObjectType* OBJECT_ATOMIC;
extern CObjectType* OBJECT_BULLET;
extern CObjectType* OBJECT_BBOX;
extern CObjectType* OBJECT_TNT;
extern CObjectType* OBJECT_SCRAP1;
extern CObjectType* OBJECT_SCRAP2;
extern CObjectType* OBJECT_SCRAP3;
extern CObjectType* OBJECT_SCRAP4;
extern CObjectType* OBJECT_SCRAP5;
extern CObjectType* OBJECT_MARKPOWER;
extern CObjectType* OBJECT_MARKSTONE;
extern CObjectType* OBJECT_MARKURANIUM;
extern CObjectType* OBJECT_MARKKEYa;
extern CObjectType* OBJECT_MARKKEYb;
extern CObjectType* OBJECT_MARKKEYc;
extern CObjectType* OBJECT_MARKKEYd;
extern CObjectType* OBJECT_BOMB;
extern CObjectType* OBJECT_WINFIRE;
extern CObjectType* OBJECT_SHOW;
extern CObjectType* OBJECT_BAG;
extern CObjectType* OBJECT_PLANT0;
extern CObjectType* OBJECT_PLANT1;
extern CObjectType* OBJECT_PLANT2;
extern CObjectType* OBJECT_PLANT3;
extern CObjectType* OBJECT_PLANT4;
extern CObjectType* OBJECT_PLANT5;
extern CObjectType* OBJECT_PLANT6;
extern CObjectType* OBJECT_PLANT7;
extern CObjectType* OBJECT_PLANT8;
extern CObjectType* OBJECT_PLANT9;
extern CObjectType* OBJECT_PLANT10;
extern CObjectType* OBJECT_PLANT11;
extern CObjectType* OBJECT_PLANT12;
extern CObjectType* OBJECT_PLANT13;
extern CObjectType* OBJECT_PLANT14;
extern CObjectType* OBJECT_PLANT15;
extern CObjectType* OBJECT_PLANT16;
extern CObjectType* OBJECT_PLANT17;
extern CObjectType* OBJECT_PLANT18;
extern CObjectType* OBJECT_PLANT19;
extern CObjectType* OBJECT_TREE0;
extern CObjectType* OBJECT_TREE1;
extern CObjectType* OBJECT_TREE2;
extern CObjectType* OBJECT_TREE3;
extern CObjectType* OBJECT_TREE4;
extern CObjectType* OBJECT_TREE5;
extern CObjectType* OBJECT_MOBILEwt;
extern CObjectType* OBJECT_MOBILEtt;
extern CObjectType* OBJECT_MOBILEft;
extern CObjectType* OBJECT_MOBILEit;
extern CObjectType* OBJECT_MOBILEwa;
extern CObjectType* OBJECT_MOBILEta;
extern CObjectType* OBJECT_MOBILEfa;
extern CObjectType* OBJECT_MOBILEia;
extern CObjectType* OBJECT_MOBILEwc;
extern CObjectType* OBJECT_MOBILEtc;
extern CObjectType* OBJECT_MOBILEfc;
extern CObjectType* OBJECT_MOBILEic;
extern CObjectType* OBJECT_MOBILEwi;
extern CObjectType* OBJECT_MOBILEti;
extern CObjectType* OBJECT_MOBILEfi;
extern CObjectType* OBJECT_MOBILEii;
extern CObjectType* OBJECT_MOBILEws;
extern CObjectType* OBJECT_MOBILEts;
extern CObjectType* OBJECT_MOBILEfs;
extern CObjectType* OBJECT_MOBILEis;
extern CObjectType* OBJECT_MOBILErt;
extern CObjectType* OBJECT_MOBILErc;
extern CObjectType* OBJECT_MOBILErr;
extern CObjectType* OBJECT_MOBILErs;
extern CObjectType* OBJECT_MOBILEsa;
extern CObjectType* OBJECT_MOBILEtg;
extern CObjectType* OBJECT_MOBILEdr;
extern CObjectType* OBJECT_CONTROLLER;
extern CObjectType* OBJECT_WAYPOINT;
extern CObjectType* OBJECT_FLAGb;
extern CObjectType* OBJECT_FLAGr;
extern CObjectType* OBJECT_FLAGg;
extern CObjectType* OBJECT_FLAGy;
extern CObjectType* OBJECT_FLAGv;
extern CObjectType* OBJECT_KEYa;
extern CObjectType* OBJECT_KEYb;
extern CObjectType* OBJECT_KEYc;
extern CObjectType* OBJECT_KEYd;
extern CObjectType* OBJECT_HUMAN;
extern CObjectType* OBJECT_TOTO;
extern CObjectType* OBJECT_TECH;
extern CObjectType* OBJECT_BARRIER0;
extern CObjectType* OBJECT_BARRIER1;
extern CObjectType* OBJECT_BARRIER2;
extern CObjectType* OBJECT_BARRIER3;
extern CObjectType* OBJECT_MOTHER;
extern CObjectType* OBJECT_EGG;
extern CObjectType* OBJECT_ANT;
extern CObjectType* OBJECT_SPIDER;
extern CObjectType* OBJECT_BEE;
extern CObjectType* OBJECT_WORM;
extern CObjectType* OBJECT_RUINmobilew1;
extern CObjectType* OBJECT_RUINmobilew2;
extern CObjectType* OBJECT_RUINmobilet1;
extern CObjectType* OBJECT_RUINmobilet2;
extern CObjectType* OBJECT_RUINmobiler1;
extern CObjectType* OBJECT_RUINmobiler2;
extern CObjectType* OBJECT_RUINfactory;
extern CObjectType* OBJECT_RUINdoor;
extern CObjectType* OBJECT_RUINsupport;
extern CObjectType* OBJECT_RUINradar;
extern CObjectType* OBJECT_RUINconvert;
extern CObjectType* OBJECT_RUINbase;
extern CObjectType* OBJECT_RUINhead;
extern CObjectType* OBJECT_TEEN0;
extern CObjectType* OBJECT_TEEN1;
extern CObjectType* OBJECT_TEEN2;
extern CObjectType* OBJECT_TEEN3;
extern CObjectType* OBJECT_TEEN4;
extern CObjectType* OBJECT_TEEN5;
extern CObjectType* OBJECT_TEEN6;
extern CObjectType* OBJECT_TEEN7;
extern CObjectType* OBJECT_TEEN8;
extern CObjectType* OBJECT_TEEN9;
extern CObjectType* OBJECT_TEEN10;
extern CObjectType* OBJECT_TEEN11;
extern CObjectType* OBJECT_TEEN12;
extern CObjectType* OBJECT_TEEN13;
extern CObjectType* OBJECT_TEEN14;
extern CObjectType* OBJECT_TEEN15;
extern CObjectType* OBJECT_TEEN16;
extern CObjectType* OBJECT_TEEN17;
extern CObjectType* OBJECT_TEEN18;
extern CObjectType* OBJECT_TEEN19;
extern CObjectType* OBJECT_TEEN20;
extern CObjectType* OBJECT_TEEN21;
extern CObjectType* OBJECT_TEEN22;
extern CObjectType* OBJECT_TEEN23;
extern CObjectType* OBJECT_TEEN24;
extern CObjectType* OBJECT_TEEN25;
extern CObjectType* OBJECT_TEEN26;
extern CObjectType* OBJECT_TEEN27;
extern CObjectType* OBJECT_TEEN28;
extern CObjectType* OBJECT_TEEN29;
extern CObjectType* OBJECT_TEEN30;
extern CObjectType* OBJECT_TEEN31;
extern CObjectType* OBJECT_TEEN32;
extern CObjectType* OBJECT_TEEN33;
extern CObjectType* OBJECT_TEEN34;
extern CObjectType* OBJECT_TEEN35;
extern CObjectType* OBJECT_TEEN36;
extern CObjectType* OBJECT_TEEN37;
extern CObjectType* OBJECT_TEEN38;
extern CObjectType* OBJECT_TEEN39;
extern CObjectType* OBJECT_TEEN40;
extern CObjectType* OBJECT_TEEN41;
extern CObjectType* OBJECT_TEEN42;
extern CObjectType* OBJECT_TEEN43;
extern CObjectType* OBJECT_TEEN44;
extern CObjectType* OBJECT_QUARTZ0;
extern CObjectType* OBJECT_QUARTZ1;
extern CObjectType* OBJECT_QUARTZ2;
extern CObjectType* OBJECT_QUARTZ3;
extern CObjectType* OBJECT_ROOT0;
extern CObjectType* OBJECT_ROOT1;
extern CObjectType* OBJECT_ROOT2;
extern CObjectType* OBJECT_ROOT3;
extern CObjectType* OBJECT_ROOT4;
extern CObjectType* OBJECT_ROOT5;
extern CObjectType* OBJECT_MUSHROOM1;
extern CObjectType* OBJECT_MUSHROOM2;
extern CObjectType* OBJECT_APOLLO1;
extern CObjectType* OBJECT_APOLLO2;
extern CObjectType* OBJECT_APOLLO3;
extern CObjectType* OBJECT_APOLLO4;
extern CObjectType* OBJECT_APOLLO5;
extern CObjectType* OBJECT_HOME1;