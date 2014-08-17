#ifndef __mole__WarShip__
#define __mole__WarShip__

#include "cocos2d.h"
#include "Config.h"
#include "Player.h"

USING_NS_CC;

class WarShip : public Player, public PlayerCreator<WarShip>
{
public:    
    WarShip();
    virtual ~WarShip();
    

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__mole__WarShip__) */
