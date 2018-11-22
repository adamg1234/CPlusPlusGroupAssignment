/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: Adam Graham & John Hazlett
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include <cstdlib>
#include <ctime>
#include "GameCharacter.h"
#include "Weapon.h"
#include "Armour.h"


GameCharacter::GameCharacter() {


}


GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state) : characterName_{ characterName }, health_{ health },
weightLimit_{ weightLimit }, food_{ food }, state_{ state } {

	health_ = 100;
	weightLimit_ = 100;
	food_ = 0;
	equippedWeapon_ = -1;
	equippedArmour_ = -1;
	state_ = CharacterState::Idle;
	
}



GameCharacter::~GameCharacter(){

}


//Getters and Setters
void GameCharacter::SetCharacterName(std::string characterName) {

	characterName_ = characterName;

}

std::string GameCharacter::GetCharacterName()const {

	return characterName_;
}

void GameCharacter::SetHealth(float health) {

	health_ = health;

}


float GameCharacter::GetHealth()const {

	return health_;

}

void GameCharacter::SetWeightLimit(float weightLimit) {

	weightLimit_ = weightLimit;

}

float GameCharacter::GetWeightLimit() const {

	return weightLimit_;

}

void GameCharacter::SetEquippedWeapon(int equippedWeapon) {

	equippedWeapon_ = equippedWeapon;

}

int GameCharacter::GetEquippedWeapon() const {

	return equippedWeapon_;

}

void GameCharacter::SetEquippedArmour(int equippedArmour) {

	equippedArmour_ = equippedArmour;

}
int GameCharacter::GetEquippedArmour() const {
	return equippedArmour_;
}

void GameCharacter::SetFood(int food) {

	food_ = food;

}
int GameCharacter::GetFood()const {

	return food_;

}

void GameCharacter::SetCharacterState(CharacterState state)
{
	state_ = state;
}

 std::vector<Weapon> GameCharacter::GetWeapons()
{

	 return weapons_;
}

 std::vector<Armour> GameCharacter::GetArmours()
 {
	 return armour_;
 }



//Main Functions
bool GameCharacter::Attack(GameCharacter &character) {

	float attackChance;
	int randomNum, randomChance;

	srand(time(0));

	//Random number generator
	randomChance = rand() % (101 - 1) + 1;
	randomNum = rand() % (21-10) + 10;

	//Check to see if character is alive, health is under 20 and that they dont have a weapon equipped
	if (health_ <= 20 || character.GetState() == CharacterState::Dead || equippedWeapon_ == -1) {
		
		return false;
	}

	//If equipped weapon weapon strength is less than the characters armour defence
	if (GetWeapon(equippedWeapon_).GetWeaponHitStrength() < character.GetArmour(equippedArmour_).GetDefence()) {
		attackChance = 20;
	}
	else
		attackChance = 60;

	//If the character is wearing any armour
	if (character.equippedArmour_ == -1) {
		attackChance = 80;
	}

	//If the character is not wearing any armour
	if (character.equippedArmour_ != -1) {

		weapons_.at(equippedWeapon_).SetWeaponHealth(weapons_.at(equippedWeapon_).GetWeaponHealth() - randomNum);
		
	}

	//For loop to loop through the weapons vector and drop a weapon that has 0 health
	for (int i = 0; i < weapons_.size(); i++) {

		if (weapons_.at(i).GetWeaponHealth() <= 0) {

			DropItem(GetWeapon(i));
		}

	}

	//If attack deemed successful
	if (randomChance <= attackChance) {

		
		if (character.GetState() == CharacterState::Defending) {
			character.SetHealth(character.GetHealth()-((character.GetHealth() / 100) * 10));
		}
		else if (character.GetState() == CharacterState::Sleeping) {
			character.SetHealth(character.GetHealth() - 100);
		}
		else if (character.GetState() == CharacterState::Idle || character.GetState() == CharacterState::Walking || character.GetState() == CharacterState::Running) {
			character.SetHealth(character.GetHealth() - ((character.GetHealth() / 100) * 20));
		}

		for (int i = 0; i < armour_.size(); i++) {

			if (armour_.at(i).GetArmourHealth() <= 0) {

				DropItem(GetArmour(i));
			}

		}

		return true;

	}
	else
		return false;
}


void GameCharacter::Defend(int armour) {

	//If there is armour in the armour vector
	if (armour_.size() > -1) {

		SetEquippedArmour(armour);

	}
	else if (armour > armour_.size() || armour < 0) {

		 equippedArmour_ = -1;
	}
	
		state_ = CharacterState::Defending;

}
//Setting the Character States
void GameCharacter::Walk() {

	state_ = CharacterState::Walking;
}

void GameCharacter::Run() {

	state_ = CharacterState::Running;
}

void GameCharacter::Sleep() {

	state_ = CharacterState::Sleeping;

	
	
}

//Returning a weapon at an index
Weapon GameCharacter::GetWeapon(int index) {

	return weapons_.at(index);


}

//Returning a piece of armour at an index
Armour GameCharacter::GetArmour(int index) {

	return armour_.at(index);

}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	float totalWeight=0;

	//For loop to go through the armour vector and assign the weight of each piece of armour to a variable  
	for (int i = 0; i < armour_.size(); i++) {

		totalWeight += armour_.at(i).GetWeight();
	}

	//For loop to go through the weapon vector and assign the weight of each weapon to a variable  
	for (int i = 0; i < weapons_.size(); i++) {

		totalWeight += weapons_.at(i).GetWeight();
	}
	//If the total weight it over the weight limit
	if ((totalWeight + weapon.GetWeight()) <= weightLimit_) {

		weapons_.push_back(weapon);
		return true;
	}
	else {
		return false;
	}
}

bool GameCharacter::PickUpArmour(Armour &armour) {

	float totalWeight = 0;

	//For loop to go through the armour vector and assign the weight of each piece of armour to a variable  
	for (int i = 0; i < armour_.size(); i++) {

		totalWeight += armour_.at(i).GetWeight();
	}

	//For loop to go through the weapon vector and assign the weight of each weapon to a variable  
	for (int i = 0; i < weapons_.size(); i++) {

		totalWeight += weapons_.at(i).GetWeight();
	}

	//If the total weight it over the weight limit
	if ((totalWeight + armour.GetWeight()) <= weightLimit_) {

		armour_.push_back(armour);
		return true;
	}
	else {
		return false;
	}
	
}

void GameCharacter::DropItem(Armour &item) {

	for (int i = 0; i < armour_.size(); i++) {

		//If the piece of armour the user wishes to remove has the same armour health, type and value as a piece of armour in the vector. Remove that piece of armour 
		if (item.GetArmourHealth() == armour_.at(i).GetArmourHealth() && item.GetArmourType() == armour_.at(i).GetArmourType() && item.GetItemValue() == armour_.at(i).GetItemValue()) {

			armour_.erase(armour_.begin() + i);
		}

	}
}

void GameCharacter::DropItem(Weapon &item) {

	for (int i = 0; i < weapons_.size(); i++) {

		//If the weapon the user wishes to remove has the same weapon health, hit strength and value as a weapon in the vector. Remove that weapon
		if (item.GetWeaponHealth() == weapons_.at(i).GetWeaponHealth() && item.GetWeaponHitStrength() == weapons_.at(i).GetWeaponHitStrength() && item.GetItemValue() == weapons_.at(i).GetItemValue()) {

			weapons_.erase(weapons_.begin() + i);
			
		}

	}
}

bool GameCharacter::EquipWeapon(int weapon) {

	
	//If there is no weapons in the vector equipped no weapon 
	if (weapon == -1) {
		equippedWeapon_ = -1;
		return false;
	}
	else 
	{ 
		equippedWeapon_ = weapon;
		return true;
	}

}

CharacterState GameCharacter::GetState() const {

	return state_;
}

void GameCharacter::AddFood(int amount) { 

	//Set the food to the amount + get food
	int Food = amount + GetFood();
	SetFood(Food);
}

void GameCharacter::Eat() {

	float Food = GetFood();
	float Food2 = GetFood();
	Food = (Food*0.8);
	float Difference = (Food2 - Food);
	
	float Health = GetHealth();
	Health = Health + (Difference*0.25);

	//If health is more than or equal to 100, health = 100
	if (Health >= 100) {
		Health = 100;
	}

	SetHealth(Health);
	SetFood(Food);
}


