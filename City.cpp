#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream> 
#include <iterator>
#include <iomanip>
#include "City.h"

using namespace std;

// конструктор. на вход подается название файла, где
// храняться все возможные города. конструктор 
// добавит все города из файла в possible_citys
CityList::CityList(string filename) {
	string city;
	ifstream in;
	in.open(filename);
	if (in) {
		while (!in.eof()) {
				in >> city;
				possible_citys.push_back(city);
		}
	}
}

// функция добавит город в current_citys
// (игрок назвал город)
void CityList::add_new_city(string new_city) {
	current_citys.push_back(new_city);
}

// функция для проверки, встречался ли 
// названный город
bool CityList::unic_check(string some_city)
{
	if (find(current_citys.begin(), current_citys.end(), some_city) != current_citys.end()) { // если условие выполнилось, значит город нашелся
		return false;
	}
	return true;
}

// функция проверки, реальный ли введенный город
// (есть ли в possible_citys)
bool CityList::is_real_check(string some_city)
{
	if (find(possible_citys.begin(), possible_citys.end(), some_city) == possible_citys.end()) { // если условие выполнилось, значит город нашелся
		return false;
	}
	return true;
}

// функция выдает последний названный город
string CityList::last_city()
{
	return current_citys.back();
}

// функция вернут все города, которые в игре
vector<string> CityList::get_current_citys()
{
	return current_citys; 
}

vector<string> CityList::get_possible_citys()
{
	return possible_citys;
}


