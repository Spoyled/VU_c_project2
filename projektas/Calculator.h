#pragma once

#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Calculator {
    string username;
public:
    double calculate();
    Calculator(string username);
    void clean(int time);
};