#include"HelloWorldScene.h"
#include"game.h"
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