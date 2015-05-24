//
//  MyScene.h
//  MyProject
//
//  Created by 丁逸鹏 on 15/4/16.
//
//

#ifndef __MyProject__MyScene__
#define __MyProject__MyScene__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class MyScene :public Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MyScene);
    
    

};


#endif /* defined(__MyProject__MyScene__) */
