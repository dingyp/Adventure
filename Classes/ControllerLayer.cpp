//
//  ControllerLayer.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#include "ControllerLayer.h"
#include "ChooseScene.h"
bool ControllerLayer::init()
{
    CCLOG("Layer init");
    if ( !Layer::init() )
    {
        return false;
    }
    inputNum=0;
    auto ui=CSLoader::createNode("ControllerLayer.csb");
    addChild(ui);
    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_left"));

    button_Left->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveleft, this));

    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_right"));

    button_Right->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveright, this));
    
    Button * button_Jump = static_cast<Button *>(ui->getChildByName("Button_jump"));
    
    button_Jump->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::jump, this));
    
    Button * button_Back = static_cast<Button * >(ui->getChildByName("Button_Back"));
    
    button_Back->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::back,this));
    
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(ControllerLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(ControllerLayer::onKeyReleased, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}
void ControllerLayer::moveright(Ref *ref,Widget::TouchEventType type)
{
    
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::rightwalk);
//            global->player->setNowDestination(Role::right);
//            global->player->changeState(walk);
            break;
            //	case (int)(cocos2d::ui::Widget::TouchEventType::MOVED):
            
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(Role::idle);
            
            
            break;
        default:
            break;
    }
    
    
}
void ControllerLayer::moveleft(Ref *ref,Widget::TouchEventType type)
{
    auto actionmove=RepeatForever::create(MoveBy::create(0.1,Vec2(-5,0)));
    actionmove->setTag(2);
    
    
    //auto game=GameScene::createScene();
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::leftwalk);
//            global->player->setNowDestination(Role::left);
//            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(Role::idle);
        
            break;
        default:
            break;
    }
}
void ControllerLayer::jump(Ref *ref,Widget::TouchEventType type)
{
    
    
    //auto game=GameScene::createScene();
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::jump);
            //            global->player->setNowDestination(Role::left);
            //            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
           // global->player->changeState(Role::idle);
            
            break;
        default:
            break;
    }
}

void ControllerLayer::back(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
           
         
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            
             Director::getInstance()->replaceScene(TransitionFade::create(1,ChooseScene::createScene()));
            break;
        default:
            break;
    }
}


void ControllerLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key with keycode %d pressed", keyCode);
    switch ((int)keyCode) {
        case 27:
            //->键
            global->player->changeState(Role::rightwalk);
            inputNum++;
            break;
        case 26:
            //<－键
            global->player->changeState(Role::leftwalk);
            inputNum++;
            break;
        case 59:
            //alt
             global->player->changeState(Role::jump);
            break;
        default:
            break;
    }
}
void ControllerLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key with keycode %d released", keyCode);
    
    switch ((int)keyCode) {
        case 27:
            
            //->键
            //
            inputNum--;
            break;
        case 26:
            //  global->player->changeState(Role::idle);
            inputNum--;
            //<－键
            break;
        case 16:
            break;
        default:
            break;
    }
    
    if (inputNum<=0) {
        global->player->changeState(Role::idle);
        inputNum=0;
        
    }
}