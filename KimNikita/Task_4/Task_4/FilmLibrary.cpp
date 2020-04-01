#include "FilmLibrary.h"
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;


void FilmLibrary::PrintMenuEditor()
{
	cout << "�������� �������� ��� ���������:" << endl;
	cout << "1 - ��������" << endl;
	cout << "2 - ��� ���������" << endl;
	cout << "3 - ��� ����������" << endl;
	cout << "4 - ��� �����������" << endl;
	cout << "5 - ���� ������ � ������" << endl;
	cout << "6 - ����� � ������" << endl;
	cout << "0 - ���������� ���������" << endl;
	cout << "� ����� ������ ������ ����� �������� ����" << endl;
}
bool comp1(const Film& a, const Film& b)
{
	if (a.date.year < b.date.year)
		return true;
	else
		if (a.date.year == b.date.year)
			return a.name < b.name;
		else
			return false;
}
bool comp2(const Film& a, const Film& b)
{
	return a.income > b.income;
}
FilmLibrary::FilmLibrary(const FilmLibrary& fl)
{
	for (int i = 0; i < fl.lib.size(); i++)
	{
		lib.push_back(fl.lib[i]);
	}
}
void FilmLibrary::SaveFilm()
{
	setlocale(LC_ALL, "Russian");
	string f;
	cout << "������� �������� ����� ��� ����������" << endl;
	getline(cin, f);
	ofstream fout;
	fout.open(f + ".txt", ios::out);
	string n;
	int y;
	cout << "������� �������� ������, ������� ������ ���������" << endl;
	getline(cin, n);
	cout << "������� ��� ������ � ������" << endl;
	cin >> y;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			fout << lib[i].name << endl;
			fout << lib[i].producer << endl;
			fout << lib[i].scenarist << endl;
			fout << lib[i].composer << endl;
			fout << lib[i].date.day << ' ' << lib[i].date.month << ' ' << lib[i].date.year << endl;
			fout << lib[i].income << endl;
			cout << "������" << endl;
			fout.close();
			return;
		}
	}
	fout.close();
	cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
}
void FilmLibrary::AddFilm()
{
	Film t;
	t.GetFilm();
	lib.push_back(t);
	sort(lib.begin(), lib.end(), comp1);
	cout << "������" << endl;
}
void FilmLibrary::FixFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	int y;
	cout << "������� �������� ������, ������ �������� ������ ��������" << endl;
	getline(cin, n);
	cout << "������� ��� ������ � ������" << endl;
	cin >> y;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			bool e = false;
			int choice = -1;
			while (true)
			{
				switch (choice)
				{
				case 0:
					e = true;
					break;
				case 1:
					cout << "������� ����� �������� ������:" << endl;
					cin.ignore();
					getline(cin, lib[i].name);
					cout << "������" << endl;
					break;
				case 2:
					cout << "������� ����� ��� ���������:" << endl;
					cin.ignore();
					getline(cin, lib[i].producer);
					cout << "������" << endl;
					break;
				case 3:
					cout << "������� ����� ��� ����������:" << endl;
					cin.ignore();
					getline(cin, lib[i].scenarist);
					cout << "������" << endl;
					break;
				case 4:
					cout << "������� ����� ��� �����������:" << endl;
					cin.ignore();
					getline(cin, lib[i].composer);
					cout << "������" << endl;
					break;
				case 5:
					cout << "������� ����� ���� ������ � ������:" << endl;
					lib[i].date.GetDate();
					cout << "������" << endl;
					break;
				case 6:
					cout << "������� ����� � ������:" << endl;
					cin >> lib[i].income;
					cout << "������" << endl;
					break;
				default:
					PrintMenuEditor();
				}
				if (e)
					break;
				cin >> choice;
			}
			cout << "������" << endl;
			return;
		}
	}
	cout << "������� ������ ��� � ����������" << endl;
}
void FilmLibrary::FindFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	int y;
	cout << "������� �������� ������" << endl;
	getline(cin, n);
	cout << "������� ��� ������ � ������" << endl;
	cin >> y;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].PrintFilm();
			cout << "������" << endl;
			return;
		}
	}
	cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
}
void FilmLibrary::PrintFilmsBy()
{
	setlocale(LC_ALL, "Russian");
	string p;
	cout << "������� ��� ���������" << endl;
	getline(cin, p);
	int f = 1;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].producer == p)
		{
			f = 0;
			cout << lib[i].name << ' ';
			lib[i].date.PrintDate();
		}
	}
	if (f)
	{
		cout << "������� ������� ��������� ��� � ����������" << endl;
	}
	else
		cout << "������" << endl;
}
void FilmLibrary::PrintFilmsIn()
{
	int y;
	cout << "������� ��� ������ � ������" << endl;
	cin >> y;
	int f = 1;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
		{
			f = 0;
			cout << lib[i].name << endl;
		}
	}
	if (f)
	{
		cout << "�������, �������� � ������ � ������ ����, ��� � ����������" << endl;
	}
	else
		cout << "������" << endl;
}
void FilmLibrary::PrintColFilmsMaxIncome()
{
	int n;
	cout << "������� ���������� �������, ������� ����� �������" << endl;
	cin >> n;
	vector<Film>t;
	for (int i = 0; i < lib.size(); i++)
	{
		t.push_back(lib[i]);
	}
	sort(t.begin(), t.end(), comp2);
	int s = t.size();
	s = min(n, s);
	for (int i = 0; i < s; i++)
	{
		cout << t[i].name << endl;
	}
	cout << "������" << endl;
}
void FilmLibrary::PrintColFilmsMaxIncomeIn()
{
	int n, y;
	cout << "������� ���������� �������, ������� ����� �������" << endl;
	cin >> n;
	cout << "������� ��� ������ � ������" << endl;
	cin >> y;
	vector<Film>t;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
			t.push_back(lib[i]);
	}
	sort(t.begin(), t.end(), comp2);
	int s = t.size();
	s = min(n, s);
	for (int i = 0; i < s; i++)
	{
		cout << t[i].name << endl;
	}
	cout << "������" << endl;
}
void FilmLibrary::PrintColFilms()
{
	cout << "����� �������: " << lib.size() << endl;
	cout << "������" << endl;
}
void FilmLibrary::DelFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	cout << "������� �������� ������, ������� ����� �������" << endl;
	getline(cin, n);
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n)
		{
			lib.erase(lib.begin() + i);
			cout << "������" << endl;
			return;
		}
	}
	cout << "������� ������ ��� � ����������" << endl;
}
ifstream& operator>>(ifstream& in, FilmLibrary& fl)
{
	int n;
	string s;
	in >> n;
	in.ignore();
	fl.lib.resize(n);
	for (int i = 0; i < n; i++)
	{
		getline(in, fl.lib[i].name);
		getline(in, fl.lib[i].producer);
		getline(in, fl.lib[i].scenarist);
		getline(in, fl.lib[i].composer);
		in >> fl.lib[i].date.day >> fl.lib[i].date.month >> fl.lib[i].date.year;
		in >> fl.lib[i].income;
		in.ignore();
		in.ignore();
	}
	sort(fl.lib.begin(), fl.lib.end(), comp1);
	return in;
}
ofstream& operator<<(ofstream& out, const FilmLibrary& fl)
{
	out << fl.lib.size() << endl;
	for (int i = 0; i < fl.lib.size(); i++)
	{
		out << fl.lib[i].name << endl;
		out << fl.lib[i].producer << endl;
		out << fl.lib[i].scenarist << endl;
		out << fl.lib[i].composer << endl;
		out << fl.lib[i].date.day << ' ' << fl.lib[i].date.month << ' ' << fl.lib[i].date.year << endl;
		out << fl.lib[i].income << endl;
		out << endl;
	}
	return out;
}