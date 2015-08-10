//
//  ChooseCharacter.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/8/10.
//
//

#include "ChooseCharacter.hpp"
#include "Global.h"
#include "Hero1.h"
#include "HelloWorldScene.h"
void ChooseDialog::close(){
    CCLOG("child call");
    BaseDialog1::close();
    //DialogNode::close();
}
bool ChooseDialog::init(){
    if(!BaseDialog1::init()){
        return false;
    }
    dialogSize=Size(300,200);
    
 //   chooseView = static_cast<PageView * >(CSLoader::createNode("ChooseCharacter.csb"));
    chooseView = PageView::create();
    chooseView->retain();
    chooseView->setClippingEnabled(true);
    chooseView->setContentSize(Size(300,200));
    chooseView->setAnchorPoint(Vec2(0.5,0.5));
    chooseView->addPage(createLayout("hero3walk1.png","我是一只可爱的小猴子\nhhhhhhhhhhhhhhhhhhhhhhh"));
    chooseView->addPage(createLayout("hero3walk1.png","我也是哦～"));
    chooseView->addPage(createLayout("saw.png","选择我有惊喜 >_<"));
    
    addChild(chooseView,1);
    
    Label * label = Label::create();
    label->setPosition(Vec2(0,70));
    addChild(label,1);
    label->setString("< 人物选择 >");
    
    label->setTextColor(Color4B::BLACK);
    this->setCloseButton();
    
    Button * button =Button::create("images/dialog2.png");
    addChild(button,1);
    button->setTitleColor(COLOR_BLACK);
    button->setTitleText("选择");
    
    //  button->set
    button->setScale9Enabled(true);
    button->setCapInsets(Rect(15,15,80,80));
    button->setContentSize(Size(60,40));
    button->setPosition(Vec2(0,-60));
    
    auto choosefunc = [&](Ref * ref,Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                int index;
                index = (int)chooseView->getCurPageIndex();
               
                close();
                UserDefault::getInstance()->setIntegerForKey("character_index",index);
                global->character_index = index;
                HelloWorld * parentScene;
                parentScene = static_cast<HelloWorld * >(global->player->getParent());
                global->player->removeFromParent();
                parentScene->initHero();
                
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
        }

    };
    
    button->addTouchEventListener(choosefunc);
    
    return true;
    
}
Layout * ChooseDialog::createLayout(){
    Layout * layout = Layout::create();
    
    Sprite * sprite = Sprite::createWithSpriteFrameName("hero3walk1.png");
    layout->addChild(sprite,1);
    sprite->setPosition(Vec2( 50,120));
    
    return layout;
}
Layout * ChooseDialog::createLayout(string fname,string introduction){
    Layout * layout = Layout::create();
    
    Scale9Sprite * sprite = Scale9Sprite::createWithSpriteFrameName(fname);
    sprite->setCapInsets(Rect(0,0,sprite->getContentSize().width,sprite->getContentSize().height));
    layout->addChild(sprite,1);
    sprite->setPosition(Vec2( 50,120));
    sprite->setContentSize(Size(64,64));
    
    
    Label * label = Label::create();
    label->setDimensions(128, 64);
    label->setVerticalAlignment(TextVAlignment::TOP);
    label->setHorizontalAlignment(TextHAlignment::LEFT);
    label->setTextColor(Color4B::BLACK);
    label->setPosition(Vec2(190,120));
    label->setString(introduction);
    layout->addChild(label,1);
    
    return layout;
}
