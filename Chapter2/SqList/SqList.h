//
// Created by 30671 on 2022/6/27.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include "../../Def.h"

/**
 * 动态线性表
 */
#define SqListMaxSize 10    // 定义最大长度

typedef struct {
    ElemType data[SqListMaxSize];   // 用静态的"数组"存放数据元素
    int length;                     // 顺序表的当前长度
} SqList;                           // 顺序表的类型定义(静态分配方式)

/**
 * 初始化静态线性表
 * @param L
 */
void InitSqList(SqList &L);

/**
 * 功能测试函数
 */
void TestSqList();

#endif //DATASTRUCTURE_SQLIST_H
