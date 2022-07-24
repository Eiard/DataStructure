/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      DNode
    @author:        30671
    @description:   DONE : 双链表
    @date:          2022/7/23
    @version:       1.0
*/
#include "DNode.h"

bool InitDLinkList(DLinkList &L) {
    L = (DLinkList) malloc(sizeof(DNode));
    if (L == nullptr) {
        return false;
    }
    L->prior = nullptr;
    L->next = nullptr;

    return true;
}

bool InitCDLinkList(DLinkList &L) {
    L = (DLinkList) malloc(sizeof(DNode));
    if (L == nullptr) {
        return false;
    }
    // 与普通双链表的区别是
    L->prior = L;
    L->next = L;

    return true;
}

bool InsertNextDNode(DNode *p, DNode *s) {
    // 原先的***  p <=> p->next ****
    // 插入到p之后 变为 *** p <=> s <=> p->next ***

    if (p == nullptr || s == nullptr) {
        return false;
    }

    s->next = p->next;  // 将结点s插入到结点p之后

    if (p->next != nullptr) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}


bool DeleteNextDNode(DNode *p) {
    if (p == nullptr) {
        return false;
    }
    DNode *q = p->next;

    if (q == nullptr) {
        return false;
    }

    p->next = q->next;

    if (q->next != nullptr) {
        q->next->prior = p;
    }
    free(q);

    return true;
}

void DestoryDLinkList(DLinkList &L) {
    // 每次删除头结点的后一个结点
    // 直到删除结束

    while (L->next != nullptr) {
        DeleteNextDNode(L);
    }
    free(L);
    L = nullptr;
}

void TraverseDLinkList(DNode *p) {
    // 后向遍历
    while (p != nullptr) {
        p = p->next;
    }

    // 前向遍历
    //    while (p != nullptr) {
    //        p = p->prior;
    //    }

    // 前向遍历(跳过头结点)
    //    while (p->prior != nullptr) {
    //        p = p->prior;
    //    }
}

void TestDLinkList() {

}