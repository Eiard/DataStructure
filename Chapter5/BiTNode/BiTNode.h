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
 * 初始化根节点
 *      树根
 * @param tree
 * @return
 */
bool InitTreeRoot(BiTree tree);

/**
 * 创建一个新的结点
 *      存入对应数据
 * @param data
 * @return
 */
BiTree createBiTNode(ElemType data);

/**
 * 给结点左孩子添加元素
 * @param father
 * @param data
 * @param flag
 * @return
 */
bool addSonBiTNode(BiTree father, ElemType data,uint8 flag);

/**
 * 功能测试函数
 */
void TestBiTNode();


#endif //DATASTRUCTURE_BITNODE_H
