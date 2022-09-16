/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      InsertSort
    @author:        30671
    @description:   DONE : 插入排序
    @date:          2022/9/15
    @version:       1.0
*/


#ifndef DATASTRUCTURE_INSERTSORT_H
#define DATASTRUCTURE_INSERTSORT_H

#include "../../Def.h"

/**
 * 直接插入排序
 *
 * 有序区  A[i] 无序区
 *
 * 稳定
 *
 * 最好时间复杂度O(n) 表初态位正序
 * 最坏情况复杂度O(n^2) 表初态逆序
 *
 * 平均时间复杂度O(n^2)
 *
 * @param A 数组
 * @param n 数组长度
 */
void InsertSort(int A[], int n);

/**
 * 折半插入排序
 *
 * 有序区  A[i] 无序区
 *
 * 稳定
 *
 * 最好时间复杂度O(n) 表初态位正序
 * 最坏情况复杂度O(n^2) 表初态逆序
 *
 * 平均时间复杂度O(n^2)
 *
 * @param A
 * @param n
 */
void BinaryInsertSort(int A[], int n);

/**
 * 希尔排序
 *
 * 不稳定
 *
 * 线性表
 *
 * 时间复杂度未知
 *
 *
 * 只能用于顺序表
 * @param A
 * @param n
 */
void ShellSort(int A[], int n);

/**
 * 遍历顺序表
 * @param A
 * @param n
 */
void Traverse(int A[], int n);

/**
 * 测试排序算法
 */
void TestInsertSort();

#endif //DATASTRUCTURE_INSERTSORT_H
