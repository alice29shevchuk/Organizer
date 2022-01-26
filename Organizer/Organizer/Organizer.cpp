#include <iostream>
#include"Task.h"
#include"Collection_Task.h"
#include<string>
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
    do
    {
        cout << "МЕНЮ:\n";
        cout << "1 - Добавление\n";
        cout << "2 - Вывод на экран\n";
        cout << "3 - Удаление\n";
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
            task = new Task(title, adress, day, month, year);
            cl.add(task);
            cout << "\t\t\t\t\t\tСобытие добавлено!\n";
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            cl.show();
            system("pause");
            system("cls");
            break;
        }
    } while (ch != 0);
    cout << "Вы вышли!";
}
