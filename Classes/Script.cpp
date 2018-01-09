#include "HelloWorldScene.h"
#include "LabelTypingEffect.h"
void HelloWorld::Stage1(Label* label)
{

}
void HelloWorld::opacity_Button()
{
	static int opacity_Direc = 0;
	if (opacity_Direc == 0)
	{
		Button->setOpacity(Button->getOpacity() - 1.0f);
		if (Button->getOpacity() <= 127)
			opacity_Direc = 1;
	}
	if (opacity_Direc == 1)
	{
		Button->setOpacity(Button->getOpacity() + 1.0f);
		if (Button->getOpacity() >= 254)
			opacity_Direc = 0;
	}
}