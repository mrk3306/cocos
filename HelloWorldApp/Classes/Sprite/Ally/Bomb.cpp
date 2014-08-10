#include "Bomb.h"

USING_NS_CC;

Bomb::Bomb()
{
    setSpecialEffect(BattleManager::SpecialEffect::Capture);
}

Bomb::~Bomb()
{
}

const char* Bomb::getImageFileName()
{
    return "bullet.png";
}

void Bomb:: move()
{
    setVisible(false);
    boundingBox().setRect(getPositionX(), getPositionY(), 90, 90);
	auto action = ScaleTo::create(0.5f, 50.0f);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Bomb::onActionCompletedThenRemove, this));
    runAction(Sequence::create(action, actionCompleted, nullptr));

    auto effect = CircleLight::createEffect();
    effect->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(effect, effect->getZOrder(), effect->getTag());
    effect->runAction();
}
