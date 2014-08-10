#ifndef __mole__Enemy04__
#define __mole__Enemy04__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "Enemy02.h"
#include "EnemyNormalBullet.h"

USING_NS_CC;

class Enemy04 : public Enemy, public EnemyCreator<Enemy04>
{
public:    
    Enemy04();
    virtual ~Enemy04();

    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;

    virtual void update(float delta) override;
    virtual void destroy() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Enemy04__) */
