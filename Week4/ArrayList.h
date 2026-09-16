//
// Created by asher on 9/15/2026.
//

#pragma once

#include <iostream>

template <typename T>
class ArrayList {
    public:
    ArrayList():size(0) {}
    ~ArrayList() {}
    void addBack(T item) {
        if (!(size >= CAPACITY)) {
            data[size++] = item;
        }
        else {
            std::cout << "Array is full" << std::endl;
        }
    }
    void addFront(T item) {
        if (!(size >= CAPACITY)) {
            for (int i = size; 0 < i; i--) {
                data[i] = data[i - 1];
            }
            data[0] = item;
            size++;
        }
        else {
            std::cout << "Array is full" << std::endl;
        }
    }
    void deleteFront() {
        if (!(size <= 0)) {
            for (int i = 0; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }
        else {
            std::cout << "Array is empty" << std::endl;
        }
    }
    void deleteBack() {
        if (!(size <= 0)) {
            data[size-- - 1] = 0;
        }
        else {
            std::cout << "Array is empty" << std::endl;
        }
    }
    bool search(T item) {
        if (size != 0) {
            for (int i = 0; i < size; i++) {
                if (data[i] == item) {
                    return true;
                }
            }
        }
        return false;
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }

    private:
    static const int CAPACITY = 20;
    T data[CAPACITY];
    int size;

};
