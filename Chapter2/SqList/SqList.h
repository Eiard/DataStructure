//
// Created by 30671 on 2022/6/27.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#include "../../Def.h"

/**
 * 静态线性表
 */
#define SqListMaxSize 10
typedef struct {
    ElemType data[SqListMaxSize];
    int length;
}SqList;


#endif //DATASTRUCTURE_SQLIST_H
