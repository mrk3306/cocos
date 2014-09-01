#ifndef __mole__TitleScene__
#define __mole__TitleScene__

#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class Title : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    //初期化のメソッド
    virtual bool init();
    
    //create()を使えるようにしている。
    CREATE_FUNC(Title);
    void pushStart(Object *pSender);
};

#endif /* defined(__mole__TitleScene__) */
