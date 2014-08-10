#include "Enemy06.h"

USING_NS_CC;

Enemy06::Enemy06()
{
    score = 10;
}

Enemy06::~Enemy06()
{
}

const char* Enemy06::getImageFileName()
{
    return "enemy06.png";
}

void Enemy06::move()
{
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy06::onActionCompletedThenRemove, this));
    
	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy06::attack()
{
}

void Enemy06::attack(Point from, Point to)
{
}

void Enemy06::specialAttack()
{
}

void Enemy06::specialAttack(Point from, Point to)
{
}

void Enemy06::destroy()
{
    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);
    
    Enemy::destroy();
}
