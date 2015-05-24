//
//  Player.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#ifndef __KaziProject__Player__
#define __KaziProject__Player__

#include <stdio.h>
#include "Role.h"
class Player : public Role{
public:
    virtual bool init();
    CREATE_FUNC(Player);
    Player();
    void updateViewPoint(float dt);
};
#endif /* defined(__KaziProject__Player__) */
