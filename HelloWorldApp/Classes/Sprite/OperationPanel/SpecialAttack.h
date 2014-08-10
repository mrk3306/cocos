#ifndef __HelloWorldApp__SpecialAttack__
#define __HelloWorldApp__SpecialAttack__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "Sprite/Player/PlayerClassLoader.h"

USING_NS_CC;

class SpecialAttack : public OperationPanel, public OperationPanelCreator<SpecialAttack>
{
public:    
    SpecialAttack();
    virtual ~SpecialAttack();

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__HelloWorldApp__SpecialAttack__) */