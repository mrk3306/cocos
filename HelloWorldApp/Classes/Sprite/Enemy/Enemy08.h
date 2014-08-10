#ifndef __HelloWorldApp__Enemy08__
#define __HelloWorldApp__Enemy08__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "Enemy02.h"

USING_NS_CC;

class Enemy08 : public Enemy, public EnemyCreator<Enemy08>
{
public:    
    Enemy08();
    virtual ~Enemy08();

    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;

    virtual void destroy() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__HelloWorldApp__Enemy08__) */
