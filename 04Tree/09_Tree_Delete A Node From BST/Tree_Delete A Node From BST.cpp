#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* Delete(Node*, int);
Node* FindMin(Node*);

int main(void)
{

}

Node* Delete(Node* root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->data)
	{
		root->left = Delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else
	{
		//No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//One child
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		//Two children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

Node* FindMin(Node* root)
{
	if (root == NULL)
	{
		cout << "Error: tree is empty!" << endl;
		return NULL;
	}
	else if(root->left == NULL)
	{
		return root;
	}
	return FindMin(root->left);
}