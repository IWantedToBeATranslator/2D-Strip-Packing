#include "FloorCeiling.h"

FloorCeiling::FloorCeiling()
{
	int tempbuf;
	int levelH[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int floorW[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;
	int BestPlace;
	int BestLevel;
	Vector2 *FloorSpaces = new Vector2[eCount];
	int levelFloorSpaces[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int howmany = eCount / 3;
	auto FSnumbers = new int[howmany][15]();
	int levelFSiter = 1;

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
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];
	levelFloorSpaces[levelFSiter] = 1;
	for (int i = 0; i < eCount; i++)
	{
		FloorSpaces[i] = Vector2(0, 0);
	}

	int spaceUsed = levelH[1] * levelW[0];

	int checker = 0;
	int FLorCE = 0;
	int FLlevel = 0;

	for (int i = 1; i < eCount; i++)
	{
		FLlevel = 0;
		FLorCE = 0;
		checker = 0;
		BestPlace = 0;
		BestLevel = levels;
		spaceUsed += _bloxArray[i]->getHeight()*_bloxArray[i]->getWidth();
		for (int k = 0; k < levels; k++)
		{
			if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && BestPlace < levelW[k])
			{
				BestPlace = levelW[k];
				BestLevel = k;
				checker = 1;
			}
			else
			{
				for (int n = levelFloorSpaces[k]; n < levelFloorSpaces[k + 1]; n++)
				{
					if ((FloorSpaces[n].x >= _bloxArray[i]->getSize().x) &&
						(FloorSpaces[n].y >= _bloxArray[i]->getSize().y) &&
						(BestPlace < FloorSpaces[n].x))
					{
						checker = 1;
						BestPlace = FloorSpaces[n].x;
						FLorCE = 1;
						FLlevel = k;
						break;
					}
				}
			}
		}
		if (!checker)
		{
			levels++;
			levelHmin += _bloxArray[i]->getHeight();
			levelH[levels] = levelHmin;
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
			levelW[levels - 1] += _bloxArray[i]->getWidth();
			BestPlace = clipWidth;
			levelFloorSpaces[levelFSiter + 1] = levelFloorSpaces[levelFSiter] + 1;
			levelFSiter++;
		}
		else
		{
			if (!FLorCE)
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW[BestLevel], levelH[BestLevel + 1] - _bloxArray[i]->getHeight()), 500);
				levelW[BestLevel] += _bloxArray[i]->getWidth();
				FloorSpaces[i] = Vector2(clipWidth - BestPlace, levelH[levels] - _bloxArray[i]->getHeight() - levelH[levels - 1]);
				levelFloorSpaces[levelFSiter]++;
			}
			else
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(clipWidth - _bloxArray[i]->getWidth() - floorW[FLlevel], levelH[FLlevel]), 500);
				floorW[FLlevel] += _bloxArray[i]->getWidth();
				for (int n = levelFloorSpaces[FLlevel]; n < levelFloorSpaces[FLlevel + 1]; n++)
				{
					FloorSpaces[n].x = FloorSpaces[n].x - _bloxArray[i]->getWidth();
				}
			}
		}
	}

	algosHeights = levelHmin;
	algosSpaces = algosHeights*clipWidth - spaceUsed;
	updateState;
}