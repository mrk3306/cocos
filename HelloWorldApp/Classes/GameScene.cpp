#include "GameScene.h"
//#include "MenuScene.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

GameScene::GameScene()
:winSize(Director::getInstance()->getWinSize())
{
    srand((unsigned)time(nullptr));
}

GameScene::~GameScene()
{
    CC_SAFE_RELEASE(background);
    //CC_SAFE_RELEASE(warShip);
}

Scene* GameScene::createScene()
{

    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameScene::init()
{

    if(!Layer::init())
    {
        return false;
    }

    //背景色設定
    LayerColor * pWhite = LayerColor::create(Color4B::WHITE);
    this->addChild(pWhite);
    
    //RewardManager::getInstance()->setScore(0);
    
    //preLoad();
    //initialPlacement();
    
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic(kBGMMain, true);
    
    scheduleUpdate();
    
    return true;
}

void GameScene::update(float delta)
{
    
}

void GameScene::preLoad()
{
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSEMoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSERemoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(kBGMMain);
    
    // É{ÉXÇ»Ç«ÇÃëÂå^âÊëúÇ≈ÉQÅ[ÉÄé¿çsíÜÇ…ì«Ç›çûÇﬁÇ∆èàóùÇ™íxÇ≠Ç»ÇÈÇÊÇ§Ç»Ç‡ÇÃÇæÇØÇ‚ÇÍÇŒè[ï™
    //ResourceManager::getInstance()->preLoadBatchNode("enemy04.png");
}

