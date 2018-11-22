/*
* Blackwitch.h
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Header for BlackWitch class
* Copyright notice
*/


#pragma once
#include "GameCharacter.h"
#include <string>
#include <vector>
#include <ctime>

class BlackWitch : public GameCharacter
{
private:
	int magicProficiency_;

	int darkPower_;

public:
	BlackWitch();

	~BlackWitch();

	BlackWitch(int magicProficiency, int darkPower);

	BlackWitch(std::string characterName, float health, float weightLimit, 
		int food, CharacterState state, int magicProficiency, int darkPower);

	virtual bool Attack(GameCharacter &character) override;

	virtual void Sleep() override;

	void Bewitch(GameCharacter  &character);

	int GetmagicProficiency();
	void SetmagicProficiency(int magicProficiency);

	int GetdarkPower();
	void SetdarkPower(int darkPower);

};
