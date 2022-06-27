//
// Created by 30671 on 2022/6/27.
//

#include "Def.h"

void Swap(ElemType &e1, ElemType &e2) {
    ElemType temp;
    temp = e1;
    e1 = e2;
    e2 = temp;
}