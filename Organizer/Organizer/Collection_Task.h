#pragma once
#include"Task.h"
struct Node
{
	Task* value;
	Node* next;
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
};

