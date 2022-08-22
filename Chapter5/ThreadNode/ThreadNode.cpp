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
 * 中序线索化二叉树T
 * @param T
 * @param pre
 */
void CreateInThread(ThreadTree &T, ThreadTree &pre) {
    pre = nullptr;  // pre 初始为null
    if (T != nullptr) { // 非空二叉树才能线索化
        InThread(T, pre);  // 中序线索化二叉树

        // 递归操作完后 pre必然指向最后一个结点
        if (pre->rChild == nullptr) {
            pre->rTag = 1;  // 对最后一个结点进行特殊处理
        }
    }
}

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

        // 前一个结点(pre)的右孩子指针域为空 建立后驱线索
        if (pre != nullptr && pre->rChild == nullptr) {
            // 当前结点的前一个结点的后继节点 = 当前节点
            pre->rChild = T;
            // 更新线索标志
            pre->rTag = 1;
        }
        // 标记当前结点成为刚刚访问过的结点
        pre = T;
        //----------------------------


        // 递归,线索化右子树
        InThread(T->rChild, pre);
    }

}
