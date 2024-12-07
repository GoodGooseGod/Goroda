#include "Player.h"

// ����������� �� ���������
Player::Player() : name("Unknown"), wins(0), draws(0) {}

// ����������� � ����������
Player::Player(const string& playerName) : name(playerName), wins(0), draws(0) {}

// ����� ��� ������� ����� ������
void Player::setName(const string& playerName) {
        name = playerName;
}

// ����� ��� ��������� ����� ������
string Player::getName(){
    return name;
}

// ����� ��� ���������� ���������� �����
void Player::addWin() {
    wins++;
}

// ����� ��� ���������� �����
void Player::addDraw() {
    draws++;
}

// ����� ��� ����������� ����������
void Player::displayStats() {
    cout << "����� " << name << ": ������ = " << wins << ", ����� = " << draws << endl;
}

// ����������
Player::~Player() {}