/*
* Blackwitch.cpp
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Implementation for BlackWitch class
* Copyright notice
*/


#include "BlackWitch.h"

BlackWitch::BlackWitch()
{

}

BlackWitch::~BlackWitch()
{

}

BlackWitch::BlackWitch(int magicProficiency, int darkPower) : magicProficiency_{ magicProficiency }, darkPower_{ darkPower }
{

}

BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, 
	int food, CharacterState state, int magicProficiency, int darkPower) 
{
	this->SetCharacterName(characterName);
	this->SetEquippedArmour(-1);
	this->SetEquippedWeapon(-1);
	this->SetHealth(health);
	this->SetFood(food);
	this->SetCharacterState(state);
	this->SetWeightLimit(weightLimit);
}

void BlackWitch::Bewitch(GameCharacter  &character)
{
	int chance = 10 + ( magicProficiency_* 5);
	if (rand() % 100 < chance)
	character.SetCharacterState(CharacterState::Sleeping);
}

bool BlackWitch::Attack(GameCharacter &character)
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

	if (GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() < character.GetArmour(GetEquippedArmour()).GetDefence()) {
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

	//if dark power is full
	int i;
	if (darkPower_ = 100)
	{
		i = 1.2;
	}
	else
	{
		i = 1;
	}
	//If attack deemed successful
	if (randomChance <= attackChance) {
		
		return true;
		if (character.GetState() == CharacterState::Defending) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 10)*i);
		}
		else if (character.GetState() == CharacterState::Sleeping) {
			character.SetHealth(character.GetHealth() - character.GetHealth());
		}
		else if (character.GetState() == CharacterState::Idle || character.GetState() == CharacterState::Walking || character.GetState() == CharacterState::Running) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 10)*i);
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

void BlackWitch::Sleep()
{
	//if character is sleeping, increase health by 1.15
	this->SetCharacterState(CharacterState::Sleeping);
	int i = this->GetHealth() * 1.15;
	this->SetHealth(i);
	if (this->GetHealth() > 100)
	{
		this->SetHealth(100);
	}
}

int BlackWitch::GetmagicProficiency()
{
	return magicProficiency_;
}

void BlackWitch::SetmagicProficiency(int magicProficiency)
{
	magicProficiency_ = magicProficiency;
}

int BlackWitch::GetdarkPower()
{
	return darkPower_;
}

void BlackWitch::SetdarkPower(int darkPower)
{
	darkPower_ = darkPower;
}

