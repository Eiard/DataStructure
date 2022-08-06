/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      LinkQueue
    @author:        30671
    @description:   DONE : 链式队列
    @date:          2022/7/31
    @version:       1.0
*/


#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H

#include "../../Def.h"

/**
 * 链表的单个结点结构体
 * 链式队列结点
 */
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

/**
 * 链式队列
 */
typedef struct {
    LinkNode *front, *rear;  // 队列的队头 和 队尾指针
} LinkQueue;

/**
 * 初始化队列(带头结点)
 * @param Q
 */
void InitQueue(LinkQueue &Q);


/**
 * 判断(带头结点)队列是否为空
 *      因为链式队列只需要判断头结点和尾节点指针是否相等
 *              相等:队列为空
 *              不相等:队列不为空
 *
 * @param Q
 * @return
 */
bool QueueIsEmpty(LinkQueue Q);

/**
 * 带头结点的队列入队操作
 * @param Q
 * @param x
 */
void EnQueue(LinkQueue &Q,ElemType x);


/**
 * 初始化无头结点链式队列
 * @param Q
 */
void InitNoHeadQueue(LinkQueue &Q);

/**
 * 判断无头结点队列是否为空
 * @param Q
 * @return
 */
bool NoHeadQueueIsEmpty(LinkQueue Q);

/**
 * 无头结点链式队列入队
 *      链式队列入队不可能满
 * @param Q
 * @param x
 */
void EnNoHeadQueue(LinkQueue &Q, ElemType x);

/**
 * 测试链式队列
 */
void TestLinkQueue();


#endif //DATASTRUCTURE_LINKQUEUE_H
