#include "NextFit.h"

NextFit::NextFit()
{
	int levelHminus = 0;
	int levelH = 0;
	int levelW = 0;

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH = bloxHeights[0];
	levelW = bloxWidths[0];

	FOR(i, 1, eCount)
	{
		if (clipWidth - levelW >= bloxWidths[i])
		{
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW, levelHminus), 500);
			levelW += bloxWidths[i];
		}
		else
		{
			levelHminus = levelH;
			levelW = bloxWidths[i];
			levelH += bloxHeights[i];
			_bloxArray[i]->addTween(Actor::TweenPosition(0, levelHminus), 500);
		}
	}

	algosHeights = levelH;
	updateState;
}