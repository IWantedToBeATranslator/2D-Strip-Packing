#include "BestFit.h"

BestFit::BestFit()
{
	int levelH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = bloxHeights[0];
	levelW[0] = bloxWidths[0];
	levelHmin = levelH[1];

	bool checker = false;

	FOR(i, 1, eCount)
	{
		checker = false;
		int BestPlace = 0;
		int BestLevel = levels;
		FOR(k, 0, levels)
		{
			if (clipWidth - levelW[k] >= bloxWidths[i] && BestPlace < levelW[k])
			{
				BestPlace = levelW[k];
				BestLevel = k;
				checker = true;
			}
		}
		if (!checker)
		{
			levels++;
			levelHmin += bloxHeights[i];
			levelH[levels] = levelHmin;
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
			levelW[levels - 1] += bloxWidths[i];
		}
		else
		{
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[BestLevel], levelH[BestLevel]), 500);
			levelW[BestLevel] += bloxWidths[i];
		}
	}

	algosHeights = levelHmin;
	updateState;
}