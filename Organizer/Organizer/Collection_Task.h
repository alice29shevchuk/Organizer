#pragma once
#include"Task.h"
#include<string>
struct Node
{
	Task* value;
	Node* next;
	int size;
	Node(){}
	Node(Task* f, Node* next)
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
	void add(Task* value)
	{
		if (this->head == NULL)
		{
			this->head = new Node(value,NULL);
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
			cout << "������ ������� ����!\n";
		}
	}
	void remove()
	{
		string title;
		Node* tmp2 = this->head;
		cout << "������� �������� �������, ������� ������ �������: ";
		getline(cin, title);
		if (this->head->value->getTitle()==title)
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
	}
	void setDay(int day,int index)
	{
		Node* iter = this->head;
		if (index<1 || index>size)
		{
			throw exception("������������ ������!\n");
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
	void setMonth(int month,int index)
	{
		Node* iter = this->head;
		if (index<1 || index>size)
		{
			throw exception("������������ ������!\n");
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
	void setYear(int year, int index)
	{
		Node* iter = this->head;
		if (index<1 || index>size)
		{
			throw exception("������������ ������!\n");
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
	void setAdress(string adress, int index)
	{
		Node* iter = this->head;
		if (index<1 || index>size)
		{
			throw exception("������������ ������!\n");
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
	void setTitle(string title, int index)
	{
		Node* iter = this->head;
		if (index<1 || index>size)
		{
			throw exception("������������ ������!\n");
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
};

