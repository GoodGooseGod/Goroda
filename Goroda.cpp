#pragma once
#include <iostream>
#include <windows.h>
#include "City.h"
#include "City.cpp"
#include "UserInterface.h"
#include "UserInterface.cpp"
#include "Player.h"
#include "Player.cpp"
#include "ComputerPlayer.h"
#include "ComputerPlayer.cpp"

#define border  cout << "--------------------------------------------------" << endl
#define setConsoleColor(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);

using namespace std;

const string file = "CityList.txt";
const int red = 12, white = 7;
const int tryConst = 5;

class Game {
    CityList CList;     // список городов
    UserInterface UI;   // пользовательский интерфейс
    Player *P1, *P2;   // игроки
    unsigned int turns = 0; // количество ходов
    bool gameNotEnded = true;
    char compPlayer;
public:
    Game(); // инициализация игры

    void startGame(char compPlayer);   // старт игры
    void stopGame();    // остановка игры
    void endGame(string winner) { UI.result(winner); gameNotEnded = false; };     // конец игры
    char turn(char letter);

    void error(string text);
};


Game::Game() : UI(), CList(file), P1(new Player()) { // конструктор
    UI.instructions();

    while (!P2) {
        UI.menu();
        cin >> compPlayer;
        switch (compPlayer) {
        case '1': P2 = new Player(); break;
        case '2': P2 = new ComputerPlayer("conputer", CList.get_possible_citys()); break;
        default: error("Неверный номер режима!"); break;
        }
    }
    border;
    P1->setName(UI.writePlayerName(1)); cin;
    if (compPlayer == '1') P2->setName(UI.writePlayerName(2));

    border;
    compPlayer = NULL;
    while (!compPlayer) {
        cout << "Выберите игрока, который будет ходить первым(1 или 2): ";
        cin >> compPlayer;
        if (compPlayer != '1' && compPlayer != '2') {
            error("Неверный номер игрока!");
            compPlayer = NULL;
        }
    }
    startGame(compPlayer);
};

void Game::error(string text) { // вывод текста красным шрифтом в случае ошибки
    border;
    setConsoleColor(red);
    cout << text << endl;
    setConsoleColor(white);
    border;
}

void Game::startGame(char compPlayer) { // начало игры
    border;
    cout << "Начало игры!" << " Ход игрока ";

    char last = NULL;   // первый ход без буквы
    int tries = tryConst;
    if (compPlayer == '1') {
        cout << P1->getName() << '!' << endl;
        while (!last && gameNotEnded && tries > 0) {     // ввод города и проверка корректности значения
            string city;
            cout << "Осталось попыток: " << tries << '.' << endl;
            tries--;
            city = UI.writeCurrentCity();
            if (city == "стоп") {
                stopGame();
                continue;
            }
            if (CList.unic_check(city) && CList.is_real_check(city)) {
                CList.add_new_city(city);
                last = city[city.length() - 1];
                if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
            }
            else error("Данный город был назван или отсутствует в списке возможных городов!");
        }
        if (tries == 0) endGame(P2->getName());
    }
    else {
        if (ComputerPlayer* cp = dynamic_cast<ComputerPlayer*>(P2)) {
            cout << P2->getName() << '!' << endl;
            string city;
            city = P2->chooseCity("ЙЦУКЕНГШЩЗХФВАПРОЛДЖЭЯЧСМИТБЮЁ"[rand() % 30]);
            cout << "Игрок " << P2->getName() << " назвал город: " << city << endl;
            CList.add_new_city(city);

            last = city[city.length() - 1];
            if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
        }
        else {
            cout << P2->getName() << '!' << endl;
            while (!last && gameNotEnded && tries > 0) {     // ввод города и проверка корректности значения
                string city;
                cout << "Осталось попыток: " << tries << '.' << endl;
                tries--;
                city = UI.writeCurrentCity();
                if (city == "стоп") {
                    stopGame();
                    continue;
                }
                if (CList.unic_check(city) && CList.is_real_check(city)) {
                    CList.add_new_city(city);
                    last = city[city.length() - 1];
                    if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
                }
                else error("Данный город был назван или отсутствует в списке возможных городов!");
            }
            if (tries == 0) endGame(P1->getName());
        }
    }
    turns++;
    

    while (gameNotEnded) { // основная игра
        last = turn(last);
        turns++;
    }
}

char Game::turn(char letter) { // ход игрока
    string city;
    char last;
    int tries = tryConst;
    letter -= 32; // перевод буквы в верхний регистр
    if (letter == 'ё') letter = 'Ё';

    border;
    cout << "Ход #" << turns << ". Ход игрока ";
    if ((turns + compPlayer) % 2 != 1) {
        cout << P2->getName() << '!' << endl;
        cout << "Последний названный город: " << CList.last_city() << "." << endl << "Требуется назвать город на букву ";
        setConsoleColor(red);
        cout << letter << endl;
        setConsoleColor(white);

        if (ComputerPlayer* cp = dynamic_cast<ComputerPlayer*>(P2)) {
            city = P2->chooseCity(letter);
            cout << "Игрок " << P2->getName() << " назвал город: " << city << endl;
            CList.add_new_city(city);

            last = city[city.length() - 1];
            if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
            return last;
        }
        else {
            char last = NULL;
            while (!last && gameNotEnded && tries > 0) { // ввод города и проверка корректности значения
                cout << "Осталось попыток: " << tries << '.' << endl;
                tries--;
                city = UI.writeCurrentCity();
                if (city == "стоп") {
                    stopGame();
                    continue;
                }
                if (CList.unic_check(city) && CList.is_real_check(city) && city[0] == letter) {
                    CList.add_new_city(city);

                    last = city[city.length() - 1];
                    if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
                    return last;
                }
                else error("Данный город был назван или отсутствует в списке возможных городов!");
            }
            if (tries == 0) endGame(P1->getName());
        }
    }
    else {
        cout << P1->getName() << '!' << endl;
        cout << "Последний названный город: " << CList.last_city() << "." << endl << "Требуется назвать город на букву ";
        setConsoleColor(red);
        cout << letter << endl;
        setConsoleColor(white);

        char last = NULL;
        while (!last && gameNotEnded && tries > 0) { // ввод города и проверка корректности значения
            cout << "Осталось попыток: " << tries << '.' << endl;
            tries--;
            city = UI.writeCurrentCity();
            if (city == "стоп") {
                stopGame();
                continue;
            }
            if (CList.unic_check(city) && CList.is_real_check(city) && city[0] == letter) {
                CList.add_new_city(city);

                last = city[city.length() - 1];
                if (last == 'ь' || last == 'ъ' || last == 'ы') last = city[city.length() - 2];
                return last;
            }
            else error("Данный город был назван или отсутствует в списке возможных городов!");
        }
        if (tries == 0) endGame(P2->getName());
    }
}

void Game::stopGame() {
    error("Игра на паузе. Для продолжения напишите 'продолжить.\n\
Для того, чтобы вывести список использованных городов напишите 'список'.\n\
Для того, чтобы завершить игру напишите 'завершить' ");
    string str;
    while (true) {
        cin >> str;
        if (str == "список") {
            border;
            UI.citiesVector(CList.get_current_citys());
        }
        if (str == "продолжить") {
            border;
            return;
        }
        if (str == "завершить") {
            gameNotEnded = false;
            return;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        
    Game game;
}