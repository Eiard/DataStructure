/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      DNode
    @author:        30671
    @description:   DONE : 双链表
    @date:          2022/7/23
    @version:       1.0
*/


#ifndef DATASTRUCTURE_DNODE_H
#define DATASTRUCTURE_DNODE_H

#include"../../Def.h"

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


/**
 * 初始化带头结点双链表
 * @param L
 * @return
 */

bool InitDLinkList(DLinkList &L);

/**
 * 初始化循环双链表
 * @param L
 * @return
 */

bool InitCDLinkList(DLinkList &L);

/**
 * 将结点s插入到p结点之后
 *      应用在循环双链表中也成立
 * @param p
 * @param s
 * @return
 */
bool InsertNextDNode(DNode *p, DNode *s);


/**
 * 删除p结点的后继节点
 * @param p
 * @return
 */
bool DeleteNextDNode(DNode *p);


/**
 * 删除整个双链表
 * @param L
 */
void DestoryDLinkList(DLinkList &L);

/**
 * 遍历双链表
 *      只需要给任意一个结点则可遍历整个链表
 * @param L
 */
void TraverseDLinkList(DNode* p);

/**
 * 功能测试函数
 */
void TestDLinkList();


#endif //DATASTRUCTURE_DNODE_H
