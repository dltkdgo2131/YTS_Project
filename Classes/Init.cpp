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

	switch (Chapter)
	{
	case 1:
		backGround1 = Sprite::create("Texture/backGround/Stage1_BackGround.png");
		backGround2 = Sprite::create("Texture/backGround/Stage1_BackGround.png");
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			chapter2_Background = Node::create();
			this->addChild(chapter2_Background);

			Tree[i] = Node::create();
			chapter2_Background->addChild(Tree[i]);

			Bush[i] = Node::create();
			//	chapter2_Bush[i]->setPosition(2560, 0);
			chapter2_Background->addChild(Bush[i]);

			backGround1 = Sprite::create("Texture/backGround/Chapter2/Chapter2_BackGround.png");
			backGround2 = Sprite::create("Texture/backGround/Chapter2/Chapter2_BackGround.png");
			for (int j = 0; j < 4; j++)
			{
				if (j < 2)
				{

					/*			tree[j + (i * 2)] = Sprite::create(StringUtils::format("Texture/backGround/Chapter2/Chapter2_tree%d.png", j+1));
								if(j % 2 == 0)
									tree[j + (i * 2)]->setPosition(430, 0);
								else
									tree[j + (i * 2)]->setPosition(1500, 0);
								tree[j + (i * 2)]->setAnchorPoint(Point(0.0f, 0.0f));
								Tree[i]->addChild(tree[j + (i * 2)],-2);*/

				}
				if (j % 3 != 0)
				{
					bush[j + (i * 4)] = Sprite::create(StringUtils::format("Texture/backGround/Chapter2/Chapter2_Bush%d.png", j + 1));
					bush[j + (i * 4)]->setAnchorPoint(Point(0.0f, 0.0f));
					bush[j + (i * 4)]->setPosition(0, -60);
					Bush[i]->addChild(bush[j + (i * 4)], -3 + j);
				}
				else
				{
					bush[j + (i * 4)] = Sprite::create(StringUtils::format("Texture/backGround/Chapter2/Chapter2_Bush%d.png", j + 1));
					bush[j + (i * 4)]->setPosition(0, -60);
					bush[j + (i * 4)]->setAnchorPoint(Point(0.0f, 0.0f));
					this->addChild(bush[j + (i * 4)], -3 + j);
				}
				switch (j + (i * 4))
				{
				case 0:
					bush[j + (i * 4)]->setPosition(300, -60);
					//		tree[j + (i * 2)]->setPosition(430, 0);
					break;
				case 1:
					bush[j + (i * 4)]->setPosition(120, -60);
					//		tree[j + (i * 2)]->setPosition(1500, 0);
					break;
				case 2:
					bush[j + (i * 4)]->setPosition(0, -60);
					//		tree[j + (i * 2)]->setPosition(2560 + 300, -60);
					break;
				case 3:
					bush[j + (i * 4)]->setPosition(70, -60);
					//		tree[j + (i * 2)]->setPosition(2560 + 1500, 0);
					break;
				case 4:
					bush[j + (i * 4)]->setPosition(bush[0]->getContentSize().width + 300, -60);
					break;
				case 5:
					bush[j + (i * 4)]->setPosition(120, -60);
					break;
				case 6:
					bush[j + (i * 4)]->setPosition(0, -60);
					break;
				case 7:
					bush[j + (i * 4)]->setPosition(bush[3]->getContentSize().width + 70, -60);
					break;
				}
			}
			rose[i] = Sprite::create("Texture/backGround/Chapter2/Chapter2_Rose.png");
			rose[i]->setAnchorPoint(Point(0.0f, 0.0f));
			rose[i]->setPosition(0, 150);
			Bush[i]->addChild(rose[i]);
			cloud[i] = Sprite::create("Texture/backGround/Chapter2/Chapter2_Cloud.png");
			cloud[i]->setAnchorPoint(Point(0.0f, 0.0f));
			cloud[i]->setPosition(0, 620);
			this->addChild(cloud[i], -4);
			if (i == 1)
			{
				rose[i]->setPosition(2560, 0);
				cloud[i]->setPosition(2560, 0);
			}
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
		{
			Bush[i] = Node::create();
			this->addChild(bush[i]);

			Tree[i] = Node::create();
			this->addChild(Tree[i]);

			for (int j = 0; j < 5; j++)
			{
				if (j < 3)
				{
					tree[j + (i * 3)] = Sprite::create(StringUtils::format("Texture/backGround/Chapter3/Chapter3_Tree%d", j + 1));
					tree[j + (i * 3)]->setAnchorPoint(Point(0.0f, 0.0f));
					tree[j + (i * 3)]->setPosition(0, 30);
					Tree[i]->addChild(tree[j + (i * 3)]);
				}
				bush[j + (i * 5)] = Sprite::create(StringUtils::format("Texture/backGround/Chapter3/Chapter3_Bush%d", j + 1));
				bush[j + (i * 5)]->setAnchorPoint(Point(0.0f, 0.0f));
				bush[j + (i * 5)]->setPosition(0, -30);
				Bush[i]->addChild(bush[j + (i * 5)]);
				switch (j + (i * 5) + 1)
				{
				case 1:
					bush[j + (i * 5)]->setGlobalZOrder(-9);
					tree[j + (i * 5)]->setGlobalZOrder(-1);
					break;
				case 2:
					bush[j + (i * 5)]->setGlobalZOrder(-6);
					tree[j + (i * 5)]->setGlobalZOrder(-2);

					break;
				case 3:
					bush[j + (i * 5)]->setGlobalZOrder(-4);
					bush[j + (i * 5)]->setPosition(300, 0);
					tree[j + (i * 5)]->setGlobalZOrder(-5);
					break;
				case 4:
					bush[j + (i * 5)]->setGlobalZOrder(3);
					break;
				case 5:
					bush[j + (i * 5)]->setGlobalZOrder(0);
					break;
				case 6:

					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					break;
				default:
					break;
				}
			}
			dungcol[i] = Sprite::create("Texture/backGround/Chapter3/Chapter3_dungcol");
			dungcol[i]->setAnchorPoint(Point(0.0f, 1.0f));
			dungcol[i]->setPosition(0, 0);
			this->addChild(dungcol[i]);
		}
	default:
		break;
	}

	backGround1->setAnchorPoint(Point(0, 0));
	backGround2->setAnchorPoint(Point(0, 0));
	backGround1->setPosition(0, 0);
	backGround2->setPosition(backGround1->getContentSize().width, 0);
	//backGround1->setVisible(false);
	//backGround2->setVisible(false);
	this->addChild(backGround1, -10);
	this->addChild(backGround2, -10);
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
	for (int i = 0; i < 4; i++)
		isAlice[i] = false;
	A_time = 0;
	B_time = 4.9f;
	A_Scale = 0.5f;
	OpacityDirec = 0;
	Alice_Condition = 1;

	for (int i = 0; i < 5; i++)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_1.plist");

		_Alice[i] = Sprite::createWithSpriteFrameName("run-1.png");
		_Alice[i]->setScale(0.5f);
		_Alice[i]->setTag(1);
		y = y_base;
		_Alice[i]->setOpacity(0);
		_Alice[i]->setPosition(C_location.x, y);
		_Alice[i]->setAnchorPoint(Point(0.5, 0.5));
		this->addChild(_Alice[i]);
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Texture/Character/Character_1.plist");

	C_1 = Sprite::createWithSpriteFrameName("run-1.png");
	C_1->setScale(0.5f);
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
	tempCoin = 0;
	// 모은 코인
	i_Collecting_Coin = 0;
	s_Collecting_Coin = Sprite::create("Texture/Object/Item/Gold_Coin.png");
	s_Collecting_Coin->setScale(0.6f);
	s_Collecting_Coin->setPosition(50, 435);
	this->addChild(s_Collecting_Coin);
	Collecting_Coin = Label::create("", "fonts/Marker Felt.ttf", 36);
	Collecting_Coin->setColor(ccc3(153, 102, 0));
	//	Collecting_Coin = Label::createWithCharMap("fonts/number.png", 50, 50, 48);
	Collecting_Coin->setPosition(173, 435);
	this->addChild(Collecting_Coin, 5);

	//모은 케이크
	i_Collecting_Cake = 0;
	s_Collecting_Cake = Sprite::create("Texture/Object/Cake/Cake.png");
	s_Collecting_Cake->setScale(0.6f);
	s_Collecting_Cake->setPosition(50, 505);
	this->addChild(s_Collecting_Cake);
	Collecting_Cake = Label::createWithTTF("0 / 800", "fonts/Marker Felt.ttf", 36);
	Collecting_Cake->setColor(ccc3(153, 102, 0));
	//Collecting_Cake = Label::createWithCharMap("fonts/Number.png", 50, 50, 48);
	Collecting_Cake->setPosition(173, 505);
	this->addChild(Collecting_Cake);

	jump_Button = Sprite::create("Texture/Object/UI/JumpButton.png");
	jump_Button->setPosition(120, 90);
	jump_Button->setScale(1.0f, 1.0f);
	slide_Button = Sprite::create("Texture/Object/UI/SlideButton.png");
	slide_Button->setPosition(1160, 90);
	slide_Button->setScale(1.0f, 1.0f);
	this->addChild(slide_Button, 7);
	this->addChild(jump_Button, 7);

	stop_Button = MenuItemImage::create("Texture/Object/UI/Stop_Button.png", "Texture/Object/UI/p_Stop_Button.png", CC_CALLBACK_1(HelloWorld::CC_StopButton, this));
	stop_Button->setPosition(1217, 663);
	stop_Button->setAnchorPoint(Point(0.5f, 0.5f));
	stop_Button->setScale(1.0f, 1.0f);

	_stop = Menu::create(stop_Button, NULL);
	_stop->setPosition(0, 0);
	this->addChild(_stop);

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
	
	removeCake = 0; // 삭제된 케이크

	gravity = 0;

	isPause = false; // 멈춤

	sub_Condition = 1;
	opacity_time = 0.3f;
	speed = -600.0f;
	Stage = 1;
	//	if (point::get()->Chapter == NULL)
	Chapter = point::get()->Chapter;
	if (Chapter < 0)
		Chapter = 1;
	//	else\
			Chapter = 2;
	CountHurdle += 0;

	beCrush = 0;
	afCrush = 0;
	isCrush = false;
	isStart = false;
	ing_Messege = 1;
	
	TeemoTime = -0.5f;
	iStar = 3;
	//	if (point::get()->StageNum == NULL)
	Stage = point::get()->StageNum;
	if (Stage < 0)
		Stage = 1;
	//	else\
			Stage = 1;
		//Stage = point::get()->StageNum;
}
void HelloWorld::setAnimation()
{
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

	switch (Chapter)
	{
	case 1:
		
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
		break;
	}


	story = Label::create("", "fonts/ChocoCookie.ttf", 48, Size(700, 200), TextHAlignment::LEFT);
	story->setPosition(500, 200);
	story->setColor(Color3B::RED);
	_script->addChild(story, 11);

	script_BackGround = Sprite::create("Texture/Object/UI/backGround.png");
	script_BackGround->setPosition(0, 0);
	script_BackGround->setOpacity(147);
	script_BackGround->setAnchorPoint(Point(0, 0));
	_script->addChild(script_BackGround, 8);

	Alice = Sprite::create(StringUtils::format("Texture/Character/%d.png", point::get()->ilust_num));
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

	_Clear = Node::create();
	_Clear->setGlobalZOrder(13);
	_Clear->setVisible(false);
	this->addChild(_Clear, 13);

	black_Background = Sprite::create("Texture/Object/UI/backGround.png");
	black_Background->setAnchorPoint(Point(0.f, 0.f));
	black_Background->setPosition(0, 0);
	black_Background->setOpacity(127);
	_Clear->addChild(black_Background);
	star_tle = Sprite::create("Texture/Object/Clear/Star_tle.png");
	star_tle->setAnchorPoint(Point(0.5f, 0.5f));
	star_tle->setPosition(635, 485);
	_Clear->addChild(star_tle, 1);

	for (int i = 0; i < iStar; i++)
	{
		star[i] = Sprite::create(StringUtils::format("Texture/Object/clear/star%d.png", i + 1));
		switch (i)
		{
		case 0:
			star[i]->setPosition(540 + 25 + (80 * i), 490);
		case 1:
			star[i]->setPosition(610, 490);
		case 2:
			star[i]->setPosition(690, 490);
		default:
			break;
		}

		star[i]->setScale(0.0f);
		star[i]->setOpacity(0);
		this->addChild(star[i], 1);
		star[i]->setGlobalZOrder(2);
	}
	
}
