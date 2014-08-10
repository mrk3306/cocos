#include "ResourceManager.h"

USING_NS_CC;

static ResourceManager* instance = nullptr;

ResourceManager* ResourceManager::getInstance()
{
    if(!instance)
    {
        instance = new ResourceManager();
        instance->init();
    }

    return instance;
}

ResourceManager::~ResourceManager()
{
    CC_SAFE_RELEASE(pool);
}

bool ResourceManager::init()
{
    pool = nullptr;

	return true;
}

void ResourceManager::preLoadBatchNode(const string fileName)
{
    before();

    if (!pool->objectForKey(fileName))
    {
        pool->setObject(SpriteBatchNode::create(fileName), fileName);
    }
}

SpriteBatchNode* ResourceManager::getBatchNode(const string fileName)
{
    preLoadBatchNode(fileName);

    return static_cast<SpriteBatchNode*>(pool->objectForKey(fileName));
}

void ResourceManager::before()
{
    if (!pool)
    {
        pool = Dictionary::create();
        pool->retain();
    }
}
