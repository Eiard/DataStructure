/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      CSNode
    @author:        30671
    @description:   TODO 
    @date:          2022/8/25
    @version:       1.0
*/


#include "CSNode.h"


/**
 * 树的  先根遍历序列  和  转化为孩子兄弟表示法的二叉树  先序序列  相同
 * @param R
 */
void PreOrder(CSTree R) {
    if (R != nullptr) {
        // 1.访问根结点数据
        Visit(R);
        // 2.遍历左孩子
        PreOrder(R->firstChild);
        // 3.遍历完该结点的左孩子之后去遍历右孩子指向的兄弟结点
        PreOrder(R->brother);
    }
}

void PostOrder(CSTree R) {
    if (R != nullptr) {
        // 1.先遍历左孩子
        PostOrder(R->firstChild);
        // 2.遍历完该结点的左孩子,就去遍历右孩子指向的兄弟结点
        PostOrder(R->brother);
        // 3.访问根节点数据
        Visit(R);
    }
}

void Visit(CSNode *R) {
    printf("%d\n", R->data);
}
