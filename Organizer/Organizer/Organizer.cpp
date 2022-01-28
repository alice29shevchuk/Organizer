#include <iostream>
#include"Task.h"
#include"Collection_Task.h"
#include<string>
using namespace A;
using namespace B;
int main()
{
    setlocale(0, "");
    Task* task;
    Collection_Task cl;
    int ch;
    string title;
    string adress;
    int day;
    int month;
    int year;
    int index;
    do
    {
        cout << "МЕНЮ:\n";
        cout << "1 - Добавление\n";
        cout << "2 - Вывод на экран\n";
        cout << "3 - Удаление по названию события\n";
        cout << "4 - Редактирование названия события\n";
        cout << "5 - Редактирование адреса\n";
        cout << "6 - Редактирование дня\n";
        cout << "7 - Редактирование месяца\n";
        cout << "8 - Редактирование года\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
            system("cls");
            cout << "Введите название: ";
            getline(cin, title);
            cout << "Введите адрес: ";
            getline(cin, adress);
            cout << "Введите день: ";
            cin >> day;
            cout << "Введите месяц: ";
            cin >> month;
            cout << "Введите год: ";
            cin >> year;
            try
            {
                task = new Task(title, adress, day, month, year);
                cl.add(task);
                cout << "\t\t\t\t\t\tСобытие добавлено!\n";
            }
            catch (const std::exception&ex)
            {
                cout << ex.what() << "\n";
                cout << "\t\t\t\t\t\tСобытие не добавлено!\n";
            }
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            cl.show();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            try
            {
                cl.remove();
            }
            catch (exception&ex)
            {
                cout << ex.what() << "\n";
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Введите индекс события, в котором хотите поменять название: ";
            cin >> index;
            cin.ignore();
            cout << "Введите на какое название хотите поменять: ";
            getline(cin,title);
            try
            {
                cl.setTitle(title, index);
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << "\n";
            }
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "Введите индекс события, в котором хотите поменять адрес: ";
            cin >> index;
            cin.ignore();
            cout << "Введите на какой адрес хотите поменять: ";
            getline(cin, adress);
            cl.setAdress(adress, index);
            cout << "Адрес изменен!\n";
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "Введите индекс события, в котором хотите поменять день: ";
            cin >> index;
            cout << "Введите на какое число хотите поменять: ";
            cin >> day;
            try
            {
                cl.setDay(day, index);
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << "\n";
            }
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            cout << "Введите индекс события, в котором хотите поменять месяц: ";
            cin >> index;
            cout << "Введите на какое число хотите поменять: ";
            cin >> month;
            try
            {
                cl.setMonth(month,index);
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << "\n";
            }
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            cout << "Введите индекс события, в котором хотите поменять год: ";
            cin >> index;
            cout << "Введите на какое число хотите поменять: ";
            cin >> year;
            try
            {
                cl.setYear(year, index);
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << "\n";
            }
            system("pause");
            system("cls");
            break;
        }
    } while (ch != 0);
    cout << "Вы вышли!";
}
