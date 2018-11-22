/*
* Orc.h
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Header for Orc class
* Copyright notice
*/


#pragma once
#include "GameCharacter.h"
#include <string>
#include <ctime>

class Orc : public GameCharacter
{
private:
	int ferociousness_;

	int strength_;

private:
	Orc();

	~Orc();

	Orc(int ferociousness, int strength);

	Orc(std::string characterName, float health, float weightLimit, 
		int food, CharacterState state, int ferociousness, int strength);

	virtual bool Attack(GameCharacter  &character) override;

	virtual void Sleep() override;

	void Scream(GameCharacter  &character);

	int Getferociousness();
	void Setferociousness(int ferociousness);

	int Getstrength();
	void Setstrength(int strength);


};