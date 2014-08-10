#ifndef __HelloWorldApp__NormalBullet__
#define __HelloWorldApp__NormalBullet__

#include "cocos2d.h"
#include "Config.h"
#include "Ally.h"

USING_NS_CC;

class NormalBullet : public Ally, public AllyCreator<NormalBullet>
{
public:    
    NormalBullet();
    virtual ~NormalBullet();
    
    virtual void move() override;
    virtual void destroy() override;

    virtual void update(float delta) override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__HelloWorldApp__NormalBullet__) */
