#include "SSH.h"
#include "SimpleAudioEngine.h"
#include <time.h>
using namespace CocosDenshion;
USING_NS_CC;

Scene* ssh::createScene()
{
	Scene* scene = Scene::createWithPhysics();
	// scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = ssh::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);
	return scene;

}
using namespace CocosDenshion;

bool ssh::init()
{

	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"SHH/CloseNormal.png",
		"SHH/CloseSelected.png",
		CC_CALLBACK_1(ssh::menuCloseCallback, this));

	budo = false;

	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
	float y = origin.y + closeItem->getContentSize().height / 2;
	closeItem->setPosition(Vec2(x, y));

	//highScore = UserDefault::getInstance()->getIntegerForKey("high");
	//UserDefault::getInstance()->setIntegerForKey("high", 100);

	background = Sprite::create("SHH/background.png");
	background->setAnchorPoint(Point(0, 0));
	background->setPosition(Vec2(0, 0));
	this->addChild(background, 0);

	background1 = Sprite::create("SHH/bg1.png");
	background1->setAnchorPoint(Point(0, 0));
	background1->setPosition(Vec2(0, 0));
	//background1->setOpacity(0);
	this->addChild(background1, -1);

	background2 = Sprite::create("SHH/bg2.png");
	background2->setAnchorPoint(Point(0, 0));
	background2->setPosition(Vec2(0, 0));
	//	background2->setOpacity(0);
	this->addChild(background2, -2);


	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(ssh::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(ssh::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(ssh::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	micnum = 3;
	int M = 0;
	el = Label::createWithTTF("EunhaLove", "fonts/Marker Felt.ttf", 32);
	el->setString(StringUtils::format("Money : %d", M));
	el->setPosition(Vec2(70, 700));
	this->addChild(el, 1);

	hsl = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	hsl->setPosition(Vec2(1200, 700));
	this->addChild(hsl, 3);

	cbl = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	cbl->setPosition(Vec2(70, 650));
	cbl->setVisible(false);
	this->addChild(cbl, 3);

	spl = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	spl->setPosition(Vec2(70, 650));
	spl->setVisible(false);
	this->addChild(spl, 3);

	gl = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	gl->setPosition(Vec2(70, 650));
	gl->setVisible(false);
	this->addChild(gl, 3);

	Score = Label::createWithTTF("Time:", "fonts/Marker Felt.ttf", 24);
	Score->setPosition(Vec2(640, 700));
	this->addChild(Score, 3);
	budo = false;

	//Restartbt = Label::createWithTTF("ReStart", "fonts/Marker Felt.ttf", 24);
	//Restartbt -> setPosition(Vec2(400, 500));
	//this->addChild(Restartbt, 1);

	coin = Sprite::create("SHH/coin.png");
	coin->setScale(0.03f);
	srand(time(NULL));
	coin->setPosition(Vec2(rand() % 100 + rand() % 935, 138));
	this->addChild(coin, 3);

	ground = Sprite::create("SHH/ground.png");
	ground->setPosition(Vec2(0, 0));
	ground->setAnchorPoint(Point(0.0f, 0.0f));
	this->addChild(ground, 2);


	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("SHH/Character/Character_1.plist");
	eunha = Sprite::createWithSpriteFrameName("run-1.png");
	CharBody = PhysicsBody::createBox(Size(eunha->getContentSize().width - 100, eunha->getContentSize().height), PhysicsMaterial(0, 0, 0));
	CharBody->setDynamic(false);
	CharBody->setCollisionBitmask(20);
	CharBody->setContactTestBitmask(true);
	eunha->setPhysicsBody(CharBody);
	C_ani_1 = Animation::create();
	C_ani_1->setDelayPerUnit(0.05f);

	for (int i = 1; i <= 6; i++)
		C_ani_1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("run-%d.png", i)));

	C_anim_1 = Animate::create(C_ani_1);
	eunha->runAction(RepeatForever::create(C_anim_1));

	//eunha = Sprite::create("eunha.png");
	eunha->setScale(0.5f);
	eunha->setPosition(Vec2(640, 168));
	this->addChild(eunha, 5);

	btl = Sprite::create("SHH/btl.png");
	btl->setScale(1.0f);
	btl->setPosition(Vec2(100, 360));
	this->addChild(btl, 4);

	randitem = Sprite::create("SHH/randitem.png");
	bisitem = false;
	randitem->setScale(0.5f);
	randitem->setPosition(Vec2(rand() % 100 + rand() % 1180, 820));
	this->addChild(randitem, 1);

	btr = Sprite::create("SHH/btr.png");
	btr->setScale(-1.0f);
	btr->setPosition(Vec2(1180, 360));
	this->addChild(btr, 4);
	for (int i = 0; i < 10; i++)
	{

		bismic[i] = true;
		mic[i] = Sprite::create("SHH/mic.png");
		micBody = PhysicsBody::createCircle(mic[i]->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
		micBody->setDynamic(false);
		micBody->setCollisionBitmask(10);
		micBody->setContactTestBitmask(true);
		mic[i]->setScale(0.5f);
		mic[i]->setPhysicsBody(micBody);
		mic[i]->setPosition(Vec2(rand() % 1280, 800));
		this->addChild(mic[i], 1);
	}



	Restartbt = Sprite::create("SHH/Restartbt.png");
	Restartbt->setPosition(Vec2(640, 500));
	this->addChild(Restartbt, 4);
	Restartbt->setVisible(false);
	Restartbt->setOpacity(200);

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치
	t = 0.0f;
	timer = 0;
	time1 = 0;
	time2 = 0;
	godtime = 0;
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("SHH/BGM.mp3");

	SimpleAudioEngine::getInstance()->playBackgroundMusic("SHH/BGM.mp3", true);

	isLeft = false;
	isRight = false;
	b_Direc = 1;
	scheduleUpdate();

	return true;
}

void ssh::update(float dt)
{
	//CCLOG("%f", time);

	for (int i = 0; i < 20; i++)
	{
		static int a = 0;
		a++;
	}
	static float ReCoin = 0;
	static float item = 0; //아이템 재생성 시간
	static float speed = 0;
	static float coinbonus = 0;
	//챕터 변경 타이머
	timer += dt;
	time1 += dt;
	time2 += dt;
	ReCoin += dt;
	item += dt;
	speed += dt;
	coinbonus += dt;
	godtime += dt;
	hsl->setString(StringUtils::format("HighScore : %.0f", highScore));
	spl->setString(StringUtils::format("SpeedUp : %.1f ", 7 - speed));
	cbl->setString(StringUtils::format("Slow : %.1f ", 7 - coinbonus));
	gl->setString(StringUtils::format("GodTime: %.1f ", 5 - godtime));
	if (timer >= 60)
	{
		for (int i = 0; i < 10; i++)
			mic[i]->setTexture(Director::getInstance()->getTextureCache()->addImage("SHH/jam.png"));
	}
	if (b_Direc == 1)
	{
		if (timer >= 60)
		{
			CCLOG("1111");
			background->runAction(FadeOut::create(1.0f));
			b_Direc = 2;
		}
	}
	if (b_Direc == 2)
	{
		background1->runAction(FadeIn::create(1.0f));
	}

	if (!(randitem->isVisible()) && item > 15)
	{
		randitem->setVisible(true);
		randitem->setPositionY(820);
		item = 0;
	}
	if (speed > 7)
	{
		spl->setVisible(false);
		ps = 4.0;
		speed = 0;
	}
	if (coinbonus > 7)
	{
		cbl->setVisible(false);
		ps = 4.0;
		coinbonus = 0;
	}
	if (godtime > 5)
	{
		gl->setVisible(false);
		gt = false;
		godtime = 0;
	}
	if (ReCoin > 3)
	{
		coin->setVisible(true);

		ReCoin = 0;
	}


	if (budo == false)
	{
		if (setlC_1 == true && eunha->getPositionX() > 50)
			eunha->setPosition(eunha->getPositionX() - ps, eunha->getPositionY());
		if (setrC_1 == true && eunha->getPositionX() < 1230)
			eunha->setPosition(eunha->getPositionX() + ps, eunha->getPositionY());
	}
	if (time1 >= 10.0)
	{
		CCLOG("SDSD");
		if (micnum<10)
			micnum++;
		time1 = 0;
	}

	if (time2 >= 1.0)
	{
		CCLOG("SDSD");
		sex++;
		for (int i = 0; i < sex; i++)
		{
			bismic[i] = false;
		}
		time2 = 0;
	}
	if (budo == false)
	{
		if (bisitem == false)
		{
			//CCLOG("DOWNDOWN");
			randitem->runAction(MoveBy::create(1 / 60, Vec2(0, -1)));
		}
		for (int i = 0; i < micnum; i++)
		{
			if (bismic[i] == false)
			{
				mic[i]->runAction(MoveBy::create(3, Vec2(0, -5)));
			}
		}
	}

	if (randitem->getPositionY() < 0)
	{

		randitem->setPosition(Vec2(rand() % 100 + rand() % 1180, 820));
	}
	if (randitem->isVisible() && eunha->getBoundingBox().intersectsRect(randitem->getBoundingBox()))
	{

		int a = (rand() % 3) + 1;
		switch (a)
		{
		case 2:  //이동속도 증가
			spl->setVisible(true);
			ps = 6.0f;
			speed = 0;
			coinbonus = 0;
			break;
		case 1:  //이동속도 감소
			cbl->setVisible(true);
			ps = 2.0f;
			speed = 0;
			coinbonus = 0;
			break;
		case 3:  //무적
			gl->setVisible(true);
			gt = true;
			godtime = 0;
			break;
		default:
			break;
		}
		SimpleAudioEngine::getInstance()->playEffect("SHH/boxopen.mp3");
		randitem->setVisible(false);
		item = 0;
	}

	for (int i = 0; i < micnum; i++)
	{
		if (mic[i]->getPositionY() < 0)
		{
			bismic[i] = true;
			mic[i]->setPosition(Vec2(rand() % 1280, 800));
		}
	}
	if (budo == false)
	{
		t += dt;
		Score->setString(StringUtils::format("%d", (int)t));
	}
	else
	{
		Score->setString("Game Over");
		GameOver = true;

		Restartbt->setVisible(true);
	}



	//for (int i = 0; i < micnum; i++)
	//{
	//	if (eunha->getBoundingBox().intersectsRect(mic[i]->getBoundingBox()) && gt == false)
	//	{
	//		SimpleAudioEngine::getInstance()->playEffect("gameover.mp3");
	//		budo = true;
	//	}
	//}



	if (coin->isVisible() && eunha->getBoundingBox().intersectsRect(coin->getBoundingBox()))
	{
		cg = (rand() % 5) + 1;
		M += cg;
		el->setString(StringUtils::format("Money : %d", M));
		SimpleAudioEngine::getInstance()->playEffect("SHH/coin.wav");
		particle = ParticleSystemQuad::create("SHH/coinget.plist");
		particle->setPosition(eunha->getPosition());
		particle->setAngle(0);                            // 각도

		particle->setDuration(1000);                      // 발생시간

		particle->setGravity(Point(100, 100));      // 중력값(x, y는 위치가 아닌 중력치)

		particle->setLife(1000);                           // 지속시간

		particle->setSpeed(0);                       // 속도

		particle->setScale(0.5f);
		this->addChild(particle, 6);
		coin->setPosition(Vec2(rand() % 100 + rand() % 1180, 138));
		coin->setVisible(false);
		ReCoin = 0;
	}
}

void ssh::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool ssh::onContactBegin(PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	for (int i = 0; i < 10; i++)
	{
		if (gt == false)
		{
			if ((20 == a->getCollisionBitmask() && 10 == b->getCollisionBitmask()) ||
				(10 == a->getCollisionBitmask() && 20 == b->getCollisionBitmask()))
			{
				{
					SimpleAudioEngine::getInstance()->playEffect("SHH/gameover.mp3");

					budo = true;
				}
			}
		}
	}
	return false;
}

bool ssh::onTouchBegan(Touch *touch, Event* _event)
{
	auto Point = touch->getLocation();
	CCLOG("tch");
	if (Restartbt != NULL &&  Restartbt->getBoundingBox().containsPoint(touch->getLocation()))
	{

	}
	if (btl->getBoundingBox().containsPoint(touch->getLocation()))
	{
		setlC_1 = true;
		eunha->setScaleX(-0.5f);
		isLeft = true;
		_animation();
		btl->setTexture(Director::getInstance()->getTextureCache()->addImage("SHH/btln.png"));
	}
	if (btr->getBoundingBox().containsPoint(touch->getLocation()))
	{
		setrC_1 = true;
		eunha->setScaleX(0.5f);
		isRight = true;
		_animation();
		btr->setTexture(Director::getInstance()->getTextureCache()->addImage("SHH/btrn.png"));
	}
	if (Restartbt != nullptr)
	{
		if (Restartbt->getBoundingBox().containsPoint(touch->getLocation()) && Restartbt->isVisible())
		{
			Scene* scene = ssh::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
			Restart();
		}
	}
	return true;
}
void ssh::onTouchMoved(Touch *touch, Event* _event)
{

}
void ssh::onTouchEnded(Touch *touch, Event* _event)
{
	setlC_1 = false;
	isLeft = false;
	eunha->stopAllActions();
	btr->setTexture(Director::getInstance()->getTextureCache()->addImage("SHH/btr.png"));
	if (isRight)
		_animation();
	setrC_1 = false;
	isRight = false;
	eunha->stopAllActions();
	btl->setTexture(Director::getInstance()->getTextureCache()->addImage("SHH/btl.png"));
	if (isLeft)
		_animation();

}
void ssh::Restart()
{
	t = 0.0f;

	GameOver = false;

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	/*SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();*/
	SimpleAudioEngine::getInstance()->playBackgroundMusic("SHH/BGM.mp3", true);


	Restartbt->setVisible(false);
}
void ssh::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{ //이런 식으로 키 값에 따라 처리를 하면 된다 
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setlC_1 = true;
		eunha->setScaleX(-0.5f);
		isLeft = true;
		_animation();
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setrC_1 = true;
		eunha->setScaleX(0.5f);
		isRight = true;
		_animation();
		break;
	}
}
void ssh::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setlC_1 = false;
		isLeft = false;
		eunha->stopAllActions();
		if (isRight)
			_animation();

		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setrC_1 = false;
		isRight = false;
		eunha->stopAllActions();
		if (isLeft)
			_animation();
		break;
	}
}

void ssh::_animation()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("SHH/Character/Character_1.plist");
	C_ani_1 = Animation::create();
	C_ani_1->setDelayPerUnit(0.05f);

	for (int i = 1; i <= 6; i++)
		C_ani_1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("run-%d.png", i)));
	
	C_anim_1 = Animate::create(C_ani_1);
	eunha->runAction(RepeatForever::create(C_anim_1));
}

//void HelloWorld::onExit()
//{
//	
//}

