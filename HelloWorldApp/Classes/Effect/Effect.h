#ifndef __HelloWorldApp__Effect__
#define __HelloWorldApp__Effect__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

template <class EffectType>
class EffectCreator
{
public:
	static EffectType* createEffect()
	{
		auto ret = new EffectType();
		if (ret && ret->init())
		{
            ret->autorelease();
            ret->setTag(kTagEffect);
            ret->setZOrder(kZOrderEffect);
		
            return ret;
		}
		else
		{
			CC_SAFE_DELETE(ret);
			return nullptr;
		}
	}
};

class Effect : public Node
{
public:
    Effect(){};
    virtual ~Effect(){};

    virtual bool init() = 0;
    virtual void runAction() = 0;
};

#endif /* defined(__HelloWorldApp__Effect__) */
