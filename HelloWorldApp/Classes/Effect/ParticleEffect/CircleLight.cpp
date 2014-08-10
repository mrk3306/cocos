#include "CircleLight.h"

USING_NS_CC;

CircleLight::CircleLight()
{
}

CircleLight::~CircleLight()
{
}

const char* CircleLight::getImageFileName()
{
    return "circle_light.plist";
}

void CircleLight::runAction()
{
    auto particle = getParticle();
    auto invoke   = ScaleTo::create(0.3f, 5.5f);
    auto revoke   = ScaleTo::create(0.6f, 0);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(CircleLight::onActionCompletedThenRemove, this));

    particle->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(particle);
    particle->runAction(Sequence::create(invoke, revoke, actionCompleted, nullptr));
}
