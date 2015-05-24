//
//  MyGameScene1.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/20.
//
//

#ifndef __KaziProject__MyGameScene1__
#define __KaziProject__MyGameScene1__

#include "BaseGameScene.h"
#include <stdio.h>
class MyGameScene1 : public BaseGameScene{
public:
    static cocos2d::Scene* createScene();
    
    MyGameScene1();
    void updateEvent(float dt);
    virtual void onEnter();
    virtual void restart();
};
#endif /* defined(__KaziProject__MyGameScene1__) */
