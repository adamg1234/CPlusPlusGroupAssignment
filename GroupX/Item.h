#pragma once
/*
* Item.h
*
* Version information v0.1
* Authors:
* Date:06/12/2017
* Description: Header file for Item
* Copyright notice
*/

#include<string>
#include<vector>
#include<iostream>
#pragma once

class Item
{
private:
	std::string itemName_;
	float weight_;
	int itemValue_;

public:
	Item();
	Item(std::string itemName, int itemValue, float weight);
	~Item();

	void SetItemName(std::string itemName);
	std::string GetItemName() const;

	void SetItemValue(int itemValue);
	int GetItemValue() const;

	void SetWeight(float weight);
	float GetWeight()const;
};