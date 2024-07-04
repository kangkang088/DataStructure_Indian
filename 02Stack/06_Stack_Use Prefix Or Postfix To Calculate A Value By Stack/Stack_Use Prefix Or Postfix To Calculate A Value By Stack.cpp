#include <iostream>
#include <stack>
using namespace std;

int CalcualtePostfix(char*, int);
int CalculatePrefix(char*, int);
int CalculateTempResult_Postfix(int, int, char);
int CalculateTempResult_Prefix(int, int, char);

int main(void)
{
	char C[51];
	cout << "Enter a Postfix expression: ";
	gets_s(C);
	cout << CalcualtePostfix(C, strlen(C)) << endl;
	cout << "Enter a Prefix expression: ";
	gets_s(C);
	cout << CalculatePrefix(C, strlen(C)) << endl;
}

int CalcualtePostfix(char* C, int length)
{
	stack<char> S;
	int num1, num2, result{};
	for (int i = 0; i < length; i++)
	{
		if (C[i] >= '0' && C[i] <= '9')
		{
			S.push(C[i]);
		}
		else if (C[i] == '*' || C[i] == '+' || C[i] == '-' || C[i] == '/')
		{
			num1 = S.top() - '0';
			S.pop();
			num2 = S.top() - '0';
			S.pop();
			result = CalculateTempResult_Postfix(num1, num2, C[i]);
			S.push(result + '0');
		}
	}
	return result;
}

int CalculatePrefix(char* C, int length)
{
	stack<char> S;
	int num1, num2, result{};
	for (int i = length - 1; i >= 0; i--)
	{
		if (C[i] >= '0' && C[i] <= '9')
		{
			S.push(C[i]);
		}
		else if (C[i] == '*' || C[i] == '+' || C[i] == '-' || C[i] == '/')
		{
			num1 = S.top() - '0';
			S.pop();
			num2 = S.top() - '0';
			S.pop();
			result = CalculateTempResult_Prefix(num1, num2, C[i]);
			S.push(result + '0');
		}
	}
	return result;
}

int CalculateTempResult_Postfix(int num1, int num2, char c)
{
	switch (c)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num2 - num1;
	case '*':
		return num1 * num2;
	case '/':
		return num2 / num1;
	}
}

int CalculateTempResult_Prefix(int num1, int num2, char c)
{
	switch (c)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	}
}