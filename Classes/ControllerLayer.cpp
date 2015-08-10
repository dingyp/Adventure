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
    button_Left->setSwallowTouches(false);
    //button_Left->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveleft, this));
    
    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_right"));
    button_Right->setSwallowTouches(false);
    
    //button_Right->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveright, this));
    
    Button * button_Jump = static_cast<Button *>(ui->getChildByName("Button_jump"));
    
    button_Jump->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::jump, this));
    Button * button_Back2 = Button::create("transparentLight/transparentLight43.png");
    button_Back2->setPosition(VisibleRect::mrightTop());
    button_Back2->setScale(0.6);
    button_Back2->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::back, this));
    addChild(button_Back2);
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(ControllerLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(ControllerLayer::onKeyReleased, this);
    
    
    
    auto heartNode = Node::create();
    Scale9Sprite * background = Scale9Sprite::create("images/dialog2.png");
    background->setAnchorPoint(Vec2(0.3,0.72));
    background->setPreferredSize(Size(70,70));
    heartNode-> addChild(background,-1);
    
    Sprite * heart  = Sprite::createWithSpriteFrameName("hudHeart_full.png");
    heart->setScale(0.25);
    heartNode->addChild(heart);
    addChild(heartNode);
    heartNode->setPosition(VisibleRect::mleftTop());
    
    Sprite * scoreSprite = Sprite::createWithSpriteFrameName("hudCoin.png");
    scoreSprite->setScale(0.25);
    scoreSprite->setPosition(Vec2(0,-32));
    heartNode->addChild(scoreSprite);
    
    heartLabel = Label::create();
    scoreLabel = Label::create();
    
    heartLabel->setColor(Color3B::BLACK);
    scoreLabel->setColor(Color3B::BLACK);
    
    heartNode ->addChild(heartLabel);
    heartNode->addChild(scoreLabel);
    
    heartLabel->setPosition(Vec2(32,0));
    scoreLabel->setPosition(Vec2(32,-32));
    
    schedule(schedule_selector(ControllerLayer::updateUI), 0.1);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto touchlistener = EventListenerTouchOneByOne::create();
    touchlistener->onTouchBegan=[=](Touch* touch, Event* event){
        // auto target = static_cast<Button*>(event->getCurrentTarget());
        
        Point location = touch->getLocation();
      //  log("location begin %f,%f",location.x,location.y);
        
        Rect leftrect = button_Left->getBoundingBox();
        Rect rightrect  = button_Right->getBoundingBox();
        
        if (leftrect.containsPoint(location)) {
            global->player->changeState(Role::leftwalk);
            button_Left->setTag(1);
            button_Right->setTag(0);
            return true;
        }
        if (rightrect.containsPoint(location)) {
            global->player->changeState(Role::rightwalk);
            button_Right->setTag(1);
            button_Left->setTag(0);
            return true;
        }
        return false;
    };
    touchlistener->onTouchMoved=[=](Touch* touch, Event* event){
        Rect leftrect = button_Left->getBoundingBox();
        Rect rightrect  = button_Right->getBoundingBox();
        Point location = touch->getLocation();
        if (leftrect.containsPoint(location)) {
            if (button_Left->getTag()==0) {
                global->player->changeState(Role::leftwalk);
                button_Left->setTag(1);
                button_Right->setTag(0);
            }
            
            
        }
        if (rightrect.containsPoint(location)) {
            if (button_Right->getTag()==0) {
                global->player->changeState(Role::rightwalk);
                button_Left->setTag(0);
                button_Right->setTag(1);
            }
        }
        //log("touch moved %f,%f",touch->getLocation().x,touch->getLocation().y );
    };
    touchlistener->onTouchEnded=[](Touch* touch, Event* event){
        global->player->changeState(Role::idle);
    };
    touchlistener->setSwallowTouches(false);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, button_Left);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), button_Right);
    return true;
}
void ControllerLayer::moveright(Ref *ref,Widget::TouchEventType type)
{
    
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::rightwalk);
            //  CCLOG("began");
            //            global->player->setNowDestination(Role::right);
            //            global->player->changeState(walk);
            break;
            //	case (int)(cocos2d::ui::Widget::TouchEventType::MOVED):
            
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            //CCLOG("ended");
            global->player->changeState(Role::idle);
            
            break;
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(Role::idle);
            //CCLOG("cancled");
            
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
void ControllerLayer::updateUI(float dt){
    if (scoreLabel!=NULL) {
        char str[20];
        sprintf(str, "%d",global->scoreNum);
        scoreLabel->setString(str);
    }
    if (heartLabel!=NULL) {
        char str[20];
        sprintf(str, "%d",global->hearts);
        heartLabel->setString(str);
    }
    
}