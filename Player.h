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
    Player(); // ����������� �� ���������
    Player(const string& playerName); // ����������� � ����������
    void setName(const string& playerName); // ����� ��� ������� ����� ������
    string getName(); // ����� ��� ��������� ����� ������
    void addWin(); // ����� ��� ���������� ���������� �����
    void addDraw(); // ����� ��� ���������� �����
    void displayStats(); // ����� ��� ����������� ����������
    ~Player(); // ����������
};

