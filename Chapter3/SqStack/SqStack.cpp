/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqStack
    @author:        30671
    @description:   TODO : 顺序栈
    @date:          2022/7/27
    @version:       1.0
*/


#include "SqStack.h"


void InitSqStack(SqStack &S) {
    S.top = -1;
}

bool Push(SqStack &S, QueueElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }

    // 先移入 再栈顶指针后移
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, QueueElemType &x) {
    if (S.top == -1) {
        return false;
    }

    // 先取出元素 后减一 (只进行了逻辑删除)
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, QueueElemType &x) {
    if (S.top == -1) {
        return false;
    }

    // 先读取元素
    x = S.data[S.top];
    return true;
}


void TestSqStack() {
    SqStack S;  // 声明一个顺序栈(分配空间)
    InitSqStack(S);

    /**
     * 其他操作
     */

    char a[] = "{{}}";

    printf("%d", bracketCheck(a, sizeof(a)));

}

bool bracketCheck(char str[], int length) {
    SqStack S;
    InitSqStack(S);

    for (int i = 0; i < length; ++i) {
        // 如果为左括号则压入栈中
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else {

            // 如果为空则说明扫描到右括号且栈为空 匹配失败
            //            if (StackEmpty(S))
            //                return false;

            // 从栈顶取出一个括号进行匹配
            QueueElemType topElem;
            Pop(S, topElem);

            // 如果 扫描到的是) 而栈顶不是 ( 的话则说明匹配失败 则直接结束
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return true;
}


int computeSuffix(char *str, int length) {
    return 0;
}


bool turnSuffixToInfix(char *suffix, int sLength, char infix, int iLength) {
    return false;
}
