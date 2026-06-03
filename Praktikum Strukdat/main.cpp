#include <iostream>
#include <string>
#include "syntaxchecker.hpp"

int main() {
    std::string s;
    std::cin >> s;

    if (isValid(s)){
        std::cout << "True";
    } else{
        std::cout << "False";
    }

    return 0;
}
