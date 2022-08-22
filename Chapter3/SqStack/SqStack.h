/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SqStack
    @author:        30671
    @description:   TODO 
    @date:          2022/7/27
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H


#include "../../Def.h"

#define MaxSize 10  // 定义栈中元素的最大个数

typedef struct {
    QueueElemType data[MaxSize];  // 静态数组存放元素
    int top;  // 栈顶指针
} SqStack;

/**
 * 初始化顺序栈栈
 * @param S
 */
void InitSqStack(SqStack &S);

/**
 * 往栈中push一个元素
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, QueueElemType x);

/**
 * 从栈中Pop出一个元素
 * @param S
 * @param x
 * @return
 */
bool Pop(SqStack &S, QueueElemType &x);

/**
 * 读取栈顶元素
 * @param S
 * @param x
 * @return
 */
bool GetTop(SqStack S, QueueElemType &x);


/**
 * 栈测试函数
 */
void TestSqStack();

/**
 * 括号匹配
 *      1. 扫描下一个元素
 *      2. 扫描到左括号压入栈中
 *      3. 扫描到右括号,从栈中取出一个括号进行匹配,匹配失败则匹配错误,匹配成功则继续
 *      4. 直到读取完元素后,栈为空,则匹配成功
 * @param str
 * @param length
 * @return
 */
bool bracketCheck(char str[], int length);

/**
 * 后缀表达式值的运算方式
 *      特点:    运算符前面最近的两个操作数执行运算
 *      1. 从左往右扫描下一个元素,直到处理完所有元素
 *      2. 若扫描到操作数则压入栈,并回到1,否则执行3
 *      3. 若扫描到运算符,则弹出两个栈顶元素,执行相应运算,运算结果压回栈顶,回到1
 * @param str
 * @param length
 * @return
 */
int computeSuffix(char str[], int length);

/**
 * 将后缀转化为中缀表达式
 * @param suffix
 * @param sLength
 * @param infix
 * @param iLength
 * @return
 */
bool turnSuffixToInfix(char suffix[], int sLength, char infix, int iLength);


#endif //DATASTRUCTURE_SQSTACK_H
