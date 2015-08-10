//
//  Item.hpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/25.
//
//

#ifndef Item_cpp
#define Item_cpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class Item : public Node{
public:
    enum Type {end,coin,platformer,diamond,heart,hiddenbox,unhiddenbox};
    Item(Type type);
    Type type;
    virtual void onEnter();
    Sprite * mSprite;
    virtual void update(float dt);
    void update2(float dt);
    
    
    virtual Rect getBoundingBox();
    
    bool isCollisioned;
    
};

#endif /* Item_cpp */
