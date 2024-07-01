#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

Node* head;
void Insert(int data);
void Print();
void Delete(int n);

int main()
{
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//2 4 6 5
	Print();
	int n;
	printf("Enter a position\n");
	scanf_s("%d", &n);
	Delete(n);
	Print();
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

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n) {
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}
	int i;
	for (i = 0; i < n - 2; i++)
	{
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}