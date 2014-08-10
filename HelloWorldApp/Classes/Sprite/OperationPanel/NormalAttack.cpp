#include "NormalAttack.h"

USING_NS_CC;

NormalAttack::NormalAttack()
{
}

NormalAttack::~NormalAttack()
{
}

const char* NormalAttack::getImageFileName()
{
    return "weapon_a.png";
}

void NormalAttack::touchBegan(Touch *touch)
{
    auto target = dynamic_cast<Player*>(getTarget());
    target->attack();
}

void NormalAttack::touchMoved(Touch *touch)
{
}

void NormalAttack::touchEnded(Touch *touch)
{
}
