#ifndef __mole__Ignite__
#define __mole__Ignite__

#include "cocos2d.h"
#include "Config.h"
#include "ParticleEffect.h"

USING_NS_CC;

class Ignite : public ParticleEffect, public EffectCreator<Ignite>
{
public:    
    Ignite();
    virtual ~Ignite();

    virtual void runAction() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Ignite__) */
