//
//  Enemy.hpp
//
//
//  Created by 丁逸鹏 on 15/7/27.
//
//

#ifndef Enemy_cpp
#define Enemy_cpp

#include <stdio.h>
#include "cocos2d.h"
#include "Role.h"
using namespace cocos2d;

class Enemy : public Role{
public:
    Enemy(string s);

    void updateMove(float dt);
    void ai(float dt);
    virtual void update(float dt);
    virtual Rect getBoundingBox();
};
#endif /* Enemy_cpp */
