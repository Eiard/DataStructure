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
                A[j] = A[j - 1];
                j--;
            } while (j >= 0 && A[j] < temp);


            A[j + 1] = temp;
        }
    }


}

void TestSort() {

}
