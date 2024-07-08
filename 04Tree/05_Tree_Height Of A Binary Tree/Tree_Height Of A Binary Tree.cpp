#include <iostream>
#include <utility>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int FindHeight(Node*);

int main(void)
{

}

int FindHeight(Node* root)
{
	if (root == NULL)
		return -1;//By edges,not by number of nodes.
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}