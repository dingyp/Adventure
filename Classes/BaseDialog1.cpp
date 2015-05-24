//
//  BaseDialog1.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/4.
//
//

#include "BaseDialog1.h"
#include "VisibleRect.h"
#include <iostream>

bool BaseDialog1::init(){
    if(!Layer::init()){
        return false;
    }
    dialogSize=Size(150,150);
    
    
//    auto node = CSLoader::createNode("DialogNode.csb");
//    this->addChild(node);
//    
//    Button * buttonClose = static_cast<Button*>(node->getChildByName("dialog")->getChildByName("Button_Close"));
//    Button * buttonOk= static_cast<Button*>(node->getChildByName("dialog")->getChildByName("Button_Ok"));
//    buttonClose->addTouchEventListener(CC_CALLBACK_2(BaseDialog1::closeCallBack,this));
//    buttonOk->addTouchEventListener(CC_CALLBACK_2(BaseDialog1::closeCallBack, this));
    auto listener = EventListenerTouchOneByOne::create();
    auto callback = [](Touch * ,Event *)
    
    {
        CCLOG("ss");
        return true;
        
    };
    listener->onTouchBegan = callback;
    
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}
void BaseDialog1::onEnter(){
    Layer::onEnter();
   // SpriteFrame * texture= SpriteFrame::create("");
     background = Scale9Sprite::create("images/dialog2.png");//,Rect(0,0,55,65),Rect(30, 30, 1,1));
    //background->set
   // background->setPosition(Vec2(0,0));
    //background->set
    
    
    background->setPreferredSize(dialogSize);
    Button * closeButton = Button::create("images/close.png");
    background->addChild(closeButton);
    
    this->setAnchorPoint(Vec2(0.5,0.5));
    closeButton->setPosition(Vec2(dialogSize.width,dialogSize.height));
    closeButton->addTouchEventListener(CC_CALLBACK_2(BaseDialog1::closeCallBack, this));
    //closeButton->addTouchEventListener(CC_CALLBACK_2([](Ref * ref,Widget::TouchEventType type){}, this));
    this->addChild(background);
}
void BaseDialog1::closeCallBack(Ref * ref,Widget::TouchEventType type)
{
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            close();
            //Director::getInstance()->replaceScene(TransitionFade::create(1, ChooseScene::createScene()));
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
    
}
void BaseDialog1::close(){
    //this->removeAllChildren();
    this->removeFromParent();
}