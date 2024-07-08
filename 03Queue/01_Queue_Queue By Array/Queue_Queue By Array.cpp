#include <iostream>
using namespace std;

void Enqueue(int);
void Dequeue(void);
int Front(void);
bool IsEmpty(void);
bool IsFull(void);

int A[10] = {0};
int front, rear;

int main(void)
{
	front = rear = -1;
	Enqueue(5);
	Enqueue(4);
	Enqueue(3);
	Enqueue(2);
	Enqueue(1);
	Dequeue();
	Enqueue(5);
	Enqueue(4);
	Enqueue(3);
	Enqueue(2);
	Enqueue(1);
	Enqueue(1);
	cout << A[3] << endl;
	cout << IsFull() << endl;
	cout << Front() << endl;
}

void Enqueue(int x)
{
	if (IsFull())
		return;
	else if (IsEmpty())
	{
		front = rear = 0;
	}
	else
	{
		rear = (rear + 1) % (sizeof(A) / sizeof(int));
	}
	A[rear] = x;
}

void Dequeue(void)
{
	if (IsEmpty())
		return;
	else if (front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front = (front + 1) % (sizeof(A) / sizeof(int));
	}
}

int Front(void)
{
	if (!IsEmpty())
		return A[front];
}

bool IsEmpty(void)
{
	if (front == -1 && rear == -1)
		return true;
	return false;
}

bool IsFull(void)
{
	if ((rear + 1) % (sizeof(A) / sizeof(int)) == front)
		return true;
	return false;
}