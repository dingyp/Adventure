//
//  StartScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/15.
//
//

#include "StartScene.hpp"
#include "Define.h"
#include "VisibleRect.h"
#include "HelloWorldScene.h"
Scene * StartScene ::createScene(){
    Scene * scene = Scene::create();
    scene->addChild(StartScene::create());
    return scene;
}

bool StartScene::init(){
    
    if (!Layer::init()) {
        return false;
    }
    m_iNumOfLoad = 0;
    schedule(schedule_selector(StartScene::updateState),0.1);
    
    numLabel = Label::create();
    numLabel->setPosition(VisibleRect::center());
    numLabel->setTextColor(Color4B::BLACK);
    addChild(numLabel);
    char str[25];
    sprintf(str, "加载纹理中 ::>_<::");
    numLabel->setString(str);
    
    
    Director::getInstance()->getTextureCache()->addImageAsync("herostay.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("herowalk.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("hero2.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/hero3.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/grasstile.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/item.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/item2.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/enemies.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    Director::getInstance()->getTextureCache()->addImageAsync("images/tiles.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));

    Director::getInstance()->getTextureCache()->addImageAsync("images/baozi.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));

    
    return true;
}
void StartScene::loadingTextureCallBack(Texture2D * texture)
{
    switch (m_iNumOfLoad++)
    {
        case 0:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("herostay.plist",texture);
            break;
        case 1:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("herowalk.plist",texture);
            break;
        case 2:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero2.plist",texture);
            break;
        case 3:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/hero3.plist",texture);

            break;
        case 4:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/grasstile.plist",texture);

            break;
        case 5:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/item.plist",texture);

            break;
        case 6:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/item2.plist",texture);
 
            break;
        case 7:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/enemies.plist",texture);

            break;
        case 8:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/tiles.plist",texture);
            break;
        case 9:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/baozi.plist",texture);
            break;
            
    }
    log("%d",m_iNumOfLoad);
}
void StartScene::updateState(float dt){
    char str[25];
    sprintf(str, "加载纹理中 ::>_<:: ");
    numLabel->setString(str);
    if (m_iNumOfLoad>=10) {
        scheduleOnce(schedule_selector(StartScene::nextScene), 0.5);
        this->unschedule(schedule_selector( StartScene::updateState));
    }
}

void StartScene::nextScene(float dt){
    auto scene = HelloWorld::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}