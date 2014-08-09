#ifndef __HelloWorldApp__Config_h
#define __HelloWorldApp__Config_h

enum kTag
{
    kTagUnDefine   = -1,
    kTagBackground = 1,
    kTagLabel,
    kTagPlayer,
    kTagOperationPanel,
    kTagEnemy,
    kTagAlly,
    kTagEffect,
    kTagScore,
    kTagTime,
    kTagLife = 3,
    kTagLife1,
    kTagLife2,
    kTagLife3,
    kTagLife4,
    kTagLife5,
    kTagLife6,
    kTagBomb,
    kTagStar,
};

enum kZOrder
{
    kZOrderBackground,
    kZOrderLabel,
    kZOrderGameOver,
    kZOrderMovableSprite,
    kZOrderOperationPanel,
    kZOrderEffect
};

#endif /* defined(__HelloWorldApp__Config_h) */