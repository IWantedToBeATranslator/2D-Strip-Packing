#include "FirstFit.h"

FirstFit::FirstFit()
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
		FOR(k, 0, levels)
		{
			if (clipWidth - levelW[k] >= bloxWidths[i])
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW[k], levelH[k]), 500);
				levelW[k] += bloxWidths[i];
				checker = true;
				break;
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
	}

	algosHeights = levelHmin;
	updateState;
}