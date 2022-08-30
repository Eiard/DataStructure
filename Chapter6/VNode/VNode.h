/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      VNode
    @author:        30671
    @description:   DONE : 邻接表
    @date:          2022/8/30
    @version:       1.0
*/


#ifndef DATASTRUCTURE_VNODE_H
#define DATASTRUCTURE_VNODE_H

#include "../../Def.h"

#define MaxVertexNum 100

typedef char VertexType;
typedef double InfoType;


/**
 * 边/弧
 * 从某一个顶点顶点指向其他顶点
 *
 * 对于某一个顶点来说
 *      其弧连成了一个串:该串是以自己为起点,以能到的点为终点的弧
 *
 */
typedef struct ArcNode {
    int adjvex;  // 边/弧   指向那个结点
    ArcNode *next;  // 指向下一条弧的指针
    InfoType info;  // 边的权值
} ArcNode;

/**
 * 顶点
 *
 * AdjList[MaxVertexNum]
 *      顶点信息的数组
 *
 */
typedef struct VNode {
    VertexType data; // 顶点信息
    ArcNode *first;  // 该顶点
} VNode, AdjList[MaxVertexNum];

/**
 * 用邻接表存储的图
 * vertices(顶点信息的数组)
 */
typedef struct {
    AdjList vertices;
    int vexNum, arcNum;  // 顶点的个数    弧的个数
} ALGraph;


#endif //DATASTRUCTURE_VNODE_H
