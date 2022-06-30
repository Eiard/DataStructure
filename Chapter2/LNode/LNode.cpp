/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      LNode
    @author:        30671
    @description:   TODO 
    @date:          2022/6/28
    @version:       1.0
*/


#include "LNode.h"

LNode *GetElemLinkList(LinkList L, int i) {
    // 计数器
    int j = 1;

    // 第一个有效数据类
    LNode *p = L->next;

    // 第0个节点则直接返回头结点
    if (i == 0) {
        return L;
    }

    // 非法下标
    if (i < 1) {
        return nullptr;
    }

    // p不为空指针  且 下标还没到
    while (p != nullptr && j < i) {
        // 指针后移
        p = p->next;

        // 计数器++
        j++;
    }
    return p;

}

LinkList HeadInsertBuildLinkList(LinkList &L) {
    LNode *s;
    int x;

    // 给链表头结点动态分配内存空间(创建头结点)
    L = (LinkList) malloc(sizeof(LNode));

    // 初始为空链表
    L->next = nullptr;

    // 输入节点的值
    scanf("%d", &x);

    while (x != 9999) {
        // 动态分配一个节点
        s = (LNode *) malloc(sizeof(LNode));

        // 把值放入
        s->data = x;

        // 让新节点s 的下一跳指向 头结点的下一跳
        s->next = L->next;

        // 头结点的下一跳指向 新结点s
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList TailInsertBuildLinkList(LinkList &L) {
    int x;

    return L;
}

bool InitLinkList(LinkList &L) {
    // 初始化头结点
    L = (LNode *) malloc(sizeof(LNode));

    // 内存分配失败
    if (L == nullptr) {
        return false;
    }

    // 头结点下一跳结点初始化为 nullptr
    L->next = nullptr;

    return true;
}

void TraverseLinkList(LinkList L) {
    if (L->next == nullptr) {
        printf("空链表!\n");
        return;
    }

    // 从第一个有效节点开始遍历
    LNode *p = L->next;

    // 每读完一个结点的值就向后跳
    while (p) {
        printf("%d ", p->data);

        // 向后跳
        p = L->next;
    }
}


void TestLinkList() {
    LinkList L;

    HeadInsertBuildLinkList(L);



    TraverseLinkList(L);

}
