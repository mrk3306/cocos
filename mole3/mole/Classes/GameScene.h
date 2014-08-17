#ifndef __mole__GameScene__
#define __mole__GameScene__

#include "cocos2d.h"
#include "Config.h"
#include "SimpleAudioEngine.h"
#include "ResourceManager.h"
#include "RewardManager.h"
#include "OperationPanelClassLoader.h"
#include "PlayerClassLoader.h"
#include "WarShip.h"
#include "EnemyClassLoader.h"
#include "AllyClassLoader.h"
#include "LifeLeft.h"
#include "LifeRight.h"

using namespace std;
USING_NS_CC;

class GameScene : public Layer
{
public:
    GameScene();
    virtual ~GameScene();
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(GameScene);
    
private:
    Sprite*  background;
    WarShip* warShip;
    Size     winSize;
    int feverTimeFlg = 0;
    int feverTime = 0;
    
    void update(float delta);
    
    void preLoad();
    void initialPlacement();
    void createPlayer();
    void createEnemy();
    void dispLife();
    void collisionDetection();
    void updateInfomationPanel();
    void countdown(float delta);
    void menuAction(Object *pSender);
    void endFeverTime(float dt);

    
};
#endif /* defined(__mole__GameScene__) */
