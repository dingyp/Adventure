//
//  BaseGameScene.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#ifndef __KaziProject__BaseGameScene__
#define __KaziProject__BaseGameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ControllerLayer.h"

#include "Hero1.h"
#include "Global.h"
using namespace cocos2d;
class BaseGameScene :public Layer
{
public:
    virtual void onEnter();
    static Scene * createScene();
    experimental::TMXTiledMap * map;
    Sprite * background ;
    Sprite * background2 ;
    ParallaxNode * parallaxNode;
    void updateState(float dt);
    void win();
    virtual void nextScene(float dt);
    void restartCallBack(Ref * ref,Widget::TouchEventType type);
    virtual void restart() ;
    void initPlateForm();
    void initTMXTiledMap();
    void updateBackground(float dt);
    Node * platformNode;
};
#endif /* defined(__KaziProject__BaseGameScene__) */
