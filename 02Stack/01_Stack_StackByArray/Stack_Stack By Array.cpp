#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int);
void Pop(void);
int Top(void);
void Print(void);

int main(void)
{
	Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();
	return 0; 
}

void Print(void)
{
	int i;
	cout << "Stack: ";
	for (i = 0; i <= top; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void Push(int x)
{
	if (top == MAX_SIZE - 1)
	{
		cout << "Error: stack overflow" << endl;
		return;
	}
	A[++top] = x;
}

void Pop(void)
{
	if (top == -1)
	{
		cout << "Error: No element to pop" << endl;
		return;
	}
	top--;
}

int Top(void)
{
	return A[top];
}