/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      InsertSort
    @author:        30671
    @description:   DONE : 插入排序
    @date:          2022/9/15
    @version:       1.0
*/


#include "InsertSort.h"

/**
 * 按升序排序 1 2 3 4 ..
 * @param A
 * @param n
 */
void InsertSort(int A[], int n) {
    int i, j;

    /**
     * 在移动数据元素时用于暂存当前的结点数据
     */
    ElemType temp;

    /**
     * 从1开始是因为
     * 默认 第一个元素是有序的A[0]有序
     * 所以直接从i = 1开始
     */
    for (i = 1; i < n; ++i) {
        if (A[i] < A[i - 1]) {  // 第i-1个 比 第i个 大,则说明第i个元素需要插入到前面的有序序列中
            /**
             * 因为要移动
             * 所以先暂存数据,后序移动时会有数据将当前位置覆盖
             */
            temp = A[i];

            /**
             * 从后往前,如果自己比别人小
             * 则让别人后移
             */
            j = i - 1;
            do {
                A[j + 1] = A[j];
                j--;
            } while (j >= 0 && A[j] > temp);


            A[j + 1] = temp;
        }
    }
}


void BinaryInsertSort(int A[], int n) {
    int i, j, high, low, mid;

    ElemType temp;

    for (i = 1; i < n; ++i) {
        if (A[i] < A[i - 1]) {
            temp = A[i];
            low = 0;
            high = i - 1;

            /**
             * while循环结束
             *
             * 会停留在需要插入的位置下标 high+1
             */
            while (low <= high) {
                mid = (low + high) / 2;
                if (temp < A[mid]) {  // temp小于A[mid] 则说明该插在左边
                    high = mid - 1;
                } else {  // temp大于A[mid] 则说明该插在左右边
                    low = mid + 1;
                }
            }

            /**
             * 得到下标之后
             * 从下标开始的所有有序元素后移
             *
             * 从后往前后移
             * 从j-1开始移动到high+1
             *
             *
             */
            for (j = i - 1; j >= high + 1; j--) {
                A[j + 1] = A[j];  // 后移
            }

            /**
             * 最终A[high+1]是需要插入的位置
             */
            A[high + 1] = temp;
        }
    }
}


void ShellSort(int A[], int n) {
    int i, j;
    ElemType temp;

    /**
     * 默认初始步数为 n/2(默认为顺序表总长度的一半)
     *
     * 用于后面
     * i i+d i+2d i+3d .... 为一组
     */
    int d = n / 2;

    while (d > 0) {


        /**
         * 为什么i从d开始
         *
         * 因为从d开始才有下标为d-d = 0 的元素大小与下标为d的元素相比
         *
         */
        for (i = d; i < n; ++i) {
            //            暂存
            temp = A[i];


            /**
             * 每个按d间距划分的子序列进行简单插入排序
             *
             * 元素i的 前d步的元素为起点
             * 每次单调递减d
             */
            j = i - d;
            while (j >= 0 && temp < A[j]) {
                // 比temp大的都后移
                A[j + d] = A[j];
                // 每个子序列的元素差为d
                j = j - d;
            }
            // 最后将temp插入到前面子序列的适应位置
            A[j + d] = temp;
        }

        d = d / 2;
    }

}

void Traverse(int A[], int n) {
    for (int j = 0; j < n; ++j) {
        printf("%d\t", A[j]);
    }
}

void TestInsertSort() {

    ElemType a[] = {5, 4, 2, 6, 7, 1, 14};

    // 直接插入排序
    // InsertSort(a, 7);
    // 折半插入排序
    // BinaryInsertSort(a, 7);
    // 希尔排序
    ShellSort(a, 7);

    Traverse(a, 7);

}
