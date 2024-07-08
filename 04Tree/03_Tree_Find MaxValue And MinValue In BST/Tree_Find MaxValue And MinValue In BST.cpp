#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

int FindMinByIterator(BstNode*);
int FindMaxByRecursion(BstNode*);

int main(void)
{
	
}

int FindMinByIterator(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Errotr: Tree is empty\n";
		return -1;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int FindMaxByRecursion(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Errotr: Tree is empty\n";
		return -1;
	}
	else if (root->right == NULL)
	{
		return root->data;
	}
	return FindMaxByRecursion(root->right);
}