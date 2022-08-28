/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      UFSets
    @author:        30671
    @description:   DONE : 并查集
    @date:          2022/8/28
    @version:       1.0
*/

#ifndef DATASTRUCTURE_UFSETS_H
#define DATASTRUCTURE_UFSETS_H

#include "../../Def.h"

#define UFSet_SIZE 100

int UFSets[UFSet_SIZE];  // 集合元素 (双亲指针数组)

/**
 * 初始化操作
 *
 * 每个元素自成单元素集合
 * @param s
 */
void Initial(const int s[]);

/**
 * 找自己的根
 * @param s
 * @param x
 * @return
 */
int Find(int s[], int x);

/**
 * 前期是两个子集和不相交
 *
 * 求并集
 * @param s
 * @param root1
 * @param root2
 */
void Union(int s[], int root1, int root2);

#endif //DATASTRUCTURE_UFSETS_H
