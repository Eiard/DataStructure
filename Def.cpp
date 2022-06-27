#include "Def.h"

/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure
    @sourceFileName:Def
    @author:        30671
    @description:   TODO
    @date:          2022/6/27
    @version:       1.0
*/

void Swap(ElemType &e1, ElemType &e2) {
    ElemType temp;
    temp = e1;
    e1 = e2;
    e2 = temp;
}