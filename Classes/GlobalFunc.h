
//
//  GlobalFunc.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__GlobalFunc__
#define __KaziProject__GlobalFunc__

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.h"
#include "Global.h"
using namespace cocos2d;
class GlobalFunc:public Singleton<GlobalFunc>

{
public:
//    Animation * createAni(Texture2D * texture,int row,int col,int frames);
//    Point  tileCoordForPosition(Point pos);//用于游戏坐标换算到地图坐标
//    Point  positionCoordForTile(Point pos);//用于地图坐标换算到游戏坐标
};

#define globalFunc GlobalFunc::instance()

#define DECLARE_SINGLETON_MEMBER(_Ty)	\
template <> _Ty* Singleton<_Ty>::_instance = NULL;



#endif