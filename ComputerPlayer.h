#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include "Player.h"


class ComputerPlayer : public Player {
private:
    vector<string> availableCities;

public:
    // Конструктор
    ComputerPlayer(const string& playerName, const vector<string>& cities);

    // Метод для выбора города случайным образом
    string chooseCity(char lastLetter);

    //  Метод для задания имени компьютеру
    void setName(const string& playerName);

    // Деструктор
    ~ComputerPlayer();
};
