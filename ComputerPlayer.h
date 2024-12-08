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
    // �����������
    ComputerPlayer(const string& playerName, const vector<string>& cities);

    // ����� ��� ������ ������ ��������� �������
    string chooseCity(char lastLetter);

    //  ����� ��� ������� ����� ����������
    void setName(const string& playerName);

    // ����������
    ~ComputerPlayer();
};
