#include "Enemy04.h"

USING_NS_CC;

Enemy04::Enemy04()
{
    max_life = 3;
    setLife(max_life);
    score = 50;
}

Enemy04::~Enemy04()
{
}

const char* Enemy04::getImageFileName()
{
    return "enemy04.png";
}

void Enemy04::update(float delta)
{
    Enemy::update(delta);
    
}

void Enemy04::move()
{
    /*
    auto winSize = Director::getInstance()->getWinSize();
    float x = getPositionX();
    float y = getPositionY();

    ccBezierConfig bezier;
    bezier.controlPoint_1 = Point(0, winSize.height);
    bezier.controlPoint_2 = Point(0, winSize.height * 0.2);
    bezier.endPosition    = Point(x, y);
    ActionInterval* bezierMove = BezierTo::create(10.0f, bezier);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy04::onActionCompletedThenRemove, this));
                    
    runAction(Sequence::create(bezierMove, actionCompleted, nullptr));
    */
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy04::onActionCompletedThenRemove, this));
    
	runAction(Sequence::create(action, actionCompleted, nullptr));
    
}

void Enemy04::attack()
{
    auto parent = getParent();
    if (parent)
    {

    }
}

void Enemy04::attack(Point from, Point to)
{
}

void Enemy04::specialAttack()
{
}

void Enemy04::specialAttack(Point from, Point to)
{
}
void Enemy04::destroy()
{
    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);
    
    Enemy::destroy();
}
