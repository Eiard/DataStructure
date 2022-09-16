/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ExchangeSort
    @author:        30671
    @description:   TODO 
    @date:          2022/9/16
    @version:       1.0
*/


#ifndef DATASTRUCTURE_EXCHANGESORT_H
#define DATASTRUCTURE_EXCHANGESORT_H

#include "../../Def.h"

/**
 * 冒泡排序
 *
 * 稳定 (每次只与相邻的元素互换)
 *
 * 最好时间复杂度O(n) 表初态位正序
 * 最坏情况复杂度O(n^2) 表初态逆序
 *
 * 平均时间复杂度O(n^2)
 * @param A
 * @param n
 */
void BubbleSort(int A[], int n);

/**
 * 划分 为左子区间 和 右子区间
 * @param A
 * @param low 子区间的第一个下标
 * @param high 子区间的最后一个下标
 * @return
 */
int partition(int A[], int low, int high);

/**
 * 快速排序
 *
 * 最好时间复杂度 O(o^log2n) 也是平均时间复杂度
 *
 * 顺序或者逆序时时间复杂度为O(n^2)
 * @param low
 * @param high
 * @param n
 */
void QuickSort(int A[], int low, int high);


/**
 * 测试排序算法
 */
void TestExchangeSort();


#endif //DATASTRUCTURE_EXCHANGESORT_H
