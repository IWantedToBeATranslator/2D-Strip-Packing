#include "AlgButton.h"

AlgButton::AlgButton(int x, int y, std::string textstr, int actionNumber)
{
	//create button Sprite
	button = new Sprite();

	//setup it:
	//set button.png image. Resource 'button' defined in 'res.xml'
	button->setResAnim(algosResources.getResAnim("button"));

	//centered button at screen
	Vector2 pos = Vector2(x, y);
	button->setPosition(pos);

	//register  click handler to button
	EventCallback cb = CLOSURE(this, &AlgButton::buttonClicked);
	button->addEventListener(TouchEvent::CLICK, cb);

	actNum = actionNumber;

#ifdef CLOSURE_FUNCTION //if your compiler supports lambda

	button->addEventListener(TouchEvent::CLICK, [](Event * e)->void
	{
		//log::messageln("button clicked");
	});

#endif

	//create NFDH TextField Actor
	text = new TextField();
	//attach it as child to button
	text->attachTo(button);
	//centered in button
	text->setPosition(button->getSize() / 2);

	//initialize text style
	style.font = algosResources.getResFont("font_visitor_small")->getFont();
	style.color = Color::Black;
	style.vAlign = TextStyle::VALIGN_MIDDLE;
	style.hAlign = TextStyle::HALIGN_CENTER;

	text->setStyle(style);
	text->setText(textstr);
}

AlgButton::AlgButton(int x, int y, int actionNumber)
{
	//create button Sprite
	button = new Sprite();

	//setup it:
	//set button.png image. Resource 'button' defined in 'res.xml'
	button->setResAnim(algosResources.getResAnim("button_small"));

	//centered button at screen
	Vector2 pos = Vector2(x, y);
	button->setPosition(pos);

	//register  click handler to button
	EventCallback cb = CLOSURE(this, &AlgButton::buttonClicked);
	button->addEventListener(TouchEvent::CLICK, cb);

	actNum = actionNumber;

#ifdef CLOSURE_FUNCTION //if your compiler supports lambda

	button->addEventListener(TouchEvent::CLICK, [](Event * e)->void
	{
		//log::messageln("button clicked");
	});

#endif

	//create NFDH TextField Actor
	text = new TextField();
	//attach it as child to button
	text->attachTo(button);
	//centered in button
	text->setPosition(button->getSize() / 2);

	//initialize text style
	style.font = algosResources.getResFont("font_visitor_small")->getFont();
	style.color = Color::Black;
	style.vAlign = TextStyle::VALIGN_MIDDLE;
	style.hAlign = TextStyle::HALIGN_CENTER;

	text->setStyle(style);
	if (actionNumber == -2)	text->setText("UP");
	if (actionNumber == -3)	text->setText("DN");
}

spSprite AlgButton::getButton()
{
	return button;
};

spTextField AlgButton::getText()
{
	return text;
};

void AlgButton::buttonClicked(Event * event)
{
	//user clicked to button

	//animate button by changing color
	button->setColor(Color::White);
	button->addTween(Sprite::TweenColor(Color::Gray), 200, 1, true);

	//animate text by scaling
	text->setScale(1.0f);
	text->addTween(Actor::TweenScale(0.9f), 200, 1, true);

	//user clicked to button

	//animate button by changing color
	button->setColor(Color::White);
	button->addTween(Sprite::TweenColor(Color::Gray), 200, 1, true);

	//animate text by scaling
	text->setScale(1.0f);
	text->addTween(Actor::TweenScale(0.9f), 200, 1, true);

	//_blockClip->removeChildren();
	Algos(actNum);
}