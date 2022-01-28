#pragma once
#include<iostream>
using namespace std;
namespace A
{
	class Task
	{
	private:
		string title;
		string adress;
		int day;
		int month;
		int year;
	public:
		Task()
		{
			this->title = "";
			this->adress = "";
			this->day = 1;
			this->month = 1;
			this->year = 2000;
		}
		Task(string title, string adress, int day, int month, int year)
		{
			if (isDigit(title) == true)
			{
				throw exception("� �������� �����!");
			}
			if (day > 31 || day < 1)
			{
				throw exception("������������ ����!");
			}
			if (month > 12 || month < 1)
			{
				throw exception("������������ �����!");
			}
			if (year > 2022 || year < 1900)
			{
				throw exception("������������ ���!");
			}
			this->title = title;
			this->adress = adress;
			this->day = day;
			this->month = month;
			this->year = year;
		}
		bool isDigit(string str)
		{
			bool flag = 0;
			const char* s = str.c_str();
			for (int i = 0; i < str.length(); i++)
			{
				if (isdigit(s[i]))
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
				if (flag == 1)
				{
					return true;
				}
			}
		}
		void setTitle(string title)
		{
			try
			{
				if (isDigit(title) == true)
				{
					throw exception("� �������� �����!");
				}
				this->title = title;
				cout << "�������� ��������!\n";
			}
			catch (const exception& ex)
			{
				cout << ex.what() << "\n";
			}
		}
		string getTitle()
		{
			return this->title;
		}

		void setAdress(string adress)
		{
			this->adress = adress;
		}
		string getAdress()
		{
			return this->adress;
		}

		void setDay(int day)
		{
			try
			{
				if (day > 31 || day < 1)
				{
					throw exception("������������ ����!");
				}
				this->day = day;
				cout << "���� �������!\n";
			}
			catch (const exception& ex)
			{
				cout << ex.what() << "\n";
			}
		}
		int getDay()
		{
			return this->day;
		}

		void setMonth(int month)
		{
			try
			{
				if (month > 12 || month < 1)
				{
					throw exception("������������ �����!");
				}
				this->month = month;
				cout << "����� �������!\n";
			}
			catch (const exception& ex)
			{
				cout << ex.what() << "\n";
			}
		}
		int getMonth()
		{
			return this->month;
		}

		void setYear(int year)
		{
			try
			{
				if (year > 2022 || year < 1900)
				{
					throw exception("������������ ���!");
				}
				this->year = year;
				cout << "��� �������!\n";
			}
			catch (const exception& ex)
			{
				cout << ex.what() << "\n";
			}
		}
		int getYear()
		{
			return this->year;
		}
		void print()
		{
			cout << "��������: " << this->title << "\n�����: " << this->adress << "\n����: " << this->day << "\n�����: " << this->month << "\n���: " << this->year << "\n\n";
		}
	};
}
