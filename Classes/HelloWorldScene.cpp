#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Hero1.h"
#include "ChooseScene.h"
#include "ChooseCharacter.hpp"
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
    
    auto uilayer = Layer::create();
    uilayer->addChild(layer->uiNode);
    scene->addChild(uilayer);
   // scene->addChild(layer->uiNode);
    
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
    uiNode = CSLoader::createNode("MainScene.csb");

    
    map = experimental::TMXTiledMap ::create("map/map.tmx");
    global->map=map;
    platFormNode=Node::create();
    global->platFormNode=platFormNode;
    addChild(platFormNode);
    addChild(map,0);
    Hero1 * hero= new Hero1(global->character_index);
    TMXObjectGroup *objects = map->getObjectGroup("init");
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("player");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    
    
    
    hero->setPosition(Vec2(x,y));
    global->player=hero;
    addChild(hero,1);
    Button * button = static_cast<Button*>(uiNode->getChildByName("Button_1"));
    button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touch, this));
    Button * button2 = static_cast<Button*>(uiNode->getChildByName("Button_2"));
    button2->addTouchEventListener(CC_CALLBACK_2(HelloWorld::select, this));
    
    
    Button * startButton = Button::create("PNG/buttonLong_brown.png","PNG/buttonLong_brown_pressed.png");
    startButton->setTitleText("play");
    startButton->setScale9Enabled(true);
    startButton->setContentSize(Size(startButton->getContentSize().width/1.5,startButton->getContentSize().height/1.3));
    startButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touch, this));
    auto point = objects->getObject("startButton");
    int x2 = point["x"].asInt();
    int y2 = point["y"].asInt();
    
    startButton->setPosition(Vec2(x2,y2));
    addChild(startButton, 1);
    return true;
}
void HelloWorld::touch(Ref * ref,Widget::TouchEventType type){
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            Director::getInstance()->replaceScene(TransitionFade::create(1, ChooseScene::createScene()));
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
    //  Sprite *sprite=Sprite::create("res/");
}
void HelloWorld::select(Ref * ref,Widget::TouchEventType type){
    ChooseDialog * dialog;
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            dialog=ChooseDialog::create();
            
            dialog->setPosition(VisibleRect::center());
            //dialog->setPosition(VisibleRect::center());
            this->getParent()->addChild(dialog,2);
            
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
    //  Sprite *sprite=Sprite::create("res/");
}
void HelloWorld::initHero(){
    Hero1 * hero= new Hero1(global->character_index);
    TMXObjectGroup *objects = map->getObjectGroup("init");
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("player");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    
    
    
    hero->setPosition(Vec2(x,y));
    global->player=hero;
    addChild(hero,1);

}