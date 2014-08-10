#include "ArrowUnder.h"

USING_NS_CC;

ArrowUnder::ArrowUnder()
{
}

ArrowUnder::~ArrowUnder()
{
}

const char* ArrowUnder::getImageFileName()
{
    return "under.png";
}

void ArrowUnder::update(float delta)
{
    auto target = static_cast<Player*>(getTarget());
    if (target->getPositionY() <= 0) {
        return;
    }

	auto action = MoveTo::create(0.02f, Point(target->getPositionX(), target->getPositionY() - target->getSpeed()));
    action->setTag(getTag());

    target->runAction(action);
}

void ArrowUnder::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void ArrowUnder::touchMoved(Touch *touch)
{
}

void ArrowUnder::touchEnded(Touch *touch)
{
    unscheduleUpdate();
    getTarget()->stopActionByTag(getTag());
}
