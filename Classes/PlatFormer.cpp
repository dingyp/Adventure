//
//  PlatFormer.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/13.
//
//
#include "Global.h"
#include "PlatFormer.h"
void PlatFormer::onEnter()
{
    Node::onEnter();
    mSprite=Sprite::createWithSpriteFrameName("grassMid.png");
    
    mSprite->setScale(scales);
    _velocity=Vec2(0,0);
    addChild(mSprite);
    _distance=0;
    maxdistance=0;
    moveID=0;
    schedule(schedule_selector(PlatFormer::updateMove),global->fps);
}

Size PlatFormer::getContentSize(){
    Size size= mSprite->getContentSize();
    return Size(scales* size.width,scales* size.height);
}
PlatFormer::PlatFormer()
{
    scales=0.25;
}
void PlatFormer::updateMove(float dt){
    switch (moveID) {
        case 1:
            _distance += _velocity.x;
            break;
        case 2:
            _distance += _velocity.x;
            break;
        case 3:
            _distance += _velocity.y;
            break;
        case 4:
            _distance += _velocity.y;
            break;
        default:
            break;
    }
    
  
    this->setPosition(this->getPosition()+_velocity);
    if (_distance>maxdistance||_distance<0) {
        _velocity=-_velocity;
    }
}
