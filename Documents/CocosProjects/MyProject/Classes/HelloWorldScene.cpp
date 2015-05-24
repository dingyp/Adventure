#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
//    Sprite * sprite =Sprite::create("hero1.png");
//    sprite->setPosition(Vec2(300,300));
//    sprite->setTag(1);
//    addChild(sprite,1);
//    
//    Sprite * background =Sprite::create("bg.png");
//    background->setAnchorPoint(Vec2(0,0));
//    addChild(background,0);
//    time=0;
//    time2=0;
//    scheduleUpdate();
//    schedule(schedule_selector(HelloWorld::updatePosition), 1);
    
    SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("pastries.plist","parstries1.png");
    
    Sprite * sprite = Sprite::createWithSpriteFrameName("1.png");
    sprite->setScale(2);
    sprite->setAnchorPoint(Vec2(0,0));
    sprite->setPosition(Point(0,0));
    
    
    
    addChild(sprite);
    
    Sprite * sprite2= Sprite::createWithSpriteFrameName("2.png");
    sprite->addChild(sprite2);
    sprite2->setPosition(Vec2(200,-200));
    
    return true;
}
void HelloWorld::update(float dt)
{
    
//    Node * node =this->getChildByTag(1);
//    Point p=node->getPosition();
//    if(p.y>300){
//        node->setPosition(Point(p.x,p.y-5));
//    }
    
    
    
    time+=dt;
    CCLOG("time1:%f",time);
}
void HelloWorld::updatePosition(float dt)
{
    time2+=dt;
    CCLOG("time2:%f",time2);
}