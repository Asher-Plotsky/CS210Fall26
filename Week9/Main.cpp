#include <iostream>
#include <ostream>
//
// Created by asher on 10/20/2026.
//
void countdown(int n) {
    if ( n <= 0)
        return;
    std::cout << n << " ";
    countdown(n - 2);
}
int main()
{
    countdown(5);
}