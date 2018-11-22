/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: Adam Graham & John Hazlett
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include<string>
#include<vector>
#include<iostream>
#include"Weapon.h"
#include"Armour.h"


enum CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead };

#pragma once
class GameCharacter
{

private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_;
	int equippedArmour_;
	std::vector<Weapon> weapons_;
	std::vector<Armour> armour_;
	int food_;
	CharacterState state_;


public:
	GameCharacter();
	GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state); //set equipped armour & weapon to -1
	~GameCharacter();


	void SetCharacterName(std::string characterName);
	std::string GetCharacterName()const;

	void SetHealth(float health);
	float GetHealth()const;

	void SetWeightLimit(float weightLimit);
	float GetWeightLimit()const;

	void SetEquippedWeapon(int equippedWeapon);
	int GetEquippedWeapon()const;

	void SetEquippedArmour(int equippedArmour);
	int GetEquippedArmour()const;

	void SetFood(int food);
	int GetFood()const;

	void SetCharacterState(CharacterState state);
	std::vector<Weapon> GetWeapons();
	std::vector<Armour> GetArmours();



	virtual bool Attack(GameCharacter &character)=0;
	void Defend(int armour);
	void Walk();
	void Run();
	virtual void Sleep()=0;
	Weapon GetWeapon(int index);
	Armour GetArmour(int index);
	virtual bool PickUpWeapon(Weapon &weapon);
	virtual bool PickUpArmour(Armour &armour);
	void DropItem(Armour &item);
	void DropItem(Weapon &item);
	bool EquipWeapon(int weapon);
	CharacterState GetState() const;
	void AddFood(int amount);
	virtual void Eat();


};

