//
//  StartScene.hpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/15.
//
//

#ifndef StartScene_cpp
#define StartScene_cpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class StartScene : public Layer{
public:
    
    virtual bool init();
    CREATE_FUNC(StartScene);
    static Scene * createScene();
    // 资源加载
    void loadingTextureCallBack(Texture2D * texture);
    
    void updateState(float dt);
    
    void nextScene(float dt);
    Label *  numLabel;
    int m_iNumOfLoad;
};
#endif /* StartScene_cpp */
