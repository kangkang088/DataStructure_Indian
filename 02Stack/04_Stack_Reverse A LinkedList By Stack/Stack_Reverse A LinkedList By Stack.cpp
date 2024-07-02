#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void Reverse(void);
void Insert(int);
void Print(void);

int main(void)
{
	Insert(5); Print();
	Insert(6); Print();
	Insert(7); Print();
	Insert(8); Print();
	Reverse();
	Print();
}

void Reverse(void)
{
	if (head == NULL)
		return;
	stack<Node*> S;
	Node* temp = head;
	while (temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty())
	{
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
	return;
}

void Insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		return;
	}
	Node* temp1 = head;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
	return;
}

void Print(void)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return;
}