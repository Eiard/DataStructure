/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqQueue
    @author:        30671
    @description:   DONE : 静态队列
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
    return false;
}


bool EnSqQueue(SqQueue &Q, ElemType x) {
    if (SqQueueIsFull(Q))
        return false; // 队满 报错

    // 存入数据
    Q.data[Q.rear] = x;
    // 取余 (取模)
    Q.rear = (Q.rear + 1) % MaxSize;

    return true;
}

void TestSqQueue() {

    // 声明一个队列(顺序存储)
    SqQueue Q;

    // 初始化队列
    InitSqQueue(Q);


    // 后续操作




}
