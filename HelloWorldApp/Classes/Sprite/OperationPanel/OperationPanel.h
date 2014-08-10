#ifndef __HelloWorldApp__OperationPanel__
#define __HelloWorldApp__OperationPanel__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

template <class OperationPanelType>
class OperationPanelCreator
{
public:
	static OperationPanelType* createOperationPanel(Node* target)
	{
		auto ret = new OperationPanelType();
		if (ret && ret->init())
		{
            ret->autorelease();
            ret->setTag(kTagOperationPanel);
            ret->setZOrder(kZOrderOperationPanel);
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

class OperationPanel : public Sprite
{
public:
    OperationPanel();
    virtual ~OperationPanel();

    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);

    CC_SYNTHESIZE(Node*, target, Target);

    bool init();
    
protected:
    virtual const char* getImageFileName() = 0;
    virtual void touchBegan(Touch *touch) = 0;
    virtual void touchMoved(Touch *touch) = 0;
    virtual void touchEnded(Touch *touch) = 0;

    bool active;

private:
    EventListenerTouchOneByOne* touchListener;
};

#endif /* defined(__HelloWorldApp__OperationPanel__) */
