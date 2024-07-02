#include <iostream>
#include <stack>
using namespace std;

void Reverse(char* C, int);

int main(void)
{
	char C[51];
	cout << "Enter a string: ";
	gets_s(C);
	Reverse(C, strlen(C));
	cout << "Output = " << C;
}

void Reverse(char* C, int n)
{
	stack<char> S;
	for (int i = 0; i < n; i++)
	{
		S.push(C[i]);
	}
	for (int i = 0; i < n; i++)
	{
		C[i] = S.top();
		S.pop();
	}
}