//
//  Hero1.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/24.
//
//

#include "Hero1.h"
#include "Global.h"
Hero1::Hero1()
{
    name = "hero3";
    this->setIdleAni(global->createAni("hero3walk", 1,1));
    this->setWalkAni(global->createAni("hero3walk", 9));
    
//    string s = "sa";
//    Animation * idelAni = Animation::create();
//    idelAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk1.png"));
//    idelAni->setDelayPerUnit(0.08);
//    idelAni->retain();
//    this->setIdleAni(idelAni);
//    
//    Animation * walkAni = Animation::create();
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk1.png"));
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk2.png"));
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk3.png"));
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk4.png"));
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk5.png"));
//    walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3walk6.png"));
//    walkAni->setDelayPerUnit(0.08);
//    walkAni->retain();
//    this->setWalkAni(walkAni);
    scales=0.5;
    speed = 2;
}
Hero1::Hero1(int character_idx){
    Animation * idelAni = Animation::create();
    Animation * walkAni = Animation::create();
    switch (character_idx) {
        case 0:
            name = "hero3";
            mSprite =Sprite::createWithSpriteFrameName("hero3walk1.png");

            this->setIdleAni(global->createAni("hero3walk", 1,1));
            this->setWalkAni(global->createAni("hero3walk", 9));
            scales=0.5;
            speed = 2;
            break;
        case 1:
            name = "baozi";
            mSprite = Sprite::createWithSpriteFrameName(name+"1.png");
            idelAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(name+"1.png"));
            idelAni->setDelayPerUnit(0.08);
            idelAni->retain();
            this->setIdleAni(idelAni);
            
            for (int i =1; i<=7; i++) {
                char s[2];
                sprintf(s,"%d",i);
                //char *
                walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(name+s+".png"));
              
                
            }
           
            walkAni->setDelayPerUnit(0.08);
            walkAni->retain();
            this->setWalkAni(walkAni);
            
            scales=0.12;
            speed = 2;
            break;
            
        default:
            name = "saw";
            
            
            mSprite = Sprite::createWithSpriteFrameName("saw.png");
           
            idelAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("saw.png"));
            idelAni->setDelayPerUnit(0.08);
            idelAni->retain();
            this->setIdleAni(idelAni);
        
           
            walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("saw.png"));
            walkAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("saw_move.png"));
            
            walkAni->setDelayPerUnit(0.08);
            walkAni->retain();
            this->setWalkAni(walkAni);
            
            Animation * deadAni = Animation::create();
            deadAni->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("saw_dead.png"));
            deadAni->setDelayPerUnit(0.08);
            deadAni->retain();
            this->setDeadAni(deadAni);
            scales=0.25;
            speed = 2;
            break;
            break;
    }
}