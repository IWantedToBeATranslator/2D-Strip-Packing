#include "Sleator.h"

Sleator::Sleator()
{
	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	auto bloxData = new int[eCount][2];
	bool *packedBlox = new bool[eCount];
	FOR(i, 0, eCount) packedBlox[i] = false;

	int levels = 0;
	int levelHeights[60];
	FOR(i, 0, 60) levelHeights[i] = 0;
	int levelWidths[60];
	FOR(i, 0, 60) levelWidths[i] = clipWidth;
	int levelPositions[60];
	FOR(i, 0, 60) levelPositions[i] = 0;

	bool packed = false;

	do
	{
		levels++;
		int counter = 0;
		FOR(i, 0, eCount) if (!packedBlox[i]) counter++;

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
		int tempWidth = levelWidths[levels - 1];
		int *KPMatrix = new int[counter*tempWidth];
		FOR(i, 0, counter)
			FOR(j, 0, tempWidth)
				KPMatrix[i*(counter + 1) + j] = 0;

		//Fill matrix
		FOR(k, 1, counter+1)
		{
			FOR(y, 1, tempWidth+1)
			{
				if (y < bloxWidths[whatToPack[k - 1]])
				{
					KPMatrix[k*counter + (y - 1)] = KPMatrix[(k - 1)*counter + (y - 1)];
				}
				else if (y > bloxWidths[whatToPack[k - 1]])
				{
					KPMatrix[k*counter + (y - 1)] =
						MAX(KPMatrix[(k - 1)*counter + (y - 1)], KPMatrix[(k - 1)*counter + (y - 1) - bloxWidths[whatToPack[k - 1]]])
						+ bloxWidths[whatToPack[k - 1]] * bloxHeights[whatToPack[k - 1]];
				}
				else
				{
					KPMatrix[k*counter + (y - 1)] =
						MAX(KPMatrix[(k - 1)*counter + (y - 1)], bloxWidths[whatToPack[k - 1]] * bloxHeights[whatToPack[k - 1]]);
				}
				int a = 1;
			}
			int b = 1;
		}

		//array for answers
		int bc = counter;
		bool *Answer = new bool[counter];
		FOR(i, 0, counter) Answer[i] = false;

		//Find the right one
		while (bc > 0 && tempWidth > 0)
		{
			if (KPMatrix[bc*counter + (tempWidth - 1)] != KPMatrix[(bc - 1)*counter + (tempWidth - 1)])
			{
				Answer[bc - 1] = true;
				tempWidth -= bloxWidths[whatToPack[bc - 1]];
			}
			bc--;
		}

		//Pack 'em
		bool first = true;
		FOR(i, 0, counter)
		{
			if (Answer[i])
			{
				if (first) { levelHeights[levels] = levelHeights[levels - 1] + bloxHeights[i]; first = false; }
				_bloxArray[whatToPack[i]]->addTween(Actor::TweenPosition(levelPositions[levels - 1], levelHeights[levels - 1]), 500);
				levelPositions[levels - 1] += bloxWidths[whatToPack[i]];
				levelWidths[levels - 1] = levelWidths[levels-1] - bloxWidths[whatToPack[i]];
				packedBlox[whatToPack[i]] = true;
			}
		}

		//packed check
		packed = true;
		FOR(i, 0, eCount)
			if (!packedBlox[i]) { packed = false; break; }

		delete KPMatrix;
	} while (!packed);

	algosHeights = levelHeights[levels];
	updateState;
}
