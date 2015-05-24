//
//  Player.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#include "Player.h"
#include "Global.h"
bool Player::init()
{
    if(!Node::init())
    {
        return false;
    }
    return true;
}
Player::Player()
{
   // Sprite * spritexture=Sprite::create("images/miku_num10.png");
    if(NULL==this->getIdleAni()){
        name = "hero2";
        this->setIdleAni(global->createAni("hero2walk", 3,3));
        this->setWalkAni(global->createAni("hero2walk", 4));
        scales=0.5;
    }
    
    schedule(schedule_selector(Player::updateViewPoint), global->fps);
    
}
void Player::updateViewPoint(float dt){
    this->setViewpointCenter(this->getPosition());
}