#include "Knapsack0-1.h"

Knapsack01::Knapsack01()
{
	int tempbuf;
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
	/*

	//https://en.wikipedia.org/wiki/Knapsack_problem#0.2F1_knapsack_problem
	//Есть ценности в максимальной площади (bloxArea), массы в ширине (_bloxArray[i]->getWidth()), количество (eCount) и вместимость (maxArea)
	//От нуля до вместимости заполнить первую строку матрицы нулями
	//https://www.youtube.com/watch?v=PLJHuErj-Tw

	//get values
	int* bloxArea = new int(eCount);
	for (int i = 0; i < eCount; i++)
	{
		bloxArea[i] = _bloxArray[i]->getWidth()*_bloxArray[i]->getHeight();
	}

	//get capacity of one level
	int fieldWidth = getStage()->getWidth();

	int Level = 0;
	int* levels;
	int levelH[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < eCount; i++)
	{
		//setting capacities for new level
		unsigned int** maxArea = new unsigned int*[eCount];
		for (int i = 0; i < eCount; i++)
		{
			unsigned int* maxArea = new unsigned int[]
		}

		for (int j = 0; j < fieldWidth; j++)
		{

		}

		for (int k = 1; k < eCount; k++)
		{
			for (int j = 0; j < fieldWidth; j++)
			{
				if (_bloxArray[k - 1] > j)
				{

				}
			}
		}

		_bloxArray[i]->addTween(Actor::TweenPosition());

		Level++;

		delete maxArea;
	}
	delete bloxArea;*/
}