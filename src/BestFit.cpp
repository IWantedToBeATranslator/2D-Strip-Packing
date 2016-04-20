#include "BestFit.h"

BestFit::BestFit()
{
	int tempbuf;
	int levelH[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;
	int BestPlace;
	int BestLevel;

	spColorRectSprite bloxBuffer;

	for (int m = 0; m < eCount; m++)
	{
		for (int n = 0; n < eCount - 1; n++)
		{
			if (bloxHeights[n] < bloxHeights[n + 1])
			{
				tempbuf = bloxHeights[n];
				bloxHeights[n] = bloxHeights[n + 1];
				bloxHeights[n + 1] = tempbuf;

				bloxBuffer = _bloxArray[n];
				_bloxArray[n] = _bloxArray[n + 1];
				_bloxArray[n + 1] = bloxBuffer;
			}
		}
	}

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];

	int spaceUsed = levelH[1] * levelW[0];

	int checker = 0;

	for (int i = 1; i < eCount; i++)
	{
		checker = 0;
		BestPlace = 0;
		BestLevel = levels;
		spaceUsed += _bloxArray[i]->getHeight()*_bloxArray[i]->getWidth();
		for (int k = 0; k < levels; k++)
		{
			if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && BestPlace<levelW[k])
			{
				BestPlace = levelW[k];
				BestLevel = k;
				checker = 1;
			}
		}
		if (!checker)
		{
			levels++;
			levelHmin += _bloxArray[i]->getHeight();
			levelH[levels] = levelHmin;
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
			levelW[levels - 1] += _bloxArray[i]->getWidth();
		}
		else
		{
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[BestLevel], levelH[BestLevel]), 500);
			levelW[BestLevel] += _bloxArray[i]->getWidth();
		}
	}

	algosHeights = levelHmin;
	algosSpaces = algosHeights*clipWidth - spaceUsed;
	updateState;
}