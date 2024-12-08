#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UserInterface {
public:
    void instructions();
    void menu();
    string writePlayerName(int playerNumber);
    string writeCurrentCity();
    void citiesVector(vector<string> cities);
    void result(string& winner);
};
