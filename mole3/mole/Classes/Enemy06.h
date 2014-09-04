#ifndef __mole__Enemy06__
#define __mole__Enemy06__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class Enemy06 : public Enemy, public EnemyCreator<Enemy06>
{
public:
    Enemy06();
    virtual ~Enemy06();
    
    virtual void move() override;
    virtual void destroy() override;
    
protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Enemy06__) */
