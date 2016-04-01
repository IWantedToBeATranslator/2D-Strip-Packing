#include "functionality.h"

/*
	void NextFitDescHigh()
	{
		int levelHminus=0;
		int levelH = 0;
		int levelW = 0;

		_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
		levelH = _bloxArray[0]->getHeight();
		levelW = _bloxArray[0]->getWidth();

		for (int i = 1; i < eCount; i++)
		{
			if (_blockClip->getWidth() - levelW >= _bloxArray[i]->getWidth())
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW, levelHminus), 500);
				levelW += _bloxArray[i]->getWidth();
			}
			else
			{
				levelHminus = levelH;
				levelW = _bloxArray[i]->getWidth();
				levelH += _bloxArray[i]->getHeight();
				_bloxArray[i]->addTween(Actor::TweenPosition(0, levelHminus), 500);
			}
		}
	}

	/*void FirstFitDescHigh()
	{
		int* levelH = new int[10];
		levelH[0] = 0;
		int levelW = 0;

		_bloxArray[0]->setX(0);
		_bloxArray[0]->setY(0);
		levelH[0] = _bloxArray[0]->getHeight();
		levelW = _bloxArray[0]->getWidth();

		for (int i = 1; i < eCount; i++)
		{
			if (_blockClip->getWidth() - levelW >= _bloxArray[i]->getWidth())
			{
				_bloxArray[i]->setX(levelW);
				_bloxArray[i]->setY(levelH[0]);
				levelW += _bloxArray[i]->getWidth();
			}
			else
			{
				levelH[0] = levelH[1];
				levelW = _bloxArray[i]->getWidth();
				levelH += _bloxArray[i]->getHeight();
				_bloxArray[i]->setY(levelHminus);
				_bloxArray[i]->setX(0);
			}
		}
	}
};
//declare spMainActor as intrusive_ptr holder of MainActor
typedef oxygine::intrusive_ptr<MainActor> spMainActor;
//you could use DECLARE_SMART preprocessor definition it does the same:
//DECLARE_SMART(MainActor, spMainActor)
*/
void func_preinit() {}

//called from main.cpp
void func_init()
{
	//load xml file with resources definition
	gameResources.loadXML("res.xml");

	srand(time(0));
	//typedef oxygine::intrusive_ptr<MainActor> spMainActor;

	//spMainActor was defined above as smart intrusive pointer (read more: http://www.boost.org/doc/libs/1_60_0/libs/smart_ptr/intrusive_ptr.html)
	spMainActor actor = new MainActor;

	AlgButton NFDH = *new AlgButton(0, (int)(actor->stageHeight - actor->buttonHeight), "Next Fit\nDecr High", 1);
	AlgButton FFDH = *new AlgButton((int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "First Fit\nDecr High", 2);
	AlgButton BFDH = *new AlgButton(2 * (int)(actor->buttonWidth), (int)(actor->stageHeight - actor->buttonHeight), "Best Fit\nDecr High", 3);

	actor->addChild(NFDH.getButton());
	actor->addChild(FFDH.getButton());
	actor->addChild(BFDH.getButton());

	//and add it to Stage as child
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
	gameResources.free();
}