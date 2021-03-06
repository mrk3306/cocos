#include "Enemy08.h"

USING_NS_CC;

Enemy08::Enemy08()
{
    setTag(kTagLife);
    score = 50;
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

void Enemy08::destroy()
{
    
    Enemy::destroy();
}
