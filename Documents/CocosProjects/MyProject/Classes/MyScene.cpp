//
//  MyScene.cpp
//  MyProject
//
//  Created by 丁逸鹏 on 15/4/16.
//
//

#include "MyScene.h"
Scene* MyScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MyScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MyScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
//    auto red = LayerColor::create(Color4B(255, 100, 100, 128), visibleSize.width/2, visibleSize.height/2);
//    
//    auto green = LayerColor::create(Color4B(100, 255, 100, 128), visibleSize.width/4, visibleSize.height/4);
//    
//    red->addChild(green);
//    
//    this->addChild(red, 0);
    
    
    auto red = LayerColor::create(Color4B(255, 100, 100, 255), visibleSize.width/2, visibleSize.height/2);
    
    red->ignoreAnchorPointForPosition(false);
    red->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    auto green = LayerColor::create(Color4B(100, 255, 100, 255), visibleSize.width/4, visibleSize.height/4);
    green->ignoreAnchorPointForPosition(false);
    green->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 - 100));
    red->setPositionZ(1);
    green->setPositionZ(0);
    this->addChild(red, 0);
    this->addChild(green, 1);
    
    return true;
}