#include "Star.h"

USING_NS_CC;

Star::Star()
{
    score = 10;
    setTag(kTagStar);
}

Star::~Star()
{
}

const char* Star::getImageFileName()
{
    return "star.png";
}

void Star::move()
{
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Star::onActionCompletedThenRemove, this));
    
	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Star::attack()
{
}

void Star::attack(Point from, Point to)
{
}

void Star::specialAttack()
{
}

void Star::specialAttack(Point from, Point to)
{
}

void Star::destroy()
{

    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);
    
    Enemy::destroy();
}
