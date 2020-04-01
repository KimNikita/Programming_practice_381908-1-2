#include "FilmLibrary.h"
#include <locale>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void PrintMenu()
{
	cout << "����" << endl;
	cout << "-------------------" << endl;
	cout << "0 - ��������� ����� � �����" << endl;
	cout << "1 - �������� �����" << endl;
	cout << "2 - �������� ������ ������ �� ��������" << endl;
	cout << "3 - ����� ����� �� �������� � ����" << endl;
	cout << "4 - ������ ��� ������ ��������� ���������" << endl;
	cout << "5 - ������ ��� ������, �������� � ������ � ��������� ����" << endl;
	cout << "6 - ������ �������� ����� ������� � ����������� �������" << endl;
	cout << "7 - ������ ������ ����� ������� � ����������� ������� � ��������� ����" << endl;
	cout << "8 - ������ ������� ����� �������" << endl;
	cout << "9 - ������� ����� �� ��������" << endl;
	cout << "10 - ����� �� ���������" << endl;
	cout << "� ����� ������ ������ ����� �������� ����" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("output.txt", ios::out);
	ifstream fin("input.txt");
	FilmLibrary fb1;
	fin >> fb1;
	FilmLibrary fb2(fb1);
	cout << "����� ���������� � �������� ���������� �������" << endl;
	cout << "���� ������ ������������ � � ����������, � ��� ���� ���� input.txt" << endl;
	int v = -1;
	bool e = false;
	while (true)
	{
		switch (v)
		{
		case 0:
			fb1.SaveFilm();
			break;
		case 1:
			fb1.AddFilm();
			break;
		case 2:
			fb1.FixFilm();
			break;
		case 3:
			fb1.FindFilm();
			break;
		case 4:
			fb1.PrintFilmsBy();
			break;
		case 5:
			fb1.PrintFilmsIn();
			break;
		case 6:
			fb1.PrintColFilmsMaxIncome();
			break;
		case 7:
			fb1.PrintColFilmsMaxIncomeIn();
			break;
		case 8:
			fb1.PrintColFilms();
			break;
		case 9:
			fb1.DelFilm();
			break;
		case 10:
			e = true;
			break;
		default:
			PrintMenu();
		}
		if (e)
			break;
		cin >> v;
		cin.ignore();
	}
	cout << "��������� ����� ������������ � ����� output";
	fout << "����" << endl;
	fout << fb2;
	fout << "�����" << endl;
	fout << fb1;
	return 0;
}
