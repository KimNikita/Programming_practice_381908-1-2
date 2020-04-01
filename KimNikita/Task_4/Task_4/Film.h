#pragma once

#include "Date.h"
#include <string>

using namespace std;

class Film {
public:
	string name;
	string producer;
	string scenarist;
	string composer;
	Date date;
	long long int income;
	Film() :income(0) {}
	void PrintFilm()
	{
		cout << "��������: " << name << endl;
		cout << "��������: " << producer << endl;
		cout << "���������: " << scenarist << endl;
		cout << "����������: " << composer << endl;
		cout << "���� ������ � ������: ";
		date.PrintDate();
		cout << "����� � ������: " << income << endl;
	}
	void GetFilm()
	{
		cout << "������� �������� ������:" << endl;
		getline(cin, name);
		cout << "������� ��� ���������:" << endl;
		getline(cin, producer);
		cout << "������� ��� ����������:" << endl;
		getline(cin, scenarist);
		cout << "������� ��� �����������:" << endl;
		getline(cin, composer);
		date.GetDate();
		cout << "������� ����� � ������:" << endl;
		cin >> income;
	}
	~Film() {}
};
