#include "Join.h"

Join::Join()
{
	int tempbuf;
	int levelH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin = 0;
	spaceUsed = 0;

	int gamma = 10;

	auto rectPairs = new int[(int)(eCount / 2)][2];

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	int jn = 0;
	int it = 0;

	while (jn + 1 < eCount)
	{
		tempbuf = _bloxArray[jn]->getWidth() + _bloxArray[jn+1]->getWidth();
		if (((_bloxArray[jn]->getHeight() - _bloxArray[jn + 1]->getHeight()) / _bloxArray[jn]->getHeight() * 100 < gamma)
			&& (tempbuf <= clipWidth))
		{
			rectPairs[it][0] = jn;
			rectPairs[it][1] = tempbuf;
			jn += 2;
			it++;
		}
		else jn++;
	}

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	spaceUsed += levelH[1] * levelW[0];

	int lowit = 0;

	if (rectPairs[0][0] == 0)
	{
		_bloxArray[1]->addTween(Actor::TweenPosition(levelW[0], 0), 500);
		levelW[0] += _bloxArray[1]->getWidth();
		spaceUsed += _bloxArray[1]->getHeight() * _bloxArray[1]->getWidth();
		lowit = 1;
	}
	levelHmin = levelH[1];

	int checker = 0;
	int SorP;

	FOR(i, lowit+1, eCount)
	{
		SorP = 0;
		FOR(n, lowit, it)
		{
			if (rectPairs[n][0] == i)
			{
				SorP = 1;
				lowit++;
				spaceUsed += _bloxArray[i]->getHeight()*_bloxArray[i]->getWidth() + _bloxArray[i+1]->getHeight()*_bloxArray[i+1]->getWidth();
				break;
			}
			if (rectPairs[n][0] > i) break;
		}

		if (!SorP)
		{
			checker = 0;
			FOR(k, 0, levels)
			{
				if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && !checker)
				{
					_bloxArray[i]->addTween(Actor::TweenPosition(levelW[k], levelH[k]), 500);
					levelW[k] += _bloxArray[i]->getWidth();
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
		}
		else
		{
			checker = 0;
			FOR(k, 0, levels)
			{
				if (clipWidth - levelW[k] >= rectPairs[lowit - 1][1] && !checker)
				{
					_bloxArray[i]->addTween(Actor::TweenPosition(levelW[k], levelH[k]), 500);
					_bloxArray[i+1]->addTween(Actor::TweenPosition(levelW[k]+_bloxArray[i]->getWidth(), levelH[k]), 500);
					levelW[k] += rectPairs[lowit-1][1];
					checker = 1;
				}
			}
			if (!checker)
			{
				levels++;
				levelHmin += _bloxArray[i]->getHeight();
				levelH[levels] = levelHmin;
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
				_bloxArray[i+1]->addTween(Actor::TweenPosition(levelW[levels - 1] + _bloxArray[i]->getWidth(), levelH[levels - 1]), 500);
				levelW[levels - 1] += rectPairs[lowit-1][1];
			}
			i++;
		}
	}

	algosHeights = levelHmin;
	updateState;
}
