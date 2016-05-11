#include "FirstFit.h"

FirstFit::FirstFit()
{
	int levelH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];

	bool checker = false;

	FOR(i, 1, eCount)
	{
		checker = false;
		FOR(k, 0, levels)
		{
			if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && !checker)
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW[k], levelH[k]), 500);
				levelW[k] += _bloxArray[i]->getWidth();
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
	}

	algosHeights = levelHmin;
	updateState;
}