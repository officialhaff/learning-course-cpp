//
// Created by user on 21.06.2026.
//

#include <iostream>
using namespace std;


int main() {

    int x = 1;
    int y = 2;

    // std::cout << &x << " " <<  &y << " " << (&y - &x) << std::endl;

    const int& xREF = x + y;

    std::cout << xREF << std::endl;

}