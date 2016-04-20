#include "functionality.h"

//called before func_init()
void func_preinit() {}

//called from main.cpp
void func_init()
{
	//load xml file with resources definition
	algosResources.loadXML("res.xml");

	//get new seed from current time
	srand(time(0));
	//create new main actor
	spMainActor actor = new MainActor;

	spColorRectSprite Bound = initActor(
		new ColorRectSprite,
		arg_color = Color::Black,
		arg_x = clipWidth,
		arg_y = 0,
		arg_width = 1,
		arg_height = clipHeight
	);
	actor->addChild(Bound);

	//create buttons
	/*
	AlgButton NFDH = *new AlgButton(0,  (int)(actor->stageHeight - 2 * actor->buttonHeight), "Next Fit\nDecr High", 1);
	AlgButton FFDH = *new AlgButton(    (int)(actor->buttonWidth), (int)(actor->stageHeight - 2 * actor->buttonHeight), "First Fit\nDecr High", 2);
	AlgButton BFDH = *new AlgButton(2 * (int)(actor->buttonWidth), (int)(actor->stageHeight - 2 * actor->buttonHeight), "Best Fit\nDecr High", 3);
	AlgButton KPSK = *new AlgButton(3 * (int)(actor->buttonWidth), (int)(actor->stageHeight - 2 * actor->buttonHeight), "Knapsack 0-1", 4);
	AlgButton SPLT = *new AlgButton(4 * (int)(actor->buttonWidth), (int)(actor->stageHeight - 2 * actor->buttonHeight), "Split Fit", 5);
	AlgButton JOIN = *new AlgButton(0,  (int)(actor->stageHeight - actor->buttonHeight), "Join", 6);
	AlgButton FCNR = *new AlgButton(    (int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "Floor Ceiling\nNo Rotation", 7);
	AlgButton SLTR = *new AlgButton(2 * (int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "Sleathor", 8);
	AlgButton BRKE = *new AlgButton(3 * (int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "Burke", 9);
	AlgButton REST = *new AlgButton(4 * (int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "Reset", 10);
	*/

	AlgButton NFDH = *new AlgButton(actor->stageWidth - actor->buttonWidth, 0, "Next Fit\nDecr High", 1);
	AlgButton FFDH = *new AlgButton(actor->stageWidth - actor->buttonWidth, actor->buttonHeight, "First Fit\nDecr High", 2);
	AlgButton BFDH = *new AlgButton(actor->stageWidth - actor->buttonWidth, 2* actor->buttonHeight, "Best Fit\nDecr High", 3);
	AlgButton KPSK = *new AlgButton(actor->stageWidth - actor->buttonWidth, 3* actor->buttonHeight, "Knapsack 0-1", 4);
	AlgButton SPLT = *new AlgButton(actor->stageWidth - actor->buttonWidth, 4* actor->buttonHeight, "Split Fit", 5);
	AlgButton JOIN = *new AlgButton(actor->stageWidth - actor->buttonWidth, 5* actor->buttonHeight, "Join", 6);
	AlgButton FCNR = *new AlgButton(actor->stageWidth - actor->buttonWidth, 6* actor->buttonHeight, "Floor Ceiling\nNo Rotation", 7);
	AlgButton SLTR = *new AlgButton(actor->stageWidth - actor->buttonWidth, 7* actor->buttonHeight, "Sleathor", 8);
	AlgButton BRKE = *new AlgButton(actor->stageWidth - actor->buttonWidth, 8* actor->buttonHeight, "Burke", 9);
	AlgButton REST = *new AlgButton(actor->stageWidth - actor->buttonWidth, 9* actor->buttonHeight, "Reset", 10);

	//append buttons to MainActor
	actor->addChild(NFDH.getButton());
	actor->addChild(FFDH.getButton());
	actor->addChild(BFDH.getButton());
	actor->addChild(KPSK.getButton());
	actor->addChild(SPLT.getButton());
	actor->addChild(JOIN.getButton());
	actor->addChild(FCNR.getButton());
	actor->addChild(SLTR.getButton());
	actor->addChild(BRKE.getButton());
	actor->addChild(REST.getButton());

	spTextField mainInfo = initActor(
		new TextField,
		arg_color = Color(0, 0, 0),
		arg_x = actor->stageWidth - actor->buttonWidth + 5,
		arg_y = 10 * actor->buttonHeight + 5,
		arg_anchor = Vector2(1, 1),
		arg_text = "Total height: " + (std::string)std::to_string(algosHeights) + "\n\nTotal unused space:\n" + (std::string)std::to_string(algosSpaces),
		arg_attachTo = actor,
		arg_input = false
		);
	actor->addChild(mainInfo);
	_mainInfo = mainInfo;

	//and append everything to Stage
	getStage()->addChild(actor);
}

//called each frame from main.cpp
void func_update()
{
}

//called each frame from main.cpp
void func_destroy()
{
	//free previously loaded resources
	algosResources.free();
}