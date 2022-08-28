/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      HTNode
    @author:        30671
    @description:    DONE : 哈夫曼树的构造 哈夫曼编码
    @date:          2022/8/28
    @version:       1.0
*/

#ifndef DATASTRUCTURE_HTNODE_H
#define DATASTRUCTURE_HTNODE_H

#include "../../Def.h"


typedef char THNodeElemType;

// 哈夫曼树的结点
typedef struct {
    THNodeElemType data;  // 结点值
    double weight;  // 权重
    int parent;  // 双亲结点
    int lChild;  // 左孩子结点
    int rChild;  // 右孩子结点
} HTNode;

#define N 100
// 哈夫曼编码
typedef struct {
    THNodeElemType cd[N];  // 存放当前结点的哈夫曼编码
    int start;  // 表示cd[start .. n] 部分是哈夫曼编码
} HCode;

/**
 * 构造哈夫曼树
 *      利用线性表来构造哈夫曼树
 *
 *      原理:
 *              每次找到两个最小的组合成一个新的
 *              再在集合中删除这两个,把最新的加入进去
 *              再在新的集合中找到两个最小的组合成一个新的,逐渐循环,直到构造出整个哈夫曼树
 * @param ht
 * @param n
 */
void CreateHT(HTNode ht[], int n);


/**
 * 求对应的哈夫曼编码
 * @param ht
 * @param hcd
 * @param n
 */
void CreatHCode(HTNode ht[], HCode hcd[], int n);


#endif //DATASTRUCTURE_HTNODE_H
