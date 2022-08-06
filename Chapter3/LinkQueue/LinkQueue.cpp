/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      LinkQueue
    @author:        30671
    @description:   DONE : 链式队列
    @date:          2022/7/31
    @version:       1.0
*/


#include "LinkQueue.h"

void InitQueue(LinkQueue &Q) {
    // 初始时 front 和 rear 都指向头结点
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

bool QueueIsEmpty(LinkQueue Q) {
    // 也可以判断Q->next = null
    // 如果为null 也可以判断队空

    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x) {

    // 申请一个新的节点
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));

    // 存入数据
    s->data = x;

    // 设置新结点的下一个结点为空
    s->next = nullptr;

    // 让s接上原先的队尾结点
    Q.rear->next = s;

    // s变为新的队尾结点
    Q.rear = s;
}


void InitNoHeadQueue(LinkQueue &Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
}


bool NoHeadQueueIsEmpty(LinkQueue Q) {
    if (Q.front == nullptr) {
        return true;
    } else
        return false;
}

void EnNoHeadQueue(LinkQueue &Q, ElemType x) {

    // 申请一个新的节点
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));

    // 存入数据
    s->data = x;

    // 设置新结点的下一个结点为空
    s->next = nullptr;

    // 对于空队列来说插入第一个元素执行的操作
    // 对于无头结点的链式队列来说
    //          空队列Q.front 和Q.rear 均为null
    //          插入时需要对front 和 rear 两个指针均进行修改
    if (Q.front == nullptr) {
        Q.front = s;
        Q.rear = s;
    } else {
        // 对rear结点进行后插操作
        Q.rear->next = s;

        // 将新的结点作为rear
        Q.rear = s;
    }
}

void TestLinkQueue() {

    LinkQueue Q;    // 声明一个队列
    InitQueue(Q);  // 初始化队列

    /**
     * 后续操作
     */

}

