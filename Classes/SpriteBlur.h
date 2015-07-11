//
//  SpriteBlur.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/6/10.
//
//

#ifndef __KaziProject__SpriteBlur__
#define __KaziProject__SpriteBlur__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class SpriteBlur : public Sprite
{
public:
    ~SpriteBlur();
    bool initWithTexture(Texture2D* texture, const Rect&  rect);
    void initGLProgram();
    
    static SpriteBlur* create(const char *pszFileName);
    void setBlurRadius(float radius);
    void setBlurSampleNum(float num);

    protected:
    float _blurRadius;
    float _blurSampleNum;
};

#endif /* defined(__KaziProject__SpriteBlur__) */
