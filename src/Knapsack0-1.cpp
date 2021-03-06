﻿#include "Knapsack0-1.h"

Knapsack01::Knapsack01()
{
	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	bool *packedBlox = new bool[eCount];
	FOR(i, 0, eCount) packedBlox[i] = false;

	int levels = 0;
	int levelHeights[60];
	FOR(i, 0, 60) levelHeights[i] = 0;
	int levelPositions[60];
	FOR(i, 0, 60) levelPositions[i] = 0;

	bool packed = false;

	int *KPMatrix;
	KPMatrix = new int[(eCount+1)*(clipWidth+1)];

	do
	{
		levels++;
		int counter = 0;
		FOR(i, 0, eCount) if (!packedBlox[i]) counter++;

		//contains numbers of the unpacked rectangles
		int *whatToPack = new int[counter];

		counter = 0;
		FOR(i, 0, eCount)
		{
			if (!packedBlox[i]) {
				whatToPack[counter] = i;
				counter++;
			}
		}

		//make a matrix width * unpacked amount
		int tempWidth = clipWidth;
		FOR(i, 0, counter+1)
			FOR(j, 0, tempWidth+1)
			KPMatrix[i*tempWidth + j] = 0;

		//fill matrix
		FOR(k, 1, counter + 1)
		{
			FOR(y, 1, tempWidth + 1)
			{
				if (y < bloxWidths[whatToPack[k - 1]])
				{
					KPMatrix[k*tempWidth + (y - 1)] = KPMatrix[(k - 1)*tempWidth + (y - 1)];
				}
				else if (y > bloxWidths[whatToPack[k - 1]])
				{
					KPMatrix[k*tempWidth + (y - 1)] =
						MAX(KPMatrix[(k - 1)*tempWidth + (y - 1)], KPMatrix[(k - 1)*tempWidth + ((y - 1) - bloxWidths[whatToPack[k - 1]])]
							+ bloxWidths[whatToPack[k - 1]] * bloxHeights[whatToPack[k - 1]]);
				}
				else
				{
					KPMatrix[k*tempWidth + (y - 1)] =
						MAX(KPMatrix[(k - 1)*(tempWidth + 1) + (y - 1)], bloxWidths[whatToPack[k - 1]] * bloxHeights[whatToPack[k - 1]]);
				}
			}
		}

		//array for answers
		int bc = counter;
		int maxWidth = tempWidth;
		bool *Answer = new bool[counter];
		FOR(i, 0, counter) Answer[i] = false;

		//find the right one
		while (bc > 0 && tempWidth > 0)
		{
			if (KPMatrix[bc*maxWidth + (tempWidth - 1)] != KPMatrix[(bc - 1)*maxWidth + (tempWidth - 1)])
			{
				Answer[bc - 1] = true;
				tempWidth -= bloxWidths[whatToPack[bc - 1]];
			}
			bc--;
		}

		//pack 'em
		bool first = true;
		FOR(i, 0, counter)
		{
			if (Answer[i])
			{
				if (first) { levelHeights[levels] = levelHeights[levels - 1] + bloxHeights[whatToPack[i]]; first = false; }
				_bloxArray[whatToPack[i]]->addTween(Actor::TweenPosition(levelPositions[levels - 1], levelHeights[levels - 1]), 500);
				levelPositions[levels - 1] += bloxWidths[whatToPack[i]];
				packedBlox[whatToPack[i]] = true;
			}
		}

		//packed check
		packed = true;
		FOR(i, 0, eCount) if (!packedBlox[i]) { packed = false; break; }
	} while (!packed);

	delete[] KPMatrix;
	algosHeights = levelHeights[levels];
	updateState;
}