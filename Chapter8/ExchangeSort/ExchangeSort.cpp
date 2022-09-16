/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      ExchangeSort
    @author:        30671
    @description:   TODO 
    @date:          2022/9/16
    @version:       1.0
*/


#include "ExchangeSort.h"
#include "../InsertSort/InsertSort.h"

void BubbleSort(int *A, int n) {
    int i, j;

    bool exchange;

    // 在i = n-1时,为最后一个元素,且其他元素已经排序好了
    for (i = 0; i < n - 1; ++i) {
        exchange = false;
        /**
         * 为什么j>i  因为前i个都已经排序好了
         *
         * 从后往前进行比较
         *
         * 与自己相邻的前一个元素比大小
         *
         * 进行交换
         */
        for (j = n - 1; j > i; j--) {
            // 谁值小,谁往前面换
            if (A[j] < A[j - 1]) {
                // 交换1次 移动3次
                Swap(A[j], A[j - 1]);
                exchange = true;
            }
        }
        /**
         * 如果一整趟 下来 exchange仍为false 则说明都没有任何一次交换 ,则说明已经有序了
         */
        if (!exchange) {
            return;
        }
    }

}


int partition(int A[], int low, int high) {
    // 以temp为基准
    // 划分为比他小的在左边  比他大的在右边
    ElemType temp = A[low];

    while (low < high) {  // 两端交替向中间扫描
        while (low > high && A[high] >= temp)  // 由右向左扫描,找到一个比temp小的
            high--;
        A[low] = A[high];  // 基准的右边找到这个比temp小的元素 放在low这个空位

        while (low < high && A[low] <= temp)  // 由左向右扫描,找到一个比temp大的
            low++;
        A[high] = A[low];  // 基准的左边找到这个比temp大的元素 放在high这个空位 因为刚才已经将high这个元素转移到了low
    }

    // 一趟能确定该基准的最终位置
    A[low] = temp;
    return low;
}

void QuickSort(int A[], int low, int high) {
    // 如果low = high 则说明 该子区间只有一个元素 ,就已经是有序的
    if (low < high) {
        int i = partition(A, low, high);  // 处理完之后返回已经找到最终位置的基准元素的下标

        // 递归 左边 和 右边 的两个子序列
        QuickSort(A, low, i - 1);
        QuickSort(A, i + 1, high);
    }
}

void TestExchangeSort() {
    ElemType a[] = {5, 4, 2, 6, 7, 1, 14};

    QuickSort(a, 0, 7);

    Traverse(a, 7);
}
