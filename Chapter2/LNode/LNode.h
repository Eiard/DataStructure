/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      LNode
    @author:        30671
    @description:   TODO 
    @date:          2022/6/28
    @version:       1.0
*/


#ifndef DATASTRUCTURE_LNODE_H
#define DATASTRUCTURE_LNODE_H

#include "../../Def.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 初始化带头结点单链表
 * @param L
 * @return
 */
bool InitHeadLinkList(LinkList &L);

/**
 * 初始化无头结点单链表
 * @param L
 * @return
 */
bool InitNoHeadLinkList(LinkList &L);

/**
 * 采用头插法建立带头结点单链表
 * 读入数据的顺序与生成的链表中的元素的顺序是相反的
 *      每个节点插入的时间复杂度 = O(1)
 *      设单链表总长度为n       建立一个单链表总时间复杂度为 = O(n)
 *
 * @param L
 * @return
 */
LinkList HeadInsertBuildHeadLinkList(LinkList &L);

/**
 * 采用尾插法建立带头结点单链表
 * 读入数据的顺序与生成的链表中的元素的顺序是相同的
 *      使用了辅助指针r(始终指向末尾,并且新结点假如时,跟着后移)
 *      每个节点插入的时间复杂度 = O(1)
 *      设单链表总长度为n       建立一个单链表总时间复杂度为 = O(n)
 * @param L
 * @return
 */
LinkList TailInsertBuildHeadLinkList(LinkList &L);


/**
 * 带头结点单链表按序号查找结点:
 *      LNode* 强调是一个节点
 *      LinkList 强调是一个链表
 *      时间复杂度为 O(n)
 * @param L
 * @param i
 * @return  节点地址
 */
LNode *GetElemHeadLinkList(LinkList L, int i);

/**
 * 带头结点单链表按值查找结点:
 *      依次向后移动并且数值比较
 *      时间复杂度 = O(n)
 * @param L
 * @param e
 * @return
 */
LNode *LocateElemHeadLinkList(LinkList L, ElemType e);

/**
 * 遍历带头结点单链表
 * @param L
 */
void TraverseHeadLinkList(LinkList L);

/**
 * 判断无头结点的单链表是否为空
 * @param L
 */
bool NoHeadLinkListIsEmpty(LinkList L);

/**
 * 判断有头结点的单链表是否位空
 * @param L
 */
bool HeadLinkListIsEmpty(LinkList L);

/**
 * 功能测试函数
 */
void TestLinkList();

#endif //DATASTRUCTURE_LNODE_H
