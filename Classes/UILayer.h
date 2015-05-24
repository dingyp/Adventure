//
//  UILayers.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/28.
//
//

#ifndef __KaziProject__UILayers__
#define __KaziProject__UILayers__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Global.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;
class UILayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(UILayer);
    //static UILayer * instance();
    //static UILayer * _instance;
};
#endif /* defined(__KaziProject__UILayers__) */
