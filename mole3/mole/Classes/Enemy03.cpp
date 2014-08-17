#include "Enemy03.h"

USING_NS_CC;

Enemy03::Enemy03()
:winSize(Director::getInstance()->getWinSize())
{
   score = 50;
}

Enemy03::~Enemy03()
{
}

const char* Enemy03::getImageFileName()
{
    return "enemy03.png";
}
void Enemy03::fever()
{
    this->schedule(schedule_selector(Enemy03::setPoint));
}
void Enemy03::setPoint(float dt)
{
    
    auto target = static_cast<Player*>(getTarget());
    if( getPositionY() > (winSize.height * 0.7)){
        this->setPosition(getPositionX(), (getPositionY()-5));
    }
    else if( getPositionY() <= (target->getPositionY()) ){
        this->setPosition(target->getPositionX(), (getPositionY()-10));
    }
    else{
        
        auto x = target->getPositionX() - getPositionX();
        auto minus = 0;
        if(x < 0){
            x=x*-1;
            minus = 1;
        }
        
        if(x > 5){
            
            if(minus==1){
                this->setPosition((getPositionX()-10), (getPositionY()-8));
            }else{
                this->setPosition((getPositionX()+10), (getPositionY()-8));
            }
            
            
        }else{
            this->setPosition(target->getPositionX(), (getPositionY()-5));
        }
        
        
    }
}
void Enemy03::move()
{
	auto action = MoveTo::create(1.5f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy03::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy03::destroy()
{
    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);
    
    Enemy::destroy();
}
