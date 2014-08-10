#include "BurnOut.h"

USING_NS_CC;

BurnOut::BurnOut()
{
}

BurnOut::~BurnOut()
{
}

const char* BurnOut::getImageFileName()
{
    return "burn_out.plist";
}

void BurnOut::runAction()
{
    auto particle = getParticle();
    auto invoke   = ScaleTo::create(0.3f, 1.5f);
    auto revoke   = ScaleTo::create(0.6f, 0);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(BurnOut::onActionCompletedThenRemove, this));

    particle->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(particle);
    particle->runAction(Sequence::create(invoke, revoke, actionCompleted, nullptr));
}
