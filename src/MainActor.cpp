#include "MainActor.h"

MainActor::MainActor()
{
	{
		spClipRectActor blockClip = initActor(
			new ClipRectActor,
			arg_x = 0,
			arg_y = 0,
			arg_size = Vector2(stageWidth, stageHeight - buttonHeight)
			);
		getStage()->addChild(blockClip);

		_blockClip = blockClip;
	}

	//Blocks Generation
	{
		for (int i = 0; i < eCount; i++)
		{
			_bloxArray[i] = spawnRandomBlock();
			bloxHeights[i] = _bloxArray[i]->getHeight();
		}
	}
}

spColorRectSprite MainActor::spawnRandomBlock()
{
	Color randColor((int)(rand() % 255), (int)(rand() % 255), (int)(rand() % 255), (int)(rand() % 255));

	int posX = (int)rand() % (int)(stageWidth - buttonWidth);
	int posY = (int)rand() % (int)(stageHeight - buttonHeight);
	int bloxWidth = (int)rand() % (int)(stageWidth) / 6 + 20;
	int bloxHeight = (int)rand() % (int)(stageHeight) / 7 + 20;

	spColorRectSprite blox = initActor(
		new ColorRectSprite,
		arg_color = randColor,
		arg_x = posX,
		arg_y = posY,
		arg_w = bloxWidth,
		arg_h = bloxHeight,
		arg_blend = blend_disabled
		);
	_blockClip->addChild(blox);
	return blox;
}

spColorRectSprite MainActor::spawnGradientBlock(int Decreaser)
{
	//Color randColor(255-(Decreaser % 255), (int)(rand() % 255), (int)(rand() % 255), 255);
	Color gradColor(40, 50, 20 + Decreaser * (int)(235 / eCount), 255);

	int posX = (int)rand() % (int)(stageWidth - buttonWidth);
	int posY = (int)rand() % (int)(stageHeight - buttonHeight);
	int bloxWidth = (int)rand() % ((int)(stageWidth - buttonWidth) - (int)(stageWidth))*1.5 + 20;
	int bloxHeight = (int)rand() % ((int)(stageHeight - buttonHeight) - (int)(stageHeight)) * 2 + 20;

	spColorRectSprite blox = initActor(
		new ColorRectSprite,
		arg_color = gradColor,
		arg_x = posX,
		arg_y = posY,
		arg_w = bloxWidth,
		arg_h = bloxHeight,
		arg_blend = blend_disabled
		);
	_blockClip->addChild(blox);
	return blox;
}