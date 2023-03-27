//
// Created by Иван Назаров on 27.03.2023.
//
#pragma once

#include <iostream>

struct Shape {
    virtual void which() const = 0;
};

struct Rectangle : Shape {
    void which() const {
        std::cout << "Rectangle" << std::endl;
    }
};

struct Triangle : Shape {
    void which() const {
        std::cout << "Triangle" << std::endl;
    }
};

