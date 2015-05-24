//
//  ControllerLayer.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__ControllerLayer__
#define __KaziProject__ControllerLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Global.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;
class ControllerLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(ControllerLayer);
	   //important!!!
    //dd
    int inputNum;//键盘左右键按下个数
    void moveright(Ref * ref,Widget::TouchEventType type);
    void moveleft(Ref * ref,Widget::TouchEventType type);
    void jump(Ref * ref,Widget::TouchEventType type);
    void back(Ref * ref,Widget::TouchEventType type);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

#endif /* defined(__KaziProject__ControllerLayer__) */
