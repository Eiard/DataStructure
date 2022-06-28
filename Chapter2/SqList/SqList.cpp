/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqList
    @author:        30671
    @description:   TODO 
    @date:          2022/6/27
    @version:       1.0
*/


#include "SqList.h"

void InitSqList(SqList &L) {
    L.length = 0;
}

void InsertSqList(SqList &L, int i, ElemType e) {
    // 将第i个元素及其后面的元素后移
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }

    // 在位置i放入e
    L.data[i - 1] = e;

    // 长度加1
    L.length++;
}

void Traverse(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf(" No.%d %d\n", i, L.data[i]);
    }
}


void TestSqList() {
    SqList L;

    InitSqList(L);

    InsertSqList(L, 1, 2);
    InsertSqList(L, 1, 3);
    Traverse(L);


}
