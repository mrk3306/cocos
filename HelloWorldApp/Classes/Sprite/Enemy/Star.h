#ifndef __HelloWorldApp__Star__
#define __HelloWorldApp__Star__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"
#include "Enemy02.h"

USING_NS_CC;

class Star : public Enemy, public EnemyCreator<Star>
{
public:
    Star();
    virtual ~Star();
    
    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;
    virtual void destroy() override;
    
protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__HelloWorldApp__Star__) */
