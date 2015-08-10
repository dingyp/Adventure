//
//  MyGameScene.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#ifndef __KaziProject__MyGameScene__
#define __KaziProject__MyGameScene__

#include <stdio.h>
#include "BaseGameScene.h"
class MyGameScene : public BaseGameScene{
public:
    static cocos2d::Scene* createScene();
    
    MyGameScene();
    void updateEvent(float dt);
    virtual void onEnter();
    virtual void restart();
    virtual void nextScene(float dt);
};
#endif /* defined(__KaziProject__MyGameScene__) */
