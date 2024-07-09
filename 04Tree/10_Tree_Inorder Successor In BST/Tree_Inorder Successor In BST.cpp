#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* GetSuccessor(Node*, int);
Node* Find(Node*,int);
Node* FindMin(Node*);

int main(void)
{

}

Node* GetSuccessor(Node* root, int data)
{
	Node* current = Find(root, data);
	if (current == NULL)
		return NULL;
	if (current->right != NULL)
	{
		return FindMin(current->right);
	}
	else
	{
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current)
		{
			if (ancestor->data > current->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

Node* Find(Node* root,int data)
{
	if (root == NULL)
		return NULL;
	else if (root->data == data)
		return root;
	else if (root->data < data)
	{
		root = Find(root->right, data);
	}
	else
	{
		root = Find(root->left, data);
	}
	return root;
}

Node* FindMin(Node* root)
{
	if (root == NULL)
		return NULL;
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}