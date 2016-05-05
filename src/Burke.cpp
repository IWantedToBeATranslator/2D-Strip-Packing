#include "Burke.h"

Burke::Burke()
{
	/*
	// Starting declarations
	int tempbuf;
	int IsOrdered;
	int levelH[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levels = 1;
	int levelW[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int levelHmin;
	spaceUsed = 0;
	spColorRectSprite bloxBuffer;
	auto heightMap = new int[15][3]; //[0] for X, [1] for Y, [2] for gap width
	int Counter;
	int tempX;

	// Sorting: non-increasing HEIGHT (just in case)
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

	// Sorting: non-increasing WIDTH
	for (int m = 0; m < eCount; m++)
	{
		for (int n = 0; n < eCount - 1; n++)
		{
			if (bloxWidths[n] < bloxWidths[n + 1])
			{
				tempbuf = bloxWidths[n];
				bloxWidths[n] = bloxWidths[n + 1];
				bloxWidths[n + 1] = tempbuf;

				bloxBuffer = _bloxArray[n];
				_bloxArray[n] = _bloxArray[n + 1];
				_bloxArray[n + 1] = bloxBuffer;
			}
		}
	}

	// Order and placement arrays declarations for all methods
	int *LeftmostOrder = new int[eCount];
	auto LeftmostXY = new int[eCount][2];
	int *TallestOrder = new int[eCount];
	auto TallestXY = new int[eCount][2];
	int *SmallestOrder = new int[eCount];
	auto SmallestXY = new int[eCount][2];


	// Leftmost
	IsOrdered = 0;
	Counter = 0;
	heightMap[0][0] = 0; heightMap[0][1] = 0; heightMap[0][2] = clipWidth;
	while (!IsOrdered)
	{
		// Lowest gap
		levelHmin = heightMap[0][1];
		tempbuf = 0;
		FOR(i,0,Counter+1)
			if (levelHmin > heightMap[i][2])
			{
				levelHmin = heightMap[i][1];
				tempbuf = i;
			}

		Counter = tempbuf + 1;
		tempbuf = 1;

	}
	IsOrdered = 0;*/

	/* Tallest neighbour */



	/* Smallest neighbour */



	/* Placement */

	/*
	_bloxArray[0]->addTween(Actor::TweenPosition(0, 0), 500);
	levelH[1] = _bloxArray[0]->getHeight();
	levelW[0] = _bloxArray[0]->getWidth();
	levelHmin = levelH[1];

	spaceUsed += levelH[1] * levelW[0];

	int checker = 0;

	for (int i = 1; i < eCount; i++)
	{
		spaceUsed += _bloxArray[i]->getHeight()*_bloxArray[i]->getWidth();
		checker = 0;
		for (int k = 0; k < levels; k++)
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

	algosHeights = levelHmin;
	algosSpaces = algosHeights*clipWidth - spaceUsed;
	updateState;*/
}
