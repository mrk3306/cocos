#include "Ally.h"

USING_NS_CC;

Ally::Ally()
:max_life(1)
{
    setLife(max_life);
    setPower(1);
    setSpeed(15.0f);
    setEffectiveArea(Director::getInstance()->getWinSize());
    setTag(kTagAlly);
    setZOrder(kZOrderMovableSprite);
    setStatus(Ally::Status::Normal);
    setSpecialEffect(BattleManager::SpecialEffect::Nothing);
}

Ally::~Ally()
{
}

bool Ally::init()
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

void Ally::update(float delta)
{
    if (getPositionX() < 0 || getPositionX() > getEffectiveArea().width || getPositionY() < 0 || getPositionY() > getEffectiveArea().height) {
        removeFromParent();
    }

    if (life <= 0)
    {
        destroy();
    }
}

void Ally::hurt(int power, BattleManager::SpecialEffect sp)
{
    life -= power;
}

void Ally::recovery(int power)
{
    life += power;
    if (life > max_life)
    {
        life = max_life;
    }
}

void Ally::destroy()
{
    removeFromParent();
}

void Ally::onActionCompletedThenRemove(Object* sender)
{
    static_cast<Node*>(sender)->removeFromParent();
}
