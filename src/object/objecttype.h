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

#include <map>
#include <string>
#include <vector>

//TODO: Make all code use this thing
enum ObjectCapability
{
	CAP_PROGRAM, // programmable
	CAP_BUILD, // can build

	CAP_GAMER_NAME, // the name of this object will be the name of current player

	CAP_TRANSPORTABLE, // transportable object
	CAP_BUILDING, // can't move on it's own
	CAP_MOTOR, // can move around

	CAP_WRECK, // Wreck (can be recovered)
	CAP_RUIN, // Ruin
	CAP_MARK, // marker
	CAP_FLAG, // flag

	CAP_WHEELED, // wheeled
	CAP_TRACKED, // tracked
	CAP_WINGED, // winged
	CAP_LEGGED, // legged
	CAP_TRACKED_BIG, // big tracked (special bots)

	CAP_FLY, // can fly

	CAP_GRAB, // grabber
	CAP_GRAB_EX, // extended grabber (not Subber)
	CAP_GRAB_FLY, // can grab while flying
	CAP_SNIFF, // sniffer
	CAP_SHOOT, // shooter
	CAP_SHOOT_ORGA, // orga shooter
	CAP_SHOOT_PHAZER, // phazer shooter

	CAP_MAX // limit
};

class CObjectType
{
public:
	CObjectType();
	virtual ~CObjectType();

	//! Returns object name (e.g. Barrier1, SpaceShip)
	virtual const std::string& GetName() = 0;
	//! Returns name for use in CBot (e.g. Barrier, SpaceShip)
	virtual const std::string& GetScriptableName();
	//! Returns object user-friendly name (e.g. Barrier, Space ship)
	virtual const std::string& GetUnlocalizedDisplayName() = 0;
	//! Returns object user-friendly name, translated into user's current language
	std::string GetDisplayName();
	//! Returns unique ID for this type
	int GetUniqueID();

	virtual CObjectType* GetBaseType();

	bool HasCapability(ObjectCapability cap);

protected:
	friend class CTypeRegistry;
	void SetUniqueID(int uid);

	int m_uid;
	std::map<ObjectCapability, bool> m_capabilities;
};

class CObjectTypeVirtual : public CObjectType
{
public:
	CObjectTypeVirtual(const std::string& name);
	
	const std::string& GetName();
	const std::string& GetUnlocalizedDisplayName();

protected:
	std::string m_name;
};

class CObjectTypeHardcoded : public CObjectType
{
public:
	CObjectTypeHardcoded(const std::string& name, const std::string& displayName = "", CObjectType* baseType = nullptr);
	static CObjectTypeHardcoded* Create(const std::string& name, const std::string& displayName = "", std::vector<ObjectCapability> caps = std::vector<ObjectCapability>(), CObjectType* baseType = nullptr);

	const std::string& GetName();
	const std::string& GetUnlocalizedDisplayName();
	CObjectType* GetBaseType();

	void SetCapability(ObjectCapability cap, bool value = true);

protected:
	std::string m_name;
	std::string m_displayName;
	CObjectType* m_baseType;
};