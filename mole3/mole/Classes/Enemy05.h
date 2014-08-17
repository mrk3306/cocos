#ifndef __shooting2__Enemy05__
#define __shooting2__Enemy05__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class Enemy05 : public Enemy, public EnemyCreator<Enemy05>
{
public:    
    Enemy05();
    virtual ~Enemy05();

    virtual void move() override;
    virtual void destroy() override;
    
protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__Enemy05__) */
