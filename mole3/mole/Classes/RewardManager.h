#ifndef __mole__RewardManager__
#define __mole__RewardManager__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

class RewardManager
{
public:
    static RewardManager* getInstance();

    CC_SYNTHESIZE(int, score, Score);
    CC_SYNTHESIZE(int, time, Time);
    CC_SYNTHESIZE(int, life, Life);
    
    void reset();

private:
    RewardManager(){};
    bool init();
};

#endif /* defined(__mole__RewardManager__) */
