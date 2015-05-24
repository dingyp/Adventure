//
//  ChooseNode.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/23.
//
//

#ifndef __KaziProject__ChooseNode__
#define __KaziProject__ChooseNode__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
using namespace cocostudio;
using namespace cocos2d;
using namespace cocos2d::ui;
class ChooseNode:public Node{
public:
    virtual bool init();
    void chooseright(Ref * ref,Widget::TouchEventType type);
    void chooseleft(Ref * ref,Widget::TouchEventType type);
    void choose(Ref * ref,Widget::TouchEventType type);
    CREATE_FUNC(ChooseNode);
    int index;
    int maxLength;
    int length;
};
#endif /* defined(__KaziProject__ChooseNode__) */
