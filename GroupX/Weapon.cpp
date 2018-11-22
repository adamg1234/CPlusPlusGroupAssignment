/*
* Weapon.cpp
*
* Version information v0.1
* Authors: Martin Curran
* Date:06/12/2017
* Description: Class file for weapon
* Copyright notice
*/

#include <iostream>
#include "Weapon.h"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string weaponName, int Value, float weight, int hitStrength, int weaponHealth):Item{ weaponName, Value, weight }, weaponHitStrength_{ hitStrength }, weaponHealth_{ weaponHealth } {}


//Get and set methods for weapon health
void Weapon::SetWeaponHealth(int weaponHealth)
{
	weaponHealth_ = weaponHealth;
}

int Weapon::GetWeaponHealth()const
{
	return weaponHealth_;
}

//Get and Set methods for weapon hit strength
void Weapon::SetWeaponHitStrength(int hitStrength)
{
	weaponHitStrength_ = hitStrength;
}

int Weapon::GetWeaponHitStrength()const
{
	return weaponHitStrength_;
}