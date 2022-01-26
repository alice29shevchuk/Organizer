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
		Node* tmp = this->head;
		while (tmp != NULL)
		{
			tmp->value->print();
			tmp = tmp->next;
		}
	}
	void remove()
	{
		string title;
		Node* tmp2 = this->head;
		cout << "¬ведите название событи€, которое хотите удалить: ";
		getline(cin, title);
		if (this->head->value->getTitle()==title)
		{
			Node* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
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
		}
	}
};

