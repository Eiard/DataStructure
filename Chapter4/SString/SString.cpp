/**
    -*- coding:utf-8 -*-
    @projectName:   DataStructure 
    @FileName:      SString
    @author:        30671
    @description:   TODO 
    @date:          2022/8/14
    @version:       1.0
*/


#include "SString.h"


int Index_KMP(SString S, SString T) {
    // 时间复杂度0(m) m为模式串T的长度
    // 求next数组
    int next[T.length + 1];
    get_next(T, next);

    int i = 1;
    int j = 1;

    // 时间复杂度0(n) n 为 S主串的长度
    while (i <= S.length && j <= T.length) {
        /**
         * if条件中的j == 0
         *      对于主串中的子串第一个 与 模式串中第一个失配的情况
         *              都执行一次,让j从0->1 并且 i = i+1
         *              然后下一次执行时就是判断j = 1 和 i = i+1 的字符进行比较
         * if条件中  S.ch[i] == T.ch[j]
         *      匹配成功两者都后移
         */
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            // 跳转到自己的next数组指向的地方
            j = next[j];
        }
    }

    /**
     * 与朴素模式匹配算法相同
     *
     * 满足j > T.length则说明T的所有连续匹配成功了
     *      此时返回的 i - T.length 正好是主串中的匹配到的子串的首字符的下标
     *
     */
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

void get_next(SString T, int next[]) {

    // i是遍历指针
    int i = 1;

    // j是前缀指针
    int j = 0;
    next[1] = 0;

    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {

            /**
             * abaac
             *
             * 第一次执行的时候
             *
             * i = 1 j = 0
             *
             * 两者满足条件   后移
             *
             * i = 2 j = 1
             * ☆并且此时给next[2] = 1
             *
             * 此时开始下一步
             * abaac    判断i = 2 的字符b 与 j = 1的字符a相比是否相等
             *
             * 不相等  则j = next[j] 即 j = next[1] = 0
             *
             * 此时进入if条件(满足j = 0)
             * i = 2 j = 0
             *两者均++
             * i = 3 j = 1
             * ☆next[3] = 1
             *
             * abaac 再判断 i =3 的字符a 与 j = 1的字符a相比 相等
             *
             * 两者均++
             * i = 4 j = 2
             * ☆并且next[4] = 2
             *
             * abaac 再判断 i = 4的字符a 与 j = 2的字符b相比 不相等
             * j = 1 = next[2]
             *
             * abaac 再判断 i = 4的字符a 与 j = 1的字符a相比 相等
             * 两者均++
             * i = 5 j = 2
             * ☆next[5] = 2
             *
             * 结束
             *
             * 最终得到next数组为
             *
             * 位序 1 2 3 4 5
             *     0 1 1 2 2
             *
             */

            ++i;
            ++j;

            // 赋值next数组
            // j是最大相等前后缀长度
            next[i] = j;

        } else {
            j = next[j];
        }
    }
}

void get_nextVal(SString T, int nextVal[]) {
    int i = 1;


    int j = 0;
    nextVal[1] = 0;

    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;

            // 与get_next的唯一区别
            if (T.ch[i] != T.ch[j])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];

        } else {
            j = nextVal[j];
        }
    }
}


/**
 * 整体思路
 *      两个下标主串下标i,匹配串下标j
 *
 *      while循环为两者都小于对应的length
 *
 *          两者对应的一个字符相等
 *              两者都后移
 *          匹配失败(回溯)
 *              主串i = i-j+2
 *              匹配串j = 1
 *
 *      如果最后j>T.length  匹配的下标j已经跑到T的末尾了,则说明前面都已经匹配上了
 *          return i-T.length (返回在主串中匹配到的子串的头的下标)
 *      如果不满足
 *          return 0
 * @param S
 * @param T
 * @return
 */
int Index(SString S, SString T) {
    /**
     * i为S的下标
     * j为T的下标
     */
    int i = 1;
    int j = 1;

    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            /**
             * 如果当前匹配对应字符相等
             *      则继续跳转到下一个字符进行匹配
             *
             *      要真正要到子串的条件是
             *              直到while循环结束,必须有[连续]T.length次 都执行了这个操作
             *              即连续T.length个都相等
             */
            ++i;
            ++j;
        } else {
            /**
             * 如果对应字符匹配过程中有一次失败
             *      则回溯到主串刚开始匹配字符的下一个字符
             *      i-j+1 是主串中的子串 开始1对1进行比较的开始下标
             *      i-j+2 是下一个
             */
            i = i - j + 2;
            j = 1;
        }
    }

    /**
     * 如果   j>T.length
     *              满足(下标j已经移动到了T串的最后面,则说明已经有连续个T.length的字符已经完全匹配完成了):
     *                  返回匹配到的字串的第一个字符的下标
     *              不满足(直到while循环结束都没有找到连续T.length个字符都匹配):
     *                  返回0
     */
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

bool InitString(SString &T) {

    //    T.ch = (char *) malloc(MAX_LEN * sizeof(char));

    //    if (T.ch == nullptr) {
    //        return false;
    //    }
    return true;

}

bool SubString(SString &Sub, SString S, int pos, int length) {

    // 越界了
    if (pos + length - 1 > S.length)
        return false;

    // 将字串赋值给一个从下标0开始的空串
    for (int i = pos; i < pos + length; ++i) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }

    Sub.length = length;
    return true;
}

bool StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; ++i) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }

    // 扫描过的所有字符都相等,则长度长的串更大
    return S.length - T.length;
}


int Index1(SString S, SString T) {
    int i = 1, n = StrLength(S), m = StrLength(T);

    // 用于暂存字串
    SString sub;

    while (i < n - m + 1) {
        // 每次直接取一个字串T长度的字符串来比较
        SubString(sub, S, i, m);

        // 如果取出来的子串和T相比不相等则直接往后移一个,继续取出同样长度的子串用来判断
        // 否则,匹配成功,直接返回下标
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }

}

bool StrLength(SString &S) {
    return S.length;
}


bool StrAssign(SString &S, SString T) {
    return false;
}

bool StrCopy(SString S, SString &T) {
    return false;
}

bool StrEmpty(SString &S) {
    return S.length <= 0;
}

bool ClearString(SString &S) {
    S.length = 0;
    return true;
}

bool DestroyString(SString &S) {
    //    free(S.ch);
    //    S.ch = nullptr;
    return false;
}

bool Concat(SString &T, SString &S1, SString &S2) {
    return false;
}

void TestSString() {
    SString S;
    char a[8] = "abcddca";
    char b[4] = "ddc";
    for (int i = 0; i < 7; ++i) {
        // ch[0] 不存放东西
        S.ch[i + 1] = a[i];
    }
    S.length = 7;

    SString T;
    for (int i = 0; i < 4; ++i) {
        // ch[0] 不存放东西
        T.ch[i + 1] = b[i];
    }
    T.length = 3;

    // 朴素模式串匹配算法
    printf("%d\n", Index(S, T));
    printf("%d\n", Index_KMP(S, T));

}
