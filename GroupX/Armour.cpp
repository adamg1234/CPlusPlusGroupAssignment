/*
* Weapon.cpp
*
* Version information v0.1
* Authors: Martin Curran
* Date:10/12/2017
* Description: Class file for Armour
* Copyright notice
*/

#include <iostream>
#include "Armour.h"

Armour::Armour() {}

Armour::Armour(std::string armourName, int value, float weight, int defence, int armourHealth, ArmourType armourType): Item{ armourName, value, weight }, armourHealth_{ armourHealth }, armourType_{ armourType }, defence_{ defence } {};

void Armour::SetArmourHealth(int armourHealth)
{
	armourHealth_ = armourHealth;
}

int Armour::GetArmourHealth() const
{
	return armourHealth_;
}

void Armour::SetArmourType(ArmourType armourType)
{
	armourType_ = armourType;
}

ArmourType Armour::GetArmourType() const
{
	return armourType_;
}

void Armour::SetDefence(int defence)
{
	defence_ = defence;
}
int Armour::GetDefence() const
{
	return defence_;
}
