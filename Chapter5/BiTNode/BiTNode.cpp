/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      BiTNode
    @author:        30671
    @description:   TODO 
    @date:          2022/8/16
    @version:       1.0
*/


#include "BiTNode.h"


/**
 * 用来判断是添加左孩子 还是 右孩子
 */
enum {
    Left,
    Right,
};

bool InitTreeRoot(BiTree tree) {
    tree = (BiTree) malloc(sizeof(BiTree));
    tree->data = 1;
    tree->lChild = nullptr;
    tree->rChild = nullptr;
    return true;
}

BiTree createBiTNode(ElemType data) {
    // 动态申请一个结点
    BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
    if (p == nullptr)
        return nullptr;

    // 存入数据
    p->data = data;

    // 新添加的结点左孩子和有孩子初始化为null
    p->lChild = nullptr;
    p->rChild = nullptr;

    return p;
}

bool addSonBiTNode(BiTree father, ElemType data, uint8 flag) {
    if (father == nullptr) {
        return false;
    }

    BiTNode *p = createBiTNode(data);
    if (p == nullptr) {
        return false;
    }

    // 按照flag决定是左孩子还是右孩子
    if (flag == Left) {
        father->lChild = p;
    } else if (flag == Right) {
        father->rChild = p;
    } else {
        return false;
    }
    return true;
}

BiTNode *getSonBiTNode(BiTree father, int flag) {
    if (father == nullptr) {
        return nullptr;
    }
    
    if (flag == Left) {
        return father->lChild;
    } else if (flag == Right) {
        return father->rChild;
    } else {
        return nullptr;
    }
}

void TestBiTNode() {

    //  定义一棵空树
    BiTree root = nullptr;

    // 初始化树根结点
    InitTreeRoot(root);


}
