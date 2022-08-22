/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqQueue
    @author:        30671
    @description:   DONE : 队列queue 静态队列
    @date:          2022/7/30
    @version:       1.0
*/


#include "SqQueue.h"

void InitSqQueue(SqQueue &Q) {
    Q.rear = Q.front;
}

bool SqQueueIsEmpty(SqQueue Q) {
    if (Q.rear == Q.front)  // 队空的条件
        return true;
    else {
        return false;
    }
}

bool SqQueueIsFull(SqQueue Q) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return true;
    else
        return false;
}


bool EnSqQueue(SqQueue &Q, QueueElemType x) {
    if (SqQueueIsFull(Q))
        return false; // 队满 报错

    // 存入数据
    Q.data[Q.rear] = x;

    // 尾操作
    // 调用方法宏
    Q.rear = ASC_MODULO_OPERATION(Q.rear, MaxSize);

    //    取余 (取模)
    //    Q.rear = (Q.rear + 1) % MaxSize;

    return true;
}


bool DeSqQueue(SqQueue &Q, QueueElemType &x) {
    if (SqQueueIsEmpty(Q))
        return false;

    // 取出队头的数据
    x = Q.data[Q.front];

    // 头操作
    // 调用方法宏
    //    Q.front = ASC_MODULO_OPERATION(Q.front, MaxSize);

    Q.front = (Q.front + 1) % MaxSize;

    return false;
}

bool GetHead(SqQueue Q, QueueElemType &x) {
    if (SqQueueIsEmpty(Q))
        return false;

    // 取出队头的元素   (尾进头出)
    x = Q.data[Q.front];
    return true;
}


int SqQueueLength(SqQueue Q) {
    // 假如rear = 2
    // front = 3
    // 则当前队列长度为  (2-3+10)%10 = 9

    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

void TestSqQueue() {

    // 声明一个队列(顺序存储)
    SqQueue Q;

    // 初始化队列
    InitSqQueue(Q);


    // 后续操作




}
