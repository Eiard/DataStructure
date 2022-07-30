/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ShStack
    @author:        30671
    @description:   TODO 
    @date:          2022/7/27
    @version:       1.0
*/


#include "ShStack.h"


void InitShStack(ShStack &S) {
    S.top0 = -1;
    S.top1 = MaxSize;
}

bool ShStackIsFull(ShStack S) {
    if (S.top0 + 1 == S.top1) {
        return true;
    }
    return false;
}
