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


void SelectSort(int A[], int n) {
    // 为什么 条件为 i<n-1 因为到最后一次选择时,最大的元素一定在最后面 所以 不需要执行n次 只需要执行n-1次
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        // 在第i个元素之后(前面都是有序的从小到大) 找出后面中最小的元素,并且获得到下标存在min中
        for (int j = i + 1; j < n - 1; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        // 找到最小的下标为min 然后与这一趟的开头的元素i交换
        if (min != i) {
            Swap(A[i], A[min]);
        }
    }
}

#endif //DATASTRUCTURE_SELECTSORT_H
