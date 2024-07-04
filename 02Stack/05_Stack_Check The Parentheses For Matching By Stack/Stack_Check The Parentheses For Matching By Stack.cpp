#include <iostream>
#include <stack>
using namespace std;

bool CheckParentheses(char*,int);
bool CheckSingleChar(char,stack<char>*);

int main(void)
{
	char C[51];
	cout << "Enter the string: ";
	gets_s(C);
	cout << CheckParentheses(C,strlen(C)) << endl;
}

bool CheckParentheses(char* C,int length)
{
	stack<char> S;
	for (char i = 0; i < length; i++)
	{
		if (C[i] == '{' || C[i] == '[' || C[i] == '(')
		{
			S.push(C[i]);
		}
		else if(C[i] == '}' || C[i] == ']' || C[i] == ')')
		{
			if (S.empty() || !CheckSingleChar(C[i],&S))
				return false;
			else
			{
				S.pop();
			}
		}
	}
	return S.empty();
}

bool CheckSingleChar(char c,stack<char>* stack)
{
	switch (c)
	{
	case '}':
		return stack->top() == '{';
	case ']':
		return stack->top() == '[';
	case ')':
		return stack->top() == '(';
	}
}