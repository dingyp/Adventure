//
//  MyGameScene2.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/20.
//
//

#ifndef __KaziProject__MyGameScene2__
#define __KaziProject__MyGameScene2__
#include "BaseGameScene.h"
#include <stdio.h>
class MyGameScene2 : public BaseGameScene{
public:
    static cocos2d::Scene* createScene();
    
    MyGameScene2();
    void updateEvent(float dt);
    virtual void onEnter();
    virtual void restart();
    virtual void nextScene(float dt);
};
#endif /* defined(__KaziProject__MyGameScene2__) */

