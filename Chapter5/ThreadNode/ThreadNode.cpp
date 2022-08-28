/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ThreadNode
    @author:        30671
    @description:   DONE : 线索二叉树
                  中序        先序      后序
    找前驱          ✔          x        ✔
    找后继          ✔          ✔        x
    打 x 的 必须借助三叉链表才能实现

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

        // 指针域处理函数
        Visit(T, pre);

        // 递归,线索化右子树
        InThread(T->rChild, pre);
    }

}


void CreatePreThread(ThreadTree &T, ThreadTree &pre) {
    pre = nullptr;  // pre 初始为null
    if (T != nullptr) { // 非空二叉树才能线索化
        PreThread(T, pre);  // 中序线索化二叉树

        // 递归操作完后 pre必然指向最后一个结点
        if (pre->rChild == nullptr) {
            pre->rTag = 1;  // 对最后一个结点进行特殊处理
        }
    }
}

/**
 * 类似于先序遍历
 *      根
 *      左
 *      右
 *
 * @param T
 * @param pre
 */
void PreThread(ThreadTree &T, ThreadTree &pre) {
    if (T != nullptr) {
        // 指针域处理函数
        Visit(T, pre);

        // 递归,线索化左子树
        // 避免形成死循环
        if (T->lTag == 0) {
            PreThread(T->lChild, pre);
        }

        // 递归,线索化右子树
        PreThread(T->rChild, pre);
    }
}

void CreatePostThread(ThreadTree &T, ThreadTree &pre) {
    pre = nullptr;  // pre 初始为null
    if (T != nullptr) { // 非空二叉树才能线索化
        PreThread(T, pre);  // 中序线索化二叉树

        // 递归操作完后 pre必然指向最后一个结点 (对右孩子空指针处理)
        if (pre->rChild == nullptr) {
            pre->rTag = 1;  // 对最后一个结点进行特殊处理
        }
    }
}

/**
 * 左
 * 右
 * 根
 *
 * @param T
 * @param pre
 */
void PostThread(ThreadTree &T, ThreadTree &pre) {
    if (T != nullptr) {
        // 递归,线索化左子树
        PreThread(T->lChild, pre);

        // 递归,线索化右子树
        PreThread(T->rChild, pre);

        // 指针域处理函数
        Visit(T, pre);
    }
}


/**
 * 左右空指针线索化函数
 * @param T
 * @param pre
 */
void Visit(ThreadTree &T, ThreadTree &pre) {

    //----------------------------
    // 处理左孩子指针
    // 中间是对结点的操作
    // 左孩子指针域为空 建立前驱线索
    if (T->lChild == nullptr) {
        // 指向中序遍历的前一个结点
        T->lChild = pre;
        // 更新线索标志
        T->lTag = 1;
    }


    // 处理右孩子指针
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

}

/**
 * 找到以p为根的字树中,第一个被中序遍历的结点
 *
 *      p
 *   l     r
 * l  r  l   r
 *
 *
 * @param p
 * @return
 */
ThreadNode *InFirstNode(ThreadNode *p) {


    /**
     * 由于是 左 根 右
     *
     * 对于根p而言
     *
     * 从此处开始的最左边的结点就是中序第一个被遍历的结点
     *
     */
    // 左边有结点 不是线索化的结点
    while (p->lTag == 0)
        p = p->lChild;


    return p;
}

/**
 * 找p的后继结点
 *
 *             p
 *         l       r
 *       l   r   l   r
 *      l r l r l r l r
 *             l
 *
 *            所以p的后继是p的右孩子的最左边的孩子
 *
 *            若p->rTag == 1 则next = p->rChild
 *            若p->rTag == 0 则next = p->rChild->lChild->lChild->....
 *                                  右 -> 左 -> 左 ......
 * @param p
 * @return
 */
ThreadNode *InNextNode(ThreadNode *p) {
    if (p->rTag == 0) {
        return InFirstNode(p->rChild);
    } else {
        return p->rChild;
    }
}

/**
 * 根节点p的最右边的结点是最后遍历的结点
 *
 * @param p
 * @return
 */
ThreadNode *InLastNode(ThreadNode *p) {
    // 右边有结点 不是线索化的结点
    // 不一定是叶节点
    while (p->rTag == 0)
        p = p->rChild;
    return p;
}

ThreadNode *InPreNode(ThreadNode *p) {
    // 左子树中最右下结点
    // p->lTag == 0 未线索化的结点
    if (p->lTag == 0)return InLastNode(p->lChild);
    else {  // p->lTag == 1 则说明p的左孩子已经被线索化为前驱结点指针 直接跳向前驱
        return p->lChild;
    }
}

/**
 * 直接找到第一个要遍历的点
 *
 * 通过线索直接跳向后继节点
 *
 * 时间复杂度为0(1)
 *
 * @param Tree
 */
void InOrder(ThreadTree Tree) {
    for (ThreadNode *p = InFirstNode(Tree); p != nullptr; p = InNextNode(p)) {

        // visit(p)
        printf("%d", p->data);

    }
}

/**
 * 后序线索二叉树遍历
 *
 * 需要三叉链表
 * @param p
 * @return
 */
ThreadNode *PrePreNode(ThreadNode *p) {
    // 需要三叉链表 访问父亲结点
    return nullptr;
}


ThreadNode *PreNextNode(ThreadNode *p) {
    if (p->lTag == 0) {
        // 有左孩子
        return p->lChild;
    } else {
        // 没有左孩子
        return p->rChild;
    }
}


ThreadNode *PostPreNode(ThreadNode *p) {
    if (p->lTag == 1)  // Tag == 1 已经线索化好的前驱结点指针
        return p->lChild;
    else {
        if (p->rTag == 0) {
            // 有右孩子
            // 左 右 根
            // 左 (左 右 根) 根
            // 前驱就是右孩子
            return p->rChild;
        } else {
            // p没有右孩子

            // 左 根
            // (左 右 根) 根
            // 前驱就是左孩子
        }
    }
}

ThreadNode *PostNextNode(ThreadNode *p) {
    if (p->rTag == 1) // 已经线索化的情况,直接通过线索跳转
        return p->rChild;
    else {
        // 则必有右孩子

        // 后序遍历 左 右 根

        // .... 需要三叉链表 可以返回到父亲节点
    }
}
