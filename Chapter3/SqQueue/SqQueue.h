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

    /**
     *  注意判断rear的指向
     *          指向队尾元素的后一个
     *              添加时 先Q.data[rear] = x 再 rear++
     *          指向队尾元素:
     *              添加时 先rear++ 再Q.data[rear] = x
     */
    int front, rear;
    /**
     * 方案2:
     * 队列的当前长度 用于判断队列是否已满 或 为空的 一种方案
     *      入队时size++
     *      出队时size--
     */
    //int size;

    /**
     * 方案3:
     * 队列的当前长度 用于判断队列是否已满 或 为空的 一种方案
     *      删除操作成功时,令tag = 0
     *      插入操作成功时,令tag = 1
     *
     *      使用情况
     *          只有删除操作,才可能导致队空
     *              在删除时的判断条件:
     *                      front==rear && tag==0 (上一个操作是删除 并且 删除后正好没有元素了)
     *                          满足该条件则说明队列元素为空不能删除元素
     *          只有插入操作,才可能导致队满
     *              在插入时的判断条件:
     *                      front==rear && tag==1 (上一个操作是插入 并且 插入之后正好满了)
     *                          满足该情况则说明队满不能插入元素
     */
    //int tag;  // 最近进行的是删除/插入

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
 *          入队方式
 *              Q.data[front]然后front++
 *              front++ 然后 Q.data[front]
 *
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
 * 队列只能查询队头元素的值
 * @param Q
 * @param x
 * @return
 */
bool GetHead(SqQueue Q, ElemType &x);

/**
 * 计算队列的长度
 * @param Q
 * @return
 */
int SqQueueLength(SqQueue Q);

/**
 * 测试静态队列函数
 */
void TestSqQueue();


#endif //DATASTRUCTURE_SQQUEUE_H
