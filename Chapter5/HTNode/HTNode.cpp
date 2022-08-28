/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      HTNode
    @author:        30671
    @description:   DONE : 哈夫曼树 哈夫曼编码
    @date:          2022/8/28
    @version:       1.0
*/


#include "HTNode.h"


void CreateHT(HTNode ht[], int n) {
    int i, k, lnode, rnode;
    double min1, min2;
    for (i = 0; i < 2 * n - 1; ++i) {  // 所有结点的相关域置初值-1
        ht[i].parent = ht[i].lChild = ht[i].rChild = -1;
    }

    // 构造哈夫曼树的n-1个分支
    for (i = 0; i < 2 * n - 1; ++i) {
        min1 = min2 = 32767;
        lnode = rnode = -1;  // lnode和rnode为最小权重的两个结点位置

        /**
         * 找到值最小的两个结点
         * (还未组合的结点)
         */
        for (int k = 0; k < i - 1; ++k) { // 在ht[0..i-1]中找权值最小的两个结点
            if (ht[k].parent == -1) {  // 只在尚未构造二叉树的结点中查找     如果parent==-1  则说明该节点还未给其找父亲
                if (ht[k].weight < min1) {


                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }


        // 已经找到两个值相加最小的结点
        // 相加之后 新分支节点的weight = lweight+rweight
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        /**
         * 两个值最小的结点(组合到分支节点上)
         * 更新分支节点的左右孩子指针
         * 更新左右孩子的父亲结点指针
         */
        ht[i].lChild = lnode;
        ht[i].rChild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}


/**
 * hcd 哈夫曼编码为一个数组
 *
 *      对于一个结点A 则生成的对应hcd元素为
 *              start 为字符开始的下标
 *
 * 直接到根,然后每网上一级就判断自己是上一级的什么孩子,如果是左孩子则对应0 如果是右孩子则对应1
 * @param ht
 * @param hcd
 * @param n
 */
void CreatHCode(HTNode ht[], HCode hcd[], int n) {

    int i, f, c;
    HCode hc;

    for (int i = 0; i < n; ++i) {

        // 从后往前存储0 和 1

        hc.start = n;
        c = i;

        /**
         * 从叶子结点开始,即哈夫曼树的叶子结点开始,往上遍历
         * 每网上遍历一层就按左孩子为0 右孩子为1
         *
         * 最后形成的是倒序的从下到上的0或1
         *
         * 则是正向的从上到下
         */
        while (f != -1) {  // 循环到无双亲 直接到根

            // ht[f]为双亲结点
            if (ht[f].lChild == c) {  // 左孩子 0
                hc.cd[hc.start--] = '0';
            } else {  // 右孩子 1
                hc.cd[hc.start--] = '1';
            }
            // c作为暂存上一个结点(原先的f)  用于下一次循环的作为孩子结点
            c = f;

            // 再找f的父亲 f = f父亲的索引  用于下一次循环的作为父亲结点
            f = ht[f].parent;
        }
        hc.start++;  // start指向哈夫曼编码最开始的字符
        hcd[i] = hc;
    }
}
