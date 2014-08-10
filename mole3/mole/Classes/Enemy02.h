#ifndef __mole__Enemy02__
#define __mole__Enemy02__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"

USING_NS_CC;

class Enemy02 : public Enemy, public EnemyCreator<Enemy02>
{
public:    
    Enemy02();
    virtual ~Enemy02();

    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;

    virtual void update(float delta) override;
    virtual void hurt(int power, BattleManager::SpecialEffect sp) override;
    virtual void destroy() override;

    void captured();

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__Enemy02__) */
