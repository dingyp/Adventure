//
//  GatesNode.hpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/8.
//
//

#ifndef GatesNode_cpp
#define GatesNode_cpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
#include "IncludeScene.hpp"
using namespace cocostudio;
using namespace cocos2d;
using namespace cocos2d::ui;

class GatesNode : public Node {
public:
    LabelAtlas * gateNumSprite;
    GatesNode(int num,bool isLocked,int choice);
    virtual void onEnter();
    
private:
    int id;
    bool isSelected;
    bool isLocked;
    int gateNum;
    int choice;

};
#endif /* GatesNode_cpp */
