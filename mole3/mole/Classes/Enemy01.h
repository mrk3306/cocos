#ifndef __mole__Enemy01__
#define __mole__Enemy01__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class Enemy01 : public Enemy, public EnemyCreator<Enemy01>
{
public:    
    Enemy01();
    virtual ~Enemy01();
    Size     winSize;
    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;
    virtual void fever();
    virtual void setPoint(float dt);
    
    virtual void update(float delta) override;
    virtual void destroy() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Enemy01__) */
