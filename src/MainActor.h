#include <functional>
#include "Shared.h"
using namespace oxygine;

class MainActor : public Actor
{
public:
	spTextField		_NFDHtext;
	spTextField		_FFDHtext;
	spSprite		_NFDHbutton;
	spSprite		_FFDHbutton;

	float buttonHeight = algosResources.getResAnim("button")->getHeight();
	float buttonWidth = algosResources.getResAnim("button")->getWidth();
	float buttonSmallHeight = algosResources.getResAnim("button_small")->getHeight();
	float buttonSmallWidth = algosResources.getResAnim("button_small")->getWidth();
	float stageHeight = getStage()->getHeight();
	float stageWidth = getStage()->getWidth();

	MainActor();
};

DECLARE_SMART(MainActor, spMainActor);