/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      OrthogonalList
    @author:        30671
    @description:   TODO 
    @date:          2022/8/30
    @version:       1.0
*/


#ifndef DATASTRUCTURE_ORTHOGONALLIST_H
#define DATASTRUCTURE_ORTHOGONALLIST_H

#include "../../Def.h"

typedef double TypeInfo;

typedef struct Bow            //定义弧
{
    // 弧尾顶点编号 和 弧头顶点编号
    int head, tail;

    // 权值
    TypeInfo info;

    // 弧头 相同的下一条弧
    struct Bow *hlink;


    // 弧尾 相同的下一条弧
    struct Bow *tlink;

} Bow;

typedef struct FirstNode        //定义头结点
{
    char data;

    Bow *firIn;
    Bow *firOut;
} FirstNode;

typedef struct            //记录顶点的数量和弧的数量，先定义100顶点
{
    FirstNode list[100];

    int peak, edge;
} total;


#endif //DATASTRUCTURE_ORTHOGONALLIST_H
