//
//  UILayers.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/28.
//
//

#include "UILayer.h"
bool UILayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    return true;
}
//UILayer * UILayer::instance()
//{
//    if( !_instance){
//        _instance = UILayer::create();
//    }
//    return _instance;
//}