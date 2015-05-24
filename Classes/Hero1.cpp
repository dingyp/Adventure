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
    scales=0.5;
}
