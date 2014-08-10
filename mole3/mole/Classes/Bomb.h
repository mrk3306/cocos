#ifndef __mole__Bomb__
#define __mole__Bomb__

#include "cocos2d.h"
#include "Config.h"
#include "Ally.h"

USING_NS_CC;

class Bomb : public Ally, public AllyCreator<Bomb>
{
public:    
    Bomb();
    virtual ~Bomb();
    
    virtual void move() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Bomb__) */
