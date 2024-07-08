#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int);
void Dequeue(void);
bool IsEmpty(void);
int Front(void);
void Print(void);

int main(void)
{
	Enqueue(5);
	Enqueue(6);
	Enqueue(7);
	Enqueue(8);
	cout << Front() << endl;
	Print();
	Dequeue();
	cout << Front() << endl;
}

void Enqueue(int x)
{	
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue(void)
{
	Node* temp = front;
	if (front == NULL)
		return;
	if (front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete temp;
}

bool IsEmpty(void)
{
	return front == rear == NULL;
}

int Front(void)
{
	if (front == NULL)
		return INT32_MAX;
	return front->data;
}

void Print(void)
{
	Node* temp = front;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}