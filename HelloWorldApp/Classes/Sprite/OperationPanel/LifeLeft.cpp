#include "LifeLeft.h"

USING_NS_CC;

LifeLeft::LifeLeft()
{
}

LifeLeft::~LifeLeft()
{
}

const char* LifeLeft::getImageFileName()
{
    return "life_right.png";
}

void LifeLeft::update(float delta)
{

}

void LifeLeft::touchBegan(Touch *touch)
{
    scheduleUpdate();
}

void LifeLeft::touchMoved(Touch *touch)
{
}

void LifeLeft::touchEnded(Touch *touch)
{

}
