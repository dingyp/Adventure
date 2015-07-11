//
//  VisibleRect.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#include "VisibleRect.h"


USING_NS_CC;

Rect VisibleRect::s_visibleRect;
float VisibleRect::_mdimens = 0;
void VisibleRect::lazyInit()
{
    // no lazy init
    // Useful if we change the resolution in runtime
    s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    _mdimens = s_visibleRect.size.height/7;
}

Rect VisibleRect::getVisibleRect()
{
    lazyInit();
    return s_visibleRect;
}

Vec2 VisibleRect::left()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::right()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::top()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::bottom()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

Vec2 VisibleRect::center()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::leftTop()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::mleftTop()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+_mdimens, s_visibleRect.origin.y+s_visibleRect.size.height-_mdimens);

}

Vec2 VisibleRect::rightTop()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::mrightTop(){
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width-_mdimens, s_visibleRect.origin.y+s_visibleRect.size.height-_mdimens);
}

Vec2 VisibleRect::leftBottom()
{
    lazyInit();
    return s_visibleRect.origin;
}

Vec2 VisibleRect::mleftBottom(){
    lazyInit();
    return Vec2(_mdimens,_mdimens);
}

Vec2 VisibleRect::rightBottom()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}
Vec2 VisibleRect::mrightBottom(){
    lazyInit();
    return Vec2(s_visibleRect.origin.x-_mdimens + s_visibleRect.size.width, s_visibleRect.origin.y + _mdimens);
}

float VisibleRect::mDimens(){
    return _mdimens;
}

Vec2 VisibleRect::mleft(){
    lazyInit();
    return Vec2(s_visibleRect.origin.x+_mdimens,  s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::mright(){
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width-_mdimens, s_visibleRect.origin.y+s_visibleRect.size.height/2);

}
Size VisibleRect::screenSize(){
    return  Director::getInstance()->getOpenGLView()->getVisibleRect().size;
}
