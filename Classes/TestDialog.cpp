//
//  TestDialog.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/4.
//
//

#include "TestDialog.h"
#include "VisibleRect.h"

void TestDialog::close(){
    CCLOG("child call");
    BaseDialog1::close();
    //DialogNode::close();
}
bool TestDialog::init(){
    if(!BaseDialog1::init()){
        return false;
    }
    Label * label =Label::create();
    label->setString("heheda~");
  //  label->setDimensions(100, 100);
    label->setColor(COLOR_BLACK);
    label->setPosition(Vec2(0,30));
    addChild(label,1);
    this->setCloseButton();
    Button * button =Button::create("images/dialog2.png");
    addChild(button,1);
    button->setTitleColor(COLOR_BLACK);
    button->setTitleText("么么哒");
    
  //  button->set
    button->setScale9Enabled(true);
    button->setCapInsets(Rect(15,15,80,80));
    button->setContentSize(Size(60,40));
    button->setPosition(Vec2(0,-30));
    
    button->addTouchEventListener(CC_CALLBACK_2(BaseDialog1::closeCallBack, this));
    dialogSize=Size(220,150);
  // CCLOG("dddd");
    return true;
}
