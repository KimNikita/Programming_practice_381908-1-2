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
	ifstream fin("input.txt");
	FilmLibrary fb1;
	fin >> fb1;
	FilmLibrary fb2(fb1);
	Film t;
	string n;
	string f;
	string p;
	int y;
	int c;
	cout << "����� ���������� � �������� ���������� �������" << endl;
	cout << "���� ������ ������������ � � ����������, � ��� ���� ���� input.txt" << endl;
	int v = -1;
	bool e = false;
	while (true)
	{
		switch (v)
		{
		case 0:
			cin.ignore();
			cout << "������� �������� ����� ��� ����������" << endl;
			getline(cin, f);
			fout.open(f + ".txt", ios::out);
			cout << "������� �������� ������, ������� ������ ���������" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������" << endl;
			cin >> y;
			if (fb1.SaveFilm(fout, n, y))
				cout << "������" << endl;
			else
				cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
			fout.close();
			break;
		case 1:
			cin.ignore();
			t.GetFilm();
			fb1.AddFilm(t);
			cout << "������";
			break;
		case 2:
			cin.ignore();
			cout << "������� �������� ������, ������ �������� ������ ��������" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������" << endl;
			cin >> y;
			if (fb1.FixFilm(n, y))
				cout << "������" << endl;
			else
				cout << "������� ������ ��� � ����������" << endl;
			break;
		case 3:
			cin.ignore();
			cout << "������� �������� ������" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������" << endl;
			cin >> y;
			if (fb1.FindFilm(n, y))
				cout << "������" << endl;
			else
				cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
			break;
		case 4:
			cin.ignore();
			cout << "������� ��� ���������" << endl;
			getline(cin, p);
			if (fb1.PrintFilmsBy(p))
				cout << "������" << endl;
			else
				cout << "������� ������� ��������� ��� � ����������" << endl;
			break;
		case 5:
			cout << "������� ��� ������ � ������" << endl;
			cin >> y;
			if (fb1.PrintFilmsIn(y))
				cout << "������" << endl;
			else
				cout << "�������, �������� � ������ � ������ ����, ��� � ����������" << endl;
			break;
		case 6:
			cout << "������� ���������� �������, ������� ����� �������" << endl;
			cin >> c;
			fb1.PrintColFilmsMaxIncome(c);
			cout << "������" << endl;
			break;
		case 7:
			cout << "������� ���������� �������, ������� ����� �������" << endl;
			cin >> c;
			cout << "������� ��� ������ � ������" << endl;
			cin >> y;
			if (fb1.PrintColFilmsMaxIncomeIn(c, y))
				cout << "������" << endl;
			else
				cout << "�������, �������� � ������ � ������ ����, ��� � ����������" << endl;
			break;
		case 8:
			cout << "����� �������: " << fb1.ColFilms() << endl;
			cout << "������" << endl;
			break;
		case 9:
			cin.ignore();
			cout << "������� �������� ������, ������� ����� �������" << endl;
			getline(cin, n);
			if (fb1.DelFilm(n))
				cout << "������" << endl;
			else
				cout << "������� ������ ��� � ����������" << endl;
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
	}
	ofstream fout2;
	fout2.open("output.txt", ios::out);
	cout << "��������� ����� ������������ � ����� output";
	fout2 << "����" << endl;
	fout2 << fb2;
	fout2 << "�����" << endl;
	fout2 << fb1;
	fout2.close();
	return 0;
}
