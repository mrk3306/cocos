#include "Enemy01.h"

USING_NS_CC;

Enemy01::Enemy01()
:winSize(Director::getInstance()->getWinSize())
{
    score = 10;
}

Enemy01::~Enemy01()
{
    
}

const char* Enemy01::getImageFileName()
{
    return "enemy01.png";
}


void Enemy01::fever()
{
    this->schedule(schedule_selector(Enemy01::setPoint));
}

void Enemy01::setPoint(float dt)
{
    
    auto target = static_cast<Player*>(getTarget());
    if( getPositionY() > (winSize.height * 0.8)){
        this->setPosition(getPositionX(), (getPositionY()-10));
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
                this->setPosition((getPositionX()-10), (getPositionY()-12));
            }else{
                this->setPosition((getPositionX()+10), (getPositionY()-12));
            }

        
        }else{
            this->setPosition(target->getPositionX(), (getPositionY()-10));
        }

        
    }
}

void Enemy01::move()
{
	auto action = MoveTo::create(3.0f, Point(getPositionX(), 0));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy01::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy01::update(float delta)
{

    if (getPositionY() > 0) {
        //auto reward_manager = RewardManager::getInstance();
        //reward_manager->setLife(reward_manager->getLife()-0.5);
        //log("%d",getPositionY());
    }
    
}


void Enemy01::attack()
{
}

void Enemy01::attack(Point from, Point to)
{
}

void Enemy01::specialAttack()
{
}

void Enemy01::specialAttack(Point from, Point to)
{
}

void Enemy01::destroy()
{
    //auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    //cuptured_enemy->setPosition(getPositionX(), getPositionY());
    //getParent()->addChild(cuptured_enemy);

    Enemy::destroy();
}
