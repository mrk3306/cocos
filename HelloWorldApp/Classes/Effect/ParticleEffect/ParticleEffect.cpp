#include "ParticleEffect.h"

USING_NS_CC;

ParticleEffect::ParticleEffect()
{
}

ParticleEffect::~ParticleEffect()
{
    CC_SAFE_RELEASE(particle);
}

bool ParticleEffect::init()
{
     particle = ParticleSystemQuad::create(getImageFileName());
    if (particle)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ParticleEffect::onActionCompletedThenRemove(Object* sender)
{
    static_cast<Node*>(sender)->removeFromParent();
}
