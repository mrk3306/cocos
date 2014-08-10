#include "Enemy08.h"

USING_NS_CC;

Enemy08::Enemy08()
{
    score = 10;
    setTag(kTagLife);
}

Enemy08::~Enemy08()
{
}

const char* Enemy08::getImageFileName()
{
    return "life.png";
}

void Enemy08::move()
{
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy08::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy08::attack()
{
}

void Enemy08::attack(Point from, Point to)
{
}

void Enemy08::specialAttack()
{
}

void Enemy08::specialAttack(Point from, Point to)
{
}

void Enemy08::destroy()
{
    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);

    Enemy::destroy();
}
