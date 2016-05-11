#include "SplitFit.h"

SplitFit::SplitFit()
{
	int levelH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin = 0;

	int levelRH[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelsR = 1;
	int levelRW[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	spColorRectSprite bloxBuffer;

	spColorRectSprite *WideBlox = new spColorRectSprite[eCount];
	spColorRectSprite *ThinBlox = new spColorRectSprite[eCount];

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	int CountRest = 0;
	int Count12 = 0;
	FOR(i, 0, eCount)
	{
		if (_bloxArray[i]->getWidth() > clipWidth / 2)
		{
			WideBlox[Count12] = _bloxArray[i];
			Count12++;
		}
		else
		{
			ThinBlox[CountRest] = _bloxArray[i];
			CountRest++;
		}
	}

	FOR(i, 0, Count12)
		FOR(j, 0, Count12 - 1)
		if (WideBlox[j]->getWidth() < WideBlox[j + 1]->getWidth())
		{
			bloxBuffer = WideBlox[j];
			WideBlox[j] = WideBlox[j + 1];
			WideBlox[j + 1] = bloxBuffer;
		}

	FOR(i, 0, Count12)
	{
		WideBlox[i]->addTween(Actor::TweenPosition(0, levelHmin), 500);
		levelHmin += WideBlox[i]->getHeight();
	}

	int regionRW = 0;
	int regionRH = 0;
	int regionRX = 0;
	int regionRY = 0;
	int levelRHmin = 0;

	FOR(i, 0, Count12)
	{
		if (WideBlox[i]->getWidth() < 2 * clipWidth / 3)
		{
			regionRX = WideBlox[i]->getWidth();
			regionRY = regionRH;
			regionRW = clipWidth - regionRX;
			regionRH = levelHmin - regionRH;
			break;
		}
		regionRH += WideBlox[i]->getHeight();
	}

	int Rcheck = 0;
	int Restcheck = 0;
	int checker = 0;
	int RorO = 0;

	FOR(i, 0, CountRest)
	{
		if ((ThinBlox[i]->getHeight() <= regionRH) && (ThinBlox[i]->getWidth() <= regionRW))
			RorO = 1;
		else
			RorO = 0;

		if (RorO)
		{
			if (Rcheck)
			{
				checker = 0;
				FOR(k, 0, levelsR)
				{
					if (regionRW - levelRW[k] >= ThinBlox[i]->getWidth() && !checker)
					{
						ThinBlox[i]->addTween(Actor::TweenPosition(regionRX + levelRW[k], regionRY + levelRH[k]), 500);
						levelRW[k] += ThinBlox[i]->getWidth();
						checker = 1;
					}
				}
				if (!checker)
				{
					if (ThinBlox[i]->getHeight() <= regionRH - levelRHmin)
					{
						levelsR++;
						levelRHmin += ThinBlox[i]->getHeight();
						levelRH[levelsR] = levelRHmin;
						ThinBlox[i]->addTween(Actor::TweenPosition(regionRX + levelRW[levelsR - 1], regionRY + levelRH[levelsR - 1]), 500);
						levelRW[levelsR - 1] += ThinBlox[i]->getWidth();
					}
					else
						RorO = 0;
				}
			}
			else
			{
				Rcheck = 1;
				ThinBlox[i]->addTween(Actor::TweenPosition(regionRX, regionRY), 500);
				levelRH[1] = ThinBlox[i]->getHeight();
				levelRW[0] = ThinBlox[i]->getWidth();
				levelRHmin = levelRH[1];

				checker = 0;
			}
		}

		if (!RorO)
		{
			if (Restcheck)
			{
				checker = 0;
				FOR(k, 0, levels)
				{
					if (clipWidth - levelW[k] >= ThinBlox[i]->getWidth() && !checker)
					{
						ThinBlox[i]->addTween(Actor::TweenPosition(levelW[k], levelH[k]), 500);
						levelW[k] += ThinBlox[i]->getWidth();
						checker = 1;
					}
				}
				if (!checker)
				{
					levels++;
					levelHmin += ThinBlox[i]->getHeight();
					levelH[levels] = levelHmin;
					ThinBlox[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
					levelW[levels - 1] += ThinBlox[i]->getWidth();
				}
			}
			else
			{
				Restcheck = 1;
				ThinBlox[i]->addTween(Actor::TweenPosition(0, levelHmin), 500);
				levelH[0] = levelHmin;
				levelH[1] = levelHmin + ThinBlox[i]->getHeight();
				levelW[0] = ThinBlox[i]->getWidth();
				levelHmin = levelH[1];

				checker = 0;
			}
		}
	}

	algosHeights = levelHmin;
	updateState;
}