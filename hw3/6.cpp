#include<iostream>
using namespace std;

struct Node {
	int data;
	int length;		// distance to parent
	struct Node* left;
	struct Node* right;
};

Node* Insert(int data, int length) {
	Node* node = new Node;
	node->data = data;
	node->length = length;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int find_dist(Node* root, int x) {
	if (root == NULL) {
		return -1;
	}
	int dist = 0;
	if (root->data == x) {
		return dist;
	}
	if ((dist = find_dist(root->left, x)) >= 0) {
		dist += root->left->length;
		return dist;
	}
	if ((dist = find_dist(root->right, x)) >= 0) {
		dist += root->right->length;
		return dist;
	}
	return dist;
}

int main() {
	Node* root = Insert(0, 0);
	root->left = Insert(1, 5);
	root->right = Insert(2, 3);
	root->left->left = Insert(3, 2);
	root->left->right = Insert(4, 6);
	root->right->left = Insert(5, 4);
	root->left->right->left = Insert(6, 1);

	for(int i = 0; i <= 6; i++) {
		cout << find_dist(root, i) << " ";
	}
}
