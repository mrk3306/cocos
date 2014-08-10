#ifndef __mole__ArrowRight__
#define __mole__ArrowRight__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class ArrowRight : public OperationPanel, public OperationPanelCreator<ArrowRight>
{
public:    
    ArrowRight();
    virtual ~ArrowRight();

     void update(float delta);

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__mole__ArrowRight__) */
