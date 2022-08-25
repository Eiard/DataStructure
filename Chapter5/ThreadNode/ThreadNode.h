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

#endif //DATASTRUCTURE_THREADNODE_H
