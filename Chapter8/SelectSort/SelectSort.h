/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SelectSort
    @author:        30671
    @description:   TODO 
    @date:          2022/9/16
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SELECTSORT_H
#define DATASTRUCTURE_SELECTSORT_H

#include "../../Def.h"

/**
 * 简单选择排序
 *
 * 不稳定
 *
 * 时间复杂度 O(n^2)
 * @param A
 * @param n
 */
void SelectSort(int A[], int n);


/**
 * 调整以A[low] 为根的左子树和右子树为大根堆
 */
void sift(int A[], int low, int high);

/**
 * 只能用于顺序表
 *
 * 包含两个主要过程
 *
 * 建立大根堆
 * 交换大根堆的顶点和最后一个结点,交换完后,对根节点进一步调整为最大堆
 *
 * 时间复杂度O(n^log2n)
 * @param A
 * @param n
 */
void HeapSort(int A[],int n);

#endif //DATASTRUCTURE_SELECTSORT_H
