#include "Enemy02.h"

USING_NS_CC;

Enemy02::Enemy02()
{
    score = 50;
}

Enemy02::~Enemy02()
{
}

const char* Enemy02::getImageFileName()
{
    return "enemy02.png";
}

void Enemy02::update(float delta)
{
    Enemy::update(delta);

    if (getStatus() == Status::Captured)
    {
        auto target = getTarget();
        if (getBoundingBox().containsPoint(target->getPosition()))
        {
            destroy();
        }
        else
        {
            captured();
        }
    }
}

void Enemy02::move()
{
}

void Enemy02::attack()
{
}

void Enemy02::attack(Point from, Point to)
{
}

void Enemy02::specialAttack()
{
}

void Enemy02::specialAttack(Point from, Point to)
{
}

void Enemy02::captured()
{
    auto target = getTarget();
    MoveTo* move = MoveTo::create(0.5f, target->getPosition());
    ActionInterval* actionRotate = RotateBy::create(0.5f, 360);
    auto spawn = Spawn::createWithTwoActions(actionRotate, move);

    runAction(spawn);
}

void Enemy02::hurt(int power, BattleManager::SpecialEffect sp)
{
    if (getStatus() == Status::Unbreakable)
    {
        return;
    }

    switch (sp)
    {
    case BattleManager::Capture:
        setStatus(Status::Captured);
        break;

    default:
        break;
    }
}

void Enemy02::destroy()
{
    removeFromParent();

    auto reward_manager = RewardManager::getInstance();
    reward_manager->setScore(reward_manager->getScore() + score);
}
