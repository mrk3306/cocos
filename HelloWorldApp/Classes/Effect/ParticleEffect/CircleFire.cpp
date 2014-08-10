#include "CircleFire.h"

USING_NS_CC;

CircleFire::CircleFire()
{
}

CircleFire::~CircleFire()
{
}

const char* CircleFire::getImageFileName()
{
    return "circle_fire.plist";
}

void CircleFire::runAction()
{
    auto particle = getParticle();
    auto invoke   = ScaleTo::create(0.3f, 1.5f);
    auto revoke   = ScaleTo::create(0.6f, 0);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(CircleFire::onActionCompletedThenRemove, this));

    particle->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(particle);
    particle->runAction(Sequence::create(invoke, revoke, actionCompleted, nullptr));
}
