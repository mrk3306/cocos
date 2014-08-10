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
    CC_SAFE_RELEASE(warShip);
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    scene->addChild(GameScene::create());
    
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
    
    preLoad();
    initialPlacement();
    
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic(kBGMMain, true);
    
    scheduleUpdate();
    
    return true;
}

void GameScene::update(float delta)
{
    createEnemy();
    collisionDetection();
    updateInfomationPanel();
}

void GameScene::preLoad()
{
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSEMoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSERemoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(kBGMMain);
    
    // É{ÉXÇ»Ç«ÇÃëÂå^âÊëúÇ≈ÉQÅ[ÉÄé¿çsíÜÇ…ì«Ç›çûÇﬁÇ∆èàóùÇ™íxÇ≠Ç»ÇÈÇÊÇ§Ç»Ç‡ÇÃÇæÇØÇ‚ÇÍÇŒè[ï™
    ResourceManager::getInstance()->preLoadBatchNode("enemy04.png");
}

void GameScene::initialPlacement()
{
    //    auto bg1 = Sprite::create("bg1.png");
    //    auto bg2 = Sprite::create("bg2.png");
    //    auto bg3 = Sprite::create("bg3.png");
    //    auto paraNode = ParallaxNode::create();
    //    paraNode->addChild(bg1, 1, Point(0.5f, 0), Point(0, winSize.height));
    //    paraNode->addChild(bg2, 2, Point(1.5f, 0), Point(0, winSize.height / 10));
    //    paraNode->addChild(bg3, 3, Point(2.0f, 0), Point(0, winSize.height / 3));
    //    paraNode->setPosition(Point(winSize.width, winSize.height / 5));
    //    addChild(paraNode, kZOrderBackground);
    //
    //    auto move1  = MoveBy::create(10.0f, Point(-winSize.width, 0));
    //    auto move2  = MoveBy::create(0.0f, Point(winSize.width, 0));
    //    auto repeat = RepeatForever::create(Sequence::create(move1, move2, nullptr));
    //    paraNode->runAction(repeat);
    
    
    // 画像1つ目、2つ目ホhover
    auto backButton = MenuItemImage::create(
                                            "CloseNormal.png",  //表示
                                            "CloseSelected.png",  //タップ時の画像
                                            CC_CALLBACK_1(GameScene::menuAction, this));
    
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
    auto heart01_l = LifeLeft::createOperationPanel(warShip);
    heart01_l->setPosition(Point(winSize.width * 0.92, winSize.height * 0.85));
    addChild(heart01_l, kZOrderLabel, kTagLife1);
    
    auto heart01_r = LifeLeft::createOperationPanel(warShip);
    heart01_r->setPosition(Point(winSize.width * 0.85, winSize.height * 0.85));
    addChild(heart01_r, kZOrderLabel, kTagLife2);
    
    // ライフ2
    auto heart02_l = LifeLeft::createOperationPanel(warShip);
    heart02_l->setPosition(Point(winSize.width * 0.78, winSize.height * 0.85));
    addChild(heart02_l, kZOrderLabel, kTagLife3);
    
    createPlayer();
    
    
    auto left = ArrowLeft::createOperationPanel(warShip);
    left->setPosition(Point((winSize.width / 2) - left->getContentSize().width, left->getContentSize().height));
    addChild(left, left->getZOrder(), left->getTag());
    
    auto right = ArrowRight::createOperationPanel(warShip);
    right->setPosition(Point((winSize.width / 2) + right->getContentSize().width , right->getContentSize().height));
    addChild(right, right->getZOrder(), right->getTag());
    
    //auto top = ArrowTop::createOperationPanel(warShip);
    //top->setPosition(Point(top->getContentSize().width * 2.0f, top->getContentSize().height * 2));
    //addChild(top, top->getZOrder(), top->getTag());
    
    //auto under = ArrowUnder::createOperationPanel(warShip);
    //under->setPosition(Point(under->getContentSize().width * 2.0f, under->getContentSize().height));
    //addChild(under, under->getZOrder(), under->getTag());
    
    //auto attack = NormalAttack::createOperationPanel(warShip);
    //attack->setPosition(Point(winSize.width * 0.8f, attack->getContentSize().height * 2));
    //addChild(attack, attack->getZOrder(), attack->getTag());
    
    //auto special = SpecialAttack::createOperationPanel(warShip);
    //special->setPosition(Point(winSize.width*0.8f + special->getContentSize().width, special->getContentSize().height * 2));
    //addChild(special, special->getZOrder(), special->getTag());
}



void GameScene::menuAction(Object *pSender)
{
    // 遷移先の画面のインスタンス
    Scene *pScene = GameScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    Director::getInstance()->replaceScene(transition);
    
    
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
        
        if (rand()%150 == 1  || rand()%150 == 2 || rand()%150 == 3)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width < winSize.height * 0.4) {
                enemy_width = winSize.height * 0.4;
            } else if (enemy_width > winSize.height * 0.8) {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy = Enemy01::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->fever();
        }
        else if (rand()%150 == 4 || rand()%150 == 5  || rand()%150 == 6)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width < winSize.height * 0.4) {
                enemy_width = winSize.height * 0.4;
            } else if (enemy_width > winSize.height * 0.8) {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy = Enemy03::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->fever();
        }
        
        
    }else{
        
        
        if (rand()%150 == 11)
        {
            //float enemy_height = winSize.height*(rand()%100+1)/100;
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width < winSize.height * 0.4) {
                enemy_width = winSize.height * 0.4;
            } else if (enemy_width > winSize.height * 0.8) {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy = Enemy01::createEnemy(warShip);
            //enemy->setPosition(winSize.width, enemy_height);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();
        }
        else if (rand()%150 == 13)
        {
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width > winSize.height * 0.8)
            {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy = Enemy03::createEnemy(warShip);
            enemy->setPosition(enemy_width, winSize.height);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();
        }
        else if (rand()%150 ==16)
        {
            
            float enemy_width = winSize.width*(rand()%100+1)/100;
            if (enemy_width > winSize.height * 0.8)
            {
                enemy_width = winSize.height * 0.8;
            }
            
            auto enemy6 = Enemy06::createEnemy(warShip);
            enemy6->setPosition(enemy_width, winSize.height);
            addChild(enemy6, enemy6->getZOrder(), enemy6->getTag());
            enemy6->move();
        }
        else if (rand()%150 == 23)
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
            enemy->move();
            
        }
        else if (rand()%150 == 111)
        {
            
            //ライフ
//            float enemy_width = winSize.width*(rand()%100+1)/100;
//            if (enemy_width > winSize.height * 0.8)
//            {
//                enemy_width = winSize.height * 0.8;
//            }
//            
//            auto enemy08 = Enemy08::createEnemy(warShip);
//            enemy08->setPosition(enemy_width, winSize.height);
//            addChild(enemy08, enemy08->getZOrder(), enemy08->getTag());
//            enemy08->move();
        }
        else if (rand()%150 == 100)
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
            star->move();
        }
        
        
        
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
                
                if(targetNode->getPositionY() < 0 ){
                    
                    log("%d",targetNode->getPositionY());
                    
                }
                
                
                if (targetNode && targetNode->getTag() == kTagAlly)
                {
                    auto ally = dynamic_cast<Ally*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        //ally->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        //enemy->hurt(ally->getPower(), ally->getSpecialEffect());
                    }
                }
                
                // 追加　スコア表示
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    
                    auto player = dynamic_cast<Player*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        
                        
                        if(player->playerStatus() == true){
                        
                        auto reward_manager = RewardManager::getInstance();
                        reward_manager->setScore(reward_manager->getScore() + 50);
                        
                        
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->destroy();
                        
                        }
                        
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
                        
                        
                        if(player->playerStatus() == true){
                        
                        
                        auto reward_manager = RewardManager::getInstance();
                        reward_manager->setLife(reward_manager->getLife()-1);
                        auto life = reward_manager->getLife();
                        Sprite* life1 = (Sprite*)this->getChildByTag(kTagLife1);
                        Sprite* life2 = (Sprite*)this->getChildByTag(kTagLife2);
                        Sprite* life3 = (Sprite*)this->getChildByTag(kTagLife3);
                        
                        if(life <= 0 ){
                            life1->setVisible(false);
                            
                        }else if(life==1){
                            
                            life2->setVisible(false);
                            
                        }else{
                            
                            life3->setVisible(false);
                            
                        }
                        
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->destroy();
                        
                        }
                        
                        
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
                        
                        
                        if(player->playerStatus() == true){
                            
                            
                            
                            //player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                            ///enemy->destroy();
                            
                        }
                        
                        
                    }
                }
            }
        }
        
        // スターとあたった場合
        if (currentNode && currentNode->getTag() == kTagStar)
        {
            
            for (auto targetNode : children)
            {
                
                
                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        feverTimeFlg = 1;
                        this->schedule(schedule_selector(GameScene::endFeverTime),5.0f);
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
    
    auto reward_manager = RewardManager::getInstance();
    auto life = reward_manager->getLife();
    //log("%d",life);
    
    
    
    
}