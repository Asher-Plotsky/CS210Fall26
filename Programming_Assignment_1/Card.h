//
// Created by asher on 9/29/2026.
//

#pragma once
#include <string>

class Card {
    public:
    Card(int n, int c) {
        number = n + 1;
        switch (c){
        case 0:
            color = "red";
            break;
        case 1:
            color = "green";
            break;
        case 2:
            color = "blue";
            break;
        case 3:
            color = "yellow";
            break;
        }
    }
    void print()
    {
        std::cout << color << " " << number << std::endl;
    }
    private:
    int number;
    std::string color;
};
