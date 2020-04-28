#include "TicketOffice.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russia");
	ifstream fin("input.txt");
	Cinema mycinema;
	fin >> mycinema;
	TicketOffice ticketoffice(mycinema);
	Date t_date;
	Time t_time;
	int day, month, hour, minute;
	cin >> day >> month >> hour >> minute;
met:
	try
	{
		ticketoffice.SetCurrentDateTime(Date(day, month), Time(hour, minute));
		t_date = Date(29, 4);
		t_time = Time(14, 0);
		if (ticketoffice.IsFree(t_date, t_time, 1, 20, 1))
		{
			cout << "����� ��������" << endl;
			ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1);
			cout << "����� ���������������" << endl;
		}
		else
			cout << "����� ������" << endl;
		double sum = ticketoffice.CalculateCost(1, t_date, t_time, 1);
		cout << "��������� ������� �� ��������� �����: " << sum;
		if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
			cout << "����� ���������������" << endl;
		else
		{
			cout << "��� ������ ���-�� ��������� ����";
			if (ticketoffice.CancelOrder(1, t_date, t_time, 1))
			{
				cout << "����� �������" << endl;
				if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
					cout << "����� ���������������" << endl;
				else
					cout << "����� �� ������� ���������������" << endl;
			}
			else
				cout << "����� �� ������� ��������" << endl;
			vector<Ticket> mytickets = ticketoffice.CreateTickets(1, t_date, t_time, 1);
			cout << "���� ������:" << endl;
			for (int i = 0; i < mytickets.size(); i++)
			{
				mytickets[i].PrintTicket();
			}
		}
	}
	catch (exception exp)
	{
		cout << exp.what();
		goto met;
	}
	return 0;
}