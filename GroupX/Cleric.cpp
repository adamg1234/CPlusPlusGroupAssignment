/*
* Cleric.cpp
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Implementation for Cleric class
* Copyright notice
*/


#include "Cleric.h"


Cleric::Cleric()
{

}

Cleric::~Cleric()
{

}

Cleric::Cleric(int pietylevel) : pietyLevel_{ pietylevel }
{

}

Cleric::Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel) : pietyLevel_{pietyLevel}
{
	this->SetCharacterName(characterName);
	this->SetEquippedArmour(-1);
	this->SetEquippedWeapon(-1);
	this->SetHealth(health);
	this->SetFood(food);
	this->SetCharacterState(state);
	this->SetWeightLimit(weightLimit);
}

bool Cleric::Attack(GameCharacter &character)
{
	float attackChance;
	int randomNum, randomChance;

	srand(time(0));

	randomChance = rand() % (101 - 1) + 1;
	randomNum = rand() % (21 - 10) + 10;

	if (this->GetHealth() <= 20 || character.GetState() == CharacterState::Dead || this->GetEquippedWeapon() == -1) {

		return false;
		//Must add in health bonus for individual characters (Will be virtual)
	}

	if (this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength() < character.GetArmour(character.GetEquippedArmour()).GetDefence()) {
		attackChance = 20;
	}
	else
		attackChance = 60;

	if (character.GetEquippedArmour() == -1) {
		attackChance = 80;
	}

	if (character.GetEquippedArmour() != -1) {

		this->GetWeapons().at(this->GetEquippedWeapon()).SetWeaponHealth(this->GetWeapons().at(this->GetEquippedWeapon()).GetWeaponHealth() - randomNum);

	}

	for (int i = 0; i < this->GetWeapons().size(); i++) {

		if (this->GetWeapons().at(i).GetWeaponHealth() <= 0) {

			DropItem(GetWeapon(i));
		}

	}


	

	//If attack deemed successful
	if (randomChance <= attackChance) {

		return true;
		if (character.GetState() == CharacterState::Defending) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 10));
		}
		else if (character.GetState() == CharacterState::Sleeping) {
			character.SetHealth(character.GetHealth() - character.GetHealth());
		}
		else if (character.GetState() == CharacterState::Idle || character.GetState() == CharacterState::Walking || character.GetState() == CharacterState::Running) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 20));
		}

		for (int i = 0; i < this->GetArmours().size(); i++) {

			if (this->GetArmours().at(i).GetArmourHealth() <= 0) {

				DropItem(GetArmour(i));
			}

		}

	}
	else
		return false;
}


void Cleric::Sleep()
{
	this->SetCharacterState(CharacterState::Sleeping);
	int i = this->GetHealth() * 1.2;
	this->SetHealth(i);
	if (this->GetHealth() > 100)
	{
		this->SetHealth(100);
	}
}


void Cleric::PrayFor(GameCharacter  &character)
{
	int chance = (rand() % 2) + 1;

	//Check to see if successful
	if (chance == 1) 
	{
		float i = (character.GetHealth() * 0.05) * pietyLevel_;
		float a = character.GetHealth() + i;
		character.SetHealth(a);
	}
}

int Cleric::GetpietyLevel()
{
	return pietyLevel_;
}

void Cleric::SetpietyLevel(int pietyLevel)
{
	pietyLevel_ = pietyLevel;
}