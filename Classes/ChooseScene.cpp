
//
//  ChooseScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#include "ChooseScene.h"
#include "HelloWorldScene.h"
#include "MyGameScene.h"
#include "MyGameScene1.h"
#include "SpriteBlur.h"
#include "MyGameScene2.h"
#include "GatesNode.hpp"

Scene* ChooseScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ChooseScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool ChooseScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
//    
//    SpriteBlur * spriteblur = SpriteBlur::create("map/colored_grass.png");
//    spriteblur->setBlurRadius(20);
////    
//    spriteblur->setPosition(Vec2(0,0));
//    spriteblur->setAnchorPoint(Vec2(0,0));
//    spriteblur->setScale(0.5);
//    addChild(spriteblur,0);
    
    auto ui = CSLoader::createNode("ChooseScene.csb");
    
    addChild(ui,1);
    
    PageView * chooseNode = static_cast<PageView *>(ui->getChildByName("ChoosePageView"));
    
    
    
    
    chooseNode->setPositionY(VisibleRect::screenSize().height/2);
    
    Vector<Layout * > pages =  chooseNode->getPages();
    
    
    
    int n = 5;//拖动灵敏度
    
    initGateNode(chooseNode);
    
    for (int i = 0; i <pages.size(); i++) {
        auto pagecopy = pages.at(i);
        Point p  = pagecopy->getPosition();
        
        
        
        auto func = [=](Ref * reg, Widget::TouchEventType type){
            auto page = pages.at(i);
         //   auto p = pagecopy->getPosition();
            switch (type) {
                    
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    global->nowchoosePoint = page->getPosition();
                    break;
                case cocos2d::ui::Widget::TouchEventType::MOVED:
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:
                    
                    break;
                case cocos2d::ui::Widget::TouchEventType::CANCELED:
                    Size size = page->getContentSize();
                    Point laterpoint = page->getPosition();
                    long index1 = chooseNode->getCurPageIndex();
                    //log("p.x:%f,pl.x:%f,size:%f,index:%ld",global->nowchoosePoint.x,laterpoint.x,size.width,index1);
                    if ( global->nowchoosePoint.x - laterpoint.x>size.width/n&&index1<pages.size()-1) {
                        chooseNode->scrollToPage(index1+1);
                     //   log("+1");
                    }else if(global->nowchoosePoint.x-laterpoint.x<-size.width/n&&index1>0){
                    //    log("-1");
                        chooseNode->scrollToPage(index1-1);
                    }
//                    if (size.width/2>p.x&&p.x>size.width/n&&i>0  ) {
//                         log("canceled");
//                        chooseNode->scrollToPage(i-1);
//                    }else if(-size.width/2<p.x && p.x< -size.width/n && i <pages.size()-1){
//                        chooseNode->scrollToPage(i+1);
//                        
//                    }
                    
                    break;
            }
            
        };
        
        pagecopy->addTouchEventListener(func);
    }
 
    
    
    
    //chooseNode->se
    
    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_Left"));
//    Button * button_Left = Button ::create("transparentLight");
//    button_Left->setPosition(VisibleRect::mleft());
//    addChild(button_Left);
    button_Left->addTouchEventListener(CC_CALLBACK_2(ChooseScene::chooseleft, this));
    
    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_Right"));
  //  Button * button_Right = Button::create("");
    button_Right->addTouchEventListener(CC_CALLBACK_2(ChooseScene::chooseright, this));
    
    
 //   Button * button_Choose = static_cast<Button *>(ui->getChildByName("Button_Start"));
    
//    button_Choose->addTouchEventListener(CC_CALLBACK_2(ChooseScene::choose, this));
    
//    Button * button_Back = static_cast<Button *>(ui->getChildByName("Button_Back"));
//    
//    button_Back->addTouchEventListener(CC_CALLBACK_2(ChooseScene::back, this));
    
    Button * button_Back2 = Button::create("transparentLight/transparentLight22.png");
    button_Back2->setPosition(VisibleRect::leftTop()+Vec2(5,-5));
    button_Back2->setAnchorPoint(Vec2(0,1));
    button_Back2->setScale(0.5);
    button_Back2->addTouchEventListener(CC_CALLBACK_2(ChooseScene::back, this));
    addChild(button_Back2);
    mainNode =Node::create();
    mainNode->setAnchorPoint(Vec2(0,0.5 ));
    
    Sprite * chooseSprite1  = Sprite::create("map/blue_desert.png");
    mainNode->addChild(chooseSprite1);
    chooseSprite1->setScale(0.15);
    chooseSprite1->setPosition(Vec2(0,0));
    
    
    Sprite * chooseSprite2  = Sprite::create("map/colored_grass.png");
    mainNode->addChild(chooseSprite2);
    chooseSprite2->setScale(0.15);
    chooseSprite2->setPosition(Vec2(480,0));
    
    Sprite * chooseSprite3  = Sprite::create("map/colored_shroom.png");
    mainNode->addChild(chooseSprite3);
    chooseSprite3->setScale(0.15);
    chooseSprite3->setPosition(Vec2(960,0));
    
    sceneIndex=0;
    
    mainNode->setPosition(VisibleRect::center());
   // addChild(mainNode,0);
    return true;
}
void ChooseScene::choose(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            switch (sceneIndex) {
                case 0:
                   Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene::createScene()));
                    break;
                case 1:
                    Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene1::createScene()));
                    break;
                case 2:
                    Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene2::createScene()));
                    break;
                default:
                    break;
            }
        
            break;
        default:
            break;
    }
}
void ChooseScene::back(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
               Director::getInstance()->replaceScene(TransitionFade::create(1,HelloWorld::createScene()));
            
            break;
        default:
            break;
    }
}
void ChooseScene::chooseleft(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            if(sceneIndex>0){
                mainNode->runAction(MoveBy::create(0.3, Vec2(480,0)));
                sceneIndex--;
            }
            break;
        default:
            break;
    }
}
void ChooseScene::chooseright(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            if(sceneIndex<2){
                mainNode->runAction(MoveBy::create(0.3, Vec2(-480,0)));
                sceneIndex++;
            }
            break;
        default:
            break;
    }
}
void ChooseScene::initGateNode(PageView * chooseNode){
   Vector<Layout * > pages =  chooseNode->getPages();
 
    Node * gate = chooseNode->getChildByName("Panel_1")->getChildByName("gate_1");
//    gates[0]=pages.at(0)->getChildByName("gate_1");
//    gates[1]=pages.at(1)->getChildByName("gate_2");
//    gates[2]=pages.at(2)->getChildByName("gate_3");
    
    Vec2 center = gate->getPosition();
    Size size = gate->getContentSize();
    Vec2 *positions = new Vec2[4];
    
    float param = 4.5;
    positions[0]=Vec2(-size.width/param,size.height/param)+center;
    positions[1]=Vec2(size.width/param,size.height/param)+center;
    positions[2]=Vec2(-size.width/param,-size.height/param)+center;
    positions[3]=Vec2(size.width/param,-size.height/param)+center;
    for (int i = 1; i <= 12; i++) {
        if(i/4<=pages.size()){
            GatesNode * gatenode;
            if (i<=3) {
                gatenode = new GatesNode(i,false,(i-1)/4);
            }else{
                gatenode = new GatesNode(i,true,(i-1)/4);
            }
            
            gatenode->setPosition(positions[(i-1)%4]);
            
            pages.at((i-1)/4)->addChild(gatenode);
        }
    }
}