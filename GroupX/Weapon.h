#pragma once
/*
* Weapon.h
*
* Version information v0.1
* Authors: Martin Curran
* Date:
* Description: Header file for the weapon class
* Copyright notice
*/

#include<string>
#include<vector>
#include<iostream>
#include "Item.h"
#pragma once

class Weapon : public Item {
private:
	int weaponHitStrength_;
	int weaponHealth_;

public:
	Weapon();	Weapon::~Weapon();
	Weapon(std::string weaponName, int Value, float weight, int hitStrength, int health);

	void SetWeaponHitStrength(int weaponHitStrength_);
	int GetWeaponHitStrength() const;

	void SetWeaponHealth(int weaponHealth_);
	int GetWeaponHealth() const;
};