#ifndef __HelloWorldApp__CircleFire__
#define __HelloWorldApp__CircleFire__

#include "cocos2d.h"
#include "Config.h"
#include "ParticleEffect.h"

USING_NS_CC;

class CircleFire : public ParticleEffect, public EffectCreator<CircleFire>
{
public:    
    CircleFire();
    virtual ~CircleFire();

    virtual void runAction() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__HelloWorldApp__CircleFire__) */
