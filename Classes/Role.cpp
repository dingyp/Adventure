//
//  Role.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#include "Role.h"
#include "Global.h"
#include "Define.h"
void Role::onEnter()
{
    Node::onEnter();
    if(NULL==this->getIdleAni()){
        //sprintf(name, "hero");
        name = "hero";
        Sprite * walkSprite=Sprite::create("images/miku_walk8.png");
        walkTexture=walkSprite->getTexture();
        Sprite * idleSprite=Sprite::create("images/miku_idle10.png");
        idleTexture=idleSprite->getTexture();
        this->setWalkAni(global->createAni(walkTexture, 1, 8, 8));
        // this->setIdleAni(global->createAni(idleTexture, 1, 10, 10));
        this->setIdleAni(global->createAni("herostay", 5));
        scales=0.5;
        speed = 1;
    }
    _velocity=Point(0,0);
    isOnPlatFormer=false;
    isRecycled = false;
    //speed = 1.5;
    char spname[25];
    sprintf(spname, "walk1");
//    if (name!="enemy") {
//        
//        mSprite=Sprite::createWithSpriteFrameName(name+spname+".png");
//
//    }
    
    
    
    mSprite->setScale(scales);
    
    this->addChild(mSprite);
    this->changeState(idle);
    this->setNowDestination(right);
    this->isJump=false;
    //idleAction->retain();
    
    jumps = 0;
    
    schedule(schedule_selector(Role::updateState), global->fps);
    schedule(schedule_selector(Role::updateDown),global->fps);
    schedule(schedule_selector(Role::updateGravity), global->fps);
    schedule(schedule_selector(Role::updateMove), global->fps);
    //schedule(schedule_selector(Role::updateViewPointer),global->fps);
    
}
Size Role::getContentSize()
{
    return Size(scales*mSprite->getContentSize().width,scales*mSprite->getContentSize().height);
}
void Role::changeState(State s)
{
    if(nowState!=jump){
        formState=nowState;
    }
    if(nowState == dead){
        return;
    }

    
 
    nowState=s;
    
    
    isRun=false;
    
    
    switch (nowState) {
        case idle:
            this->stopAllActionsByTag(2);
            this->mSprite->stopAllActions();
            _horizontalvelocity=Vec2(0,0);
            idleAction=RepeatForever::create(Animate::create(this->getIdleAni()));
            this->mSprite->runAction(idleAction);
            break;
        case rightwalk:
            isRun=true;
            this->stopAllActionsByTag(2);
            this->setNowDestination(right);
            this->mSprite->stopAllActions();
            this->mSprite->setFlippedX(false);
            _horizontalvelocity=Vec2(speed,0);
            
        
           
            this->mSprite->runAction(RepeatForever::create(Animate::create(this->getWalkAni())));
        
            break;
        case leftwalk:
            isRun=true;
            this->stopAllActionsByTag(2);
            this->setNowDestination(left);
            
            this->mSprite->stopAllActions();
            this->mSprite->setFlippedX(true);
            _horizontalvelocity=Vec2(-speed, 0);
          
            this->mSprite->runAction(RepeatForever::create(Animate::create(this->getWalkAni())));
           
            break;
        case jump:
            if (jumps<=1) {
                
                this->_velocity=Point(0,4.5);//初速度
                jumps++;
                CCLOG("jump1");
                if(!isJump){
                    CCLOG("jump2");
                    schedule(schedule_selector(Role::updateGravity),global->fps);
                    isJump=true;
                }
            }
            break;
        case dead:
            
            
            
            if (this->name!="enemy") {
//                auto func = [&](){
//                    log("dead");
//                    this->isRecycled = true;
//                };

                this->runAction(Sequence::create(Blink::create(1, 3), CallFunc::create([&](){
                    log("dead");
                    this->isRecycled = true;
                }),NULL) );
            }else{
                this->mSprite->runAction(RepeatForever::create( Animate::create(this->getDeadAni())));
            //   this->removeFromParent();
                unscheduleUpdate();
            //   this->runAction(Sequence::create(RepeatForever::create( Animate::create(deadAni)), NULL));
            }
            
            //  this->removeFromParent();
            break;
            
        default:
            break;
    }
}
void Role::updateState(float dt)
{
    Vec2 point=global->tileCoordForPosition(this->getPosition());
    experimental:: TMXLayer *collisionLayer=global->map->getLayer("ground");
    if(this->getPositionY()<=-100){
        this->changeState(dead);
    }
    //CCLOG("y:%f",this->getPositionY());
    //左右碰撞检测
    int x1=this->getContentSize().width/2*0.8;
    int y1=this->getContentSize().height/2*0.8;
    Point p1,p2,p3;
    Point playerpoint=this->getPosition();
    int x=playerpoint.x;
    int y=playerpoint.y;
    switch (this->getNowDestination()) {
        case right:
            p1=Point(x+x1,y-y1);
            p2=Point(x+x1,y);
            p3=Point(x+x1,y+y1);
            
            break;
        case left:
            p1=Point(x-x1,y+y1);
            p2=Point(x-x1,y);
            p3=Point(x-x1,y-y1);
            break;
        default:
            break;
    }
    //头顶碰撞检测
    Point upp1,upp2,upp3;
    //upp1=playerpoint-
    upp1 = playerpoint+Vec2(-x1,y1);
    upp2 = playerpoint+Vec2(0,y1);
    upp3 = playerpoint+Vec2(x1,y1);
    
    Point rupp1 = global->tileCoordForPosition(upp1);
    Point rupp2 = global->tileCoordForPosition(upp2);
    Point rupp3 = global->tileCoordForPosition(upp3);
    
    moveplatformy=-200;
    //Node * onFormNode;
    bool platformercoll1=false,platformercoll2=false,platformercoll3=false;
    if (global->platFormNode!=NULL) {
        Vector<Node*> nodes=global->platFormNode->getChildren();
        if (nodes.size()>0) {
            for (auto node: nodes) {
                
                PlatFormer * platformer = static_cast<PlatFormer *>(node);
                if ( abs(node->getPositionX()-this->getPositionX())<=PIXEL_WIDTH/3*2&&this->getPositionY()-node->getPositionY()>0) {
                    moveplatformy=MAX(moveplatformy,node->getPositionY()+16);
                    onFormNode=dynamic_cast<PlatFormer*>( node);
                }
                Rect rect = platformer->getBoundingBox();
                if (rect.containsPoint(p1)) {
                    platformercoll1 = true;
                }
                if (rect.containsPoint(p2)) {
                    
                    platformercoll2 = true;
                }
                if (rect.containsPoint(p3)) {
                    platformercoll3 = true;
                }
                if (platformercoll2&&(platformercoll1||platformercoll2)) {
                    break;
                }
                
            }
            
        }
        
    }
    
    
    bool pformupp1=false,pformupp2=false,pformupp3=false;

    if (global->platFormNode!=NULL) {
        Vector<Node*> nodes=global->platFormNode->getChildren();
        if (nodes.size()>0) {
            for (auto node: nodes) {

                PlatFormer * platformer = static_cast<PlatFormer *>(node);
                Rect rect = platformer->getBoundingBox();
                if (rect.containsPoint(upp1)) {
                    pformupp1 = true;
                }
                if (rect.containsPoint(upp2)) {
                    pformupp2 = true;
                }
                if (rect.containsPoint(upp3)) {
                    pformupp3 = true;
                }
                if (pformupp2&&(pformupp1||pformupp3)) {
                    if (isJump) {
                        _velocity = Vec2(0,0);
                    }

                    break;
                }

            }
        }
    }//平台移动上方遮挡舍弃
    
    Point r1=global->tileCoordForPosition(p1);
    Point r2=global->tileCoordForPosition(p2);
    Point r3=global->tileCoordForPosition(p3);
    
    int id1=collisionLayer->getTileGIDAt(r1);
    int id2=collisionLayer->getTileGIDAt(r2);
    int id3=collisionLayer->getTileGIDAt(r3);
    
    int uid1 = collisionLayer->getTileGIDAt(rupp1);
    int uid2 = collisionLayer->getTileGIDAt(rupp2);
    int uid3 = collisionLayer->getTileGIDAt(rupp3);
    
    if ((uid1||uid3)&&uid2) {
        if (isJump) {
            _velocity = Vec2(0,0);
        }
        
        //    JumpOverCallBack();
    }
    if(((id1||id3)&&id2)||(platformercoll2&&(platformercoll1||platformercoll2)))
    {
        this->stopAllActionsByTag(2);
        this->_horizontalvelocity=Vec2(0,0);
        isRun=false;
    }else{
        
        if(nowState==leftwalk||nowState==rightwalk){
            
            // CCLOG("resume");
            if(!isRun){
                this->changeState(nowState);
            }
            //this->changeState(nowState);
        }
        
        if(nowState==jump&&(formState==leftwalk||formState==rightwalk))
        {
            if(!isRun){
                this->changeState(formState);
            }
        }
    }
    
    int flag=0;
    
    for(int i=point.y;i<global->map->getMapSize().height;i++)
    {
        if(collisionLayer->getTileGIDAt(Vec2(point.x,i+1))||i==global->map->getMapSize().height-1)
        {
            if(i!=point.y&&moveplatformy!=20){
                flag=1;
                yIndexPlatForm=i+1;
                platformy=MAX(global->positionCoordForTile(Vec2(point.x,yIndexPlatForm)).y+global->map->getTileSize().height/2,moveplatformy);
                
                if(!isDown&&!isJump){
                    if (platformy!=moveplatformy) {
                        //CCLOG("a");
                        schedule(schedule_selector(Role::updateGravity),  global->fps);
                        isDown=true;
                        CCLOG("downstart");
                        
                        //判断是否在自定义平台上
                        isOnPlatFormer=false;
                    }else{
                        schedule(schedule_selector(Role::updateGravity),  global->fps);
                        if (!isOnPlatFormer) {
                            //  log("isOnplatFormer: false");
                            isDown=true;//modified ?
                        }else{
                            //  log("isOnplatFormer: true ");
                            isDown=false;
                        }
                        isDown=true;//modified ?
                        
                        //CCLOG("b");
                        // isOnPlatFormer=true;
                    }
                }
                
            }else{
                yIndexPlatForm=i+1;
                platformy=MAX(global->positionCoordForTile(Vec2(point.x,yIndexPlatForm)).y+global->map->getTileSize().height/2,moveplatformy);
                if (platformy!=moveplatformy) {
                    //CCLOG("d");
                    // isOnPlatFormer=false;
                }else{
                    //CCLOG("e");
                    // isOnPlatFormer=true;
                }
            }
            if(i==global->map->getMapSize().height-1){
                yIndexPlatForm=i+10;
                platformy=MAX(global->positionCoordForTile(Vec2(point.x,yIndexPlatForm)).y+global->map->getTileSize().height/2,moveplatformy);
            }
            break;
        }
    }
}

void Role::updateDown(float dt)
{
    if(isDown)
    {
        
        Vec2 point=global->tileCoordForPosition(this->getPosition());
        // TMXLayer *collisionLayer=global->map->getLayer("ground");
        float playery=this->getPositionY()-this->getContentSize().height/2;
        // float plateformy=global->positionCoordForTile(Vec2(point.x,yIndexPlatForm)).y+global->map->getTileSize().height/2;
        // CCLOG("comp: %f,%f",playery,plateformy);
        if(playery<=platformy){
            //            log("true");
            jumps=0;
            //   CCLOG("downtoground");
            this->stopAllActionsByTag(3);
            this->setPositionY(platformy+this->getContentSize().height/2);
            if (platformy==moveplatformy&&platformy!=-200) {
                isOnPlatFormer=true;
            }else{
                isOnPlatFormer=false;
            }
            downOverCallBack();
            
        }
    }
}
void Role::JumpOverCallBack()
{
    isJump=false;
    isDown=true;
}
void Role::downOverCallBack()
{
    isJump=false;
    isDown=false;
    
    this->_velocity = Point(0,0);
    unschedule(schedule_selector(Role::updateGravity));
    if(nowState==jump){
        changeState(formState);
    }
    //    if(nowState==leftwalk||nowState==rightwalk){
    //        this->changeState(nowState);
    //    }//有什么用？？？
}
void Role::deadCallBack(){
    this->nowState = dead;
}
void Role::setViewpointCenter(Point p)
{
    Size size = Director::getInstance()->getWinSize();
    float x = MAX(p.x, size.width / 2);
    float y = MAX(p.y, size.height / 2);
    
    x = MIN(x, (global->map->getMapSize().width*global->map->getTileSize().width) - size.width / 2);
    y = MIN(y, (global->map->getMapSize().height*global->map->getTileSize().height) - size.height / 2);
    Point actualPosition = Point(x, y);
    Point centerOfView = Point(size.width / 2, size.height / 2);
    Point viewPoint =centerOfView - actualPosition;
    
    
    this->getParent()->setPosition(viewPoint);
   
}
void Role::updateGravity(float dt)
{
    
    if(_velocity.y<=0)
    {
        JumpOverCallBack();
    }
    Point gravity = Point(0.f, -7.f);
    Point gravityStep = gravity* dt;
    this->_velocity = this->_velocity+gravityStep;
    this->setPosition(this->getPosition()+ _velocity);
}


void Role::updateMove(float dt){
    if (isOnPlatFormer) {
        this->setPosition(this->getPosition()+_horizontalvelocity+onFormNode->_velocity);
        
    }else{
        this->setPosition(this->getPosition()+_horizontalvelocity);
        
    }
}
