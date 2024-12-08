#include <iostream>
#include <string>
#include <vector>
#include "UserInterface.h"

// ����� ��� ����������� ����������
void UserInterface::instructions() {
    cout << "����� ���������� � ���� '������'!" << endl;
    cout << "������� ����:" << endl;
    cout << "1. �������� �����, ������������ �� ��������� ����� ����������� ������." << endl;
    cout << "2. ���� �������� ������������� �� �, �, �, ����������� ������������� �����." << endl;
    cout << "3. ��� ���������� ������ �� ����� ���� �������." << endl;
    cout << "--------------------------------------------------" << endl;
}

// ����� ��� ����������� ���� ������ ������ ����
void UserInterface::menu() {
    cout << "�������� ����� ����:" << endl;
    cout << "1. ������� ������ ��������" << endl;
    cout << "2. ������� ������ ����������" << endl;
    cout << "������� ����� ������: ";
}

// ����� ��� ����� ����� ������
string UserInterface::writePlayerName(int playerNumber) {
    string name;
    cout << "������� ��� ������ " << playerNumber << ": ";
    getline(cin, name);
    return name;
}

// ����� ��� ����� �������� ������
string UserInterface::writeCurrentCity() {
    string city;
    cout << "������� �������� ������: ";
    getline(cin, city);
    return city;
}

// ����� ��� ����������� ������ ��������� �������
void UserInterface::citiesVector(vector<string>& cities) {
    cout << "��������� ������:" << endl;
    for (string& city : cities) {
        cout << "- " << city << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// ����� ��� ����������� ����������� ����
void UserInterface::result(string& winner) {
    cout << "���� ��������! ����������: " << winner << endl;
}