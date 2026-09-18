//
// Created by asher on 9/17/2026.
//

# pragma once
#include <iostream>
#include <ostream>

template <typename T>
class Node {
    public:
    T *value;
    Node<T> *next;

    Node(T *value) {
        this->value = value;
        next = nullptr;
    }
    void print() {
        value->print();
    }
};
