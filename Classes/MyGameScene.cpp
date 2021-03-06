//
//  MyGameScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#include "MyGameScene.h"
#include "IncludeScene.hpp"

MyGameScene::MyGameScene()
{
    map= cocos2d::experimental::TMXTiledMap::create("map/map1.tmx");// experimental::TMXTiledMap::create("map/map2.tmx");
    
  //   background=Sprite::create("map/blue_shroom.png");
}
Scene* MyGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = new MyGameScene();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer,1);
    // return the scene
    //schedule(schedule_selector(MyGameScene::updateEvent), 0.1);
  //  scene->addChild(layer->background,0);
    return scene;
}
void MyGameScene::updateEvent(float dt)
{
   // int x=global->player->getPosition().x;
    
    
}
void MyGameScene::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
 
    schedule(schedule_selector(MyGameScene::updateEvent), 1);
    
}

void MyGameScene::restart()
{
    Director::getInstance()->replaceScene(TransitionFade::create(1, MyGameScene::createScene()));
}

void MyGameScene::nextScene(float dt){
     Director::getInstance()->replaceScene(TransitionFade::create(1, MyGameScene1::createScene()));
}
