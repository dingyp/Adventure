//
//  BaseDialog1.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/4.
//
//

#ifndef __KaziProject__BaseDialog1__
#define __KaziProject__BaseDialog1__

#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "cocos-ext.h"
#include "Define.h"
using namespace cocos2d::ui;
using namespace cocos2d;
class BaseDialog1 : public Layer
{
public:
    virtual bool init();
    virtual void onEnter();
    CREATE_FUNC(BaseDialog1);
    void closeCallBack(Ref * ref,Widget::TouchEventType type);
    virtual void close();
    Size dialogSize;
    Scale9Sprite *background;
};
#endif /* defined(__KaziProject__BaseDialog1__) */
