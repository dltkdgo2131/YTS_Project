#include"Loading.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"SingleTone.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

using namespace CocosDenshion;

Scene* Loading::LoadingScene()
{
	auto Scene = Scene::create();
	auto layer = Loading::create();
	Scene->addChild(layer);
	return Scene;
}
Loading::Loading() : _numberOfSprites(47), _numberOfLoadedSprites(0)
{
	//auto size = Director::getInstance()->getWinSize();

	//_labelLoading = Label::createWithTTF("loading...", "fonts/ChocoCookie.ttf", 80);
	//_labelPercent = Label::createWithTTF("%0", "fonts/ChocoCookie.ttf", 80);

	//_labelLoading->setPosition(Vec2(size.width / 2, size.height / 2 - 20));
	//_labelPercent->setPosition(Vec2(size.width / 2, size.height / 2 + 20));

	//this->addChild(_labelLoading);
	//this->addChild(_labelPercent);

	// load texture

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/backGround/Script/Button.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/backGround/Script/Chat.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/backGround/Script/Nick.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/backGround/Script/Skip.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/backGround/Stage1_BackGround.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 5
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Character/Character_1.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Character/Character_Damage_1.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Character/Character_Jume_1.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/Character_Slide_1.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/0.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 10
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/1.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/2.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/3.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Cahracter/4.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Cake/Cake.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 15

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Heart/Heart.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Heart/None_Heart.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Hurdle/Chapter1/bat.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Hurdle/Chapter1/Spider_1.plist", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Hurdle/Chapter1/Table_Chair.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 20

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Bigger.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Fast_Item.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Slow_Item.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Teemo_Item.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Teemo.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 25
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Coin.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Item/Gold_Coin.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/Stick/1_Stick.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/backGround.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Fiver_1.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 30
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Fiver_2.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Fiver_3.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Fiver_4.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Fiver_5.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/JumpButton.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 35
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_JumpButton.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/SlideButton.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_JumpButton.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/option.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_option.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 40

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/Shose.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/rePlay.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_rePlay.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/resume.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_resume.png", CC_CALLBACK_1(Loading::loadingCallBack, this)); // 45
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/stop.png", CC_CALLBACK_1(Loading::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("Texture/Object/UI/p_stop.png", CC_CALLBACK_1(Loading::loadingCallBack, this));

}
void Loading::loadingCallBack(Texture2D *texture)
{
	++_numberOfLoadedSprites;
	//_labelPercent->setString(StringUtils::format("%d ", (int)(((float)_numberOfLoadedSprites / _numberOfSprites) * 100)));
	if ((int)(((float)_numberOfLoadedSprites / _numberOfSprites) * 100) == 100)
	{
		this->setTouchEnabled(true);
		this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	}
	if (_numberOfLoadedSprites == _numberOfSprites)
	{
		//		this->removeChild(_labelLoading, true);
		//		this->removeChild(_labelPercent, true);
	}
}
bool Loading::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Background = Sprite::create("Texture/Loading/BackGround.png");
	Background->setPosition(0, 0);
	Background->setAnchorPoint(Point(0, 0));
	this->addChild(Background);

	Back_Loading = Sprite::create("Texture/Loading/Back_Loading.png");
	Back_Loading->setPosition(90, 40);
	Back_Loading->setScaleX(1.03f);
	Back_Loading->setAnchorPoint(Point(0, 0));
	this->addChild(Back_Loading);

	Loading_Bar = Sprite::create("Texture/Loading/Loading_Bar.png");
	Loading_Bar->setPosition(112.5f, 52.5f);
	Loading_Bar->setAnchorPoint(Point(0, 0));
	Loading_Bar->setScale(0.1f, 0.9f);
	this->addChild(Loading_Bar);

	scheduleUpdate();
	return true;
}

void Loading::update(float dt)
{
	if (Loading_Bar->getScaleX() < 1.0f)
		Loading_Bar->setScaleX(Loading_Bar->getScaleX() + 0.005f);

	if (Loading_Bar->getScaleX() >= 1.0f)
	{
		this->setTouchEnabled(true);
		this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	}
}

bool Loading::onTouchBegan(Touch* touch, Event* _event)
{

	Vec2 location = Vec2(touch->getLocation().x, touch->getLocation().y);
	CCLOG("%f %f", location.x, location.y);

	Scene* pScene = TransitionFade::create(2.0f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(pScene);

	return true;
}

void Loading::onTouchEnded(Touch* touch, Event* _event)
{

}




void Loading::onTouchMoved(Touch* touch, Event* _event)
{

}