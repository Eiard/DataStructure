/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      MGraph
    @author:        30671
    @description:   DONE : 邻接矩阵
    @date:          2022/8/30
    @version:       1.0
*/


#include "MGraph.h"

int FirstNeighbor(MGraph G, int v) {
    return 0;
}

int NextNeighbor(MGraph G, int v, int w) {
    return 0;
}

void BFSTraverse(MGraph G) {
    /**
     * 初始化visited访问数组
     */
    for (int i = 0; i < G.vexNum; ++i) {
        visited[i] = false;
    }

    /**
     * 初始化一个辅助队列
     */
    InitQueue(Q);

    /**
     * 对所有顶点按顺序作为出发点遍历
     * 如果已经被访问过则跳过
     */
    for (int i = 0; i < G.vexNum; ++i) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}


void BFS(MGraph G, int v) {
    /**
     * 访问下标为v的顶点数据
     * 并且更新访问数组
     */
    visit(v);
    visited[v] = true;

    /**
     * 第一个顶点入队
     */
    EnQueue(Q, v);

    /**
     * 队列不为空则继续
     */
    while (!QueueIsEmpty(Q)) {
        // 不空的话 出队一个
        DeQueue(Q, v);

        /**
         * 依次遍历该结点相邻的所有结点
         *
         * 都进行入队
         *
         * 每出队一个结点
         * 都会访问其没有访问过的邻接结点
         * 并且在访问完后继续放入队尾
         *
         */
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            // 如果该结点未被访问
            if (!visited[w]) {
                visit(w);  // 访问顶点w
                visited[w] = true;  // 更新标记
                EnQueue(Q, w);  // 每个结点访问完之后都入队
            }
        }
    }
}


void visit(int v) {
    printf("%c \n", mGraph.Vex[v]);
}


void TestMGraph() {

}