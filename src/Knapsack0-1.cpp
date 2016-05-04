#include "Knapsack0-1.h"

Knapsack01::Knapsack01()
{
	sortNonDecr(_bloxArray, bloxHeights, bloxWidths);

	//https://en.wikipedia.org/wiki/Knapsack_problem#0.2F1_knapsack_problem
	//Есть ценности в максимальной площади (bloxArea), массы в ширине (_bloxArray[i]->getWidth()), количество (eCount) и вместимость (maxArea)
	//От нуля до вместимости заполнить первую строку матрицы нулями
	//https://www.youtube.com/watch?v=PLJHuErj-Tw

	/*
		eCount прямоугольников
		ширины getWidth()
		высоты getHeight()
		и ценности bloxArea = W * H
		создается таблица Optimum[]
	

	//get values
	int* bloxArea = new int(eCount);
	for (int i = 0; i < eCount; i++)
	{
		bloxArea[i] = _bloxArray[i]->getWidth()*_bloxArray[i]->getHeight();
	}

	//get capacity of one level - ширина clipWidth

	int Level = 0;
	int* levels;
	int levelH[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool unpacked = true;

	while (unpacked)
	{
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
	} 
	delete bloxArea;*/
}