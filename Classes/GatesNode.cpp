//
//  GatesNode.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/8.
//
//

#include "GatesNode.hpp"
GatesNode::GatesNode(int num,bool isLocked,int choice = 0){
    gateNum = num;
    this->isLocked = isLocked;
    this->choice = choice;
}

void GatesNode::onEnter(){
    Node::onEnter();
    Button * background;
//    switch (choice) {
//        case 0:
//            background = Button::create("images/UI/buttonSquare_beige_pressed.png");
//            break;
//        case 1:
//            background = Button::create("images/UI/buttonSquare_brown_pressed.png");
//            break;
//        case 2:
//            
//        default:
//            background = Button::create("images/UI/buttonSquare_beige_pressed.png");
//            break;
//    }
    
    background = Button::create("images/dialog2.png");
    
    background->setSwallowTouches(false);
    background->setScale9Enabled(true);
    background->setCapInsets(Rect(15,15,80,80));
    //background->setContentSize(Size(60,40));

    background->setContentSize( (background->getContentSize()*0.6));
    addChild(background);
    gateNumSprite = LabelAtlas::create("0123456789", "images/shu.png",26,31,'0');
    char spname[30];
    sprintf(spname,"%d",gateNum);
    gateNumSprite->setString(spname);
    gateNumSprite->setScale(0.7);
    gateNumSprite->setAnchorPoint(Vec2(0.5,0.5));
    gateNumSprite->setPosition(Vec2(background->getContentSize()/2));
    Sprite * lock = Sprite::create("images/lock2.png");
    lock->setPosition(Vec2(background->getContentSize()/2));
    lock->setScale(0.5);
    if (isLocked) {
        background->addChild(lock);
    }else{
        background->addChild(gateNumSprite);
    }
    
    auto callback =  [=](Ref * reg, Widget::TouchEventType type){
        switch (type) {
                
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                log("clicked");
                
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                
           //     break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
              //  log("ss");
                switch (gateNum) {
                    case 1:
                        Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene::createScene()));
                        break;
                    case 2:
                        Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene1::createScene()));
                        break;
                    case 3:
                        Director::getInstance()->replaceScene(TransitionFade::create(1,MyGameScene2::createScene()));
                        break;
                    default:
                        break;
                }
                break;
        }
        
    };
    if (!isLocked) {
        background->addTouchEventListener(callback);
    }
    
   // this->setScale(0.6);
    
}
