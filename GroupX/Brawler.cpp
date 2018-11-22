/*
* Brawler.cpp
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Implementation for Brawler class
* Copyright notice
*/


#include "Brawler.h"


Brawler::Brawler()
{

}

Brawler::~Brawler()
{

}

Brawler::Brawler(int punchDamage, int strength) : punchDamage_{ punchDamage }, strength_{ strength }
{

}

Brawler::Brawler(std::string characterName, float health, float weightLimit,
	int food, CharacterState state, int punchDamage, int strength) : punchDamage_{ punchDamage }, strength_{ strength }
{
	this->SetCharacterName(characterName);
	this->SetEquippedArmour(-1);
	this->SetEquippedWeapon(-1);
	this->SetHealth(health);
	this->SetFood(food);
	this->SetCharacterState(state);
	this->SetWeightLimit(weightLimit);
}

//Attept to attach character by punching
bool Brawler::Brawl(GameCharacter  &character)
{
	float attackChance;
	int randomNum, randomChance;

	srand(time(0));

	randomChance = rand() % (101 - 1) + 1;
	randomNum = rand() % (21 - 10) + 10;

	if (this->GetHealth() <= 20 || character.GetState() == CharacterState::Dead) {

		return false;
		//Must add in health bonus for individual characters (Will be virtual)
	}

	if (punchDamage_ < character.GetArmour(GetEquippedArmour()).GetDefence()) {
		attackChance = 20;
	}
	else
		attackChance = 60;

	if (character.GetEquippedArmour() == -1) {
		attackChance = 80;
	}

	int i = (strength_ / 10) * 5;

	//If attack deemed successful
	if (randomChance <= attackChance) {

		return true;
		if (character.GetState() == CharacterState::Defending) {
			character.SetHealth(character.GetHealth() - (((character.GetHealth() / 100) * 10) + i)/2);
		}
		else if (character.GetState() == CharacterState::Sleeping) {
			character.SetHealth(character.GetHealth() - character.GetHealth());
		}
		else if (character.GetState() == CharacterState::Idle || character.GetState() == CharacterState::Walking || character.GetState() == CharacterState::Running) {
			character.SetHealth(character.GetHealth() - (((character.GetHealth() / 100) * 20) + i)/2);
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

bool Brawler::Attack(GameCharacter &character)
{
	float attackChance;
	int randomNum, randomChance;

	srand(time(0));

	randomChance = rand() % (101 - 1) + 1;
	randomNum = rand() % (21 - 10) + 10;

	if (this->GetHealth() <= 20 || this->GetState() == CharacterState::Dead) {

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

	//Extra damange for strength
	int i = (strength_ / 10) * 5;

	//If attack deemed successful
	if (randomChance <= attackChance) {

		return true;
		if (character.GetState() == CharacterState::Defending) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 10) + i);
		}
		else if (character.GetState() == CharacterState::Sleeping) {
			character.SetHealth(character.GetHealth() - (100 + i));
		}
		else if (character.GetState() == CharacterState::Idle || character.GetState() == CharacterState::Walking || character.GetState() == CharacterState::Running) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 20) + i);
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

void Brawler::Sleep()
{
	this->SetCharacterState(CharacterState::Sleeping);
	int i = this->GetHealth() * 1.2;
	this->SetHealth(i);
	if (this->GetHealth() > 100)
	{
		this->SetHealth(100);
	}
}

int Brawler::GetpunchDamage()
{
	return punchDamage_;
}

void Brawler::SetpunchDamage(int punchDamage)
{
	punchDamage_ = punchDamage;
}

int Brawler::Getstrength()
{
	return strength_;
}

void Brawler::Setstrength(int strength)
{
	strength_ = strength;
}