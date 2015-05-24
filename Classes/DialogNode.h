//
//  DialogNode.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/27.
//
//

#ifndef __KaziProject__DialogNode__
#define __KaziProject__DialogNode__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "cocos-ext.h"
using namespace cocos2d::ui;
using namespace cocos2d;
class DialogNode: public Node{
public:
    virtual bool init();
    virtual void onEnter();
    CREATE_FUNC(DialogNode);
    void closeCallBack(Ref * ref,Widget::TouchEventType type);
    virtual void close();
};
#endif /* defined(__KaziProject__DialogNode__) */
