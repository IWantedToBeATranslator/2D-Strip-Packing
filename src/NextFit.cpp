#include "NextFit.h"

NextFit::NextFit()
{
	int levelHminus = 0;
	int levelH = 0;
	int levelW = 0;

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH = _bloxArray[0]->getHeight();
	levelW = _bloxArray[0]->getWidth();

	FOR(i, 1, eCount)
	{
		if (clipWidth - levelW >= _bloxArray[i]->getWidth())
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

	algosHeights = levelH;
	updateState;
}