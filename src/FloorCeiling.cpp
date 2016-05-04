#include "FloorCeiling.h"

FloorCeiling::FloorCeiling()
{
	int levelH[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int floorW[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;
	int BestPlace;
	int BestLevel;
	Vector2 *FloorSpaces = new Vector2[eCount];
	int levelFloorSpaces[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //кол-во элементов в уровне на потолке
	int howmany = eCount;
	auto FSnumbers = new int[howmany][20](); // номера элементов на потолке по уровням

	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];
	levelFloorSpaces[0] = 1;
	FSnumbers[0][0] = 0;
	FOR(i, 0, eCount) FloorSpaces[i] = Vector2(0, 0);

	bool checker = false;
	bool FLorCE = false;
	int FLlevel = 0;
	int tempbuf = 0;

	FOR(i, 1, eCount)
	{
		FLlevel = 0;
		FLorCE = false;
		checker = false;
		BestPlace = 0;
		BestLevel = levels;
		FOR(k, 0, levels)
		{
			// Checking ceiling
			if (clipWidth - levelW[k] >= _bloxArray[i]->getWidth() && BestPlace < levelW[k])
			{
				BestPlace = levelW[k];
				BestLevel = k;
				checker = true;
			}
			// Checking floor
			else
			{
				FOR(n, 0, levelFloorSpaces[k])
				{
					if ((FloorSpaces[FSnumbers[n][k]].x >= _bloxArray[i]->getSize().x) &&
						(FloorSpaces[FSnumbers[n][k]].y >= _bloxArray[i]->getSize().y) &&
						(BestPlace < FloorSpaces[FSnumbers[n][k]].x))
					{
						checker = true;
						BestPlace = FloorSpaces[FSnumbers[n][k]].x;
						FLorCE = true;
						FLlevel = k;
						tempbuf = n;
						break;
					}
				}
			}
		}
		// New level
		if (!checker)
		{
			levels++;
			levelHmin += _bloxArray[i]->getHeight();
			levelH[levels] = levelHmin;
			_bloxArray[i]->addTween(Actor::TweenPosition(levelW[levels - 1], levelH[levels - 1]), 500);
			levelW[levels - 1] += _bloxArray[i]->getWidth();
			BestPlace = clipWidth;
			levelFloorSpaces[levels - 1] = 1;
			FSnumbers[0][levels - 1] = i;
		}
		// On existing level
		else
		{
			// On ceiling
			if (!FLorCE)
			{
				_bloxArray[i]->addTween(Actor::TweenPosition(levelW[BestLevel], levelH[BestLevel + 1] - _bloxArray[i]->getHeight()), 500);
				levelW[BestLevel] += _bloxArray[i]->getWidth();
				FSnumbers[levelFloorSpaces[BestLevel]][BestLevel] = i;
				FloorSpaces[i] = Vector2(clipWidth - BestPlace, levelH[BestLevel+1] - _bloxArray[i]->getHeight() - levelH[BestLevel]);
				levelFloorSpaces[BestLevel]++;
			}
			// On floor
			else
			{
				floorW[FLlevel] += _bloxArray[i]->getWidth();
				_bloxArray[i]->addTween(Actor::TweenPosition(clipWidth - floorW[FLlevel], levelH[FLlevel]), 500);
				FOR(n, 0, levelFloorSpaces[FLlevel])
				{
					FloorSpaces[FSnumbers[n][FLlevel]].x = FloorSpaces[FSnumbers[n][FLlevel]].x - _bloxArray[i]->getWidth();
				}
			}
		}
	}

	FOR(i, 0, levels)
		FOR(n, 0, levelFloorSpaces[i])
		{
			int a = 1;
		}

	algosHeights = levelHmin;
	updateState;
}