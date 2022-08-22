/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SeqList
    @author:        30671
    @description:   DONE : 动态的顺序表
    @date:          2022/6/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

#include "../../Def.h"

/**
 * 静态线性表
 */
#define SeqListInitSize 10      // 顺序表的初始长度

typedef struct {
    QueueElemType *data;             // 指示动态分配数组的指针
    int MaxSize;                // 顺序表的最大容量
    int length;                 // 顺序表的当前长度
} SeqList;                      // 顺序表的类型定义(动态分配方式)

/**
 * 初始化动态分配线性表
 * @param L
 */
void InitSeqList(SeqList &L);

/**
 * 增加动态数组的长度
 * @param L
 * @param len
 */
void IncreaseSeqListSize(SeqList &L, int len);

/**
 * 功能测试函数
 */
void TestSeqList();

#endif //DATASTRUCTURE_SEQLIST_H
