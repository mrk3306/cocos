#ifndef __HelloWorldApp__ArrowTop__
#define __HelloWorldApp__ArrowTop__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "Sprite/Player/PlayerClassLoader.h"

USING_NS_CC;

class ArrowTop : public OperationPanel, public OperationPanelCreator<ArrowTop>
{
public:    
    ArrowTop();
    virtual ~ArrowTop();

    void update(float delta);

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__HelloWorldApp__ArrowTop__) */
