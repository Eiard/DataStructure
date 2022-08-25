/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      CTNode
    @author:        30671
    @description:   DONE : 孩子表示法    利用顺序和链式混合存储的方式
    @date:          2022/8/25
    @version:       1.0
*/


#ifndef DATASTRUCTURE_CTNODE_H
#define DATASTRUCTURE_CTNODE_H

#include "../../Def.h"

#define MAX_TREE_SIZE 100;

struct CTNode {
    int child;  // 孩子结点在数组中的位置
    struct CTNode *next;  // 下一个孩子
};

typedef struct {
    ElemType data;
    struct CTNode *firstChild;  // 第一个孩子
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE]
    int n, r;  // 结点数 和 根的位置
} CTree;


#endif //DATASTRUCTURE_CTNODE_H
