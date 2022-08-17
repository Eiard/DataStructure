/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      main
    @author:        30671
    @description:   FIXME
    @date:          2022/6/27
    @version:       1.0
*/


#include "Def.h"
#include "Chapter2/SqList/SqList.h"
#include "Chapter2/SeqList/SeqList.h"
#include "Chapter2/LNode/LNode.h"
#include "Chapter2/DNode/DNode.h"
#include "Chapter2/STNode/STNode.h"

#include "Chapter3/LinkQueue/LinkQueue.h"
#include "Chapter3/ShStack/ShStack.h"
#include "Chapter3/SqQueue/SqQueue.h"
#include "Chapter3/SqStack/SqStack.h"

#include "Chapter4/SString/SString.h"

#include "Chapter5/TreeNode/TreeNode.h"
#include "Chapter5/BiTNode/BiTNode.h"

int main() {
    // 静态线性表测试
    // TestSqList();

    // 动态线性表测试
    // TestSqeList();

    // 单链表的测试
    // TestLinkList();

    // 栈相关功能测试
    // TestSqStack();

    // 串 字符串匹配算法的测试
    // TestSString();

    // 树相关功能测试
    TestBiTNode();

    return 0;
}

