#pragma once
#include <iostream>
#include <string>
using namespace std;


class Player {
private:
    string name;
    int wins;
    int draws;

public:
    Player(); // Конструктор по умолчанию
    Player(const string& playerName); // Конструктор с параметром
    void setName(const string& playerName); // Метод для задания имени игрока
    string getName(); // Метод для получения имени игрока
    void addWin(); // Метод для увеличения количества побед
    void addDraw(); // Метод для добавления ничьи
    void displayStats(); // Метод для отображения статистики
    ~Player(); // Деструктор
};

