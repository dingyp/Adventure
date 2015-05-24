//
//  TestDialog.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/4.
//
//

#ifndef __KaziProject__TestDialog__
#define __KaziProject__TestDialog__

#include "BaseDialog1.h"
class TestDialog:public BaseDialog1
{
public:
    virtual void close();
    virtual bool init();
    CREATE_FUNC(TestDialog);
};

#endif /* defined(__KaziProject__TestDialog__) */
