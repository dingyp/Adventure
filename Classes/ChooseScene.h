//
//  ChooseScene.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#ifndef __KaziProject__ChooseScene__
#define __KaziProject__ChooseScene__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
using namespace cocostudio;
using namespace cocos2d;
using namespace cocos2d::ui;
class ChooseScene : public Layer{
public:
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(ChooseScene);
    void chooseright(Ref * ref,Widget::TouchEventType type);
    void chooseleft(Ref * ref,Widget::TouchEventType type);
    void choose(Ref * ref,Widget::TouchEventType type);
    void back(Ref * ref,Widget::TouchEventType type);

    Node * mainNode ;
    int sceneIndex;
};

#endif /* defined(__KaziProject__ChooseScene__) */
