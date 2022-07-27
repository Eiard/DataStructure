/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqStack
    @author:        30671
    @description:   TODO : 顺序栈
    @date:          2022/7/27
    @version:       1.0
*/


#include "SqStack.h"


void InitSqStack(SqStack &S) {
    S.top = -1;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }

    // 先移入 再栈顶指针后移
    S.data[++S.top] = x;
    return true;
}


void TestSqStack() {
    SqStack S;  // 声明一个顺序栈(分配空间)
    InitSqStack(S);

    /**
     * 其他操作
     */

}
