
#include "SimpleAudioEngine.h"
#include "Chapter1.h"
#include "game.h"

using namespace CocosDenshion;
Scene* HelloWorld::createScene()
{
	Scene* scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = HelloWorld::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);
	return scene;
}
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	h_Repeat = 1;

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	/// 카메라 ////////////////////
	setCamera();
	/// 잡것 //////////////////////
	//auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	//auto edgeNode = Node::create();
	//edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 100));
	//edgeNode->setPhysicsBody(edgeBody);

	//this->addChild(edgeNode);
	setKeyListener();
	setMath();
	/// 배경  /////////////////////
	setBackGround();
	setItem();
	setAnimation();
	setClear();
	setScript();
	/// 캐릭터 ///////////////////
	setCharacter();
	setUI();
	/// 파티클 ///////////////////
	setParticle();

	/// 생명 /////////////////////
	setHeart();
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	/// 수집 젤리, 점수/////////


	/// 젤리 ///////////////////
	for (int i = 0; i < 2000; i++)
		isAddChildCake[i] = false;
	chapte1_S1();

	this->setTouchEnabled(true);

	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}
void HelloWorld::update(float dt)
{
	if (isClear == true)
	{
		if (tempCake != i_Collecting_Cake)
		{
			for (int i = 0; i < 3; i++)
				tempCake += 1.0f;
			if (tempCake > i_Collecting_Cake - 1)
				tempCake = i_Collecting_Cake;
			clearTerm->setString(StringUtils::format("%.0f /  %d", tempCake, Max_Collecting_Cake));
		}
		if (tempCake != i_Collecting_Coin)
		{
			for (int i = 0; i < 3; i++)
				tempCoin += 1.0f;
			if (tempCoin > i_Collecting_Coin - 1)
				tempCoin = i_Collecting_Coin;
			clearCoin->setString(StringUtils::format("%.0f", tempCoin));
		}
	}
	if (isPause == false)
	{
		inGame(dt);
		MoveCake_Stick(dt);
	}
}
void HelloWorld::inGame(float dt)
{
	////follow_Camera->setPosition(follow_Camera->getPositionX() + 4.0f, 360);
	//this->runAction(camera);
	/// 케이크, 장애물 //////////
	Collecting_Cake->setString(StringUtils::format("%.0f /  %d", i_Collecting_Cake, Max_Collecting_Cake));
	Collecting_Coin->setString(StringUtils::format("%.0f", i_Collecting_Coin));

	switch (Stage)
	{
	case 1:
		if (i_Collecting_Cake >= 500)
			Max_Collecting_Cake = 700;
	}
	//	EatCake();
	//	CrashHurdle();
	/// 배경 반복 /////////
	BackGround_Setting();

	/// 플레이어 점프, 슬라이딩 /////////

	Condition_Process(dt);
	B_time -= dt;
	opacity_time -= dt;
	if (A_Scale >= 0.8f)
		A_time -= dt;

	JumpProcess();

	if (isSlide && direction == 0)
	{
		C_1->setRotation(270);
		C_1->setPosition(C_1->getPositionX(), y - 70);
	}
	else
	{
		C_1->setRotation(0);
		C_1->setPosition(C_1->getPositionX(), y);
	}
	time_label -= dt;

	if (isStart != true)
	{
		opacity_Button();
	}
	if (C_1->getPositionY() <= -100)
	{
		isClear = true;
		isPause = true;
		Crush_Fail();
	}
}
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_Z)
	{
		if (n_JumpCount < 2)
		{
			DoJump();
			isJump = true;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_X)
	{
		isSlide = true;
		C_animation(4);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		isPause = true;
		Check_Star();
		if (iStar > 0)
			crushClear();
		else if (iStar <= 0)
			Crush_Fail();
		isClear = true;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		isAlice[2] = true;
		if (SlowTime >= 0.0f)
			SlowTime = 5.0f;
		FastTime = 5.0f;
		speed = -1200;
		if (Alice_Condition != 2)
			Alice_Condition = 4;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		i_Collecting_Cake += 50;
	}
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_X)
	{
		isSlide = false;
		C_animation(1);
	}
}

bool HelloWorld::onContactBegin(PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	if ((200000 != a->getCollisionBitmask() || 200000 != b->getCollisionBitmask()))
	{
		for (int i = 0; Hurdle[i] != NULL; i++)
		{
			if ((1 == a->getCollisionBitmask() && i + 3 == b->getCollisionBitmask()) ||
				(i + 3 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
			{
				isCrushHurdle = true;
				if (isHurdle[i] == true && Alice_Condition == 1 && isFiver[5] == false && !isAlice[1] && !isAlice[2] && !isAlice[3])
				{
					Heart[NowHeart]->setTexture(CCTextureCache::sharedTextureCache()->addImage(StringUtils::format("Texture/Object/Heart/None_Heart.png")));
					Hurdle[i]->getPhysicsBody()->removeFromWorld();
					if (Hurdle[i]->getTag() == 2)
						h_Repeat = 2;
					for (int j = 0; j < h_Repeat; j++)
					{
						/*		if (isFiver[5] = true)
								{
								Hurdle[i + j]->runAction(MoveBy::create(1.0f, Vec2(600, 600)));
									Hurdle[i + j]->runAction(RotateBy::create(2.0f, Vec2(300, 0)));

								}*/
						Hurdle[i + j]->setOpacity(127);
						isHurdle[i + j] = false;
						if (j == h_Repeat)
							i += j;
					}

					h_Repeat = 1;

					Alice_Condition = 3;
					isAlice[3] = true;
					B_time = 3.0f;
					NowHeart -= 1;
					if (NowHeart == -1)
						Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0f, HelloWorld::createScene()));
				}
			}
		}
		for (int i = 0; cake[i] != NULL; i++)
		{

			if ((1 == a->getCollisionBitmask() && i + 10000 == b->getCollisionBitmask()) ||
				(i + 10000 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
			{

				isCrushCake = true;
				if (isCake[i] == true)
				{
					//cake[i]->setVisible(false);
					isCake[i] = false;
					cake[i]->getPhysicsBody()->removeFromWorld();

					if (cake[i]->getTag() == 1)
					{
						i_Collecting_Cake += 1;
						cake[i]->runAction(Spawn::create(FadeOut::create(0.3f), ScaleTo::create(0.5f, 1.0f), MoveBy::create(2.0f, Vec2(0, 800)), NULL));
						//cake[i]->runAction(Sequence::create(ScaleTo::create(0.1f, 0.8f), ScaleTo::create(0.1f, 0.0f), NULL));

					
						//CakeParticle = ParticleSystemQuad::create("Texture/Particle/CakeParticle.plist");
						//CakeParticle->setPosition(cake[i]->getPosition());
						//CakeParticle->setScale(0.1f);
						//CakeParticle->setLife(1.0f);
						//CakeParticle->setGlobalZOrder(0);
						///*		CakeParticle->setSpeed(500);*/
						////				CakeParticle->setAngle(300);
						//this->addChild(CakeParticle);
						
					}
					if (cake[i]->getTag() == 2)
					{
						if (isFiver[5])
						{
							if (plusArr >= 30)
								plusArr = 0;
							i_Collecting_Cake += 1;
							plusCoin[plusArr] = Label::createWithTTF("+1", "fonts/Marker Felt.ttf", 36);
							plusCoin[plusArr]->setPosition(Collecting_Cake->getPositionX() + 100, Collecting_Cake->getPositionY());
							this->addChild(plusCoin[plusArr]);
							plusCoin[plusArr]->runAction(Spawn::create(FadeOut::create(0.3f), ScaleTo::create(0.3f, 1.0f), MoveBy::create(3.6f, Vec2(1200, 0)), NULL));
							Collecting_Coin->runAction(Sequence::create(Spawn::create(ScaleTo::create(0.1f, 1.3f), MoveTo::create(0.2f, Vec2(203, 435)), NULL), (Spawn::create(ScaleTo::create(0.2f, 1.0f), NULL)), NULL));
							Collecting_Cake->runAction(Sequence::create(Spawn::create(ScaleTo::create(0.1f, 1.3f), MoveTo::create(0.2f, Vec2(203, 503)), NULL), (Spawn::create(ScaleTo::create(0.2f, 1.0f), NULL)), NULL));
						}
						if (plusArr >= 30)
							plusArr = 0;
						cake[i]->setPosition(C_1->getPositionX(), C_1->getPositionY() + 100);
						cake[i]->runAction(Spawn::create(FadeOut::create(0.3f), ScaleTo::create(0.3f, 0.8f), MoveBy::create(2.1f, Vec2(0, 700)), NULL));
						i_Collecting_Coin += 1;

						plusCoin[plusArr] = Label::createWithTTF("+1", "fonts/Marker Felt.ttf", 36);
						plusCoin[plusArr]->setPosition(C_1->getPositionX() + 50, C_1->getPositionY() + 100);
						this->addChild(plusCoin[plusArr]);
						plusCoin[plusArr]->runAction(Spawn::create(FadeOut::create(0.3f), ScaleTo::create(0.3f, 1.0f), MoveBy::create(2.1f, Vec2(0, 700)), NULL));

						if (plusArr >= 30)
							plusArr = 0;
						plusCoin[plusArr] = Label::createWithTTF("+1", "fonts/Marker Felt.ttf", 36);
						plusCoin[plusArr]->setPosition(Collecting_Coin->getPositionX() + 50, Collecting_Coin->getPositionY());
						plusCoin[plusArr]->runAction(Spawn::create(FadeOut::create(0.3f), ScaleTo::create(0.3f, 1.3f), MoveBy::create(3.6f, Vec2(1200, 0)), NULL));
						this->addChild(plusCoin[plusArr]);
					}

					if (cake[i]->getTag() >= 3)
					{
						cake[i]->setVisible(false);
						for (int j = 3; j < 8; j++)
						{
							if (cake[i]->getTag() == j)
							{
								isFiver[j - 3] = true;
								Fiver[j - 3]->setVisible(true);
							}
						}
						for (int l = 0; l < 5; l++)
							if (isFiver[l] == true)
								i_Fiver += 1;
						if (i_Fiver >= 5)
						{
							FiverTime = 5.0f;
							isFiver[5] = true;
						}
						i_Fiver = 0;
					}
				}
			}
		}
		for (int i = 0; item[i] != NULL; i++)
		{
			if ((1 == a->getCollisionBitmask() && i + 20000 == b->getCollisionBitmask()) ||
				(i + 20000 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
			{
				isCrushItem = true;
				if (isItem[i] == true)
				{
					switch (item[i]->getTag())
					{
					case bigger:
						item[i]->setVisible(false);
						isItem[i] = false;
						isAlice[1] = true;
						Alice_Condition = 2;
						A_time = 5.0f;
						break;
					case teemo:
						item[i]->setVisible(false);
						isItem[i] = false;
						TeemoTime = 15.0f;
						Teemo->setVisible(true);
						break;
					case fast:
						item[i]->setVisible(false);
						isItem[i] = false;
						isAlice[2] = true;
						if (SlowTime >= 0.0f)
							SlowTime = 5.0f;
						FastTime = 5.0f;
						speed = -1200;
						if (Alice_Condition != 2)
							Alice_Condition = 4;
						break;
					case slow:
						item[i]->setVisible(false);
						isItem[i] = false;
						if (FastTime >= 0.0f)
							FastTime = 5.0f;
						SlowTime = 5.0f;
						speed = -300;
						break;
					}
					item[i]->getPhysicsBody()->removeFromWorld();
				}
			}
		}
		if (1 == a->getCollisionBitmask() && 100000 == b->getCollisionBitmask() ||
			100000 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask() && isClear == false)
		{
			isPause = true;
			Check_Star();
			if (iStar > 0)
				crushClear();
			else if (iStar <= 0)
				Crush_Fail();
			isClear = true;
			/*Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, HelloWorld::createScene()));*/
		}
		if ((1 == a->getCollisionBitmask() && 200000 == b->getCollisionBitmask()) ||
			(200000 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()) && isCrush == false)
		{
			isCrush = true;
		}
		CCLOG("%d %d", a->getCollisionBitmask(), b->getCollisionBitmask());
		isCrushCake = false;
		isCrushHurdle = false;
		isCrushItem = false;
	}
	return true;
}
bool HelloWorld::onContactEnded(PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();
	if ((1 == a->getCollisionBitmask() && 200000 == b->getCollisionBitmask()) ||
		(200000 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()) && isCrush == true)
	{
		if(y == y_base - 1)
			isCrush = false;
	}
	CCLOG("E%d %d", a->getCollisionBitmask(), b->getCollisionBitmask());
	return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* _event)
{
	/// jump_Slide //////////
	if (slide_Button->getBoundingBox().containsPoint(touch->getLocation()))
	{
		slide_Button->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_SlideButton.png"));
		isSlide = true;
	}
	/*if (jump_Button->getBoundingBox().containsPoint(touch->getLocation()))
	{
		jump_Button->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_JumpButton.png"));
		if (n_JumpCount < 2)
			DoJump();
	}*/
	/// 팝업창 /////////

	if (stop_BackGround->isVisible())
	{
		if (option->getBoundingBox().containsPoint(touch->getLocation()))
		{
			option->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_option.png"));
			SimpleAudioEngine::getInstance()->playEffect("btClick.wav", false);
		}
		if (resume->getBoundingBox().containsPoint(touch->getLocation()))
		{
			resume->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_Resume.png"));
			SimpleAudioEngine::getInstance()->playEffect("btClick.wav", false);
		}
		if (rePlay->getBoundingBox().containsPoint(touch->getLocation()))
		{
			rePlay->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_rePlay.png"));
			SimpleAudioEngine::getInstance()->playEffect("btClick.wav", false);
		}
		if (stop->getBoundingBox().containsPoint(touch->getLocation()))
		{
			stop->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/p_stop.png"));
			SimpleAudioEngine::getInstance()->playEffect("btClick.wav", false);
		}
	}



	//	LabelTypingEffect::typeMessage(story, "여긴어디지?", 0.1f);
		//scheduleUpdate();
		//this->schedule(schedule_selector(HelloWorld::MoveCake_Stick), 1.0f / 60.0f);
	CCLOG("%f, %f", touch->getLocation().x, touch->getLocation().y);
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event* _event)
{

}
void HelloWorld::onTouchEnded(Touch* touch, Event* _event)
{
	slide_Button->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/SlideButton.png"));
	//jump_Button->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/JumpButton.png"));
	isSlide = false;
	//if (stop_Button->getBoundingBox().containsPoint(touch->getLocation()))
	//{

	//}

	if (Skip->getBoundingBox().containsPoint(touch->getLocation()))
	{
		isStart = true;
		scheduleUpdate();
		C_1->setVisible(true);
		_script->setVisible(false);
	}
	if (!(stop_BackGround->isVisible()))
	{
		if (isStart == false)
		{
			switch (Chapter)
			{
			case 1:
				switch (Stage)
				{
				case 1:
					switch (ing_Messege)
					{
					case 1:
						story->setPosition(620, 360);
						//		story->setScale(1.5f);
						story->setZOrder(14.0f);
						NickName->setString("앨리스");
						LabelTypingEffect::typeMessage(story, "따스한 햇볕이 내리는 오후 앨리스는 집에서 동화책을 읽고 있다. ", 0.05f, Color3B::WHITE);
						break;
					case 2:
						story->setPosition(720, 80);
						story->setZOrder(11.0f);
						_script_BackGround2->runAction(FadeOut::create(1.0f));
						LabelTypingEffect::typeMessage(story, "(똑 똑 똑)", 0.2f, Color3B::BLACK);
						break;
					case 3:
						Alice->runAction(FadeIn::create(0.5f));
						LabelTypingEffect::typeMessage(story, "어? 누가 왔나 보네.", 0.1f, Color3B::WHITE);
						break;
					case 4:
						Alice->setOpacity(127);
						LabelTypingEffect::typeMessage(story, "(끼익)", 0.2f, Color3B::BLACK);
						break;
					case 5:
						_script_BackGround3->runAction(FadeOut::create(1.0f));
						Alice->runAction(FadeIn::create(0.5f));
						LabelTypingEffect::typeMessage(story, "뭐야? 아무도 없잖아!", 0.2f, Color3B::WHITE);
						break;
					case 6:
						Alice->runAction(FadeTo::create(0.5f, 127));
						rabbit->runAction(FadeIn::create(1.0f));
						LabelTypingEffect::typeMessage(story, "신기하게 생긴 토끼가 지나간다", 0.05f, Color3B::BLACK);
						break;
					case 7:
						rabbit->runAction(FadeTo::create(0.5f, 127));
						Alice->runAction(FadeIn::create(1.0f));
						LabelTypingEffect::typeMessage(story, "저 토끼 신기하다! 따라가 봐야지~ ", 0.1f, Color3B::WHITE);
						break;
					case 8:
						Alice->runAction(FadeTo::create(0.5f, 127));
						rabbit->runAction(FadeOut::create(1.0f));
						LabelTypingEffect::typeMessage(story, "토끼는 계속 도망치다가 나무 안에 있는 토끼굴속으로 들어갔다.", 0.05f, Color3B::BLACK);
						break;
					case 9:
						Alice->runAction(FadeTo::create(0.5f, 255));
						LabelTypingEffect::typeMessage(story, "나무 속으로 도망가버렸네, 어떡하지?", 0.05f, Color3B::WHITE);
						break;
					case 10:
						LabelTypingEffect::typeMessage(story, "몰라 나도 들어가자!", 0.05f, Color3B::WHITE);
						break;
					case 11:
						_script_BackGround1->runAction(FadeOut::create(1.0f));
						_script_BackGround2->runAction(Sequence::create(FadeIn::create(1.0f), FadeOut::create(1.0f), NULL));
						script_BackGround->setVisible(false);
						LabelTypingEffect::typeMessage(story, ".", 0.05f, Color3B::WHITE);
						break;
					case 12:
						LabelTypingEffect::typeMessage(story, "음....여긴어디지? 분명 나무속으로 들어온거 같은데?", 0.05f, Color3B::WHITE);
						break;
					case 13:
						NickName->setString("토끼");
						Alice->runAction(FadeTo::create(0.5f, 127));
						rabbit2->runAction(FadeTo::create(0.5f, 255));
						LabelTypingEffect::typeMessage(story, "여긴 \"이상한 나라\"라는 곳이야", 0.05f, Color3B::WHITE);
						break;
					case 14:
						NickName->setString("앨리스");
						Alice->runAction(FadeTo::create(0.5f, 255));
						rabbit2->runAction(FadeTo::create(0.5f, 127));
						LabelTypingEffect::typeMessage(story, "뭐야 토끼가 말을 하네?", 0.05f, Color3B::WHITE);
						break;
					case 15:
						NickName->setString("토끼");
						Alice->runAction(FadeTo::create(0.5f, 127));
						rabbit2->runAction(FadeTo::create(0.5f, 255));
						LabelTypingEffect::typeMessage(story, "내가 말했잖아 여긴 이상한 나라라고 너희 세상에서는 상상할 수 없는 것 들이 수없이 많을껄?", 0.05f, Color3B::WHITE);
						break;
					case 16:
						NickName->setString("앨리스");
						Alice->runAction(FadeTo::create(0.5f, 255));
						rabbit2->runAction(FadeTo::create(0.5f, 127));
						LabelTypingEffect::typeMessage(story, "진짜 이상한 곳이네. 토끼야 여기서 나가려면 어떻게 해야 되?", 0.05f, Color3B::WHITE);
						break;
					case 17:
						NickName->setString("토끼");
						Alice->runAction(FadeTo::create(0.5f, 127));
						rabbit2->runAction(FadeTo::create(0.5f, 255));
						LabelTypingEffect::typeMessage(story, "어? 벌써 시간이 이렇게 됐네", 0.05f, Color3B::WHITE);
						break;
					case 18:
						NickName->setString("앨리스");
						Alice->runAction(FadeTo::create(0.5f, 255));
						rabbit2->runAction(FadeTo::create(0.5f, 0));
						LabelTypingEffect::typeMessage(story, "토끼야 잠깐만 기다려!", 0.05f, Color3B::WHITE);
						break;
					case 19:
						isStart = true;
						scheduleUpdate();
						C_1->setVisible(true);
						_script->setVisible(false);
						break;
						/*	case 5:
						LabelTypingEffect::typeMessage(story, "", 0.1f, Color3B::WHITE);
						break;*/
					default:
						break;
					}
					break;
				}
			}
		}
		ing_Messege += 1;
	}
	if (stop_BackGround->isVisible())
	{
		resume->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/resume.png"));
		rePlay->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/rePlay.png"));
		stop->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/stop.png"));
		option->setTexture(Director::getInstance()->getTextureCache()->addImage("Texture/Object/UI/option.png"));
		if (resume->getBoundingBox().containsPoint(touch->getLocation()))
		{
			stop_BackGround->setVisible(false);
			//Director::getInstance()->getScheduler()->resumeTarget(this);
			isPause = false;
			C_animation(1);
		}
		if (rePlay->getBoundingBox().containsPoint(touch->getLocation()))
		{
			Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, HelloWorld::createScene()));
		}
		if (stop->getBoundingBox().containsPoint(touch->getLocation()))
		{
			Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, New::NewScene()));
		}
	}

}
