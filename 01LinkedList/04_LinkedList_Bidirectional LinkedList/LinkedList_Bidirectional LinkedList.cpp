#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

Node* head;

void InsertAtHead(int);
void InsertAtTail(int);
void Print(void);
void ReversePrint(void);

Node* GetNewNode(int);

int main(void)
{
	head = NULL;
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtTail(6); Print(); ReversePrint();
	return 0;
}

Node* GetNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void InsertAtHead(int x)
{
	Node* newNode = GetNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	return;
}

void InsertAtTail(int x)
{
	Node* newNode = GetNewNode(x);
	Node* temp = head;
	if (temp == NULL)
	{
		head = newNode;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	return;
}

void Print(void)
{
	Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return;
}

void ReversePrint(void)
{
	Node* temp = head;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	cout << "Backwards: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
	return;
}