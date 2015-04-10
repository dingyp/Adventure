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
    
    Sprite * sprite =Sprite::create("hero1.png");
    sprite->setPosition(Vec2(100,400));
    sprite->setTag(1);
    addChild(sprite,1);
    
    Sprite * background =Sprite::create("bg.png");
    background->setAnchorPoint(Vec2(0,0));
    addChild(background,0);
    scheduleUpdate();
    return true;
}
void HelloWorld::update(float dt)
{
    Node * node =this->getChildByTag(1);
    Point p=node->getPosition();
    if(p.y>96){
        node->setPosition(Point(p.x,p.y-5));
    }
    
    CCLOG("update");
}