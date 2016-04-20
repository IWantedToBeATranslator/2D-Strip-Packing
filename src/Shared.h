#pragma once
#include "oxygine-framework.h"
#include <string>
#include "TweenOutline.h"

#define updateState _mainInfo->setText("Total height: " + (std::string)std::to_string(algosHeights) + "\n\nTotal unused space:\n" + (std::string)std::to_string(algosSpaces));
#define FOR(i,m,n) for(int i=m; i<n; i++)

using namespace oxygine;
extern Resources			algosResources;
extern int					eCount;
extern spColorRectSprite*	_bloxArray;
extern spClipRectActor		_blockClip;
extern spTextField			_mainInfo;
extern int*					bloxHeights;
extern int					algosHeights;
extern int					algosSpaces;
extern int					screenWidth;
extern int					screenHeight;
extern float				clipHeight;
extern float				clipWidth;

spColorRectSprite spawnRandomBlock(float stageWidth, float stageHeight, float buttonWidth, float buttonHeight, int Xmod, int Ymod);