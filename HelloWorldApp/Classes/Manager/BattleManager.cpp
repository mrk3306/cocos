#include "BattleManager.h"

USING_NS_CC;

static BattleManager* instance = nullptr;

BattleManager* BattleManager::getInstance()
{
    if(!instance)
    {
        instance = new BattleManager();
        instance->init();
    }

    return instance;
}

bool BattleManager::init()
{
    reset();

	return true;
}

void BattleManager::reset()
{
    setScore(0);
}
