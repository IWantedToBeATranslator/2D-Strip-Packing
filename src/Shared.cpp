#include "Shared.h"

Resources			algosResources;
int					eCount = 60;
spColorRectSprite*	_bloxArray = new spColorRectSprite[eCount];
spClipRectActor		_blockClip;
spTextField			_mainInfo;
int*				bloxHeights = new int[eCount];
int*				bloxWidths = new int[eCount];
int					algosHeights = 0;
int					algosSpaces = 0;
int					spaceUsed = 0;
int					screenWidth = 700;
int					screenHeight = 1000;
float				clipHeight;
float				clipWidth;

spColorRectSprite spawnRandomBlock(float stageWidth, float stageHeight, float buttonWidth, float buttonHeight, int Xmod, int Ymod)
{
	Color randColor((int)(rand() % 215 + 20), (int)(rand() % 215 + 20), (int)(rand() % 215 + 20), (int)(rand() % 215 + 20));

	int bloxWidth = (int)rand() % (int)(stageWidth) / Xmod + 20;
	int bloxHeight = (int)rand() % (int)(stageWidth) / Ymod + 20;
	int posX = (int)rand() % (int)(stageWidth - buttonWidth - bloxWidth);
	int posY = (int)rand() % (int)(stageHeight - buttonHeight - bloxHeight);

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

	spTextField bloxWidthText = initActor(
		new TextField,
		arg_color = Color(0, 0, 0),
		arg_y = bloxHeight - 15,
		arg_anchor = Vector2(1, 1),
		arg_text = (std::string)std::to_string(bloxWidth),
		arg_attachTo = blox,
		arg_input = false
	);
	Rect tempRect = bloxWidthText->getTextRect();
	bloxWidthText->setX(bloxWidth / 2 - tempRect.getWidth() / 2);
	//bloxWidthText->setHAlign(TextStyle::HorizontalAlign(bloxWidth / 2));
	blox->addChild(bloxWidthText);

	spTextField bloxHeightText = initActor(
		new TextField,
		arg_color = Color(0, 0, 0),
		arg_x = bloxWidth - 15,
		arg_rotation = -MATH_PI / 2,
		arg_anchor = Vector2(1, 1),
		arg_text = (std::string)std::to_string(bloxHeight),
		arg_attachTo = blox,
		arg_input = false
	);
	tempRect = bloxHeightText->getTextRect();
	bloxHeightText->setY(bloxHeight / 2 + tempRect.getHeight() / 2);
	//bloxHeightText->setVAlign(TextStyle::VerticalAlign(bloxHeight / 2));
	blox->addChild(bloxHeightText);

	return blox;
}

void sortNonDecr(spColorRectSprite * blocks, int * blockHeights, int * blockWidths)
{
	spColorRectSprite bloxBuffer;
	int tempbuf;
	FOR(m, 0, eCount)
	{
		FOR(n, 0, eCount-1)
		{
			if (blockHeights[n] < blockHeights[n + 1])
			{
				tempbuf = blockWidths[n];
				blockWidths[n] = blockWidths[n + 1];
				blockWidths[n + 1] = tempbuf;

				tempbuf = blockHeights[n];
				blockHeights[n] = blockHeights[n + 1];
				blockHeights[n + 1] = tempbuf;

				bloxBuffer = blocks[n];
				blocks[n] = blocks[n + 1];
				blocks[n + 1] = bloxBuffer;
			}
		}
	}
}
