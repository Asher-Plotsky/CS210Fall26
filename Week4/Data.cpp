//
// Created by asher on 9/17/2026.
//
#include <iostream>
#include "Node.h"
class Data {
    public:
    int numID;
    std::string name;

    Data(int numID, std::string name) {
        this->numID = numID;
        this->name = name;
    }
    void print() {
        std::cout << numID << " " << name << std::endl;
    }
};