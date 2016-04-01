#include "oxygine-framework.h"
using namespace oxygine;
#include <functional>
#include "Shared.h"

class MainActor : public Actor
{
public:
	spTextField		_NFDHtext;
	spTextField		_FFDHtext;
	spSprite		_NFDHbutton;
	spSprite		_FFDHbutton;

	float buttonHeight = gameResources.getResAnim("button")->getHeight();
	float buttonWidth = gameResources.getResAnim("button")->getWidth();
	float stageHeight = getStage()->getHeight();
	float stageWidth = getStage()->getWidth();

	MainActor();
	spColorRectSprite spawnRandomBlock();
	spColorRectSprite spawnGradientBlock(int Decreaser);
};

DECLARE_SMART(MainActor, spMainActor);