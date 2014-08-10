#include "ArrowLeft.h"

USING_NS_CC;

ArrowLeft::ArrowLeft()
{
}

ArrowLeft::~ArrowLeft()
{
}

const char* ArrowLeft::getImageFileName()
{
    return "left.png";
}

void ArrowLeft::update(float delta)
{
    auto target = static_cast<Player*>(getTarget());
    if (target->getPositionX() <= 0) {
        return;
    }

	auto action = MoveTo::create(0.02f, Point(target->getPositionX() - target->getSpeed(), target->getPositionY()));
    action->setTag(getTag());

    target->runAction(action);
}

void ArrowLeft::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void ArrowLeft::touchMoved(Touch *touch)
{
}

void ArrowLeft::touchEnded(Touch *touch)
{
    unscheduleUpdate();
    getTarget()->stopActionByTag(getTag());
}
