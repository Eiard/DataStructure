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
#include "../../Chapter3/LinkQueue/LinkQueue.h"


/**
 * 相当于100*100的矩阵
 */
#define MaxVertexNum 100

/**
 * 顶点数据类型
 */
typedef char MGRAPH_ElemType;

typedef struct {
    MGRAPH_ElemType Vex[MaxVertexNum];  // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];  // 灵界矩阵,边表   1代表有这条边  0代表没有这条边
    int vexNum, arcNum;  // 顶点个数 和 边的个数
} MGraph;

/**
 * 访问标记数组
 */
bool visited[MaxVertexNum];

/**
 * 初始化一个图
 */
MGraph mGraph;

/**
 * 声明一个辅助队列
 */
LinkQueue Q;

/**
 * 找到第一个相邻结点的下标
 * @param G
 * @param v
 * @return
 */
int FirstNeighbor(MGraph G, int v);

/**
 * 排在w后面的
 * 与v相邻的下一个结点的下标
 * @param G
 * @param v
 * @param w
 * @return
 */
int NextNeighbor(MGraph G, int v, int w);

/**
 * 对整个图进行广度优先遍历
 * @param G
 */
void BFSTraverse(MGraph G);

/**
 * 对顶点V进行广度优先遍历
 * @param G
 * @param v
 */
void BFS(MGraph G, int v);

/**
 * 访问顶点表中下标为v的顶点的数据
 * @param v
 */
void visit(int v);

/**
 * 功能测试函数
 */
void TestMGraph();

#endif //DATASTRUCTURE_MGRAPH_H
