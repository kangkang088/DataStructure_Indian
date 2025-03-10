#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

bool IsBinarySearchTree(Node*);
bool IsSubtreeLesser(Node*, int);
bool IsSubtreeGreater(Node*, int);

bool IsBSTUtil(Node*, int, int);
bool IsBinarySearchTree_Constraint(Node*);

int main(void)
{
}

bool IsBinarySearchTree(Node* root)
{
	if (root == NULL)
		return true;
	if (IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree(root->left)
		&& IsBinarySearchTree(root->right))
	{
		return true;
	}
	return false;
}

bool IsSubtreeLesser(Node* root, int value)
{
	if (root == NULL)
		return true;
	if (root->data <= value
		&& IsSubtreeLesser(root->left, value)
		&& IsSubtreeLesser(root->right, value))
	{
		return true;
	}
	return false;
}

bool IsSubtreeGreater(Node* root, int value)
{
	if (root == NULL)
		return true;
	if (root->data > value
		&& IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value))
	{
		return true;
	}
	return false;
}

bool IsBSTUtil(Node* root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;
	if (root->data > minValue
		&& root->data < maxValue
		&& IsBSTUtil(root->left, minValue, root->data)
		&& IsBSTUtil(root->right, root->data, maxValue))
	{
		return true;
	}
	return false;
}

bool IsBinarySearchTree_Constraint(Node* root)
{
	return IsBSTUtil(root, INT_MIN, INT_MAX);
}