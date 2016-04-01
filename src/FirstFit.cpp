#include "FirstFit.h"

FirstFit::FirstFit()
{
	int levelHminus = 0;
	int tempbuf;
	int* levelH = new int[10];
	levelH[0] = 0;
	int levels = 1;
	int levelW[10] = { 0,0,0,0,0,0,0,0,0,0 };

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
	levelH[0] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();

	int checker = 0;

	for (int i = 1; i < eCount; i++)
	{
		for (int k = 0; k < levels; k++)
		{
			checker = 0;
			if (_blockClip->getWidth() - levelW[k] >= _bloxArray[i]->getWidth() && !checker)
			{
				_bloxArray[i]->setX(levelW[k]);
				_bloxArray[i]->setY(levelH[k]);
				levelW[k] += _bloxArray[i]->getWidth();
				checker = 1;
			}

			if (checker)
			{
				break;
			}
		}
	}
}