//
//  BaseGameScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#include "BaseGameScene.h"
#include "BaseDialog1.h"
#include "VisibleRect.h"
#include "PlatFormer.h"
#include "Item.hpp"
#include "Enemy.hpp"
#include <string>

void BaseGameScene::onEnter()
{
    Layer::onEnter();
    if(NULL==map)
    {
        map=experimental::TMXTiledMap::create("map/map1.tmx");
        CCLOG("init map");
        
    }
 //   if (NULL == background) {
        background=Sprite::create("map/colored_land.png");
        background2 = Sprite::create("map/colored_land.png");
        
  //  }
    
   // background->setScale(0.5);
   // background->setAnchorPoint(Vec2(0,0));
    
    global->background = background;
    
    addChild(background,-1);
    addChild(background2,-1);
    parallaxNode = ParallaxNode::create();
    addChild(parallaxNode);
    global->scoreNum = 0;//初始化
    
    
    //parallaxNode-> addChild(map,1,Vec2(1,1),Vec2(0,0));
    
    
    addChild(map);
    global->map=map;
    TMXObjectGroup *objects = map->getObjectGroup("init");
    
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("player");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    
    
    //    Player * player=new Player();
    //    player->retain();
    //    global->player=player;
    Hero1 * hero = new Hero1(global->character_index);
    //player->setAnchorPoint(Vec2(0.5,0.5));
    global->player=hero;
    
    
    addChild(global->player);
    
 //   parallaxNode->addChild(global->player, 2, Vec2(1,1), Vec2(x,y));
    global->player->setPosition(Vec2(x,y));
    
    background->setPosition(hero->getPosition()-Vec2(0,200));
    background2->setPosition(background->getPosition()+Vec2(background->getContentSize().width,0));
    platformNode=Node::create();
    addChild(platformNode,1);
    
    global->platFormNode=platformNode;
    
    initPlateForm();
    
    initTMXTiledMap();
    
    schedule(schedule_selector(BaseGameScene::updateState),0.1);
    schedule(schedule_selector(BaseGameScene::updateBackground), global->fps);
    //    this->runAction(CCFollow::create(player,CCRectMake(0,0,map->getContentSize().width,map->getContentSize().height)));
    
}
Scene * BaseGameScene::createScene()
{
    Scene * scene=Scene::create();
    auto layer = new BaseGameScene();
    scene->addChild(layer,1);
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    
    //scene->addChild(layer->background,1);
    return scene;
    
}
void BaseGameScene::win(){
    BaseDialog1 * dialog = BaseDialog1::create();
    Button * nextButton = Button::create("images/dialog2.png");
    nextButton->setTitleText("么么");
    nextButton->setColor(Color3B::BLACK);
    nextButton->setScale9Enabled(true);
    nextButton->setCapInsets(Rect(15,15,80,80));
    nextButton->setContentSize(Size(60,40));
    nextButton->setPosition(Vec2(0,-30));
    dialog->addChild(nextButton,1);
    auto func = [&](Ref * reg, Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                //this->nextScene();
                this->scheduleOnce(schedule_selector(BaseGameScene::nextScene), 0.1);
               
                
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
        }
        
    };
    nextButton->addTouchEventListener(func);
    dialog->setPosition(VisibleRect::center());
    
    Label * label  = Label::create();
    label->setString("么么哒~");
    label->setColor(Color3B::BLACK);
    label->setPosition(Vec2(0,32));
    dialog->addChild(label, 1);
    this->getParent()->addChild(dialog,2);
    
}
void BaseGameScene::updateState(float dt){
    if(global->player->nowState==Role::dead&&global->player->isRecycled){
        //重新开始
        global->player->removeFromParent();
        global->hearts--;
        //global->player->changeState(Role::dead);
        // global->player->removeFromParent();
        Button * button =Button::create("images/dialog2.png");
        BaseDialog1 *dialog=BaseDialog1::create();
        dialog->addChild(button,1);
        button->setTitleText("再来");
        
        button->setTitleColor(COLOR_BLACK);
        button->setScale9Enabled(true);
        button->setCapInsets(Rect(15,15,80,80));
        button->setContentSize(Size(60,40));
        button->setPosition(Vec2(0,-30));
        auto func = [&](Ref * reg, Widget::TouchEventType type){
            switch (type) {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    break;
                case cocos2d::ui::Widget::TouchEventType::MOVED:
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:
                    this->restart();
                    CCLOG("dd");
                    
                    break;
                case cocos2d::ui::Widget::TouchEventType::CANCELED:
                    break;
            }
            
        };
        //button->addTouchEventListener(CC_CALLBACK_2(BaseGameScene::restartCallBack, this));
        button->addTouchEventListener(func);
        Label * label =Label::create();
        label->setString("heheda~");
        //  label->setDimensions(100, 100);
        label->setColor(COLOR_BLACK);
        label->setPosition(Vec2(0,30));
        dialog->addChild(label,1);
        dialog->setPosition(VisibleRect::center());
        
        
        this->getParent()->addChild(dialog,2);
        unscheduleAllCallbacks();
        
        
        
        
    }
    
    if (global->player->isWin) {
        win();
        unscheduleAllCallbacks();
    }
    
    
}
void BaseGameScene::restartCallBack(Ref * reg, Widget::TouchEventType type){
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            restart();
            //Director::getInstance()->replaceScene(TransitionFade::create(1, ChooseScene::createScene()));
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
}
void BaseGameScene::restart(){
    
}


void BaseGameScene::initPlateForm()
{
    TMXObjectGroup * objects= map->getObjectGroup("initplatform");
    if(objects!=NULL){
        for (auto & spawnPoint:objects->getObjects()) {
            ValueMap& dict = spawnPoint.asValueMap();
            int x = dict["x"].asInt();
            int y = dict["y"].asInt();
            PlatFormer * platformer= new PlatFormer();
            platformer->setPosition(Vec2(x,y));
            platformNode-> addChild(platformer);
            int distance = dict["move"].asInt();
            platformer->maxdistance=distance;
            
            platformer->moveID=dict["destination"].asInt();
            switch (platformer->moveID) {
                case 1:
                    //                    platformer->runAction(RepeatForever::create(Sequence::create(MoveBy::create(3, Vec2(-96,0)),MoveBy::create(3, Vec2(96,0)), NULL)));
                    platformer->_velocity=Vec2(1,0);
                    break;
                case 3:
                    platformer->_velocity=Vec2(0,1);
                    break;
                default:
                    break;
            }
        }
    }
}
void BaseGameScene::initTMXTiledMap(){
    TMXObjectGroup * objects= map->getObjectGroup("item");
    if (objects!=NULL) {
        for (auto & spawnPoint:objects->getObjects()) {
            ValueMap& dict = spawnPoint.asValueMap();
            int x = dict["x"].asInt();
            int y = dict["y"].asInt();
            int typeNum = dict["type"].asInt();
            Item * item ;
            switch (typeNum) {
                case 0:
                    item=new Item(Item::end);
                    break;
                case 1:
                    item = new Item(Item::coin);
                    break;
                case 2:
                    item = new Item(Item::diamond);
                    break;
                case 3:
                    item = new Item(Item::heart);
                    break;
                case 4:
                    item = new Item(Item::hiddenbox);
                    break;
                case 5:
                    item = new Item(Item::unhiddenbox);
                    break;
                default:
                    item = new Item(Item::platformer);
                    break;
            }
            item->setPosition(Vec2(x,y));
            addChild(item,1);
            
        }
    }
    TMXObjectGroup * enemies= map->getObjectGroup("enemies");
    if (enemies!=NULL) {
        for (auto & spawnPoint:enemies->getObjects()) {
            ValueMap& dict = spawnPoint.asValueMap();
            int x = dict["x"].asInt();
            int y = dict["y"].asInt();
            
            string s = dict["name"].asString();
            log("dd:%s",s.c_str());
            Enemy * enemy = new Enemy(s);
            enemy->setPosition(Vec2(x,y));
            addChild(enemy,1);
        }
    }
}
void BaseGameScene::nextScene(float dt){
    
}
void BaseGameScene::updateBackground(float dt){
    Point p = global->player->getPosition();
    Size size = Director::getInstance()->getWinSize();
    Point worldp = global->player->getParent()->convertToWorldSpaceAR(p);
    //log("%f,%f",worldp.x,worldp.y);
    Point centerOfView = Point(size.width / 2, size.height / 2);
    if (abs((worldp-centerOfView).x)<=10) {
        
        if (global->player->isOnPlatFormer) {
            background->setPosition(background->getPosition()+(global->player->_horizontalvelocity+global->player->onFormNode->_velocity)/3);
            background2->setPosition(background2->getPosition()+(global->player->_horizontalvelocity+global->player->onFormNode->_velocity)/3);

        }
        else{
            background->setPosition(background->getPosition()+global->player->_horizontalvelocity/1.2);
            background2->setPosition(background2->getPosition()+global->player->_horizontalvelocity/1.2);

        }
        
    }
    if (abs((worldp-centerOfView).y)<=10) {
        if (global->player->isOnPlatFormer) {
            background->setPosition(background->getPosition()+(global->player->_velocity+global->player->onFormNode->_velocity)/3);
            background2->setPosition(background2->getPosition()+(global->player->_velocity+global->player->onFormNode->_velocity)/3);

        }
        else{
            background->setPosition(background->getPosition()+global->player->_velocity/1.5);
            background2->setPosition(background2->getPosition()+global->player->_velocity/1.5);

        }
     //   background->setPosition(background->getPosition()+global->player->_velocity/1.5);
        
    }
    
}

