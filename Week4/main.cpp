#include <iostream>
#include <ostream>
#include "ArrayList.h"
//
// Created by asher on 9/15/2026.
//
class Box {
    public:
    Box(int value) : data(new int(value)){}

    ~Box() {
        delete data;
        data = nullptr;
    }
    int value() {
        return *data;
    }

    private:
    int *data;
};

int main() {
    std::cout << "Box" << std::endl;
    Box *box = new Box(5);
    std::cout << box->value() << std::endl;
    delete box;

    srand(time(nullptr));
    std::cout << "Array List" << std::endl;
    ArrayList<int> *arr;
    arr = new ArrayList<int>();
    for (int i = 0; i < 10; i++) {
        int decider = rand() % 2;
        if (decider) {
            arr->addFront(i);
        }
        else {
            arr->addBack(i);
        }
    }
    arr->printArray();
    for (int i = 0; i < 5; i++) {
        arr->deleteFront();
    }
    arr->printArray();
    arr->deleteBack();
    arr->printArray();
    std::cout << (arr->search(5) ? "True" : "False") << std::endl;
    delete arr;

    std::cout << "Linked List" << std::endl;

    return 0;
}