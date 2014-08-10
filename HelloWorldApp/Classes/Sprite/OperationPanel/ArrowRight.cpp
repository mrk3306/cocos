#include "ArrowRight.h"

USING_NS_CC;

ArrowRight::ArrowRight()
{
}

ArrowRight::~ArrowRight()
{
}

const char* ArrowRight::getImageFileName()
{
    return "right.png";
}

void ArrowRight::update(float delta)
{
    auto target = static_cast<Player*>(getTarget());
    if (target->getPositionX() >= target->getEffectiveArea().width) {
        return;
    }

	auto action = MoveTo::create(0.02f, Point(target->getPositionX() + target->getSpeed(), target->getPositionY()));
    action->setTag(getTag());

    target->runAction(action);
}

void ArrowRight::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void ArrowRight::touchMoved(Touch *touch)
{
}

void ArrowRight::touchEnded(Touch *touch)
{
    unscheduleUpdate();
    getTarget()->stopActionByTag(getTag());
}
