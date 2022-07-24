/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      STNode
    @author:        30671
    @description:   TODO 
    @date:          2022/7/24
    @version:       1.0
*/


#ifndef DATASTRUCTURE_STNODE_H
#define DATASTRUCTURE_STNODE_H

#include "../../Def.h"

#define StaticMaxSize 10

typedef struct {
    ElemType data; // 数据
    int next;  // 下标
} SLinkList[StaticMaxSize];


/**
 * 等价
 *      #define StaticMaxSize 10
 *
 *      struct Node{
 *      ElemType data; // 数据
 *      int next;  // 下标
 *      };
 *      typedef struct Node SLinkList[StaticMaxSize];  顺便用SLinkList定义一个长度为MaxSize的Node型数组
 */

/**
 * 功能测试函数
 */
void TestSLinkList();

#endif //DATASTRUCTURE_STNODE_H
