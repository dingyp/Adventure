//
//  DialogNode.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/27.
//
//

#include "DialogNode.h"
bool DialogNode::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Node::init() )
    {
        return false;
    }
    CCLOG("init node");
        return true;
}
void DialogNode::onEnter(){
    Node::onEnter();
    CCLOG("onEnter");
    //dialogsprite=Scale9Sprite::create("images/dialog1.png");
    auto node = CSLoader::createNode("DialogNode.csb");
    this->addChild(node);
    
    Button * buttonClose = static_cast<Button*>(node->getChildByName("dialog")->getChildByName("Button_Close"));
    Button * buttonOk= static_cast<Button*>(node->getChildByName("dialog")->getChildByName("Button_Ok"));
    buttonClose->addTouchEventListener(CC_CALLBACK_2(DialogNode::closeCallBack,this));
    buttonOk->addTouchEventListener(CC_CALLBACK_2(DialogNode::closeCallBack, this));

}
void DialogNode::closeCallBack(Ref * ref,Widget::TouchEventType type)
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
void DialogNode::close(){
    this->removeAllChildren();
}