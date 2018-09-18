// Linked List CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node * head;
public:
	LinkedList(){}
	
	~LinkedList()
	{
		cleanUp();		
	}
	void view();
	void push(int value);
	void pop();
	void cleanUp();
	void deleteAt(int value);
};
void LinkedList::cleanUp()
{
	Node* current = head;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}

	head = NULL;

}
void LinkedList::pop()
{
	Node *current = head;
	if (head == NULL)
	{
		cout << "List is already empty" << endl;
		return;
	}
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	head = head->next;
	free(current);
}
void LinkedList::push(int value)
{
	//Node * current = head;
	Node *new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		//new_node = head;
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
	

}

void LinkedList::view()
{
	if (head == NULL)
	{
		cout << "No item in List" << endl;
		return;
	}
	if (head->next == NULL)
	{
		cout << head->data << "-->NULL" << endl;
		return;
	}
	Node *current = head;
	while (current != NULL)
	{
		cout << current->data << "-->";
		current = current->next;
	}
	cout << "NULL";
}

void LinkedList::deleteAt(int value)
{
	Node *current = head;
	Node *pre = NULL;
	if (current != NULL && current->data == value)
	{
		head = current->next;
		free(current);
		return;
	}
	while (current != NULL && current->data != value)
	{
		pre = current;
		current = current->next;
	}
	if (current == NULL)
	{
		cout << "Item does not exists" << endl;
		return;
	}
	pre->next = current->next;

	free(current);

}


int main()
{
	LinkedList list;
	int choice, value, addedValue;
	Node *head = NULL;

	do {
		printf("\nEnter your choice...\n 1. Insert \n 2. Clean Up\n 3. View \n 4. Delete Node\n 5. Delete Node by Value\n 0. Exit\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter value to be inserted\n");
			scanf_s("\n%d", &value);

			list.push(value);
			//printf("\n%d added to List", addedValue);
			list.view();
			break;
		case 2:

			list.cleanUp();
			break;
		case 3:
			list.view();
			break;
		case 4:
			list.pop();
			break;
		case 5:
			printf("Enter the node you want to delete\n");
			scanf_s("%d", &value);
			list.deleteAt(value);
			break;
		default:
			//printList(head);
			//goto x;
			return 0;
		}
	} while (1);

    return 0;
}

