#include"HelloWorldScene.h"

void HelloWorld::Crashing()
{
	for (int i = 0; i < 2; i++)
	{
		Crash[i] = Sprite::create("Texture/Object/Cake/Cake.png");
		Crash[i]->setPosition(800, 800);
		Crash[i]->setAnchorPoint(Point(0.0f, 0.0f));
		Crash[i]->setVisible(false);
		this->addChild(Crash[i]);
		CakeBody = PhysicsBody::createCircle(cake[i]->getContentSize().width / 3, PhysicsMaterial(0, 0, 0));
		CakeBody->setDynamic(false);
		CakeBody->setCollisionBitmask(1000000);
		CakeBody->setContactTestBitmask(true);
		Crash[i]->setPhysicsBody(CakeBody);
		Crash[i]->setVisible(true);
	}
}