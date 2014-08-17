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

void Enemy06::destroy()
{
    Enemy::destroy();
}
