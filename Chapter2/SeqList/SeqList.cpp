/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SeqList
    @author:        30671
    @description:   DONE : 动态的顺序表
    @date:          2022/6/27
    @version:       1.0
*/


#include "SeqList.h"

void InitSeqList(SeqList &L) {
    /**
     * 利用malloc函数动态分配内存空间
     */
    L.data = (QueueElemType *) malloc(SeqListInitSize * sizeof(QueueElemType));
    L.length = 0;
    L.MaxSize = SeqListInitSize;
}

void IncreaseSeqListSize(SeqList &L, int len) {
    // 临时预存L指针
    QueueElemType *p = L.data;

    // 分配新的长度为L.MaxSize + len (原先长度加上自定义长度) 的动态内存空间
    L.data = (QueueElemType *) malloc((L.MaxSize + len) * sizeof(QueueElemType));

    // 将原先数组中的元素转移到新的数组中
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }

    // 更新数组最大长度
    L.MaxSize = L.MaxSize + len;

    // 释放原先的数组
    free(p);
}

void TestSeqList() {

}