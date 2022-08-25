/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      PTNode
    @author:        30671
    @description:   DONE : 双亲表示法 表示树
    @date:          2022/8/25
    @version:       1.0
*/


#ifndef DATASTRUCTURE_PTNODE_H
#define DATASTRUCTURE_PTNODE_H

#include "../../Def.h"

#define MAX_TREE_SIZE 100  // 树最大个数

typedef struct {  // 树的结点定义
    ElemType data;  // 数据元素
    int parent;  // 双亲位置域
}PTNode;

typedef struct {  // 树的类型定义
    PTNode nodes[MAX_TREE_SIZE];  // 双亲表示
    int n;  // 结点个数
};


#endif //DATASTRUCTURE_PTNODE_H
