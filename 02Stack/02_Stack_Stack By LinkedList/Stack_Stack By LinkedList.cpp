#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* top = NULL;//instead of head

void Pop(void);
void Push(int);
int Top(void);
bool IsEmpty(void);
void Print(void);

int main(void)
{
	
	Push(2); Print();
	Push(5); 
	Push(7); 
	Push(8); 
	Push(4); 
}

void Push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop(void)
{
	Node* temp;
	if (top == NULL)
		return;
	temp = top;
	top = top->link;
	delete temp;
}

int Top(void)
{
	if (top == NULL)
	{
		cout << "Error: stack is empty";
		return INT32_MAX;
	}
	return top->data;
}

bool IsEmpty(void)
{
	return top == NULL;
}

void Print(void)
{
	Node* temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}