/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      UFSets
    @author:        30671
    @description:   DONE : 并查集
    @date:          2022/8/28
    @version:       1.0
*/


#include "UFSets.h"


void Initial(int *s) {
    for (int i = 0; i < sizeof(s); ++i) {
        s[i] = i;  // 自己的父亲指向自己的集合
    }
}

int Find(int *s, int x) {
    while (s[x] >= 0)// 寻找x 的根
    {
        x = s[x];
    }
    return x;
}

void Union(int *s, int root1, int root2) {
    int root1_fa = Find(s, root1);
    int root2_fa = Find(s, root2);
    s[root2] = root1;  // 让root2 指向 root1

    //    root2原先的集合  ->  root2 -> root1
}
