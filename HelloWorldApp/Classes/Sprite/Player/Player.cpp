
#include "Player.h"

USING_NS_CC;

Player::Player()
{
    max_life = 100;

    setLife(max_life);
    setSpeed(15.0f);
    setDuration(1.0f);
    setEffectiveArea(Director::getInstance()->getWinSize());

    setTag(kTagPlayer);
    setZOrder(kZOrderMovableSprite);
}

Player::~Player()
{
}

bool Player::init()
{
    if (Sprite::initWithFile(getImageFileName()))
    {
        scheduleUpdate();
        return true;
    }
    else
    {
        return false;
    }
}

void Player::update(float delta)
{
    setDuration(getDuration()-delta);
    if (getStatus() == Status::Unbreakable && getDuration() <= 0)
    {
        setOpacity(255);
        setStatus(Status::Normal);
    }

    if (getStatus() == Status::Destroyed && getDuration() <= 0)
    {
        setLife(max_life);
        setVisible(true);
        setDuration(1.5f);
        setStatus(Status::Unbreakable);
    }

    if (life <= 0)
    {
        //log("ゲームオーバー");
        //destroy();
    }
}

void Player::hurt(int power, BattleManager::SpecialEffect sp)
{

    if (getStatus() == Status::Unbreakable && getDuration() <= 0)
    {
        return;
    }
    //life -= power;

    setOpacity(50);
    setDuration(1.0f);
    setStatus(Status::Unbreakable);
    auto effect = Ignite::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();
    
    
}

bool Player::playerStatus()
{

    if (getStatus() == Status::Unbreakable || getStatus() == Status::Destroyed)
    {
        return false;
    }else{
        return true;
    }
}

void Player::recovery(int power)
{
    //life += power;
    //if (life > max_life)
    //{
    //    life = max_life;
    //}
}

void Player::destroy()
{
    if (getStatus() == Status::Unbreakable || getStatus() == Status::Destroyed)
    {
        return;
    }

    auto effect = BurnOut::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();

    setDuration(1.0f);
    setStatus(Status::Destroyed);
    setVisible(false);
}
