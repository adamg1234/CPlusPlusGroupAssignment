#pragma once
/*
* Weapon.cpp
*
* Version information v0.1
* Authors: Martin Curran
* Date:10/12/2017
* Description: Header file for Armour
* Copyright notice
*/

#include<string>
#include<vector>
#include<iostream>
#include "Item.h"
#pragma once
enum ArmourType { Cardboard, Leather, Wood, Iron, Steel };

class Armour : public Item
{

private:
	int armourHealth_;
	int defence_;
	ArmourType armourType_;

public:
	Armour();
	Armour(std::string armourName, int value, float weight, int defence, int armourHealth, ArmourType armourType);

	void SetArmourHealth(int armourHealth);
	int GetArmourHealth() const;

	void SetArmourType(ArmourType armourType);
	ArmourType GetArmourType() const;

	void SetDefence(int defence);
	int GetDefence() const;

};