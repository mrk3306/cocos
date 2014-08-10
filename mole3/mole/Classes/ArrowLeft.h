#ifndef __mole__ArrowLeft__
#define __mole__ArrowLeft__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "PlayerClassLoader.h"

USING_NS_CC;

class ArrowLeft : public OperationPanel, public OperationPanelCreator<ArrowLeft>
{
public:    
    ArrowLeft();
    virtual ~ArrowLeft();

    void update(float delta);

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__mole__ArrowLeft__) */
