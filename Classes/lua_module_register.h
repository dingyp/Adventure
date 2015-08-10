//
//  lua_module_register.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/7/18.
//
//

#ifndef lua_module_register_h
#define lua_module_register_h
#include "lua_cocos2dx_cocosdenshion_manual.h"
#include "lua_cocos2dx_network_manual.h"
#include "lua_cocos2dx_cocosbuilder_manual.h"
#include "lua_cocos2dx_coco_studio_manual.hpp"
#include "lua_cocos2dx_extension_manual.h"
#include "lua_cocos2dx_ui_manual.hpp"
#include "lua_cocos2dx_spine_manual.hpp"
#include "lua_cocos2dx_3d_manual.h"
#include "lua_cocos2dx_audioengine_manual.h"
#include "lua/quick/lua_cocos2dx_quick_manual.hpp"

static int lua_module_register(lua_State* L)
{
    //Dont' change the module register order unless you know what your are doing
    register_cocosdenshion_module(L);
    register_network_module(L);
    register_cocosbuilder_module(L);
    register_cocostudio_module(L);
    register_ui_moudle(L);
    register_extension_module(L);
    register_spine_module(L);
    register_cocos3d_module(L);
    register_audioengine_module(L);
    return 1;
}

#endif /* lua_module_register_h */
