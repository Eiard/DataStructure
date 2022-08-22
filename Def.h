/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      Def
    @author:        30671
    @description:   DONE
    @date:          2022/6/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_DEF_H
#define DATASTRUCTURE_DEF_H

#include <cstdio>
#include <malloc.h>
#include <cstring>
#include <cmath>

/**
 * 抽象数据类型
 */
typedef int QueueElemType;

#define uint8 int

// 增加一个 并取模
#define ASC_MODULO_OPERATION(x, y) (x+1)%y

/**
 * 两数交换
 * @param e1
 * @param e2
 */
void Swap(QueueElemType &e1, QueueElemType &e2);

#endif //DATASTRUCTURE_DEF_H
