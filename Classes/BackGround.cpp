#include"HelloWorldScene.h"

void HelloWorld::BackGround_Setting()
{
	float x1 = backGround1->getPositionX();
	float x2 = backGround2->getPositionX();

	if (x2 < 0)
	{
		x1 = x2;
		x2 = x1 + backGround1->getContentSize().width;
	}

	backGround1->setPosition(x1 - 10.0f, 0);
	backGround2->setPosition(x2 - 10.0f, 0);
	switch (point::get()->Chapter)
	{
	case 1:
	case 2:
	}
}