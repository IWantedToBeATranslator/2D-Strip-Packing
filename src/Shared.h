#pragma once
#include "oxygine-framework.h"
#include <string>

#define updateState _mainInfo->setText("Total height:\n" + (std::string)std::to_string(algosHeights) + "\n\nTotal unused space:\n" + (std::string)std::to_string(algosHeights*clipWidth - spaceUsed) + "\n\nFullness rating:\n" + (std::string)std::to_string(spaceUsed/(clipWidth*algosHeights)));
#define FOR(i,a,z) for(int i=a; i<z; i++)
#define MAX(a,b) a<b?b:a

using namespace oxygine;
extern Resources			algosResources;
extern int					eCount;
extern spColorRectSprite*	_bloxArray;
extern spClipRectActor		_blockClip;
extern spTextField			_mainInfo;
extern int*					bloxHeights;
extern int*					bloxWidths;
extern int					algosHeights;
extern int					algosSpaces;
extern int					spaceUsed;
extern int					screenWidth;
extern int					screenHeight;
extern float				clipHeight;
extern float				clipWidth;

spColorRectSprite spawnRandomBlock(float stageWidth, float stageHeight, float buttonWidth, float buttonHeight, int Xmod, int Ymod);
void sortNonDecr(spColorRectSprite* blocks, int* blockHeights, int * blockWidths);