#ifndef __mole__GameEndScene__
#define __mole__GameEndScene__

#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class GameEndScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    //初期化のメソッド
    virtual bool init();
    
    //create()を使えるようにしている。
    CREATE_FUNC(GameEndScene);
    void pushStart(Object *pSender);
};

#endif /* defined(__mole__GameEndScene__) */
