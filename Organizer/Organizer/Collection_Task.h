#pragma once
#include"Task.h"
#include<string>
namespace B
{
	struct Node
	{
		A::Task* value;
		Node* next;
		int size;
		Node() {}
		Node(A::Task* f, Node* next)
		{
			this->value = f;
			this->next = NULL;
		}
	};
	class Collection_Task
	{
	private:
		Node* head;
		int size;
	public:
		Collection_Task()
		{
			this->head = NULL;
			this->size = 0;
		}
		void add(A::Task* value)
		{
			if (this->head == NULL)
			{
				this->head = new Node(value, NULL);
			}
			else
			{
				Node* tmp = this->head;
				while (tmp->next != NULL)
				{
					tmp = tmp->next;
				}
				tmp->next = new Node(value, NULL);
			}
			size++;
		}
		void show()
		{
			if (size > 0)
			{
				Node* tmp = this->head;
				while (tmp != NULL)
				{
					tmp->value->print();
					tmp = tmp->next;
				}
			}
			else
			{
				cout << "Список событий пуст!\n";
			}
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
		bool isInList(string str)
		{
			bool flag = 0;
			Node* iter = this->head;
			while (iter != NULL)
			{
				if (iter->value->getTitle() == str)
				{
					flag = 1;
					break;
				}
				iter = iter->next;
			}
			return flag;
		}
		void remove()
		{
			if (this->size != 0)
			{
				string title;
				Node* tmp2 = this->head;
				cout << "Введите название события, которое хотите удалить: ";
				getline(cin, title);
				if (isDigit(title) == true)
				{
					throw exception("В названии цифра!");
				}
				else if (isInList(title) == false)
				{
					cout << "Такого события не существует!\n";
				}
				else
				{
					if (this->head->value->getTitle() == title)
					{
						Node* tmp = this->head;
						this->head = this->head->next;
						delete tmp;
						size--;
					}
					else
					{
						Node* iter = this->head;
						Node* fordel = this->head;
						while (iter->next != NULL)
						{
							if (iter->next->value->getTitle() == title)
							{
								fordel = iter->next;
								iter->next = iter->next->next;
								delete fordel;
								break;
							}
							iter = iter->next;
						}
						size--;
					}
					cout << "Событие удалено!\n";
				}
			}
			else
			{
				cout << "Список пуст! Добавьте событие!\n";
			}
		}
		void setDay(int day, int index)
		{
			if (this->size != 0)
			{
				Node* iter = this->head;
				if (index<1 || index>size)
				{
					throw exception("Некорректный индекс!\n");
				}
				else
				{
					for (int i = 1; i < index; i++)
					{
						iter = iter->next;
					}
					iter->value->setDay(day);
				}
			}
			else
			{
				cout << "Список пуст! Поменять ничего невозможно! Добавьте событие!\n";
			}
		}
		void setMonth(int month, int index)
		{
			if (this->size != 0)
			{
				Node* iter = this->head;
				if (index<1 || index>size)
				{
					throw exception("Некорректный индекс!\n");
				}
				else
				{
					for (int i = 1; i < index; i++)
					{
						iter = iter->next;
					}
					iter->value->setMonth(month);
				}
			}
			else
			{
				cout << "Список пуст! Поменять ничего невозможно! Добавьте событие!\n";
			}
		}
		void setYear(int year, int index)
		{
			if (this->size != 0)
			{
				Node* iter = this->head;
				if (index<1 || index>size)
				{
					throw exception("Некорректный индекс!\n");
				}
				else
				{
					for (int i = 1; i < index; i++)
					{
						iter = iter->next;
					}
					iter->value->setYear(year);
				}
			}
			else
			{
				cout << "Список пуст! Поменять ничего невозможно! Добавьте событие!\n";
			}
		}
		void setAdress(string adress, int index)
		{
			if (this->size != 0)
			{
				Node* iter = this->head;
				if (index<1 || index>size)
				{
					throw exception("Некорректный индекс!\n");
				}
				else
				{
					for (int i = 1; i < index; i++)
					{
						iter = iter->next;
					}
					iter->value->setAdress(adress);
				}
			}
			else
			{
			cout << "Список пуст! Поменять ничего невозможно! Добавьте событие!\n";
 }
		}
		void setTitle(string title, int index)
		{
			if (this->size != 0)
			{
				Node* iter = this->head;
				if (index<1 || index>size)
				{
					throw exception("Некорректный индекс!\n");
				}
				else
				{
					for (int i = 1; i < index; i++)
					{
						iter = iter->next;
					}
					iter->value->setTitle(title);
				}
			}
			else
			{
				cout << "Список пуст! Поменять ничего невозможно! Добавьте событие!\n";
			}
		}
	};
}
