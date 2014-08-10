#include "LifeRight.h"

USING_NS_CC;

LifeRight::LifeRight()
{
}

LifeRight::~LifeRight()
{
}

const char* LifeRight::getImageFileName()
{
    return "life_left.png";
}

void LifeRight::update(float delta)
{

}

void LifeRight::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void LifeRight::touchMoved(Touch *touch)
{
}

void LifeRight::touchEnded(Touch *touch)
{

}
