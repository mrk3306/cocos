#include "SpecialAttack.h"

USING_NS_CC;

SpecialAttack::SpecialAttack()
{
}

SpecialAttack::~SpecialAttack()
{
}

const char* SpecialAttack::getImageFileName()
{
    return "weapon_b.png";
}

void SpecialAttack::touchBegan(Touch *touch)
{
    auto target = dynamic_cast<Player*>(getTarget());
    target->specialAttack();
}

void SpecialAttack::touchMoved(Touch *touch)
{
}

void SpecialAttack::touchEnded(Touch *touch)
{
}
