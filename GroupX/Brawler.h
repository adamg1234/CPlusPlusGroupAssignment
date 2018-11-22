/*
* Brawler.h
*
* Version information v0.1
* Authors: Jack McKigney
* Description: Header for Brawler class
* Copyright notice
*/


#pragma once
#include "GameCharacter.h"
#include <string>
#include <ctime>


class Brawler : public GameCharacter
{
private:
	int punchDamage_;
	int strength_;

public:
	Brawler();

	~Brawler();

	Brawler(int punchDamage, int strength);

	Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, 
		int punchDamage, int strength);


	virtual bool Attack(GameCharacter &character) override;

	virtual void Sleep() override;

	bool Brawl(GameCharacter  &character);

	int GetpunchDamage();
	void SetpunchDamage(int punchDamage);

	int Getstrength();
	void Setstrength(int strength);
};