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
void BaseGameScene::onEnter()
{
    Layer::onEnter();
    if(NULL==map)
    {
        map=TMXTiledMap::create("map/map1.tmx");
        CCLOG("init map");
       // background=Sprite::create("map/blue_shroom.png");
    }
//    background->setScale(0.5);
//    background->setAnchorPoint(Vec2(0,0));
    addChild(map);
    global->map=map;
    TMXObjectGroup *objects = map->getObjectGroup("init");
    auto layer = map ->getLayer("ground");
    for (auto & spawnPoint:objects->getObjects()) {
        ValueMap& dict = spawnPoint.asValueMap();
        int x = dict["x"].asInt();
        int y = dict["y"].asInt();
        auto tile= layer->getTileAt(global->tileCoordForPosition(Point(x,y)));
        //  layer->setTileGID(0, global->tileCoordForPosition(Point(x,y)));//初始化踩空
        switch (dict["move"].asInt()) {
            case 1:
                //左->右
                tile->runAction(RepeatForever::create(Sequence::create(MoveBy::create(3, Vec2(-96,0)),MoveBy::create(3, Vec2(96,0)), NULL)));
                
                break;
            case 2:
                //右->左
                tile->runAction(RepeatForever::create(Sequence::create(MoveBy::create(3, Vec2(96,0)),MoveBy::create(3, Vec2(-96,0)), NULL)));
                
                break;
                
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
        
    }

    schedule(schedule_selector(BaseGameScene::updatetileID),global->fps);
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("player");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
   
    
//    Player * player=new Player();
//    player->retain();
//    global->player=player;
    Hero1 * hero = new Hero1();
    //player->setAnchorPoint(Vec2(0.5,0.5));
    global->player=hero;
    addChild(global->player);
    global->player->setPosition(Vec2(x,y));
    
    platformNode=Node::create();
    addChild(platformNode,1);
    
    global->platFormNode=platformNode;
    
    initPlateForm();
    schedule(schedule_selector(BaseGameScene::updateState),0.1);
    
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
void BaseGameScene::updatetileID(float dt){
    
}
void BaseGameScene::updateState(float dt){
    if(global->player->nowState==Role::dead){
        //重新开始
        
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