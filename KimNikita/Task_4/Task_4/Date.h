#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
	Date() :day(0), month(0), year(1894) {}//������ ����� ����� � 1895
	void PrintDate()
	{
		string s;
		if (day < 10)
			s += '0';
		s += to_string(day) + '.';
		if (month < 10)
			s += '0';
		s += to_string(month) + '.';
		s += to_string(year);
		cout << s << endl;
	}
	void GetDate()
	{
		do
		{
			cout << "������� ��� ������ � ������:" << endl;
			cin >> year;
		} while (year < 1895);
		bool vis = false;
		if (year / 400 > 0 && year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
			vis = true;
		do
		{
			cout << "������� ����� ������ � ������:" << endl;
			cin >> month;
		} while (month > 12 || month < 1);
		do
		{
			cout << "������� ���� ������ � ������:" << endl;
			cin >> day;
		} while (day < 1 || day>31 || day > 29 && month == 2 || day == 29 && month == 2 && !vis);
	}
	~Date() {}
};