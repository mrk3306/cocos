#ifndef __HelloWorldApp__CircleLight__
#define __HelloWorldApp__CircleLight__

#include "cocos2d.h"
#include "Config.h"
#include "ParticleEffect.h"

USING_NS_CC;

class CircleLight : public ParticleEffect, public EffectCreator<CircleLight>
{
public:    
    CircleLight();
    virtual ~CircleLight();

    virtual void runAction() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__HelloWorldApp__CircleLight__) */
