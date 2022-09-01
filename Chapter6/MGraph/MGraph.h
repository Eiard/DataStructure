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
 *
 * 避免有非连通的图无法遍历到
 *
 * 实现对所有顶点的遍历
 *
 * 对于无向图,调用BFS函数的次数 = 连通分量数
 *
 * 邻接表时间复杂度 0(E + v)
 * 邻接矩阵时间复杂度 0(v^2)
 *
 * @param G
 */
void BFSTraverse(MGraph G);

/**
 * 利用了辅助队列
 *
 * 对顶点V进行广度优先遍历
 *
 * 缺点:非连通图无法通过一个结点实现遍历所有
 * 改进:实现 BFSTraverse
 *
 * @param G
 * @param v
 */
void BFS(MGraph G, int v);

/**
 * 对图进行深度优先遍历
 * 类似于树的先根遍历
 *
 * 避免非连通图无法将左右结点遍历完
 *
 * @param G
 */
void DFSTraverse(MGraph G);

/**
 * 利用了递归
 *
 * DFS遍历
 * 从结点v开始
 * 利用深度优先遍历
 * 遍历所有结点
 *
 * 缺点:对于非连通图来说,仅仅从一个顶点v不一定能遍历完所有结点
 *
 * @param G
 * @param v
 */
void DFS(MGraph G, int v);

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
