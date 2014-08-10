#ifndef __mole__Enemy03__
#define __mole__Enemy03__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class Enemy03 : public Enemy, public EnemyCreator<Enemy03>
{
public:    
    Enemy03();
    virtual ~Enemy03();
    Size     winSize;
    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;
    virtual void destroy() override;
    virtual void fever();
    virtual void setPoint(float dt);
    
protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Enemy03__) */
