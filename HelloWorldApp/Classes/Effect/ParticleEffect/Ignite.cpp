#include "Ignite.h"

USING_NS_CC;

Ignite::Ignite()
{
}

Ignite::~Ignite()
{
}

const char* Ignite::getImageFileName()
{
    return "burn_out.plist";
}

void Ignite::runAction()
{
    auto particle = getParticle();
    auto invoke   = ScaleTo::create(0.2f, 0.3f);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Ignite::onActionCompletedThenRemove, this));

    particle->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(particle);
    particle->runAction(Sequence::create(invoke, actionCompleted, nullptr));
}
