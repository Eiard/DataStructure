/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ThreadNode
    @author:        30671
    @description:   DONE : 线索二叉树
    @date:          2022/8/22
    @version:       1.0
*/


#ifndef DATASTRUCTURE_THREADNODE_H
#define DATASTRUCTURE_THREADNODE_H

#include "../../Def.h"

typedef int ThreadNodeElemType;

/**
 * 线索二叉树结点
 *      Tag == 0 表示指针指向孩子
 *      Tag == 1 表示指针是线索
 */
typedef struct ThreadNode {
    ThreadNodeElemType data;
    struct ThreadNode *lChild, *rChild;
    int lTag, rTag;  // 左右标志
} ThreadNode, *ThreadTree;


/**
 * 中序线索化二叉树T
 * @param T
 * @param pre
 */
void CreateInThread(ThreadTree &T, ThreadTree &pre);

/**
 * 中序遍历对二叉树线索化
 *      代码结构类似
 *          先遍历左子树
 *          对该节点操作
 *          再遍历右子树
 * @param Tree
 * @param pre
 */
void InThread(ThreadTree &Tree, ThreadTree &pre);

/**
 * 先序线索化二叉树T
 * @param T
 * @param pre
 */
void CreatePreThread(ThreadTree &Tree, ThreadTree &pre);

/**
 * 先序遍历对二叉树线索化
 *      代码结构类似
 *          对该节点操作
 *          先遍历左子树
 *          再遍历右子树
 * @param Tree
 * @param pre
 */
void PreThread(ThreadTree &Tree, ThreadTree &pre);


/**
 * 后序线索化二叉树T
 * @param T
 * @param pre
 */
void CreatePostThread(ThreadTree &Tree, ThreadTree &pre);

/**
 * 后序遍历对二叉树线索化
 *      代码结构类似
 *          对该节点操作
 *          先遍历左子树
 *          再遍历右子树
 * @param Tree
 * @param pre
 */
void PostThread(ThreadTree &Tree, ThreadTree &pre);


/**
 * 左右空指针线索化函数
 * @param T
 * @param pre
 */
void Visit(ThreadTree &T, ThreadTree &pre);


/**
 * 中序
 *
 * 找到以p为根的字树中,第一个被中序遍历的结点
 *
 * 最左边的第一个结点
 *
 * @param p
 * @return
 */
ThreadNode *InFirstNode(ThreadNode *p);

/**
 * 中序
 *
 * 找后继结点
 * @param p
 * @return
 */
ThreadNode *InNextNode(ThreadNode *p);


/**
 * 最后一个被中序遍历的结点
 *
 * 最右边的结点
 *
 * @param p
 * @return
 */
ThreadNode *InLastNode(ThreadNode *p);

/**
 * 中序
 *
 * 找前驱结点
 * @param p
 * @return
 */
ThreadNode *InPreNode(ThreadNode *p);

/**
 * 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
 * @param Tree
 */
void InOrder(ThreadTree Tree);


/**
 * 先序
 *
 * 找前驱根p结点的父结点必然是他的父亲
 * @param p
 * @return
 */
ThreadNode* PrePreNode(ThreadNode *p);


/**
 * 先序
 *
 * 找后继结点
 * p的后继必然是p->Left
 * @param p
 * @return
 */
ThreadNode* PreNextNode(ThreadNode *p);

/**
 * 后序
 *
 * 找前驱
 * @param p
 * @return
 */
ThreadNode* PostPreNode(ThreadNode *p);

/**
 * 后序
 *
 * 找后继结点
 * @param p
 * @return
 */
ThreadNode* PostNextNode(ThreadNode *p);

#endif //DATASTRUCTURE_THREADNODE_H
