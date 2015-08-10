//
//  Item.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/25.
//
//


#include "Item.hpp"
#include "Global.h"
#include "BaseGameScene.h"
Item::Item(Type type){
    this->type=type;
}
void Item::onEnter(){
    Node::onEnter();
    
    isCollisioned = false;
    switch(type){
        case end:
            mSprite = Sprite::createWithSpriteFrameName("flagRed1.png");
            mSprite->setVisible(false);
          //  ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(""));
            
            break;
        case coin:
            mSprite = Sprite::createWithSpriteFrameName("hudCoin.png");
            break;
        case diamond:
            mSprite = Sprite::createWithSpriteFrameName("hudJewel_blue.png");
            break;
        case heart:
            mSprite = Sprite::createWithSpriteFrameName("hudHeart_full.png");
            break;
        case hiddenbox:
            mSprite = Sprite::createWithSpriteFrameName("boxItem_boxed.png");
            mSprite->setVisible(false);
            break;
        case unhiddenbox:
            mSprite = Sprite::createWithSpriteFrameName("boxItem_boxed.png");
            PlatFormer * platFormer;
            platFormer = new PlatFormer("boxItem_disabled_boxed.png");
            BaseGameScene * parentNode;
            parentNode = static_cast<BaseGameScene*>( this->getParent());
            parentNode->platformNode->addChild(platFormer);
            platFormer->setPosition(this->getPosition());

            break;
            
        default:
            mSprite = Sprite::createWithSpriteFrameName("hudHeart_full.png");
            mSprite->setVisible(false);
            break;
    }
    addChild(mSprite);
    mSprite->setScale(0.25);
    scheduleUpdate();
    schedule(schedule_selector(Item::update2));
}
void Item::update(float dt){
    if (this->getBoundingBox().containsPoint( global->player->getPosition())) {
        
        switch (type) {
            case end:
                unscheduleUpdate();
                global->player->isWin = true;
                
                break;
            case coin:
                unscheduleUpdate();
                
                global->scoreNum++;
                this->removeFromParent();
                break;
            case diamond:
                unscheduleUpdate();
                global->scoreNum+=10;
                this->removeFromParent();
                break;
            case heart:
                unscheduleUpdate();
                global->hearts++;
                this->removeFromParent();
                break;
            case hiddenbox:
                if (global->player->getPositionY()<this->getPositionY()) {
                    
                    if (!mSprite->isVisible()) {
                        mSprite->setVisible(true);
                    }
                    unscheduleUpdate();
                    PlatFormer * platFormer;
                    platFormer = new PlatFormer("boxItem_disabled_boxed.png");
                    BaseGameScene * parentNode;
                    parentNode = static_cast<BaseGameScene*>( this->getParent());
                    parentNode->platformNode->addChild(platFormer);
                    platFormer->setPosition(this->getPosition());
                    this->removeFromParent();
                }else {
                    if (global->player->isDown) {
                        unscheduleUpdate();
                        isCollisioned = true;
                    }
                }
                break;
                
                
                
            case unhiddenbox:
                if (global->player->getPositionY()<this->getPositionY()) {
                    if (global->player-> isJump) {
                        global->player->_velocity = Vec2(0,0);
                    }
                    unscheduleUpdate();
                    this->removeFromParent();
                    
                }else{
                    global->player->_velocity = Vec2(0,0);
                }
                
                break;
                
            default:
                break;
        }
        
    }
}

void Item::update2(float dt){
    if (isCollisioned&&!global->player->isDown) {
        scheduleUpdate();
        isCollisioned = false;
    }
}

Rect Item::getBoundingBox(){
    //范围增大
    return Rect(this->getPositionX()-mSprite->getBoundingBox().size.width/1.5,
                this->getPositionY()-mSprite->getBoundingBox().size.height,
                mSprite->getBoundingBox().size.width*1.5,mSprite->getBoundingBox().size.height*1.5);
}