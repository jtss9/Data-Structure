#include<iostream>
using namespace std;

struct Node {
	int key;		//months
	int height;
	Node* left;
	Node* right;
};
int Height(Node* tmp) {
	if (tmp == NULL) {
		return -1;
	}
	return tmp->height;
}
int get_BF(Node* tmp) {
	//balance factor
	if (tmp == NULL) {
		return 0;
	}
	return Height(tmp->left) - Height(tmp->right);
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
//		A					B
//	   / \				   / \
//	  B	  c3	 =>		 c1   A
//   / \					 / \
//  c1  c2					c2  c3
Node* right_rotate(Node* A) {		
	Node* B = A->left;
	Node* C2 = B->right;
	B->right = A;
	A->left = C2;
	A->height = max(Height(A->left), Height(A->right)) + 1;
	B->height = max(Height(B->left), Height(B->right)) + 1;
	return B;
}
//		A					B
//	   / \				   / \
//    c1  B		  =>	  A   c3
//		 / \			 / \
//		c2  c3			c1  c2
Node* left_rotate(Node* A) {
	Node* B = A->right;
	Node* C2 = B->left;
	B->left = A;
	A->right = C2;
	A->height = max(Height(A->left), Height(A->right)) + 1;
	B->height = max(Height(B->left), Height(B->right)) + 1;
	return B;
}
Node* Insert_node(int key) {
	Node* tmp = new Node;
	tmp->key = key;
	tmp->height = 0;
	tmp->right = NULL;
	tmp->left = NULL;
	return tmp;
}
Node* Insert(Node* node, int key) {
	if (node == NULL)	return(Insert_node(key));
	if (key < node->key) {
		node->left = Insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = Insert(node->right, key);
	}
	else {
		cout << "Can't insert same keys.";
		return node;
	}
	node->height = 1 + max(Height(node->left), Height(node->right));
	int bf = get_BF(node);
	if (bf > 1 && key < node->left->key) {		//LL
		return right_rotate(node);
	}
	if (bf > 1 && key > node->left->key) {		//LR
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	if (bf<-1 && key>node->right->key) {		//RR
		return left_rotate(node);
	}
	if (bf < -1 && key < node->right->key) {	//RL
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
void preorder(Node* root) {
	if (root) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main() {
	Node* root = NULL;
	//months have been converted to number
	root = Insert(root, 12);
	root = Insert(root, 1);
	root = Insert(root, 4);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 8);
	root = Insert(root, 10);
	root = Insert(root, 2);
	root = Insert(root, 11);
	root = Insert(root, 5);
	root = Insert(root, 6);

	cout << "Inorder traversal: ";
	inorder(root);
	cout << "\n\n";
	cout << "Preorder traversal: ";
	preorder(root);
	cout << "\n\n";
}