#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;


class MainActor: public Actor
{
public:
    spTextField		_NFDHtext;
	spTextField		_FFDHtext;
    spSprite		_NFDHbutton;
	spSprite		_FFDHbutton;
	spClipRectActor	_blockClip;

	int eCount = 25;
	spColorRectSprite _bloxArray[25];

	MainActor()
	{
		//NFDH button
		{
			//create button Sprite
			spSprite button = new Sprite();

			//setup it:
			//set button.png image. Resource 'button' defined in 'res.xml'
			button->setResAnim(gameResources.getResAnim("button"));

			//centered button at screen
			Vector2 pos = Vector2(0, getStage()->getHeight() - button->getHeight());
			button->setPosition(pos);

			//register  click handler to button
			EventCallback cb = CLOSURE(this, &MainActor::buttonClicked);
			button->addEventListener(TouchEvent::CLICK, cb);

	#ifdef CLOSURE_FUNCTION //if your compiler supports lambda

			button->addEventListener(TouchEvent::CLICK, [](Event * e)->void
			{
				log::messageln("button clicked");
			});

	#endif

			//attach button as child to current actor
			addChild(button);
			_NFDHbutton = button;

			//create NFDH TextField Actor
			spTextField text = new TextField();
			//attach it as child to button
			text->attachTo(button);
			//centered in button
			text->setPosition(button->getSize() / 2);

			//initialize text style
			TextStyle style;
			style.font = gameResources.getResFont("main")->getFont();
			style.color = Color::White;
			style.vAlign = TextStyle::VALIGN_MIDDLE;
			style.hAlign = TextStyle::HALIGN_CENTER;

			text->setStyle(style);
			text->setText("NFDH");

			_NFDHtext = text;
		}

		//FFDH button
		{
			//create button Sprite
			spSprite button = new Sprite();

			//setup it:
			//set button.png image. Resource 'button' defined in 'res.xml'
			button->setResAnim(gameResources.getResAnim("button"));

			//centered button at screen
			Vector2 pos = Vector2(_NFDHbutton->getWidth() + 2, getStage()->getHeight() - button->getHeight());
			button->setPosition(pos);

			//register  click handler to button
			EventCallback cb = CLOSURE(this, &MainActor::buttonClicked);
			button->addEventListener(TouchEvent::CLICK, cb);

#ifdef CLOSURE_FUNCTION //if your compiler supports lambda

			button->addEventListener(TouchEvent::CLICK, [](Event * e)->void
			{
				log::messageln("button clicked");
			});

#endif

			//attach button as child to current actor
			addChild(button);
			_FFDHbutton = button;


			//create FFDH TextField Actor
			spTextField text = new TextField();
			//attach it as child to button
			text->attachTo(button);
			//centered in button
			text->setPosition(button->getSize() / 2);

			//initialize text style
			TextStyle style;
			style.font = gameResources.getResFont("main")->getFont();
			style.color = Color::White;
			style.vAlign = TextStyle::VALIGN_MIDDLE;
			style.hAlign = TextStyle::HALIGN_CENTER;

			text->setStyle(style);
			text->setText("FFDH");

			_FFDHtext = text;
		}

		//Main field
		{
			spClipRectActor blockClip = initActor(
				new ClipRectActor,
				arg_x = 0,
				arg_y = 0,
				arg_size = Vector2(getStage()->getHeight() - _NFDHbutton->getHeight(), getStage()->getWidth())
				);
			getStage()->addChild(blockClip);

			_blockClip = blockClip;
		}

		int* bloxHeights = new int[eCount];
		int tempbuf;
		for (int i = 0; i < eCount; i++)
		{
			_bloxArray[i] = spawnGradientBlock(i);
			bloxHeights[i] = _bloxArray[i]->getHeight();
		}

		spColorRectSprite bloxBuffer;

		for (int m = 0; m < eCount; m++)
		{
			for (int n = 0; n < eCount-1; n++)
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
    }

    void buttonClicked(Event* event)
    {
        //user clicked to button

        //animate button by chaning color
		_NFDHbutton->setColor(Color::White);
		_NFDHbutton->addTween(Sprite::TweenColor(Color::Green), 500, 1, true);

        //animate text by scaling
		_NFDHtext->setScale(1.0f);
		_NFDHtext->addTween(Actor::TweenScale(1.1f), 500, 1, true);

		//_blockClip->removeChildren();
		NextFitDescHigh();
    }

	spColorRectSprite spawnRandomBlock()
	{
		Color randColor((int)(rand() % 255), (int)(rand() % 255), (int)(rand() % 255), (int)(rand() % 255));

		int posX = (int) rand() % (int)(getStage()->getWidth() - _NFDHbutton->getWidth());
		int posY = (int) rand() % (int)(getStage()->getHeight() - _NFDHbutton->getHeight());
		int bloxWidth = (int) rand() % ((int)(getStage()->getWidth() - _NFDHbutton->getWidth()) - (int)(getStage()->getWidth()) / 5) + 20;
		int bloxHeight = (int) rand() % ((int)(getStage()->getHeight() - _NFDHbutton->getHeight()) - (int)(getStage()->getHeight()) / 2) + 20;

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

	spColorRectSprite spawnGradientBlock(int Decreaser)
	{
		//Color randColor(255-(Decreaser % 255), (int)(rand() % 255), (int)(rand() % 255), 255);
		Color gradColor(10, 20, 20 + Decreaser * (int)(235/eCount), 255);

		int posX = (int)rand() % (int)(getStage()->getWidth() - _NFDHbutton->getWidth());
		int posY = (int)rand() % (int)(getStage()->getHeight() - _NFDHbutton->getHeight());
		int bloxWidth = (int)rand() % ((int)(getStage()->getWidth() - _NFDHbutton->getWidth()) - (int)(getStage()->getWidth()))*1.5 + 20;
		int bloxHeight = (int)rand() % ((int)(getStage()->getHeight() - _NFDHbutton->getHeight()) - (int)(getStage()->getHeight()))*2 + 20;

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

	void NextFitDescHigh()
	{
		int levelHminus=0;
		int levelH = 0;
		int levelW = 0;

		_bloxArray[0]->setX(0);
		_bloxArray[0]->setY(0);
		levelH = _bloxArray[0]->getHeight();
		levelW = _bloxArray[0]->getWidth();

		for (int i = 1; i < eCount; i++)
		{
			if (_blockClip->getWidth() - levelW >= _bloxArray[i])
			{
				_bloxArray[i]->setX(levelW);
				_bloxArray[i]->setY(levelHminus);
				levelW += _bloxArray[i]->getWidth();
			}
			else
			{
				levelHminus = levelH;
				levelW = _bloxArray[i]->getWidth();
				levelH += _bloxArray[i]->getHeight();
				_bloxArray[i]->setY(levelHminus);
				_bloxArray[i]->setX(0);
			}
		}
	}
};
//declare spMainActor as intrusive_ptr holder of MainActor
typedef oxygine::intrusive_ptr<MainActor> spMainActor;
//you could use DECLARE_SMART preprocessor definition it does the same:
//DECLARE_SMART(MainActor, spMainActor)

void example_preinit() {}

//called from main.cpp
void example_init()
{
    //load xml file with resources definition
    gameResources.loadXML("res.xml");

	srand(time(0));

    //lets create our client code simple actor
    //spMainActor was defined above as smart intrusive pointer (read more: http://www.boost.org/doc/libs/1_60_0/libs/smart_ptr/intrusive_ptr.html)
    spMainActor actor = new MainActor;

    //and add it to Stage as child
    getStage()->addChild(actor);
}


//called each frame from main.cpp
void example_update()
{
}

//called each frame from main.cpp
void example_destroy()
{
    //free previously loaded resources
    gameResources.free();
}
