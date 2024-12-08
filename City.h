#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream> 
#include <iterator>
#include <iomanip>

using namespace std;

class CityList{
	vector <string> current_citys;  // города, которые находятся в игре(игроки их называли)
	vector <string> possible_citys; // все возможные города 
public:
	CityList(string filename);

	void add_new_city(string new_city);
	bool unic_check(string some_city);
	bool is_real_check(string some_city);
	string last_city();
	vector <string> get_current_citys();
	vector <string> get_possible_citys();

	~CityList() { };
};