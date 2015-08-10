//
//  Hero1.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/24.
//
//

#ifndef __KaziProject__Hero1__
#define __KaziProject__Hero1__

#include <stdio.h>
#include "Player.h"

//class Hero仅仅决定玩家的特征
class Hero1:public Player{
public:
    Hero1();
    Hero1(int character_idx);
    CREATE_FUNC(Hero1);
};
#endif /* defined(__KaziProject__Hero1__) */
