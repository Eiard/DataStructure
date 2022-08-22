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
 * 带头结点链表(默认)
 *      (插入到第i-1个下标结点的后面,即新结点成为第i个结点)
 *      最好的情况:
 *              插到表头,时间复杂度 = O(1)
 *      最坏的情况:
 *              插到表尾,时间复杂度 = O(n)
 *      平均时间复杂度 = O(n)
 * @param L
 * @param i
 * @param e
 * @return
 */
bool HeadLinkListInsert(LinkList &L, int i, ElemType e);

/**
 * 无头结点链表
 *      (插入到第i-1个下标结点的后面,即新结点成为第i个结点)
 *      最好的情况:
 *              插到表头,时间复杂度 = O(1)
 *      最坏的情况:
 *              插到表尾,时间复杂度 = O(n)
 *      平均时间复杂度 = O(n)
 * @param L
 * @param i
 * @param e
 * @return
 */
bool NoHeadLinkListInsert(LinkList &L, int i, ElemType e);

/**
 * 在指定结点进行后插操作
 *              时间复杂度 = O(1)
 * @param p
 * @return
 */
bool InsertNextLNode(LNode *p, ElemType e);

/**
 * 在指定结点进行前插操作,不是物理前插(逻辑前插)
 *              时间复杂度 = O(1)
 *              先后插 再交换数据
 * @param p
 * @param s
 * @return
 */
bool InsertPriorLNode(LNode *p, LNode *s);

/**
 * 删除下标为i位置的结点,并且通过引用返回删除元素的值
 *          最好情况(删除第一个结点): 时间复杂度 = O(1)
 *          最坏情况(删除最后一个结点): 时间复杂度 = O(n)
 *              平均时间复杂度 = O(n)
 * @param L
 * @param i
 * @param e
 * @return
 */
bool HeadLinkListIDelete(LinkList &L, int i, ElemType e);

/**
 * 直接删除指定结点
 * 将下一个结点的数据存到当前结点(逻辑删除) 相当于删除了一下个结点,并且将下一个结点的数据转移到当前节点
 *      时间复杂度 = O(n)
 *      如果是最后一个结点
 *          则只能从头结点遍历到最后一个结点的前一个结点才能释放最后一个结点
 * @param p
 * @return
 */
bool HeadLinkListDeleteNode(LNode *p);

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
 * 计算单链表的长度
 * @param L
 * @return
 */
int GetLengthHeadLinkList(LinkList L);

/**
 * 功能测试函数
 */
void TestLinkList();

#endif //DATASTRUCTURE_LNODE_H
