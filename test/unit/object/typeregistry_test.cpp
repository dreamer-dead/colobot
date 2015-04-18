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

#include "object/typeregistry.h"

#include <gtest/gtest.h>

class CTypeRegistryTest : public testing::Test
{
public:
	virtual void SetUp() {
		typereg = new CTypeRegistry();
	}

	virtual void TearDown() {
		delete typereg;
	}

private:
	CTypeRegistry* typereg;
};

TEST_F(CTypeRegistryTest, TestLegacyInterface)
{
	EXPECT_EQ(OBJECT_PORTICO, OBJECT_PORTICO);
	EXPECT_NE(OBJECT_PORTICO, OBJECT_BASE);
}

TEST_F(CTypeRegistryTest, TestCapabilities)
{
	EXPECT_TRUE(OBJECT_BASE->HasCapability(CAP_BUILDING));
	EXPECT_FALSE(OBJECT_HUMAN->HasCapability(CAP_BUILDING));
}

TEST_F(CTypeRegistryTest, TestGetByName)
{
	EXPECT_EQ(CTypeRegistry::GetInstancePointer()->GetByName("Portico"), OBJECT_PORTICO);
	EXPECT_EQ(CTypeRegistry::GetInstancePointer()->GetByName("SpaceShip"), OBJECT_BASE);
	EXPECT_EQ(CTypeRegistry::GetInstancePointer()->GetByName("SomeBadObject"), nullptr);
}