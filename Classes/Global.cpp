//
//  Global.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#include "Global.h"
DECLARE_SINGLETON_MEMBER(Global);
Global::Global(void)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("herostay.plist","herostay.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("herowalk.plist","herowalk.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero2.plist","hero2.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/hero3.plist","images/hero3.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/grasstile.plist", "images/grasstile.png");
    fps=  (Director::getInstance()->getAnimationInterval());
    fps= 0.01;
}
Global::~Global(void)
{
    
}
Animation *Global::createAni(string name, int frames){
    Animation * animation = Animation::create();
    for(int i = 1 ; i<= frames;i++){
        char s[2];
        sprintf(s,"%d",i);
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->spriteFrameByName(name+s+".png"));
        
    }
    animation->setDelayPerUnit(0.08);
    
    animation->retain();
    return animation;
}
Animation *Global::createAni(string name, int start,int end){
    Animation * animation = Animation::create();
    for(int i = start   ; i<= end;i++){
        char s[2];
        sprintf(s,"%d",i);
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->spriteFrameByName(name+s+".png"));
        
    }
    animation->setDelayPerUnit(0.08);
    
    animation->retain();
    return animation;
}

Animation *Global::createAni(Texture2D * texture, int row, int col , int frames)
{
    Animation * animation = Animation::create();
    
    float width=texture->getContentSize().width;
    float height = texture->getContentSize().height;
    
    for(int i=0;i<frames;i++)
    {
        animation->addSpriteFrameWithTexture(texture, Rect(i*width/col, 0, width/col, height));
    }
    animation->setDelayPerUnit(0.1);
    
    animation->retain();
    return animation;
}
Point Global::tileCoordForPosition(Point p)
{
    Size mapTileNum=map->getMapSize();
    Size tileSize=map->getTileSize();
    int x=p.x/tileSize.width;
    int y=(map->getContentSize().height-p.y)/tileSize.height;
    return Point(x,y);
}
Point Global::positionCoordForTile(Point pos)
{
    float posx= (pos.x+0.5)*map->getTileSize().width;
    float posy=map->getContentSize().height- (pos.y+0.5)*map->getTileSize().height;
    return Point(posx,posy);
}
