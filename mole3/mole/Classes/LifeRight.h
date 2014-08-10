#ifndef __shooting2__LifeRight__
#define __shooting2__LifeRight__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"

USING_NS_CC;

class LifeRight : public OperationPanel, public OperationPanelCreator<LifeRight>
{
public:    
    LifeRight();
    virtual ~LifeRight();

    void update(float delta);

        
protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__shooting2__LifeRight__) */
