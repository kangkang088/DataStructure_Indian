#include <iostream>
#include <stack>
#include <string>
using namespace std;

string TranslateInfixToPostfixWithoutParenthese(char*, int);
string TranslateInfixToPostfixWithParenthese(char*, int);
bool InStackIsHigher(char, stack<char>*);
bool IsOpeningParenthese(char);
bool IsClosingParenthese(char);
bool IsOperand(char);

int main(void)
{
	char C[51];
	cout << "Enter a Infix expression without parentheses: ";
	gets_s(C);
	cout << TranslateInfixToPostfixWithoutParenthese(C, strlen(C)) << endl;
	cout << "Enter a Infix expression with parentheses: ";
	gets_s(C);
	cout << TranslateInfixToPostfixWithParenthese(C, strlen(C)) << endl;
	return 1;

}

string TranslateInfixToPostfixWithoutParenthese(char* infix, int length)
{
	stack<char> S;
	string temp = "";
	for (int i = 0; i < length; i++)
	{
		if (infix[i] != '*' && infix[i] != '+' && infix[i] != '-' && infix[i] != '/')
		{
			temp += infix[i];
		}
		else
		{
			while (!S.empty() && InStackIsHigher(infix[i],&S))
			{
				temp += S.top();
				S.pop();
			}
			S.push(infix[i]);
		}
	}
	while (!S.empty())
	{
		temp += S.top();
		S.pop();
	}
	return temp;
}

string TranslateInfixToPostfixWithParenthese(char* infix, int length)
{
	stack<char> S;
	string temp = "";
	for (int i = 0; i < length; i++)
	{
		if (IsOperand(infix[i]))
		{
			temp += infix[i];
		}
		else if (infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/')
		{
			while (!S.empty() && InStackIsHigher(infix[i],&S) && !IsOpeningParenthese(S.top()))
			{
				temp += S.top();
				S.pop();
			}
			S.push(infix[i]);
		}
		else if (IsOpeningParenthese(infix[i]))
		{
			S.push(infix[i]);
		}
		else if (IsClosingParenthese(infix[i]))
		{
			while (!S.empty() && S.top() != '(')
			{
				temp += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while (!S.empty())
	{
		temp += S.top();
		S.pop();
	}
	return temp;
}

bool InStackIsHigher(char c, stack<char>* s)
{
	char temp = s->top();
	switch (temp)
	{
	case '*':
		if (c == '+' || c == '-' || c == '/')
			return true;
		return false;
	case '/':
		if (c == '+' || c == '-' || c == '*')
			return true;
		return false;
	case '+':
		if (c == '-' || c == '+')
			return true;
		return false;
	case '-':
		if (c == '+' || c == '-')
			return true;
		return false;
	case '(' :
			return false;
	}
}

bool IsOpeningParenthese(char c)
{
	return c == '{' || c == '(' || c == '[';
}

bool IsClosingParenthese(char c)
{
	return c == '}' || c == ')' || c == ']';
}

bool IsOperand(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}