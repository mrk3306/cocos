#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
    max_life = 1;
    score    = 10;

    setLife(max_life);
    setPower(1);
    setSpeed(15.0f);
    setDuration(0.2f);
    setEffectiveArea(Director::getInstance()->getWinSize());

    setTag(kTagEnemy);
    setZOrder(kZOrderMovableSprite);
    setStatus(Enemy::Status::Unbreakable);
    setSpecialEffect(BattleManager::SpecialEffect::Nothing);
}

Enemy::~Enemy()
{
}

bool Enemy::init()
{
    auto batchNode = ResourceManager::getInstance()->getBatchNode(getImageFileName());
    if (batchNode && Sprite::initWithTexture(batchNode->getTexture()))
    {
        scheduleUpdate();
        return true;
    }
    else
    {
        //CC_SAFE_DELETE(batchNode);
        return false;
    }
}

void Enemy::update(float delta)
{
    setDuration(getDuration()-delta);
    if (getStatus() == Status::Unbreakable && getDuration() <= 0)
    {
        setOpacity(255);
        setStatus(Status::Normal);
    }

    if (getPositionX() < 0 || getPositionX() > getEffectiveArea().width || getPositionY() < 0 || getPositionY() > getEffectiveArea().height) {
        removeFromParent();
    }

    if (life <= 0)
    {
        destroy();
    }
        
}

void Enemy::hurt(int power, BattleManager::SpecialEffect sp)
{
    if (getStatus() == Status::Unbreakable)
    {
        return;
    }
    life -= power;

    setOpacity(50);
    setDuration(0.2f);
    setStatus(Status::Unbreakable);
}

void Enemy::recovery(int power)
{
    life += power;
    if (life > max_life)
    {
        life = max_life;
    }
}

void Enemy::destroy()
{

    auto effect = BurnOut::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();
    removeFromParent();

}

void Enemy::setLife()
{

    
    
    
    
    
    
}

void Enemy::onActionCompletedThenRemove(Object* sender)
{
    static_cast<Node*>(sender)->removeFromParent();
}
