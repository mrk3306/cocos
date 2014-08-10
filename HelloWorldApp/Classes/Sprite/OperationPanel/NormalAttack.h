#ifndef __HelloWorldApp__NormalAttack__
#define __HelloWorldApp__NormalAttack__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "Sprite/Player/PlayerClassLoader.h"

USING_NS_CC;

class NormalAttack : public OperationPanel, public OperationPanelCreator<NormalAttack>
{
public:    
    NormalAttack();
    virtual ~NormalAttack();

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__HelloWorldApp__NormalAttack__) */
