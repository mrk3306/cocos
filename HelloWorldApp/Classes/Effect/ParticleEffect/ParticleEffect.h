#ifndef __HelloWorldApp__ParticleEffect__
#define __HelloWorldApp__ParticleEffect__

#include "cocos2d.h"
#include "Config.h"
#include "Effect/Effect.h"

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

#endif /* defined(__HelloWorldApp__ParticleEffect__) */
