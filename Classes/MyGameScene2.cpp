//
//  MyGameScene2.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/20.
//
//

#include "MyGameScene2.h"
MyGameScene2::MyGameScene2()
{
    map=TMXTiledMap::create("map/map3.tmx");
    // background=Sprite::create("map/blue_shroom.png");
}
Scene* MyGameScene2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = new MyGameScene2();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer,1);
    // return the scene
    //schedule(schedule_selector(MyGameScene::updateEvent), 0.1);
    //scene->addChild(layer->background,0);
    return scene;
}
void MyGameScene2::updateEvent(float dt)
{
    // int x=global->player->getPosition().x;
    
    
}
void MyGameScene2::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
    Vec2 * positions=new Vec2[10];
    
    
    
    schedule(schedule_selector(MyGameScene2::updateEvent), 1);
    
}
void MyGameScene2::restart()
{
    Director::getInstance()->replaceScene(TransitionFade::create(1, MyGameScene2::createScene()));
}


