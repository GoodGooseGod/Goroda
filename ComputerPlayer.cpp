#include "ComputerPlayer.h"


// �����������
ComputerPlayer::ComputerPlayer(const string& playerName, const vector<string>& cities) : Player(playerName), availableCities(cities) {
    srand(time(0)); // ������������� ���������� ��������� �����
}

    // ����� ��� ������ ������ ��������� �������
string ComputerPlayer::chooseCity(char lastLetter) {
    vector<string> validCities;

    // ����� ������, ������� �������� �� ��������� �����
    for (auto& city : availableCities) {
        char firstChar = city[0];
        if (firstChar == lastLetter || (lastLetter == '�' || lastLetter == '�' || lastLetter == '�' && firstChar == city[city.length() - 2])) {
            validCities.push_back(city);
        }
    }

    if (validCities.empty()) {
        return ""; // ���� ��� ��������� �������
    }

    // ����� ���������� ������
    int randomIndex = rand() % validCities.size();
    string chosenCity = validCities[randomIndex];

    // �������� ���������� ������ �� ���������
    availableCities.erase(remove(availableCities.begin(), availableCities.end(), chosenCity), availableCities.end());

    return chosenCity;
}
void ComputerPlayer::setName(const string& playerName) {
    Player::setName("���������");
}
// ����������
ComputerPlayer::~ComputerPlayer() {}