#ifndef __mole__ParticleEffect__
#define __mole__ParticleEffect__

#include "cocos2d.h"
#include "Config.h"
#include "Effect.h"

USING_NS_CC;

class ParticleEffect : public Effect
{
public:
    ParticleEffect();
    virtual ~ParticleEffect();

    virtual bool init() override;
    virtual void runAction() = 0;

    CC_SYNTHESIZE_READONLY(ParticleSystemQuad*, particle, Particle);

protected:
    virtual const char* getImageFileName() = 0;
    virtual void onActionCompletedThenRemove(Object* sender);
};

#endif /* defined(__mole__ParticleEffect__) */
