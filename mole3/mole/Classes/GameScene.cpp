#include "GameScene.h"
#include "TitleScene.h"
#include "GameEndScene.h"

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
    CC_SAFE_RELEASE(warShip);
}

Scene* GameScene::createScene()
{

    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
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
    
    RewardManager::getInstance()->setScore(0);
    initialPlacement();
    scheduleUpdate();
    
    return true;
}

void GameScene::update(float delta)
{
    createEnemy();
    dispLife();
    collisionDetection();
    updateInfomationPanel();
}


void GameScene::initialPlacement()
{
    
    //ライフを初期化
    auto reward_manager = RewardManager::getInstance();
    reward_manager->setLife(kTagLife);
    reward_manager->setTime(kTagTime);

    
    // 画像1つ目、2つ目ホhover
    auto backButton = MenuItemImage::create(
                                            "CloseNormal.png",  //表示
                                            "CloseSelected.png",  //タップ時の画像
                                            CC_CALLBACK_1(GameScene::pushBack, this));
    
    backButton->setPosition(Point(30, winSize.height * 0.95));
    auto _menu2 = Menu::create(backButton,NULL);
    _menu2->setPosition(Point::ZERO);
    this->addChild(_menu2);
    
    
    // スコア
    const char* initCountStr = String::createWithFormat("%05d", RewardManager::getInstance()->getScore())->getCString();
    auto score_label         = LabelBMFont::create(initCountStr, "whiteFont.fnt");
    score_label->setPosition(Point(winSize.width * 0.8, winSize.height * 0.95));
    addChild(score_label, kZOrderLabel, kTagScore);
    
    
    // タイマー
    const char* timer = String::createWithFormat("%03d", RewardManager::getInstance()->getTime())->getCString();
    auto timer_label = LabelBMFont::create(timer, "whiteFont.fnt");
    timer_label->setPosition(Point(winSize.width * 0.2, winSize.height * 0.85));
    addChild(timer_label, kZOrderLabel, kTagTime);
    this->schedule(schedule_selector(GameScene::countdown), 1.0f);
    
    
    // ライフ
    auto heart01 = LifeRight::createOperationPanel(warShip);
    heart01->setPosition(Point(winSize.width * 0.9, winSize.height * 0.85));
    addChild(heart01, kZOrderLabel, kTagLife1);
    
    auto heart02 = LifeLeft::createOperationPanel(warShip);
    heart02->setPosition(Point(winSize.width * 0.83, winSize.height * 0.85));
    addChild(heart02, kZOrderLabel, kTagLife2);

    auto heart03 = LifeRight::createOperationPanel(warShip);
    heart03->setPosition(Point(winSize.width * 0.7, winSize.height * 0.85));
    addChild(heart03, kZOrderLabel, kTagLife3);
  
    auto heart04 = LifeLeft::createOperationPanel(warShip);
    heart04->setPosition(Point(winSize.width * 0.63, winSize.height * 0.85));
    addChild(heart04, kZOrderLabel, kTagLife4);

    auto heart05 = LifeRight::createOperationPanel(warShip);
    heart05->setPosition(Point(winSize.width * 0.5, winSize.height * 0.85));
    addChild(heart05, kZOrderLabel, kTagLife5);

    auto heart06 = LifeLeft::createOperationPanel(warShip);
    heart06->setPosition(Point(winSize.width * 0.43, winSize.height * 0.85));
    addChild(heart06, kZOrderLabel, kTagLife6);
    
    //プレイヤー
    createPlayer();
    
    auto left = ArrowLeft::createOperationPanel(warShip);
    left->setPosition(Point((winSize.width / 2) - left->getContentSize().width, left->getContentSize().height));
    addChild(left, left->getZOrder(), left->getTag());
    
    auto right = ArrowRight::createOperationPanel(warShip);
    right->setPosition(Point((winSize.width / 2) + right->getContentSize().width , right->getContentSize().height));
    addChild(right, right->getZOrder(), right->getTag());
    
}


void GameScene::pushEnd(Object *pSender)
{
    // 遷移先の画面のインスタンス
    Scene *pScene = GameEndScene::createScene();
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    Director::getInstance()->pushScene(transition);
    
    
}


void GameScene::pushBack(Object *pSender)
{
    // 遷移先の画面のインスタンス
    Scene *pScene = Title::createScene();
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    Director::getInstance()->pushScene(transition);
    
    
}

void GameScene::countdown(float delta){
    
    // タイマー
    auto reward_manager = RewardManager::getInstance();
    reward_manager->setTime(reward_manager->getTime()-1);
    
}

void GameScene::createPlayer()
{
    if (!getChildByTag(kTagPlayer))
    {
        warShip = WarShip::createPlayer();
        warShip->setPosition(Point((winSize.width / 2), warShip->getContentSize().height * 2));
        addChild(warShip, warShip->getZOrder(), warShip->getTag());
    }
}

void GameScene::createEnemy()
{
    if(feverTimeFlg == 1){
        
        if (rand()%150 == 10  || rand()%150 == 20)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            
            auto enemy = Enemy01::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->fever();
        }
        else if (rand()%150 == 40 || rand()%150 == 50)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            
            auto enemy = Enemy03::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->fever();
        }
        
    } else {

        if (rand()%150 == 10)
        {

            float enemy_width = winSize.width*(rand()%100+1)/100;
            auto enemy = Enemy01::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();
    
        }
        else if (rand()%150 == 20)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            auto enemy = Enemy03::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();

        }
        else if (rand()%150 ==30)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            auto enemy6 = Enemy06::createEnemy(warShip);
            enemy6->setPosition(enemy_width, winSize.height);
            addChild(enemy6, enemy6->getZOrder(), enemy6->getTag());
            enemy6->move();
        }
        else if (rand()%150 == 40)
        {
            // 爆弾
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width > winSize.height * 0.8)
            {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy = Enemy05::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            //enemy->move();

        }
        else if (rand()%150 == 40)
        {
            
            //ライフ
            log("ライフライフライフライフライフ");
            float enemy_width = winSize.width*(rand()%100+1)/100;
            enemy_width = winSize.height * 0.8;
            auto enemy = Enemy08::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();

        }
        else if (rand()%600 == 60)
        {
            //スター
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width > winSize.height * 0.4)
            {
                enemy_width = winSize.height * 0.4;
            }

            auto star = Star::createEnemy(warShip);
            star->setPosition(enemy_width, winSize.height);
            addChild(star, star->getZOrder(), star->getTag());
            //star->move();

        }
    }
}

void GameScene::dispLife()
{
    auto life = RewardManager::getInstance()->getLife();
    
    log("Life is %d", life);
    
    Sprite* life1 = (Sprite*)this->getChildByTag(kTagLife1);
    life1->setOpacity(0);
    Sprite* life2 = (Sprite*)this->getChildByTag(kTagLife2);
    life2->setOpacity(0);
    Sprite* life3 = (Sprite*)this->getChildByTag(kTagLife3);
    life3->setOpacity(0);
    Sprite* life4 = (Sprite*)this->getChildByTag(kTagLife4);
    life4->setOpacity(0);
    Sprite* life5 = (Sprite*)this->getChildByTag(kTagLife5);
    life5->setOpacity(0);
    Sprite* life6 = (Sprite*)this->getChildByTag(kTagLife6);
    life6->setOpacity(0);
    
    if(life <= 0 ){

        // 遷移先の画面のインスタンス
        //Director::getInstance()->pushScene(GameEndScene::createScene());

        
    }else if(life == 1){
        life1->setOpacity(225);
        
    }else if(life == 2){
        life1->setOpacity(225);
        life2->setOpacity(225);
        
    }else if(life == 3){
        life1->setOpacity(225);
        life2->setOpacity(225);
        life3->setOpacity(225);

    }else if(life == 4){
        life1->setOpacity(225);
        life2->setOpacity(225);
        life3->setOpacity(225);
        life4->setOpacity(225);

    }else if(life == 5) {
        life1->setOpacity(225);
        life2->setOpacity(225);
        life3->setOpacity(225);
        life4->setOpacity(225);
        life5->setOpacity(225);

    }else{
        life1->setOpacity(225);
        life2->setOpacity(225);
        life3->setOpacity(225);
        life4->setOpacity(225);
        life5->setOpacity(225);
        life6->setOpacity(225);
    }

}

void GameScene::collisionDetection()
{
    auto children = getChildren();
    for (auto currentNode : children)
    {

        if (currentNode && currentNode->getTag() == kTagEnemy)
        {
            auto enemy = dynamic_cast<Enemy*>(currentNode);
            for (auto targetNode : children)
            {
                if(targetNode && targetNode->getTag() == kTagPlayer)
                {

                    if (currentNode->getPositionY() <= 90 )
                    {
                        //log("SCREEN OUT LIFE DOWN BEFOR");
                        log("SCREEN OUT LIFE DOWN BEFOR!!!!!!!!");
                        auto player = dynamic_cast<Player*>(targetNode);
  
                        auto score = static_cast<LabelBMFont*>(getChildByTag(kTagScore));
                        score->setString(String::createWithFormat("%05d", RewardManager::getInstance()->getScore())->getCString());
                        
                        auto reward_manager = RewardManager::getInstance();
                        if(reward_manager->getLife() >  0){
                            reward_manager->setLife(reward_manager->getLife()-1);
                        }
                        
                        enemy->destroy();
                        //log("SCREEN OUT LIFE DOWN AFTER %d",reward_manager->getLife());

                    }
                    
                }
                
                // 追加　スコア表示
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    
                    auto player = dynamic_cast<Player*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {

                        auto reward_manager = RewardManager::getInstance();
                        reward_manager->setScore(reward_manager->getScore() + 50);
                        
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->destroy();
                        
                    }
                }
            }
        }
        
        // 爆弾とあったった場合
        if (currentNode && currentNode->getTag() == kTagBomb)
        {
            auto enemy = dynamic_cast<Enemy*>(currentNode);
            for (auto targetNode : children)
            {
                
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    auto player = dynamic_cast<Player*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        log("爆弾と触れた？");

                        log("%d",enemy->getPower());
                        auto reward_manager = RewardManager::getInstance();

                        if(reward_manager->getLife() >  0){
                            reward_manager->setLife(reward_manager->getLife()-1);
                        }
                        
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->destroy();
                        
                    }
                }
            }
        }
        
        // ライフとあったった場合
        if (currentNode && currentNode->getTag() == kTagLife)
        {
            auto enemy = dynamic_cast<Enemy*>(currentNode);
            for (auto targetNode : children)
            {
                
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    
                    auto player = dynamic_cast<Player*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        
                        log("%d",enemy->getPower());
                        auto reward_manager = RewardManager::getInstance();
                        
                        if(reward_manager->getLife() >  kTagLife){
                             reward_manager->setLife(reward_manager->getLife()+1);
                        }
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->destroy();
                        
                    }
                }
            }
        }
        
        // スターとあたった場合
        if (currentNode && currentNode->getTag() == kTagStar)
        {
            auto enemy = dynamic_cast<Enemy*>(currentNode);
            for (auto targetNode : children)
            {
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        feverTimeFlg = 1;
                        this->schedule(schedule_selector(GameScene::endFeverTime),5.0f);
                        enemy->destroy();
                    }
                }
            }
        }
    }
}

void GameScene::endFeverTime(float dt)
{
    feverTimeFlg = 0;
}


void GameScene::updateInfomationPanel()
{
    
    auto score = static_cast<LabelBMFont*>(getChildByTag(kTagScore));
    score->setString(String::createWithFormat("%05d", RewardManager::getInstance()->getScore())->getCString());
    
    auto time = static_cast<LabelBMFont*>(getChildByTag(kTagTime));
    time->setString(String::createWithFormat("%05d", RewardManager::getInstance()->getTime())->getCString());
    
}

void GameScene::reset()
{
    

    
}
