#include "ArrowTop.h"

USING_NS_CC;

ArrowTop::ArrowTop()
{
}

ArrowTop::~ArrowTop()
{
}

const char* ArrowTop::getImageFileName()
{
    return "top.png";
}

void ArrowTop::update(float delta)
{
    auto target = static_cast<Player*>(getTarget());
    if (target->getPositionY() >= target->getEffectiveArea().height) {
        return;
    }

	auto action = MoveTo::create(0.02f, Point(target->getPositionX(), target->getPositionY() + target->getSpeed()));
    action->setTag(getTag());

    target->runAction(action);
}

void ArrowTop::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void ArrowTop::touchMoved(Touch *touch)
{
}

void ArrowTop::touchEnded(Touch *touch)
{
    unscheduleUpdate();
    getTarget()->stopActionByTag(getTag());
}
