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

bool InsertSqList(SqList &L, int i, ElemType e) {
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    // 当前存储空间已满,不能插入
    if (L.length >= SqListMaxSize) {
        return false;
    }

    /**
     * 将第i个元素及其后面的元素后移
     * 从后往前移动,先移动最后面的元素
     */
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }

    // 在位置i放入e
    L.data[i - 1] = e;

    // 长度加1
    L.length++;
}

bool DeleteSqList(SqList &L, int i, ElemType &e) {
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1) {
        return false;
    }

    // 取出要删除的元素
    e = L.data[i - 1];

    /**
     * 将i个位置后的元素都前移
     * 从前往后移动,先移动最前面的元素
     */
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];  // 后面的往前移一下
    }

    // 线性表长度减1
    L.length--;
    return true;
}

ElemType GetElemSqList(SqList L, int i) {
    // 判断i的范围是否有效
    if (i < 1 || i > L.length + 1) {
        return NULL;
    }

    // 直接通过下标获取元素
    return L.data[i - 1];
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

    int temp;
    if (DeleteSqList(L, 1, temp)) {
        Traverse(L);
        printf("The num is %d", temp);
    }

}
