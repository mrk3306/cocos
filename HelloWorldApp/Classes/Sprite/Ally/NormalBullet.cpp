#include "NormalBullet.h"

USING_NS_CC;

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}

const char* NormalBullet::getImageFileName()
{
    return "bullet.png";
}

void NormalBullet::update(float delta)
{
    Ally::update(delta);

	auto action = MoveTo::create(0.02f, Point(getPositionX() + getSpeed(), getPositionY()));
    action->setTag(getTag());

    runAction(action);
}

void NormalBullet::move()
{
    scheduleUpdate();
}

void NormalBullet::destroy()
{
    auto effect = Ignite::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();

    removeFromParent();
}
