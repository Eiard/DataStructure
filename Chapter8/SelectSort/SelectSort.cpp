/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SelectSort
    @author:        30671
    @description:   TODO 
    @date:          2022/9/16
    @version:       1.0
*/


#include "SelectSort.h"

void SelectSort(int *A, int n) {
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


void sift(int A[], int low, int high) {
    // 默认A[low]为根  A[j]为A[low]的左孩子
    int i = low, j = 2 * i;
    ElemType temp = A[low];
    while (j <= high) {
        if (j < high && A[j] < A[j + 1]) // 如果有右孩子 且 右孩子比左孩子大 则把j指向右孩子
            j++;
        if (temp < A[j]) {  // temp比孩子小, 将A[j]作为新的根(覆盖原先的根)
            A[i] = A[j];
            i = j;  // 下标j变为新的根
            j *= 2;  // 这时,j指向了新的根结点的左孩子
        } else { // 如果temp是最大的,则说明已经是大根堆了
            break;
        }
    }
    A[i] = temp;  // 把放入对应的位置
}


void HeapSort(int *A, int n) {
    /**
     * 初始序列建立大根堆
     */
    for (int i = n / 2; i > 0; i--) {
        sift(A, i, n);
    }

    /**
     * 为什么i-- ,且i从n开始
     *
     * 因为每一次交换元素时,获得到的最大值放在大根堆的最后一个元素
     * 所以每次调整新的堆的时候,范围就是 1 - i-1
     */
    for (int i = n; i >= 2; i--) {
        Swap(A[1], A[i]);  // 交换堆的第一个元素和最后一个元素
        sift(A, 1, i - 1);  // 对根节点A[1]  进行大根堆调整
    }

}
