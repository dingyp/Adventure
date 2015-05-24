//
//  ChooseNode.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/23.
//
//

#include "ChooseNode.h"
bool ChooseNode::init(){
    if(!Node::init()){
        return  false;
    }
    
    auto ui = CSLoader::createNode("ChooseNode.csb");
    
    addChild(ui,1);
    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_Left"));
    
    button_Left->addTouchEventListener(CC_CALLBACK_2(ChooseNode::chooseleft, this));
    
    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_Right"));
    
    button_Right->addTouchEventListener(CC_CALLBACK_2(ChooseNode::chooseright, this));
    
    
    Button * button_Choose = static_cast<Button *>(ui->getChildByName("Button_Choose"));
    
    button_Choose->addTouchEventListener(CC_CALLBACK_2(ChooseNode::choose, this));
    return true;
}
void ChooseNode::choose(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            
            break;
        default:
            break;
    }
}
void ChooseNode::chooseleft(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            if(index>0){
                this->runAction(MoveBy::create(1, Vec2(480,0)));
                index--;
            }
            break;
        default:
            break;
    }
}
void ChooseNode::chooseright(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            if(index<length-1){
                this->runAction(MoveBy::create(1, Vec2(-480,0)));
                index++;
            }
            break;
        default:
            break;
    }
}