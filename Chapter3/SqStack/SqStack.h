/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqStack
    @author:        30671
    @description:   TODO 
    @date:          2022/7/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H


#include "../../Def.h"

#define MaxSize 10  // 定义栈中元素的最大个数

typedef struct {
    ElemType data[MaxSize];  // 静态数组存放元素
    int top;  // 栈顶指针
} SqStack;

/**
 * 初始化顺序栈栈
 * @param S
 */
void InitSqStack(SqStack &S);

/**
 * 往栈中push一个元素
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x);

/**
 * 栈测试函数
 */
void TestSqStack();

#endif //DATASTRUCTURE_SQSTACK_H
