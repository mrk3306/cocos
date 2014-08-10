#ifndef __mole__EnemyNormalBullet__
#define __mole__EnemyNormalBullet__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"

USING_NS_CC;

class EnemyNormalBullet : public Enemy, public EnemyCreator<EnemyNormalBullet>
{
public:    
    EnemyNormalBullet();
    virtual ~EnemyNormalBullet();

    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;
    
    virtual void destroy() override;
    virtual void update(float delta);

protected:
    virtual const char* getImageFileName();
};

#endif /* defined(__mole__EnemyNormalBullet__) */
