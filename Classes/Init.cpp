#include"HelloWorldScene.h"
#include "cocos2d.h"
#pragma execution_character_set("UTF-8")

USING_NS_CC;
void HelloWorld::setCamera()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	follow_Camera = Node::create();
	follow_Camera->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	this->addChild(follow_Camera);

	camera = Follow::create(follow_Camera, Rect::ZERO);
	camera->setTarget(follow_Camera);
}
void HelloWorld::setBackGround()
{
	switch (point::get()->Chapter)
	{
	case 1:
		backGround1 = Sprite::create("Texture/backGround/Stage1_BackGround.png");
		backGround2 = Sprite::create("Texture/backGround/Stage1_BackGround.png");
	case 2:
		chapter2_Bush = Node::create();
		this->addChild(chapter2_Bush);
		for(int i = 0; i < 4; i++)

		backGround1 = Sprite::create("Texture/backGround/Stage2_BackGround.png");
		backGround2 = Sprite::create("Texture/backGround/Stage2_BackGround.png");


	default:
		break;
	}

	backGround1->setAnchorPoint(Point(0, 0));
	backGround2->setAnchorPoint(Point(0, 0));
	backGround1->setPosition(0, 0);
	backGround2->setPosition(backGround1->getContentSize().width, 0);
	this->addChild(backGround1);
	this->addChild(backGround2);
}
void HelloWorld::setKeyListener()
{
	EventListenerKeyboard* keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
}
void HelloWorld::setCharacter()
{
	C_location.setPoint(300, 200);
	LastPosition.setPoint(0, 300);
	A_time = 0;
	B_time = 4.9f;
	A_Scale = 0.5f;

	Alice_Condition = 1;

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_1.plist");

	C_1 = Sprite::createWithSpriteFrameName("run-1.png");
	C_1->setScale(0.4f, 0.4f);
	C_1->setTag(1);
	y = y_base;
	C_1->setPosition(C_location.x, y);
	C_1->setAnchorPoint(Point(0.5, 0.5));
	MyBodyParser::getInstance()->parseJsonFile("Collider/Character_1.json");
	C_1Body = MyBodyParser::getInstance()->bodyFormJson(C_1, "C_1", PhysicsMaterial(0, 0, 0));
	C_1Body->setCollisionBitmask(1);
	C_1Body->setContactTestBitmask(true);
	//C_1Body = PhysicsBody::createBox(Size(C_1->getContentSize().width / 2, C_1->getContentSize().height / 2)
	//	, PhysicsMaterial(0, 0, 0));
	C_1Body->setDynamic(false);
	C_1Body->setRotationEnable(false);
	C_1Body->setGravityEnable(false);
	C_1->setPhysicsBody(C_1Body);
	C_1->setVisible(false);
	this->addChild(C_1, 10);

	C_animation(1);
}
void HelloWorld::setHeart()
{
	for (int i = 0; i < 4; i++)
	{
		Heart[i] = Sprite::create("Texture/Object/Heart/Heart.png");
		Heart[i]->setScale(0.7);
		Heart[i]->setPosition(60 + (100 * i), 600);
		this->addChild(Heart[i]);
	}
}
void HelloWorld::setUI()
{


	m_label = 1;
	time_label = 0.2f;

	i_Collecting_Coin = 0;
	Collecting_Coin = Label::create("", "fonts/NanumBarun/NanumBarun.ttf", 24);
	Collecting_Coin->setPosition(83, 475);
	this->addChild(Collecting_Coin, 5);

	jump_Button = Sprite::create("Texture/Object/UI/JumpButton.png");
	jump_Button->setPosition(120, 90);
	jump_Button->setScale(1.0f, 1.0f);
	slide_Button = Sprite::create("Texture/Object/UI/SlideButton.png");
	slide_Button->setPosition(1160, 90);
	slide_Button->setScale(1.0f, 1.0f);
	this->addChild(slide_Button, 7);
	this->addChild(jump_Button, 7);

	stop_Button = Sprite::create("Texture/Object/UI/Stop_Button.png");
	stop_Button->setPosition(1217, 663);
	stop_Button->setAnchorPoint(Point(0.5f, 0.5f));
	stop_Button->setScale(1.0f, 1.0f);
	this->addChild(stop_Button, 7);

	stop_BackGround = Sprite::create("Texture/Object/UI/Background.png");
	stop_BackGround->setPosition(0, 0);
	stop_BackGround->setAnchorPoint(Point(0, 0));
	stop_BackGround->setOpacity(127);
	stop_BackGround->setVisible(false);
	this->addChild(stop_BackGround, 14);

	option = Sprite::create("Texture/Object/UI/option.png");
	option->setPosition(50, 660);
	option->setAnchorPoint(Point(0.5f, 0.5f));
	stop_BackGround->addChild(option);

	resume = Sprite::create("Texture/Object/UI/resume.png");
	resume->setPosition(640, 540);
	resume->setScale(0.7f, 0.7f);
	resume->setAnchorPoint(Point(0.5, 0.5));
	stop_BackGround->addChild(resume, 15);
	rePlay = Sprite::create("Texture/Object/UI/rePlay.png");
	rePlay->setPosition(640, 340);
	rePlay->setScale(0.7f, 0.7f);
	rePlay->setAnchorPoint(Point(0.5, 0.5));
	stop_BackGround->addChild(rePlay, 15);
	stop = Sprite::create("Texture/Object/UI/stop.png");
	stop->setPosition(640, 140);
	stop->setScale(0.7f, 0.7f);
	stop->setAnchorPoint(Point(0.5, 0.5));
	stop_BackGround->addChild(stop, 15);

	for (int i = 0; i < 5; i++)
	{
		Fiver[i] = Sprite::create(StringUtils::format("Texture/Object/UI/Fiver_%d.png", i + 1));
		Fiver[i]->setScale(0.7f, 0.7f);
		Fiver[i]->setVisible(false);
		Fiver[i]->setPosition(43 + (i * 50), 680);
		Fiver[i]->setAnchorPoint(Point(0.5, 0.5));
		this->addChild(Fiver[i]);
	}
}
void HelloWorld::setMath()
{
	for (int i = 0; i < 2000; i++)
	{
		direc[i] = 1;
		bat_Direc[i] = 1;
	}
	sub_Condition = 1;
	opacity_time = 0.3f;
	speed = -600.0f;
	Stage = 1;
	Chapter = 2;
	CountHurdle += 0;
	isCrush = false;
	isStart = false;
	ing_Messege = 1;
	removeCake = 0;

	Stage = point::get()->StageNum;
}
void HelloWorld::setAnimation()
{
}
void HelloWorld::setClear()
{
	_clear = Sprite::create("Texture/Object/Hurdle/Chapter1/Table_Chair.png");
	_clear->setPosition(1000, 150);
	_clear->setAnchorPoint(Point(0.0f, 0.0f));
	_clear->setScaleY(2.0f);
	this->addChild(_clear, 12);
	ClearBody = PhysicsBody::createBox(Size(_clear->getContentSize().width / 2, _clear->getContentSize().height), PhysicsMaterial(0, 0, 0), Vec2(100, 0));
	ClearBody->setDynamic(false);
	ClearBody->setCollisionBitmask(100000);
	ClearBody->setContactTestBitmask(true);
	_clear->setPhysicsBody(ClearBody);
}
void HelloWorld::setItem()
{
	i_Fiver = 0;
	FiverTime = 0.0f;
	for (int i = 0; i < 5; i++)
	{
		isFiver[i] = false;
	}

	Teemo = Sprite::create("Texture/Object/Item/Teemo.png");
	Teemo->setPosition(-200, -200);
	Teemo->setScale(1.3f);
	Teemo->setAnchorPoint(Point(0, 0));
	Teemo->setOpacity(127);
	Teemo->setVisible(false);
	this->addChild(Teemo, 13);

	CakeSection = 0;
}
void HelloWorld::setScript()
{
	story_Offset = Vec2(500, 200);

	_script = Node::create();
	this->addChild(_script, 9);

	switch (Stage)
	{
	case 1:
		_script_BackGround1 = Sprite::create("Texture/backGround/Stage2_BackGround.png");
		_script_BackGround1->setPosition(0, 0);
		_script_BackGround1->setAnchorPoint(Point(0, 0));
		_script->addChild(_script_BackGround1);

		_script_BackGround2 = Sprite::create("Texture/Object/UI/backGround.png");
		_script_BackGround2->setPosition(0, 0);
		_script_BackGround2->setAnchorPoint(Point(0, 0));
		_script->addChild(_script_BackGround2, 13);

		_script_BackGround3 = Sprite::create("Texture/backGround/Stage1_BackGround.png");
		_script_BackGround3->setPosition(0, 0);
		_script_BackGround3->setAnchorPoint(Point(0, 0));
		_script->addChild(_script_BackGround3, 1);
		
		break;
	default:
		break;
	}

	
	story = Label::create("", "fonts/ChocoCookie.ttf", 48, Size(700, 200), TextHAlignment::LEFT);
	story->setPosition(500, 200);
	story->setColor(Color3B::RED);
	_script->addChild(story,11);

	script_BackGround = Sprite::create("Texture/Object/UI/backGround.png");
	script_BackGround->setPosition(0, 0);
	script_BackGround->setOpacity(147);
	script_BackGround->setAnchorPoint(Point(0, 0));
	_script->addChild(script_BackGround, 8);

	Alice = Sprite::create(StringUtils::format("Texture/Character/%d.png",point::get()->ilust_num));
	Alice->setOpacity(0);
	Alice->setPosition(180, 300);
	Alice->setAnchorPoint(Point(0.5f, 0.5f));
	_script->addChild(Alice, 12);

	rabbit = Sprite::create("Texture/backGround/Script/rabbit.jpg");
	rabbit->setOpacity(0);
	rabbit->setPosition(1100, 300);
	rabbit->setScaleY(0.7f);
	rabbit->setAnchorPoint(Point(0.5f, 0.5f));
	_script->addChild(rabbit, 12);

	rabbit2 = Sprite::create("Texture/backGround/Script/rabbit2.jpg");
	rabbit2->setOpacity(0);
	rabbit2->setPosition(1100, 300);
	rabbit2->setScaleY(1.3f);
	rabbit2->setAnchorPoint(Point(0.5f, 0.5f));
	_script->addChild(rabbit2, 12);

	NickName = Label::create("", "fonts/ChocoCookie.ttf", 32);
	NickName->setPosition(Vec2(400, 220));
	_script->addChild(NickName, 11);

	Skip = Sprite::create("Texture/backGround/Script/Skip.png");
	Skip->setScale(0.5f);
	Skip->setPosition(Vec2(1235, 580));
	_script->addChild(Skip, 10);

	Chat = Sprite::create("Texture/backGround/Script/Chat.png");
	Chat->setScaleY(0.9f);
	Chat->setAnchorPoint(Vec2(0, 0));
	Chat->setPosition(Vec2(0, 0));
	_script->addChild(Chat, 9);

	Button = Sprite::create("Texture/backGround/Script/Button.png");
	Button->setScale(0.5f, 0.3);
	Button->setPosition(Vec2(1235, 50));
	_script->addChild(Button, 10);

	Nick = Sprite::create("Texture/backGround/Script/Nick.png");
	Nick->setPosition(Vec2(400, 220));
	Nick->setOpacity(107);
	Nick->setScale(0.2f);
	_script->addChild(Nick, 10);
}
void HelloWorld::setParticle()
{

	//CakeParticle->setAngle(0);
	//CakeParticle->setDuration(10);
	//CakeParticle->setGravity(Point(100.0f, 100.0f));
	//CakeParticle->setLife(100);
	//CakeParticle->setPosition(Point(100, 100));
	//CakeParticle->setSpeed(100);
	//CakeParticle->setScale(1.0f);
}