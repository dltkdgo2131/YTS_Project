#include "Mini.h"
#include "SimpleAudioEngine.h"
#include"time.h"
#include "ChapterSelect.h"

//#include "Mini2.h"
//cocos new<프로젝트 이름>-p<패키지 이름>-l<cpp:lua:js>-d<설치할 경로>  <-새로운 프로젝트 만들때

Scene* Mini::createScene2()
{
	auto scene = Scene::create();
	auto layer = Mini::create();
	scene->addChild(layer);
	return scene;
}

using namespace CocosDenshion;

bool Mini::init()
{

	srand(time(NULL));

	if (!Layer::init())
	{

		return false;
	}

	GameOver = true;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Mini::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(Mini::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);



	auto closeItem = MenuItemImage::create(
		"HsH/CloseNormal.png",
		"HsH/CloseSelected.png",
		CC_CALLBACK_1(Mini::menuCloseCallback, this));


	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
	float y = origin.y + closeItem->getContentSize().height / 2;
	closeItem->setPosition(Vec2(x, y));



	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	this->setTouchEnabled(true); // 터치활성화 false 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	All = Sprite::create();
	All->setVisible(false);
	this->addChild(All, 1);


	///////////Label////////////////
	start = Label::createWithTTF("Start", "fonts/Marker Felt.ttf", 24);
	start->setPosition(Vec2(600, 350));
	start->setScale(2.0f);
	this->addChild(start, 2);


	HighScore = Label::createWithTTF("HighScore:0", "fonts/Marker Felt.ttf", 24);
	HighScore->setPosition(Vec2(100, 500));
	All->addChild(HighScore, 1);

	label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(600, 550));
	All->addChild(label, 3);

	scorelabel = Label::createWithTTF("Score:0", "fonts/Marker Felt.ttf", 24);
	scorelabel->setPosition(Vec2(100, 550));
	All->addChild(scorelabel, 3);

	Restartbt = Label::createWithTTF("ReStart", "fonts/marker felt.ttf", 24);
	Restartbt->setVisible(false);
	Restartbt->setPosition(Vec2(100, 100));
	this->addChild(Restartbt, 3);

	sound1label = Label::createWithTTF("background Sound ", "fonts/Marker Felt.ttf", 24);
	sound1label->setPosition(Vec2(900, 600));
	All->addChild(sound1label, 3);

	sound2label = Label::createWithTTF("Sound effect", "fonts/Marker Felt.ttf", 24);
	sound2label->setPosition(Vec2(900, 300));
	All->addChild(sound2label, 3);

	Fever = Label::createWithTTF("", "fonts/Marker Felt.ttf", 36);
	Fever->setPosition(Vec2(100, 600));
	All->addChild(Fever, 3);
	//////////////////////////////////////////

	Up = 1;

	sex = 0;

	num = 0;

	v1 = 0.5;

	v2 = 0.5;

	t = 20.0f;

	/* auto sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr)
	{


	}
	else
	{
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(sprite, 0);
	}

	background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(Vec2(0,0));
	this->addChild(background, 0);


	stageone = Sprite::create("stageone.png");
	stageone->setAnchorPoint(Vec2(0, 0));
	stageone->setPosition(Vec2(50, 200));
	this->addChild(stageone, 1);


	stagetwo = Sprite::create("stagetwo.png");
	stagetwo->setAnchorPoint(Vec2(0, 0));
	stagetwo->setPosition(Vec2(350, 200));
	this->addChild(stagetwo, 1);


	stagethree = Sprite::create("stagethree.png");

	stagethree->setAnchorPoint(Vec2(0, 0));
	stagethree->setPosition(Vec2(645, 200));
	this->addChild(stagethree, 1);


	stagefour = Sprite::create("stagefour.png");
	stagefour->setAnchorPoint(Vec2(0, 0));
	stagefour->setPosition(Vec2(950, 200));
	this->addChild(stagefour, 1);

	m_Right = MenuItemImage::create("Right.jpg", "Right.jpg", CC_CALLBACK_1(HelloWorld::v_Right, this));
	m_Right->setScale(0.4f);
	m_Right->setPosition(Vec2(1150, 100));

	m_Left = MenuItemImage::create("Left.jpg","Left.jpg",CC_CALLBACK_1(HelloWorld::v_Left,this));
	m_Left->setScale(0.4f);
	m_Left->setPosition(Vec2(130, 100));

	dressroom = Sprite::create("dressroom.png");
	dressroom->setScale(0.3f);
	dressroom->setPosition(Vec2(950, 100));
	this->addChild(dressroom, 1);


	shop = Sprite::create("shop.png");
	shop->setScale(0.3f);
	shop->setPosition(Vec2(780, 100));
	this->addChild(shop, 1);


	Infinitemode = Sprite::create("Infinitemode.png");
	Infinitemode->setScale(0.3f);
	Infinitemode->setPosition(Vec2(600, 100));
	this->addChild(Infinitemode, 1);

	starone = Sprite::create("starone.png");
	starone->setPosition(Vec2(190, 250));
	this->addChild(starone, 1);

	startwo = Sprite::create("startwo.png");
	startwo->setPosition(Vec2(465, 250));
	this->addChild(startwo, 1);

	starthree = Sprite::create("starthree.png");
	starthree->setPosition(Vec2(770, 250));
	this->addChild(starthree, 1);

	starfour = Sprite::create("starfour.png");
	starfour->setPosition(Vec2(1060, 250));
	this->addChild(starfour, 1);

	Arrow = Menu::create(m_Left, m_Right,NULL);
	Arrow->setPosition(Vec2(0,0));
	this->addChild(Arrow, 1);	*/

	//////////Sprite////////////
	game = Sprite::create("HsH/game.png");
	game->setPosition(Vec2(600, 350));
	game->setScale(0.9f);
	All->addChild(game, 0);

	S1 = Sprite::create("HsH/1.jpg");
	S1->setPosition(Vec2(600, 350));
	S1->setScale(0.3f);
	All->addChild(S1, 1);

	SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
	SimpleAudioEngine::getInstance()->setEffectsVolume(v2);

	sound1 = Sprite::create("HsH/Sound 1.png");
	sound1->setPosition(Vec2(900, 500));
	sound1->setScale(0.05f);
	All->addChild(sound1, 1);

	sound2 = Sprite::create("HsH/Sound 2.png");
	sound2->setPosition(Vec2(900, 200));
	sound2->setScale(0.05f);
	All->addChild(sound2, 1);

	plus1 = Sprite::create("HsH/plus.png");
	plus1->setPosition(Vec2(1200, 400));
	plus1->setScale(0.5f);
	All->addChild(plus1, 1);

	plus2 = Sprite::create("HsH/plus 2.png");
	plus2->setPosition(Vec2(1200, 100));
	plus2->setScale(0.5f);
	All->addChild(plus2, 1);

	minus1 = Sprite::create("HsH/minus.png");
	minus1->setPosition(Vec2(900, 400));
	minus1->setScale(0.5f);
	All->addChild(minus1, 1);

	minus2 = Sprite::create("HsH/minus 2.png");
	minus2->setPosition(Vec2(900, 100));
	minus2->setScale(0.5f);
	All->addChild(minus2, 1);

	gayZ = Sprite::create("HsH/gayZ.png");
	gayZ->setAnchorPoint(Vec2(0, 0));
	gayZ->setPosition(Vec2(500, 170));
	gayZ->setVisible(false);
	gayZ->setScale(0.5f);
	All->addChild(gayZ, 2);

	gayZBa = Sprite::create("HsH/gayZBa.png");
	gayZBa->setAnchorPoint(Vec2(0, 0));
	gayZBa->setPosition(Vec2(500, 170));
	gayZBa->setScale(0.5f);
	All->addChild(gayZBa, 1);

	for (int i = 0; i < 5; i++)
	{
		Stick[i] = Sprite::create("HsH/Volume.png");
		Stick[i]->setPosition(Vec2(960 + (50 * i), 500));
		Stick[i]->setScale(0.5f);
		Stick[i]->setVisible(false);
		All->addChild(Stick[i], 1);
	}

	for (int i = 0; i < 5; i++)
	{
		Stick2[i] = Sprite::create("HsH/Volume 2.png");
		Stick2[i]->setPosition(Vec2(960 + (50 * i), 200));
		Stick2[i]->setScale(0.5f);
		Stick2[i]->setVisible(false);
		All->addChild(Stick2[i], 1);
	}
	///////////////////////
	sex = UserDefault::getInstance()->getFloatForKey("high");
	HighScore->setString(StringUtils::format("HighScore:%d", sex));
	scheduleUpdate();
	
	auto Quit = MenuItemImage::create("BackBt.png", "BackBt2.png", CC_CALLBACK_1(Mini::menuCallback, this));
	auto menu2 = Menu::create(Quit, NULL);
	menu2->setPosition(Vec2(100, 640));
	this->addChild(menu2, 2);
	
	return true;
}
void Mini::menuCallback(cocos2d::Ref * pSender)
{
	
		SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
		Scene *pScene = Chapter::ChapterScene();
		Director::getInstance()->replaceScene(pScene);
		SimpleAudioEngine::getInstance()->end();
	
}
void Mini::update(float dt)
{
	//dt++;
	if (t > 0.0&&GameOver == false)
	{
		t -= dt;
		label->setString(StringUtils::format("%0.1f", t));

		//	CCLOG("*%f", t);
	}
	else if (start->isVisible() == false)
	{
		label->setString("Game Over");
		if (Score > sex)
		{

			sex = Score;
			UserDefault::getInstance()->setFloatForKey("high", sex);
			HighScore->setString(StringUtils::format("HighScore:%d", sex));
		}
		Restartbt->setVisible(true);
		GameOver = true;


	}
}

void Mini::menuCloseCallback(Ref* pSender)
{


	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool Mini::onTouchBegan(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();

	CCLOG("%f %f", point.x, point.y);

	if (S1 != nullptr)
	{
		if (S1->getBoundingBox().containsPoint(touch->getLocation()) && GameOver == false)
		{

			Score += Up;
			if (gay < 9)
			{
				gay += 0.05;
				gayZ->setScaleX(gay);
				CCLOG("%f", gay);
			}
			if (gayZ->isVisible() == false)
				gayZ->setVisible(true);

			SimpleAudioEngine::getInstance()->playEffect("HsH/12.wav");

			scorelabel->setString(StringUtils::format("Score:%d", Score));

			S1->setTexture(Director::getInstance()->getTextureCache()->addImage("HsH/2.jpg"));
		}
	}


	if (Restartbt != nullptr)
	{
		if (Restartbt->getBoundingBox().containsPoint(touch->getLocation()))
		{
			SimpleAudioEngine::getInstance()->playEffect("HsH/diding.mp3");
			Restart();
		}
	}

	if (plus1 != nullptr)
	{
		if (plus1->getBoundingBox().containsPoint(touch->getLocation()) && num < 5)
		{
			Stick[num]->setVisible(true);
			v1 += 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
			num++;
		}
	}

	if (minus1 != nullptr)
	{
		if (minus1->getBoundingBox().containsPoint(touch->getLocation()) && num > 0)
		{
			Stick[num - 1]->setVisible(false);
			v1 -= 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v1);
			num--;
		}
	}

	if (plus2 != nullptr)
	{
		if (plus2->getBoundingBox().containsPoint(touch->getLocation()) && num2 < 5)
		{
			Stick2[num2]->setVisible(true);
			v2 += 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v2);
			num2++;

		}
	}

	if (minus2 != nullptr)
	{
		if (minus2->getBoundingBox().containsPoint(touch->getLocation()) && num2 > 0)
		{
			Stick2[num2 - 1]->setVisible(false);
			v2 -= 0.1;
			SimpleAudioEngine::getInstance()->setEffectsVolume(v2);
			num2--;
		}
	}


	return true;
}

void Mini::onTouchMoved(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();

}
void Mini::onTouchEnded(Touch* touch, Event* _event)
{
	if (start != nullptr)
	{
		if (start->getBoundingBox().containsPoint(touch->getLocation()) && start->isVisible() == true)
		{
			GameOver = false;
			SimpleAudioEngine::getInstance()->playEffect("HsH/diding.mp3");
			SimpleAudioEngine::getInstance()->playBackgroundMusic("HsH/11.mp3", true);
			start->setVisible(false);
			All->setVisible(true);
		}
	}
	S1->setTexture(Director::getInstance()->getTextureCache()->addImage("HsH/1.jpg"));
	if (gay > 9)
	{
		Up = 2;
		Fever->setString("Fever!!");
	}
}
//void HelloWorld::v_Right(Ref* pSender)
//{
//	Director::getInstance()->end();
//
//    #if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
//	exit(0);
//#endif
//}
//void HelloWorld::v_Left(Ref* pSender)
//{
//	Director::getInstance()->end();
//
//#if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
//	exit(0);
//#endif
//}

void Mini::Restart()
{
	if (Restartbt->isVisible() == true)
	{

		Score = 0;
		scorelabel->setString("Score:0");
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		//SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
		//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		SimpleAudioEngine::getInstance()->playBackgroundMusic("HsH/11.mp3", true);
		t = 20.0f;

		GameOver = false;

		Restartbt->setVisible(false);

		//Fever->setVisible(false);

		gay = 0.0;

		gayZ->setScaleX(gay);

		Fever->setString(" ");

		Up = 1;
	}



}


void Mini::onExit()
{
	Layer::onExit();
	UserDefault::getInstance()->setFloatForKey("high", sex);
}

void Mini::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* _event)
{


	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (S1 != nullptr && GameOver == false)
		{

			Score += Up;
			if (gay < 9)
			{
				gay += 0.05;
				gayZ->setScaleX(gay);
				CCLOG("%f", gay);
			}
			if (gay > 9)
			{
				Up = 2;
				Fever->setString("Fever!!");
			}
			SimpleAudioEngine::getInstance()->playEffect("HsH/12.wav");

			scorelabel->setString(StringUtils::format("Score:%d", Score));

			S1->setTexture(Director::getInstance()->getTextureCache()->addImage("HsH/2.jpg"));

		}
	}

}
void Mini::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* _event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		S1->setTexture(Director::getInstance()->getTextureCache()->addImage("HsH/1.jpg"));
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
	{
		if (start != nullptr && GameOver == false)
		{
			GameOver = false;
			SimpleAudioEngine::getInstance()->playEffect("HsH/diding.mp3");
			SimpleAudioEngine::getInstance()->playBackgroundMusic("HsH/11.mp3", true);
			start->setVisible(false);
			All->setVisible(true);
		}
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
		{
			Director::getInstance()->end();
		}

	}

}
