
//
//  Role.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__Role__
#define __KaziProject__Role__

#include <stdio.h>
#include "cocos2d.h"
#include "PlatFormer.h"

using namespace cocos2d;
using namespace std;
class Role:public Node
{
public:
    
    enum State{idle,rightwalk,leftwalk,jump,dead};
    enum Destination{left,right};
    virtual void onEnter();
    Sprite * mSprite;
    Texture2D * walkTexture;
    Texture2D * idleTexture;
    Texture2D * jumpTexture;
    // Texture2D * walkTexture;
    virtual Size getContentSize();
    CC_SYNTHESIZE(Animation *, walkAni,WalkAni);
    CC_SYNTHESIZE(Animation *, jumpAni,JumpAni);
    CC_SYNTHESIZE(Animation *, idleAni,IdleAni);
    CC_SYNTHESIZE(Destination , nowDestination,NowDestination);
    
    void updateState(float dt); //下落判断
    
    void updateDown(float dt); //用于下落时人物碰到地面停止
    void updateGravity(float dt); //重力模拟
    void updateMove(float dt);
    void setDown();
    void downOverCallBack();
    void changeState(State s);
    void JumpOverCallBack();
    void setViewpointCenter(Point p);
  //  void updateViewPointer(float dt);
    bool isDown,isJump,isRun;//isDown代表是否下落
    
    ActionInterval * moveAction;
    ActionInterval * downAction;
    ActionInterval * idleAction;
    float scales;
    
    Point _velocity;
    Point _horizontalvelocity;
    int yIndexPlatForm;
    float platformy;
    float moveplatformy;
    string name;
    State nowState;
    State formState;
    bool isOnPlatFormer;
    PlatFormer * onFormNode;
};
#endif /* defined(__KaziProject__Role__) */
