#include "MainActor.h"

MainActor::MainActor()
{
	{
		spClipRectActor blockClip = initActor(
			new ClipRectActor,
			arg_x = 0,
			arg_y = 0,
			arg_size = Vector2(stageWidth - buttonWidth, stageHeight)
		);
		getStage()->addChild(blockClip);

		_blockClip = blockClip;
		clipHeight = _blockClip->getHeight();
		clipWidth = _blockClip->getWidth();
		
		algosHeights = 0;
		algosSpaces = 0;
		spaceUsed = 0;
	}

	//Blocks Generation
	for (int i = 0; i < eCount / 4; i++)
	{
		_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 6, 6);
		bloxHeights[i] = _bloxArray[i]->getHeight();
		bloxWidths[i] = _bloxArray[i]->getWidth();
		spaceUsed += bloxHeights[i] * bloxWidths[i];
	}
	for (int i = eCount / 4; i < eCount / 2; i++)
	{
		_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 10, 3);
		bloxHeights[i] = _bloxArray[i]->getHeight();
		bloxWidths[i] = _bloxArray[i]->getWidth();
		spaceUsed += bloxHeights[i] * bloxWidths[i];
	}
	for (int i = eCount / 2; i < eCount / 4 * 3; i++)
	{
		_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 2, 10);
		bloxHeights[i] = _bloxArray[i]->getHeight();
		bloxWidths[i] = _bloxArray[i]->getWidth();
		spaceUsed += bloxHeights[i] * bloxWidths[i];
	}
	for (int i = eCount / 4 * 3; i < eCount; i++)
	{
		_bloxArray[i] = spawnRandomBlock(screenWidth, screenHeight, buttonWidth, buttonHeight, 9, 9);
		bloxHeights[i] = _bloxArray[i]->getHeight();
		bloxWidths[i] = _bloxArray[i]->getWidth();
		spaceUsed += bloxHeights[i] * bloxWidths[i];
	}
}