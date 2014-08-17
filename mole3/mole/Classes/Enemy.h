#ifndef __mole__Enemy__
#define __mole__Enemy__

#include "cocos2d.h"
#include "Config.h"
#include "BattleManager.h"
#include "ResourceManager.h"
#include "RewardManager.h"
#include "ParticleEffectClassLoader.h"


USING_NS_CC;

template <class EnemyType>
class EnemyCreator
{
public:
	static EnemyType* createEnemy(Node* target)
	{
		auto ret = new EnemyType();
		if (ret && ret->init())
		{
            ret->autorelease();
            ret->setTarget(target);

            return ret;
		}
		else
		{
			CC_SAFE_DELETE(ret);
			return nullptr;
		}
	}
};

class Enemy : public Sprite
{
    typedef Enemy super;
public:
    Enemy();
    virtual ~Enemy();

    enum Status
    {
        Normal,
        Captured,
        Destroyed,
        Unbreakable
    };

    enum SpetialEffect
    {
        Nothing,
        Capture
    };

    virtual void move() = 0;
    virtual void update(float delta);
    virtual void hurt(int power, BattleManager::SpecialEffect sp);
    virtual void recovery(int power);
    virtual void destroy();
    virtual void setLife();
    
	virtual void onActionCompletedThenRemove(Object* sender);

	CC_SYNTHESIZE_READONLY(const char*, type, Type);
    CC_SYNTHESIZE_READONLY(int, score, Score);
    CC_SYNTHESIZE(Node*, target, Target);
    CC_SYNTHESIZE(Status, status, Status);
    CC_SYNTHESIZE(BattleManager::SpecialEffect, specialEffect, SpecialEffect);
    CC_SYNTHESIZE(int, life, Life);
    CC_SYNTHESIZE(int, power, Power);
    CC_SYNTHESIZE(float, speed, Speed);
    CC_SYNTHESIZE(float, duration, Duration);
    CC_SYNTHESIZE(Size, effectiveArea, EffectiveArea);
    
    bool init();

protected:
    virtual const char* getImageFileName() = 0;

    int max_life;
};

#endif /* defined(__mole__Enemy__) */
