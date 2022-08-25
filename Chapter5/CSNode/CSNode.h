/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      CSNode
    @author:        30671
    @description:   TODO 
    @date:          2022/8/25
    @version:       1.0
*/


#ifndef DATASTRUCTURE_CSNODE_H
#define DATASTRUCTURE_CSNODE_H

#include "../../Def.h"

/**
 * 本质上是
 *
 * 左指针存第一个孩子
 *
 * 右指针存下一个兄弟
 *
 */
typedef struct CSNode {
    ElemType data;
    // 第一个孩子        和 右兄弟指针
    struct CSNode *firstChild, *brother;
} CSNode, *CSTree;


// 树的先根遍历
void PreOrder(CSTree Tree);

// 树的后根遍历
void PostOrder(CSTree Tree);

// 访问数据结点
void Visit(CSNode *R);


#endif //DATASTRUCTURE_CSNODE_H
