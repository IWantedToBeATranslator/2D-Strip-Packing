#include "Shared.h"

Resources			gameResources;
int					eCount = 35;
spColorRectSprite*	_bloxArray = new spColorRectSprite[eCount];
spClipRectActor		_blockClip;
int*				bloxHeights = new int[eCount];