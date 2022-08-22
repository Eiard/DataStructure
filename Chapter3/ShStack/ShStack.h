/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ShStack
    @author:        30671
    @description:   TODO : 共享栈
    @date:          2022/7/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SHSTACK_H
#define DATASTRUCTURE_SHSTACK_H

#include "../../Def.h"

#define MaxSize 10

typedef struct {
    QueueElemType dat[MaxSize];
    int top0;  //2号栈栈顶指针
    int top1;  //1号栈栈顶指针
} ShStack;

void InitShStack(ShStack &S);

bool ShStackIsFull(ShStack S);


#endif //DATASTRUCTURE_SHSTACK_H
