
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
#include "MyGameScene2.h"
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
    
    auto ui = CSLoader::createNode("ChooseScene.csb");
    
    addChild(ui,1);
    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_Left"));
    
    button_Left->addTouchEventListener(CC_CALLBACK_2(ChooseScene::chooseleft, this));
    
    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_Right"));
    
    button_Right->addTouchEventListener(CC_CALLBACK_2(ChooseScene::chooseright, this));
    
    
    Button * button_Choose = static_cast<Button *>(ui->getChildByName("Button_Start"));
    
    button_Choose->addTouchEventListener(CC_CALLBACK_2(ChooseScene::choose, this));
    
    Button * button_Back = static_cast<Button *>(ui->getChildByName("Button_Back"));
    
    button_Back->addTouchEventListener(CC_CALLBACK_2(ChooseScene::back, this));

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
    addChild(mainNode,0);
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
