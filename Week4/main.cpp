#include <iostream>
#include <ostream>
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
    Box box = Box(10);
    std::cout << box.value() << std::endl;
    delete &box;
    return 0;
}