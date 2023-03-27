//
// Created by Иван Назаров on 27.03.2023.
//
#pragma once

#include "structs.h"
#include <map>
#include <functional>
#include <typeinfo>
#include <typeindex>

template<class Base, class Result, bool Commutative>
class Multimethod {
    using Func = std::function<Result (Base*, Base*)>;
    using Key = std::pair<std::type_index, std::type_index>;
public:
    void addImpl(const std::type_info& t1, const std::type_info& t2, const Func& f) {
        map[getKey(t1, t2)] = f;
    }

    bool hasImpl(Base* a, Base* b) const {
        if (!Commutative) {
            return hasImplOrd(a, b);
        }
        return hasImplOrd(a, b) || hasImplOrd(b ,a);
    }

    Result call(Base* a, Base* b) const {
        if (!hasImplOrd(a, b)) {
            std::swap(a, b);
        }
        auto f = map.at(getKey(a, b));
        return f(a, b);
    }
private:
    std::map<Key, Func> map;
    bool hasImplOrd(Base* a, Base* b) const {
        return map.count(getKey(a, b)) != 0;
    }

    inline Key getKey(Base* a, Base* b) const {
        return std::make_pair(std::type_index(typeid(*a)), std::type_index(typeid(*b)));
    }

    inline Key getKey(const std::type_info& t1, const std::type_info& t2) const {
        return std::make_pair(std::type_index(t1), std::type_index(t2));
    }
};

