#include "Player.h"

// Конструктор по умолчанию
Player::Player() : name("Unknown"), wins(0), draws(0) {}

// Конструктор с параметром
Player::Player(const string& playerName) : name(playerName), wins(0), draws(0) {}

// Метод для задания имени игрока
void Player::setName(const string& playerName) {
        name = playerName;
}

// Метод для получения имени игрока
string Player::getName(){
    return name;
}

// Метод для увеличения количества побед
void Player::addWin() {
    wins++;
}

// Метод для добавления ничьи
void Player::addDraw() {
    draws++;
}

// Метод для отображения статистики
void Player::displayStats() {
    cout << "Игрок " << name << ": Победы = " << wins << ", Ничьи = " << draws << endl;
}

// Деструктор
Player::~Player() {}