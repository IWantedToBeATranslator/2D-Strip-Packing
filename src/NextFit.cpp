#include "NextFit.h"

NextFit::NextFit()
{
	int tempbuf;
	int levelHminus = 0;
	int levelH = 0;
	int levelW = 0;

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
	levelH = _bloxArray[0]->getHeight();
	levelW = _bloxArray[0]->getWidth();

	int spaceUsed = levelH * levelW;

	for (int i = 1; i < eCount; i++)
	{
		spaceUsed += _bloxArray[i]->getHeight()*_bloxArray[i]->getWidth();
		if (screenWidth - levelW >= _bloxArray[i]->getWidth())
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
	algosSpaces = algosHeights*screenWidth - spaceUsed;
	updateState;
}