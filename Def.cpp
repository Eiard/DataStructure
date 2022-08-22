/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      Def
    @author:        30671
    @description:   DONE
    @date:          2022/6/27
    @version:       1.0
*/


#include "Def.h"

void Swap(QueueElemType &e1, QueueElemType &e2) {
    QueueElemType temp;
    temp = e1;
    e1 = e2;
    e2 = temp;
}