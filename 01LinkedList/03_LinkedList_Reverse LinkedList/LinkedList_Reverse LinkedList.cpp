#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

Node* head;
void Insert(int);
void PrintByIteration();
void PrintByRecursion1(Node*);//directional print
void PrintByRecursion2(Node*);//reverse print
void ReverseByIteration();
void ReverseByRecursion(Node*);

int main()
{
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//2 4 6 5
	PrintByRecursion2(head);
	cout << endl;
	ReverseByRecursion(head);
	PrintByRecursion2(head);
}

void Insert(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	Node* temp1 = head;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
}

void PrintByIteration() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReverseByIteration()
{
	Node* current, * prev, * next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

//directional print
void PrintByRecursion1(Node* head)
{
	if (head == NULL)
	{
		printf_s("\n");
		return;
	}
	printf_s("%d ", head->data);
	PrintByRecursion1(head->next);
}

//reverse print
void PrintByRecursion2(Node* head)
{
	if (head == NULL)
	{
		return;
	}
	PrintByRecursion2(head->next);
	printf_s("%d ", head->data);
}

//reverse LinkedList
void ReverseByRecursion(Node* p)
{
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	ReverseByRecursion(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}