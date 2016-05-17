#pragma once
#include <cstring>
#include "Algos.h"

class AlgButton
{
public:
	spSprite button;
	spTextField text;
	TextStyle style;
	int actNum;

	AlgButton(int x, int y, std::string textstr, int actionNumber);
	AlgButton(int x, int y, int actionNumber);
	spSprite getButton();
	spTextField getText();
	void buttonClicked(Event* event);
};

//typedef oxygine::intrusive_ptr<AlgButton> spAlgButton;