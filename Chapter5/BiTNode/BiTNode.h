/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      BiTNode
    @author:        30671
    @description:   TODO 
    @date:          2022/8/16
    @version:       1.0
*/


#ifndef DATASTRUCTURE_BITNODE_H
#define DATASTRUCTURE_BITNODE_H

#include "../../Def.h"


typedef struct BiTNode {
    ElemType data; // 数据域
    struct BiTNode *lChild, *rChild; // 左 右 孩子指针
} BiTNode, *BiTree;


/**
 * 功能测试函数
 */
void TestBiTNode();




#endif //DATASTRUCTURE_BITNODE_H
