//
// Created by Иван Назаров on 27.03.2023.
//
#pragma once

#include "structs.h"

// function for checking the intersection of two rectangles
bool is_intersect_r_r(Shape * a, Shape * b);

// function for checking the intersection of a rectangle and a triangle
bool is_intersect_r_t(Shape * a, Shape * b);

// function for checking the intersection of two triangles
bool is_intersect_t_t(Shape * a, Shape * b);
