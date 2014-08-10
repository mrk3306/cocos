#ifndef __HelloWorldApp__Player__
#define __HelloWorldApp__Player__

#include "cocos2d.h"
#include "Config.h"
#include "Manager/BattleManager.h";
#include "Sprite/Ally/AllyClassLoader.h"
#include "Effect/ParticleEffect/ParticleEffectClassLoader.h"
#include "Sprite/OperationPanel/LifeRight.h"
#include "Sprite/OperationPanel/LifeLeft.h"


USING_NS_CC;

template <class PlayerType>
class PlayerCreator
{
public:
	static PlayerType* createPlayer()
	{
		auto ret = new PlayerType();
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

class Player : public Sprite
{
public:
    Player();
    virtual ~Player();

    enum Status
    {
        Normal,
        Destroyed,
        Unbreakable
    };

	virtual void attack() = 0;
	virtual void attack(Point from, Point to) = 0;
	virtual void specialAttack() = 0;
	virtual void specialAttack(Point from, Point to) = 0;

    virtual void update(float delta);
    virtual void hurt(int power, BattleManager::SpecialEffect sp);
    virtual void recovery(int power);
    virtual void destroy();
    bool playerStatus();
    
    CC_SYNTHESIZE(Status, status, Status);
    CC_SYNTHESIZE(int, life, Life);
    CC_SYNTHESIZE(float, speed, Speed);
    CC_SYNTHESIZE(float, duration, Duration);
    CC_SYNTHESIZE(Size, effectiveArea, EffectiveArea);

    bool init();

protected:
    virtual const char* getImageFileName() = 0;

    int max_life;
};

#endif /* defined(__HelloWorldApp__Player__) */
