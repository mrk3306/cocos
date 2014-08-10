#ifndef __shooting2__Enemy06__
#define __shooting2__Enemy06__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "Enemy02.h"

USING_NS_CC;

class Enemy06 : public Enemy, public EnemyCreator<Enemy06>
{
public:
    Enemy06();
    virtual ~Enemy06();
    
    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;
    virtual void destroy() override;
    
protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__Enemy06__) */
