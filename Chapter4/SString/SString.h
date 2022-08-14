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
    int length;
} SString;


/**
 * 字符串赋值操作
 *      把str赋值给sString
 * @param sString
 * @param str
 * @param length
 * @return
 */
bool StrAssign(SString &sString, char *str, int length);

/**
 * 将sString复制给copy
 * @param sString
 * @param copy
 * @return
 */
bool StrCopy(SString &sString, char *copy);

/**
 * 判断sString是否为空
 * @param sString
 * @return
 */
bool StrEmpty(SString &sString);

/**
 * 计算串长度
 * @param sString
 * @return
 */
bool StrLength(SString &sString);

/**
 * 清空串
 * @param sString
 * @return
 */
bool ClearString(SString &sString);

/**
 * 销毁串
 * @param sString
 * @return
 */
bool DestroyString(SString &sString);

/**
 * 连接s1和s2 并且赋值给sString
 * @param sString
 * @param s1
 * @param s1Length
 * @param s2
 * @param s2Length
 * @return
 */
bool Concat(SString &sString, char *s1, int s1Length, char *s2, int s2Length);

/**
 * 定位字串temp在sString中第一次出现的位置
 * @param sString
 * @param temp
 * @param length
 * @return
 */
int IndexOf(SString &sString, char *temp, int length);


/**
 * 比较两个串
 *      如果S>T   则返回值>0
 *      如果S=T   则返回值=0
 *      如果S<T   则返回值<0
 * @param sString
 * @param temp
 * @param length
 * @return
 */
bool StrCompare(SString &sString, char *temp, int length);

#endif //DATASTRUCTURE_SSTRING_H
