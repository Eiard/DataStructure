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
 * 初始化单链表
 * @param L
 * @return
 */
bool InitLinkList(LinkList &L);

/**
 * 采用头插法建立单链表
 * 读入数据的顺序与生成的链表中的元素的顺序是相反的
 *      每个节点插入的时间复杂度 = O(1)
 *      设单链表总长度为n       建立一个单链表总时间复杂度为 = O(n)
 *
 * @param L
 * @return
 */
LinkList HeadInsertBuildLinkList(LinkList &L);

/**
 * 采用尾插法建立单链表
 * 读入数据的顺序与生成的链表中的元素的顺序是相同的
 *      使用了辅助指针r(始终指向末尾,并且新结点假如时,跟着后移)
 *      每个节点插入的时间复杂度 = O(1)
 *      设单链表总长度为n       建立一个单链表总时间复杂度为 = O(n)
 * @param L
 * @return
 */
LinkList TailInsertBuildLinkList(LinkList &L);


/**
 * 按序号查找结点:
 *      LNode* 强调是一个节点
 *      LinkList 强调是一个链表
 *      时间复杂度为 O(n)
 * @param L
 * @param i
 * @return  节点地址
 */
LNode *GetElemLinkList(LinkList L, int i);

/**
 * 按值查找结点:
 *      依次向后移动并且数值比较
 *      时间复杂度 = O(n)
 * @param L
 * @param e
 * @return
 */
LNode *LocateElemLinkList(LinkList L, ElemType e);

/**
 * 遍历单链表
 * @param L
 */
void TraverseLinkList(LinkList L);

/**
 * 功能测试函数
 */
void TestLinkList();

#endif //DATASTRUCTURE_LNODE_H
