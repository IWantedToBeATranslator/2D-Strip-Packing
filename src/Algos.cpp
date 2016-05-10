#include "Algos.h"

void Algos(int AlgNumber)
{
	switch (AlgNumber)
	{
	case (1):
	{
		NextFit();
		break;
	}
	case (2):
	{
		FirstFit();
		break;
	}
	case (3):
	{
		BestFit();
		break;
	}
	case (4):
	{
		Knapsack01();
		break;
	}
	case (5):
	{
		SplitFit();
		break;
	}
	case (6):
	{
		Join();
		break;
	}
	case (7):
	{
		FloorCeiling();
		break;
	}
	case (10):
	{
		int timeseed = time(0);
		int randseed = rand();
		srand(timeseed + randseed);
		algosHeights = 0;
		algosSpaces = 0;
		spaceUsed = 0;
		updateState;
		{
			float buttonHeight = algosResources.getResAnim("button")->getHeight();
			float buttonWidth = algosResources.getResAnim("button")->getWidth();
			float stageHeight = getStage()->getHeight();
			float stageWidth = getStage()->getWidth();
			for (int i = 0; i < eCount / 4; i++)
			{
				_bloxArray[i]->detach();
				_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 6, 6);
				bloxHeights[i] = _bloxArray[i]->getHeight();
				bloxWidths[i] = _bloxArray[i]->getWidth();
				spaceUsed += bloxHeights[i] * bloxWidths[i];
			}
			for (int i = eCount / 4; i < eCount / 2; i++)
			{
				_bloxArray[i]->detach();
				_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 10, 3);
				bloxHeights[i] = _bloxArray[i]->getHeight();
				bloxWidths[i] = _bloxArray[i]->getWidth();
				spaceUsed += bloxHeights[i] * bloxWidths[i];
			}
			for (int i = eCount / 2; i < eCount / 4 * 3; i++)
			{
				_bloxArray[i]->detach();
				_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 2, 10);
				bloxHeights[i] = _bloxArray[i]->getHeight();
				bloxWidths[i] = _bloxArray[i]->getWidth();
				spaceUsed += bloxHeights[i] * bloxWidths[i];
			}
			for (int i = eCount / 4 * 3; i < eCount; i++)
			{
				_bloxArray[i]->detach();
				_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 9, 9);
				bloxHeights[i] = _bloxArray[i]->getHeight();
				bloxWidths[i] = _bloxArray[i]->getWidth();
				spaceUsed += bloxHeights[i] * bloxWidths[i];
			}
		}
		break;
	}
	}
}