//
//  Enemy.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/27.
//
//

#include "Enemy.hpp"
#include "Global.h"
Enemy::Enemy(string s){
    name ="enemy" ;
    scales = 0.25;
    mSprite = Sprite::createWithSpriteFrameName(s+".png");
    speed = 1;
    
    Animation * idelAni = Animation::create();
    idelAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(s+".png"));
    idelAni->setDelayPerUnit(0.1);
    idelAni->retain();
    this->setIdleAni(idelAni);
    
    Animation * walkAni = Animation::create();
    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(s+".png"));
    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(s+"_move.png"));
    walkAni->retain();
    walkAni->setDelayPerUnit(0.1);
    this->setWalkAni(walkAni);
    
    Animation * deadAni = Animation::create();
    deadAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(s+"_dead.png"));
    deadAni->retain();
    deadAni->setDelayPerUnit(0.1);
    this->setDeadAni(deadAni);
    schedule(schedule_selector(Enemy::updateMove), 1);
    schedule(schedule_selector(Enemy::ai),0.1);
    scheduleUpdate();
}
void Enemy::updateMove(float dt){
    int choice = rand_0_1()*3;
    if (this->getPositionY()<=-100) {
        unscheduleAllCallbacks();
        this->removeFromParent();
    }
    if (platformy==-200) {
        //代表平台为空
        if (nowState == leftwalk) {
            this->changeState(rightwalk);
        }
        else if (nowState == rightwalk) {
            this->changeState(leftwalk);
        }
        //    this->changeState(formState);
        this->changeState(jump);
    }else{
        // this->changeState(idle);
        switch (choice) {
            case 0:
                this->changeState(idle);
                break;
            case 1:
                this->changeState(leftwalk);
                break;
            default:
                this->changeState(rightwalk);
                break;
        }
    }
}
void Enemy::ai(float dt){
    
}
Rect Enemy::getBoundingBox(){
  
    return Rect(this->getPositionX()-mSprite->getBoundingBox().size.width/2,
                this->getPositionY()-mSprite->getBoundingBox().size.height/2,
                mSprite->getBoundingBox().size.width,mSprite->getBoundingBox().size.height);
}
void Enemy::update(float dt){
     if (this->getBoundingBox().containsPoint( global->player->getPosition())&&global->player->nowState!=dead) {
         
         if (global->player->getPositionY()-this->getPositionY()>0&&global->player->isDown) {
             this->changeState(idle);
             this->changeState(dead);
             global->player->_velocity=Vec2(0, 2);
             
             global->scoreNum++;
         }else{
             global->player->changeState(idle);
             global->player->changeState(dead);
         }
     
     }
}