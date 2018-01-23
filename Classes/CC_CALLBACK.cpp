#include"HelloWorldScene.h"
#include"game.h"
#include"SimpleAudioEngine.h"

using namespace CocosDenshion;
void HelloWorld::goHome(Object* pSender)
{
	Scene *scene = TransitionCrossFade::create(1.0f, New::NewScene());
	Director::getInstance()->replaceScene(scene);
}
void HelloWorld::goNext(Object* pSender)
{
	if (Stage < 4)
		point::get()->StageNum += 1;
	else
	{
		point::get()->StageNum = 1;
		point::get()->Chapter += 1;
	}
	Scene *scene = TransitionCrossFade::create(0.5f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(scene);
}
void HelloWorld::goBack(Object* pSender)
{
	Scene *scene = TransitionCrossFade::create(0.5f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(scene);
}
void HelloWorld::CC_StopButton(Object *pSender)
{	
	stop_BackGround->setVisible(true);
	SimpleAudioEngine::getInstance()->playEffect("btClick.wav", false);
	isPause = true;
	//	Director::getInstance()->getScheduler()->pauseTarget(this);
	C_1->stopAllActions();
}