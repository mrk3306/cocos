#include "WarShip.h"

USING_NS_CC;

WarShip::WarShip()
{
}

WarShip::~WarShip()
{
}

const char* WarShip::getImageFileName()
{
    return "war_ship.png";
}

void WarShip::attack()
{
    auto bullet = NormalBullet::createAlly();
    bullet->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(bullet);

    bullet->move();
}

void WarShip::attack(Point from, Point to)
{
}

void WarShip::specialAttack()
{
    auto special = Bomb::createAlly();
    special->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(special);

    special->move();
}

void WarShip::specialAttack(Point from, Point to)
{
}
