/*
* Cleric.h
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Header for Cleric class
* Copyright notice
*/


#pragma once
#include "GameCharacter.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

class Cleric : public GameCharacter
{
private:
	int pietyLevel_;

public:
	Cleric();

	~Cleric();

	Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel);

	Cleric(int pietyLevel);

	virtual bool Attack(GameCharacter &character) override;

	void PrayFor(GameCharacter  &character);

	virtual void Sleep() override;

	int GetpietyLevel();
	void SetpietyLevel(int pietyLevel);
};