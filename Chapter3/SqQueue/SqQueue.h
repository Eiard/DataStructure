/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqQueue
    @author:        30671
    @description:   DONE : 队列queue 静态队列
    @date:          2022/7/30
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H

#include "../../Def.h"

#define MaxSize 10 // 定义队列中元素的最大个数

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;



/**
 * 初始化队列
 * @param Q
 */
void InitSqQueue(SqQueue &Q);


/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
bool SqQueueIsEmpty(SqQueue Q);

/**
 * 判断队列是否为满
 *      循环队列解决方案
 *              1. 浪费一个存储单元 用于判断队列是否已满(实际上能存储数据的大小为 MaxSize-1 )
 * @param Q
 * @return
 */
bool SqQueueIsFull(SqQueue Q);

/**
 * 入队操作
 *      线状存储空间 形成循环
 *      循环队列
 * @param Q
 * @param x
 * @return
 */
bool EnSqQueue(SqQueue &Q, ElemType x);

/**
 * 出队操作
 *      删除一个队头元素 并用x返回
 * @param Q
 * @param x
 * @return
 */
bool DeSqQueue(SqQueue &Q, ElemType &x);

/**
 * 测试静态队列函数
 */
void TestSqQueue();


#endif //DATASTRUCTURE_SQQUEUE_H
