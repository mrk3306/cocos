#include "Enemy05.h"

USING_NS_CC;

Enemy05::Enemy05()
{
   setTag(kTagBomb);
   score = 50;
}

Enemy05::~Enemy05()
{
}

const char* Enemy05::getImageFileName()
{
    return "bomb.png";
}

void Enemy05::move()
{
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy05::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy05::destroy()
{
    
    Enemy::destroy();
}
