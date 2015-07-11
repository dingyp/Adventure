//
//  VisibleRect.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#ifndef __KaziProject__VisibleRect__
#define __KaziProject__VisibleRect__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class VisibleRect
{
public:
    static cocos2d::Rect getVisibleRect();
    static cocos2d::Vec2 left();
    static cocos2d::Vec2 right();
    static cocos2d::Vec2 top();
    static cocos2d::Vec2 bottom();
    static cocos2d::Vec2 center();
    static cocos2d::Vec2 leftTop();
    static cocos2d::Vec2 rightTop();
    static cocos2d::Vec2 leftBottom();
    static cocos2d::Vec2 rightBottom();
    static Vec2 mleftBottom();
    static Vec2 mrightBottom();
    static Vec2 mleftTop();
    static Vec2 mrightTop();
    static Vec2 mright();
    static Vec2 mleft();
    
    static Size screenSize();
    static float mDimens();
private:
    static void lazyInit();
    static cocos2d::Rect s_visibleRect;
    static float _mdimens;
};

#endif /* defined(__KaziProject__VisibleRect__) */
