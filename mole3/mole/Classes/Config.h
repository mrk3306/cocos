#ifndef __mole__Config_h
#define __mole__Config_h

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
    kTagLife,
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

#endif /* defined(__mole__Config_h) */