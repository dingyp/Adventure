//
//  PlatFormer.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/13.
//
//

#ifndef __KaziProject__PlatFormer__
#define __KaziProject__PlatFormer__

#include <iostream>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
class PlatFormer:public Node{
public:
    virtual void onEnter();
    PlatFormer();
    Sprite * mSprite;
    string name;
    virtual Size getContentSize();
    float scales;
    Vec2 _velocity;
    void updateMove(float dt);
    float _distance;
    float maxdistance;
    int moveID;
};
#endif /* defined(__KaziProject__PlatFormer__) */
