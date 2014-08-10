#ifndef __shooting2__LifeLeft__
#define __shooting2__LifeLeft__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"

USING_NS_CC;

class LifeLeft : public OperationPanel, public OperationPanelCreator<LifeLeft>
{
public:    
    LifeLeft();
    virtual ~LifeLeft();

    void update(float delta);

        
protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__shooting2__LifeLeft__) */
