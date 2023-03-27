//
// Created by Иван Назаров on 27.03.2023.
//
#include <iostream>
#include "structs.h"
#include "multimethod.h"
#include "functions.h"

int main()
{

    Multimethod<Shape, bool, true> is_intersect;

    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    Shape * s1 = new Triangle();
    Shape * s2 = new Rectangle();

    if (is_intersect.hasImpl(s1, s2))
    {
        bool res = is_intersect.call(s1, s2);
    }
    if (is_intersect.hasImpl(s2, s2)) {
        bool res = is_intersect.call(s2, s2);
    }
}