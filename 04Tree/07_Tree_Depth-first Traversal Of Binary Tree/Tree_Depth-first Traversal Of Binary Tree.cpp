#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void Preorder(Node*);
void Inorder(Node*);
void Postorder(Node*);

int main(void)
{

}

void Preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(Node* root)
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}