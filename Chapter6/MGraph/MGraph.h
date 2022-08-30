/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      MGraph
    @author:        30671
    @description:   DONE : 邻接矩阵
    @date:          2022/8/30
    @version:       1.0
*/


#ifndef DATASTRUCTURE_MGRAPH_H
#define DATASTRUCTURE_MGRAPH_H


#include "../../Def.h"


/**
 * 相当于100*100的矩阵
 */
#define MaxVertexNum 100

typedef char MGRAPH_ElemType;  // 顶点数目的最大值

typedef struct {
    MGRAPH_ElemType Vex[MaxVertexNum];  // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];  // 灵界矩阵,边表   1代表有这条边  0代表没有这条边
    int vexNum, arcNum;  // 顶点个数 和 边的个数
} MGraph;


#endif //DATASTRUCTURE_MGRAPH_H
