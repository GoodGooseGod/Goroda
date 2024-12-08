#include "ComputerPlayer.h"


// Конструктор
ComputerPlayer::ComputerPlayer(const string& playerName, const vector<string>& cities) : Player(playerName), availableCities(cities) {
    srand(time(0)); // Инициализация генератора случайных чисел
}

    // Метод для выбора города случайным образом
string ComputerPlayer::chooseCity(char lastLetter) {
    vector<string> validCities;

    // Найти города, которые подходят по последней букве
    for (auto& city : availableCities) {
        char firstChar = city[0];
        if (firstChar == lastLetter || (lastLetter == 'ь' || lastLetter == 'ъ' || lastLetter == 'ы' && firstChar == city[city.length() - 2])) {
            validCities.push_back(city);
        }
    }

    if (validCities.empty()) {
        return ""; // Если нет доступных городов
    }

    // Выбор случайного города
    int randomIndex = rand() % validCities.size();
    string chosenCity = validCities[randomIndex];

    // Удаление выбранного города из доступных
    availableCities.erase(remove(availableCities.begin(), availableCities.end(), chosenCity), availableCities.end());

    return chosenCity;
}
void ComputerPlayer::setName(const string& playerName) {
    Player::setName("Компьютер");
}
// Деструктор
ComputerPlayer::~ComputerPlayer() {}