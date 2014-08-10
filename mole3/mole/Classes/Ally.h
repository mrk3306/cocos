#ifndef __mole__Ally__
#define __mole__Ally__

#include "cocos2d.h"
#include "Config.h"
#include "BattleManager.h";
#include "ParticleEffectClassLoader.h"

USING_NS_CC;

template <class AllyType>
class AllyCreator
{
public:
	static AllyType* createAlly()
	{
		auto ret = new AllyType();
		if (ret && ret->init())
		{
            ret->autorelease();

			return ret;
		}
		else
		{
			CC_SAFE_DELETE(ret);
			return nullptr;
		}
	}
};


class Ally : public Sprite
{
public:    
    Ally();
    virtual ~Ally();

    enum Status
    {
        Normal,
        Captured,
        Destroyed
    };

    virtual void move() = 0;

    virtual void update(float delta);
    virtual void hurt(int power, BattleManager::SpecialEffect sp);
    virtual void recovery(int power);
    virtual void destroy();
    virtual void onActionCompletedThenRemove(Object* sender);

    CC_SYNTHESIZE(int, life, Life);
    CC_SYNTHESIZE(int, power, Power);
    CC_SYNTHESIZE(float, speed, Speed);
    CC_SYNTHESIZE(Size, effectiveArea, EffectiveArea);
    CC_SYNTHESIZE(Status, status, Status);
    CC_SYNTHESIZE(BattleManager::SpecialEffect, specialEffect, SpecialEffect);
    
    bool init();
    
private:
	virtual const char* getImageFileName() = 0;

    int max_life;
};

#endif /* defined(__mole__Ally__) */
