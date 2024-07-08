#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

void LevelOrder(Node*);
Node* Insert(Node*, char);
Node* GetNewNode(char);

int main(void)
{
	Node* root = NULL;
	root = Insert(root, 'a');
	root = Insert(root, 'b');
	root = Insert(root, 'c');
	root = Insert(root, 'd');
	LevelOrder(root);
}

void LevelOrder(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		Node* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
		Q.pop();
	}
}

Node* Insert(Node* root, char data)
{
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

Node* GetNewNode(char data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
