#include "RewardManager.h"

USING_NS_CC;

static RewardManager* instance = nullptr;

RewardManager* RewardManager::getInstance()
{
    if(!instance)
    {
        instance = new RewardManager();
        instance->init();
    }

    return instance;
}

bool RewardManager::init()
{
    reset();

	return true;
}

void RewardManager::reset()
{
    setScore(0);
    setTime(kTagTime);
    setLife(kTagLife);
}
