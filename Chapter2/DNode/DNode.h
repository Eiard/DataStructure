/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      DNode
    @author:        30671
    @description:   DONE : 双链表
    @date:          2022/7/23
    @version:       1.0
*/


#ifndef DATASTRUCTURE_DNODE_H
#define DATASTRUCTURE_DNODE_H

#include"../../Def.h"

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


#endif //DATASTRUCTURE_DNODE_H
