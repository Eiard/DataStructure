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

bool InitHeadLinkList(LinkList &L) {
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


bool InitNoHeadLinkList(LinkList &L) {
    L = nullptr;
    return true;
}


LinkList HeadInsertBuildHeadLinkList(LinkList &L) {
    LNode *s;
    ElemType x;

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

LinkList TailInsertBuildHeadLinkList(LinkList &L) {
    ElemType x;

    // 动态分配头结点地址
    L = (LinkList) malloc(sizeof(LNode));

    if (L == nullptr) {
        return nullptr;
    }

    // r为表尾指针(辅助指针)
    LNode *s, *r = L;
    // 输入结点的值
    scanf("%d", &x);

    while (x != 9999) {  // 输入9999 表示结束
        // 创建一个结点并且动态分配内存空间
        s = (LNode *) malloc(sizeof(LNode));

        // 输入的值存入新的结点
        s->data = x;

        // 辅助指针,始终指向尾部结点 (原先的尾结点指向新的结点)
        r->next = s;

        // 随着新添加的结点 , 辅助指针r 后移
        r = s;
        scanf("%d", &x);
    }

    // 给最后一个结点的下一个结点赋值为空
    r->next = nullptr;

    return L;
}

LNode *GetElemHeadLinkList(LinkList L, int i) {
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

LNode *LocateElemHeadLinkList(LinkList L, ElemType e) {
    return nullptr;
}

void TraverseHeadLinkList(LinkList L) {
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
        p = p->next;
    }
}

bool NoHeadLinkListIsEmpty(LinkList L) {
    if (L == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool HeadLinkListIsEmpty(LinkList L) {
    if (L->next == nullptr) {
        return true;
    } else {
        return false;
    }
}

void TestLinkList() {
    LinkList L;

    // 头插法建立带头结点单链表
    // HeadInsertBuildHeadLinkList(L);

    // 尾插法建立带头结点单链表
    TailInsertBuildHeadLinkList(L);

    // 遍历整个带头结点链表
    TraverseHeadLinkList(L);
}

