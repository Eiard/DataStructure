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
 * 中序遍历对二叉树线索化
 *
 * @param tree
 * @return
 */
void InThread(ThreadNode &tree);


#endif //DATASTRUCTURE_THREADNODE_H
