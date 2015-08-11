//
//  BoxItem.hpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/8/11.
//
//

#ifndef BoxItem_cpp
#define BoxItem_cpp

#include <stdio.h>
#include "Item.hpp"
class BoxItem : public Item{
public:
    enum Type {hiddenBox,unHiddenBox};
    BoxItem(Type type);
};


#endif /* BoxItem_cpp */
