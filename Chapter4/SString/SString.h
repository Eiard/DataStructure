/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SString
    @author:        30671
    @description:   TODO 
    @date:          2022/8/14
    @version:       1.0
*/


#ifndef DATASTRUCTURE_SSTRING_H
#define DATASTRUCTURE_SSTRING_H

#include "../../Def.h"

#define MAX_LEN 255

typedef struct {
    char ch[MAX_LEN];
    //    char *ch;  // 动态分配
    int length;
} SString;

/**
 * KMP算法
 *      时间复杂度
 *      包含求next数组 时间复杂度为 0(m+n) m为模式串长度
 *
 *      不包含求next数组,直接利用现有的next数组的时间复杂度 0(n) n为主串长度
 *
 * @param S
 * @param T
 * @return
 */
int Index_KMP(SString S, SString T);

/**
 * 获取匹配失败时的跳转数组
 *
 * next[j] = S的最长相等前后缀长度 + 1
 * 特别的next[1] = 0
 *
 *      时间复杂度0(m) m为模式串T的长度
 * @param T
 * @param next
 */
void get_next(SString T, int next[]);

/**
 * 朴素模式匹配算法
 *      最原始的匹配方法
 *      定位子串T在S中第一次出现的位置
 *      考试会考的算法常用
 *
 *      匹配成功的最好时间复杂度(从开始到结束每个字符都匹配成功):0(m)
 *      匹配失败的最好时间复杂度(每次都是第一个都匹配失败):0(n-m+1) = 0(n-m) 约等于0(n)
 *      最坏时间复杂度0(nm)
 * @param S
 * @param T
 * @return
 */
int Index(SString S, SString T);


/**
 * 初始化字符串
 * @param T
 * @return
 */
bool InitString(SString &T);

/**
 * 用Sub返回串S的第pos个字符起长度为len的子串
 * @param Sub
 * @param S
 * @param pos
 * @param length
 * @return
 */
bool SubString(SString &Sub, SString S, int pos, int length);

/**
 * 比较两个串
 *      如果S>T   则返回值>0
 *      如果S=T   则返回值=0
 *      如果S<T   则返回值<0
 * @param S
 * @param T
 * @return
 */
bool StrCompare(SString S, SString T);

/**
 * 定位子串T在S中第一次出现的位置
 *      封装后的算法(少用)
 * @param S
 * @param T
 * @return
 */
int Index1(SString S, SString T);

/**
 * 计算串长度
 * @param S
 * @return
 */
bool StrLength(SString &S);


/**
 * 字符串赋值操作
 *      把T赋值给S
 * @param S
 * @param T
 * @return
 */
bool StrAssign(SString &S, SString T);

/**
 * 将S复制给T
 * @param S
 * @param T
 * @return
 */
bool StrCopy(SString S, SString &T);

/**
 * 判断S是否为空
 * @param S
 * @return
 */
bool StrEmpty(SString &S);

/**
 * 清空串
 * @param S
 * @return
 */
bool ClearString(SString &S);

/**
 * 销毁串
 * @param S
 * @return
 */
bool DestroyString(SString &S);

/**
 * 连接S1和S2 并且赋值给 T
 * @param T
 * @param S1
 * @param S2
 * @return
 */
bool Concat(SString &T, SString &S1, SString &S2);


/**
 * 功能测试函数
 */
void TestSString();

#endif //DATASTRUCTURE_SSTRING_H
