#ifndef __mole__BattleManager__
#define __mole__BattleManager__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

class BattleManager
{
public:
    enum SpecialEffect
    {
        Nothing,
        Capture
    };

    static BattleManager* getInstance();

    CC_SYNTHESIZE(int, score, Score);

    void reset();

private:
    BattleManager(){};
    bool init();
};

#endif /* defined(__mole__BattleManager__) */
