#include "OperationPanel.h"

USING_NS_CC;

OperationPanel::OperationPanel()
:active(false)
{
    touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(OperationPanel::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(OperationPanel::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(OperationPanel::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

OperationPanel::~OperationPanel()
{
    Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
}

bool OperationPanel::init()
{
    if (Sprite::initWithFile(getImageFileName()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool OperationPanel::onTouchBegan(Touch* touch, Event* event)
{
	if (getBoundingBox().containsPoint(touch->getLocation()))
	{
        touchBegan(touch);
	}

    return true;
}

void OperationPanel::onTouchMoved(Touch* touch, Event* event)
{
    touchMoved(touch);
}

void OperationPanel::onTouchEnded(Touch* touch, Event* event)
{
    touchEnded(touch);
}