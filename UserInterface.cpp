#include <iostream>
#include <string>
#include <vector>
#include "UserInterface.h"

// Метод для отображения инструкций
void UserInterface::instructions() {
    cout << "Добро пожаловать в игру 'Города'!" << endl;
    cout << "Правила игры:" << endl;
    cout << "1. Назовите город, начинающийся на последнюю букву предыдущего города." << endl;
    cout << "2. Если название заканчивается на ь, ъ, ы, используйте предпоследнюю букву." << endl;
    cout << "3. Два одинаковых города не могут быть названы." << endl;
    cout << "--------------------------------------------------" << endl;
}

// Метод для отображения меню выбора режима игры
void UserInterface::menu() {
    cout << "Выберите режим игры:" << endl;
    cout << "1. Человек против человека" << endl;
    cout << "2. Человек против компьютера" << endl;
    cout << "Введите номер режима: ";
}

// Метод для ввода имени игрока
string UserInterface::writePlayerName(int playerNumber) {
    string name;
    cout << "Введите имя игрока " << playerNumber << ": ";
    getline(cin, name);
    return name;
}

// Метод для ввода текущего города
string UserInterface::writeCurrentCity() {
    string city;
    cout << "Введите название города: ";
    getline(cin, city);
    return city;
}

// Метод для отображения списка названных городов
void UserInterface::citiesVector(vector<string>& cities) {
    cout << "Названные города:" << endl;
    for (string& city : cities) {
        cout << "- " << city << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Метод для отображения результатов игры
void UserInterface::result(string& winner) {
    cout << "Игра окончена! Победитель: " << winner << endl;
}