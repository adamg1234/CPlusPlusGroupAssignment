/*
* Item.cpp
*
* Version information v0.1
* Authors:
* Date:06/12/2017
* Description: Class file for Item
* Copyright notice
*/

#include <iostream>
#include "item.h"

Item::Item() {}
Item::~Item() {}

Item::Item(std::string itemName, int itemValue, float weight):itemName_{ itemName }, itemValue_{ itemValue }, weight_{ weight } {}

void Item::SetItemName(std::string itemName)
{
	itemName_ = itemName;
}

std::string Item::GetItemName() const
{
	return itemName_;
}

void Item::SetItemValue(int itemValue)
{
	itemValue_ = itemValue;
}

int Item::GetItemValue()const
{
	return itemValue_;
}

void Item::SetWeight(float weight)
{
	weight_ = weight;
}

float Item::GetWeight()const
{
	return weight_;
}