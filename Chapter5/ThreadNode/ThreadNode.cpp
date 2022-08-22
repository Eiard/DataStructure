/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ThreadNode
    @author:        30671
    @description:   DONE : 线索二叉树
    @date:          2022/8/22
    @version:       1.0
*/


#include "ThreadNode.h"


/**
 * 类似于中序遍历
 * @param T
 * @param pre
 */
void InThread(ThreadTree &T, ThreadTree &pre) {
    if (T != nullptr) {

        // 递归,线索化左子树
        InThread(T->lChild, pre);


        //----------------------------
        // 中间是对结点的操作
        // 左孩子指针域为空 建立前驱线索
        if (T->lChild == nullptr) {
            // 指向中序遍历的前一个结点
            T->lChild = pre;
            // 更新线索标志
            T->lTag = 1;
        }

        // 右孩子指针域为空 建立后驱线索
        if (T->rChild == nullptr) {
            // 指向中序遍历的后一个结点
            T->rChild = pre;
            // 更新线索标志
            T->rTag = 1;
        }
        pre = T;
        //----------------------------


        // 递归,线索化右子树
        InThread(T->rChild, pre);
    }

}
