#include "BestFit.h"

BestFit::BestFit()
{
	int levelH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;
	int BestPlace;
	int BestLevel;

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];

	bool checker = false;

	FOR(i, 1, eCount)
	{
		checker = false;
		BestPlace = 0;
		BestLevel = levels;
		FOR(k, 0, levels)
		{
			if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && BestPlace < levelW[k])
			{
				BestPlace = levelW[k];
				BestLevel = k;
				checker = true;
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
	updateState;
}