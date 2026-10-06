//
// Created by asher on 10/6/2026.
//

#pragma once

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;

    explicit Node(T* value) : data(value), next(nullptr) {}
};
