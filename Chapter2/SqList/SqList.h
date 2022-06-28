/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqList
    @author:        30671
    @description:   TODO
    @date:          2022/6/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include "../../Def.h"

/**
 * 动态线性表
 */
#define SqListMaxSize 10    // 定义最大长度

typedef struct {
    ElemType data[SqListMaxSize];   // 用静态的"数组"存放数据元素
    int length;                     // 顺序表的当前长度
} SqList;                           // 顺序表的类型定义(静态分配方式)

/**
 * 初始化静态线性表
 * @param L
 */
void InitSqList(SqList &L);

/**
 * 向下标为i的位置插入元素 下标i后面的元素全部后移
 * 最好情况: 新元素插入到表尾,不需要移动元素
 *          i = n + 1 , 循环0次 : 最好时间复杂度 = O(1)
 * 最坏情况: 新元素插入到表头,需要将原有的n个元素全部向后移动
 *          i = 1 ,循环n次 : 最坏时间复杂度为 = O(n)
 * 平均情况: 假设新元素插入到任何一个位置的概率相同, 即 i = 1,2,3,...,length+1的概率都是p = 1/(n+1)
 *          i = 1 , 循环n次    i = 2 , 循环n-1次    i = 3 , 循环n-2次    ....    i = n + 1 , 循环0次
 *         平均循环次数 = np + (n-1)p + (n-2)p .... + 1p = n(n+1)/2 × 1/(n+1) = n/2
 *         平均时间复杂度 O(n)
 * @param L
 * @param i
 * @param e
 */
bool InsertSqList(SqList &L, int i, ElemType e);

/**
 * 删除表L中第i个位置的元素,i下标后的元素全部前移
 * 最好情况: 删除表尾元素,不需要移动元素
 *          i = n , 循环0次 : 最好时间复杂度 = O(1)
 * 最坏情况: 移动除头元素外的所有元素
 *          i = 1 ,循环n-1次 : 最坏时间复杂度为 = O(n)
 * 平均情况: 假设删除任意元素在任何一个位置的概率相同, 即 i = 1,2,3,...,length+1的概率都是p = 1/(n+1)
 *          i = 1 , 循环n-1次    i = 2 , 循环n-2次    i = 3 , 循环n-3次    ....    i = n , 循环0次
 *         平均循环次数 = (n-1)p + (n-1)p + (n-2)p .... + 1p = (n-1)(n-1 + 1)/2 × 1/(n) = (n-1)/2
 *         平均时间复杂度 O(n)
 * @param  L
 * @param  i
 * @param  e
 * @return e(通过引用返回删除的值)
 */
bool DeleteSqList(SqList &L, int i, ElemType &e);

/**
 * 通过下标直接获取元素
 * 时间复杂度 = O(1)
 * @param L
 * @param i
 * @return
 */
ElemType GetElemSqList(SqList L, int i);


/**
 * 获取某个值在该线性表中的下标
 * 最好情况: 目标元素在表头
 *          循环1次 : 最好时间复杂度 = O(1)
 * 最坏情况: 目标元素在表尾
 *          循环n次 : 最坏时间复杂度 = O(n)
 * 平均情况: 假设删除任意元素在任何一个位置的概率相同 都是 1/n
 *          目标元素    在第1位循环1次    第2位循环2次     第3位循环3次 ....    第n位循环n次
 *          平均循环次数 1/n + 2/n + 3/n .... n/n = (n+1)/2   平均时间复杂度为O(n)
 * @param L
 * @param e
 * @return
 */
ElemType LocateElemSqList(SqList L, ElemType e);


/**
 * 遍历静态线性表
 * @param L
 */
void Traverse(SqList L);

/**
 * 功能测试函数
 */
void TestSqList();

#endif //DATASTRUCTURE_SQLIST_H
