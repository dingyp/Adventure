//
//  ChooseCharacter.hpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/8/10.
//
//

#ifndef ChooseCharacter_cpp
#define ChooseCharacter_cpp

#include <stdio.h>
#include "BaseDialog1.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"

#include <iostream>
using namespace std;
using namespace cocos2d::ui;
class ChooseDialog : public BaseDialog1{
public:
    virtual void close();
    virtual bool init();
    CREATE_FUNC(ChooseDialog);
    
    Layout * createLayout();
    Layout * createLayout(string fname,string introduction);

    
    PageView * chooseView;
    
};
#endif /* ChooseCharacter_cpp */
