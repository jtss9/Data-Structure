#include<iostream>
using namespace std;
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};
struct Node* insert_node(char data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void swaptree(struct Node* node) {
	if (node == NULL) {
		return;
	}
	else {
		swaptree(node->left);
		swaptree(node->right);
		struct Node* tmp;
		tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}
void traversal(struct Node* node) {			//inorder traversal
	if (node == NULL)	return;
	traversal(node->left);
	cout << node->data << " ";
	traversal(node->right);
}
int main() {
	struct Node* root = insert_node('A');
	root->left = insert_node('B');
	root->left->left = insert_node('D');
	root->left->left->right = insert_node('G');
	root->left->right = insert_node('E');
	root->right = insert_node('C');
	root->right->left = insert_node('F');
	root->right->left->right = insert_node('H');

	cout << "Traverse the tree: ";
	traversal(root);
	cout << "\n\n";
	swaptree(root);
	cout << "Traverse the swaptree: ";
	traversal(root);
	cout << "\n\n";
}