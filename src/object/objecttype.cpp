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

#include "object/objecttype.h"

#include "common/restext.h"

#include <assert.h>
#include <libintl.h>

CObjectType::CObjectType()
{
	m_uid = 0;
	for(unsigned int i = 0; i < CAP_MAX; i++)
		m_capabilities[static_cast<ObjectCapability>(i)] = false;
}

CObjectType::~CObjectType()
{
}

const std::string& CObjectType::GetScriptableName()
{
	return GetBaseType()->GetName();
}

std::string CObjectType::GetDisplayName()
{
    if(HasCapability(CAP_GAMER_NAME))
        return g_gamerName;

    return gettext(GetUnlocalizedDisplayName().c_str());
}

CObjectType* CObjectType::GetBaseType()
{
	return this;
}

bool CObjectType::HasCapability(ObjectCapability cap)
{
	assert(cap >= 0 && cap < CAP_MAX);
	return m_capabilities[cap];
}

void CObjectType::SetUniqueID(int uid)
{
	m_uid = uid;
}

int CObjectType::GetUniqueID()
{
	return m_uid;
}


CObjectTypeHardcoded::CObjectTypeHardcoded(const std::string& name, const std::string& displayName, CObjectType* baseType)
: CObjectType()
, m_name(name)
, m_displayName(displayName)
, m_baseType(baseType)
{
}

const std::string& CObjectTypeHardcoded::GetName()
{
	return m_name;
}

const std::string& CObjectTypeHardcoded::GetUnlocalizedDisplayName()
{
	return m_displayName;
}

CObjectType* CObjectTypeHardcoded::GetBaseType()
{
	return m_baseType != nullptr ? m_baseType : this;
}

void CObjectTypeHardcoded::SetCapability(ObjectCapability cap, bool value)
{
	assert(cap >= 0 && cap < CAP_MAX);
	m_capabilities[cap] = value;
}

CObjectTypeHardcoded* CObjectTypeHardcoded::Create(const std::string& name, const std::string& displayName, std::vector<ObjectCapability> caps, CObjectType* baseType)
{
	CObjectTypeHardcoded* type = new CObjectTypeHardcoded(name, displayName, baseType);
	for(ObjectCapability cap : caps)
		type->SetCapability(cap);
	return type;
}