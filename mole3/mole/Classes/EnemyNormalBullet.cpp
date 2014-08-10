#include "EnemyNormalBullet.h"

USING_NS_CC;

EnemyNormalBullet::EnemyNormalBullet()
{
    setDuration(9999.9f);
    setSpeed(5.0f);
}

EnemyNormalBullet::~EnemyNormalBullet()
{
}

const char* EnemyNormalBullet::getImageFileName()
{
    return "bullet.png";
}

void EnemyNormalBullet::update(float delta)
{
    
    Enemy::update(delta);

	auto action = MoveTo::create(0.02f, Point(getPositionX() - getSpeed(), getPositionY()));
    action->setTag(getTag());

    runAction(action);
}

void EnemyNormalBullet::move()
{
}

void EnemyNormalBullet::destroy()
{
    auto effect = Ignite::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();

    removeFromParent();
}

void EnemyNormalBullet::attack()
{
}

void EnemyNormalBullet::attack(Point from, Point to)
{
}

void EnemyNormalBullet::specialAttack()
{
}

void EnemyNormalBullet::specialAttack(Point from, Point to)
{
}
