#include<iostream>
#include<utility>
#include<iomanip>
using namespace std;

class treenode {
public:
	pair<int, string> key_value;
	treenode* left;
	treenode* right;
	treenode* parent;
	treenode() {
		left = NULL;
		right = NULL;
		parent = NULL;
		key_value.first = NULL;
		key_value.second = "";
	}
	treenode(int key, string value) {
		left = NULL;
		right = NULL;
		parent = NULL;
		key_value.first = key;
		key_value.second = value;
	}
};

class BST {
private:
	treenode* root;

	treenode* leftmost(treenode* tmp) {
		while (tmp->left) {
			tmp = tmp->left;
		}
		return tmp;
	}
	treenode* successor(treenode* tmp) {
		if (tmp->right) {
			return leftmost(tmp->right);
		}
		treenode* new_node = tmp->parent;
		while (new_node && tmp == new_node->right) {
			tmp = new_node;
			new_node = new_node->parent;
		}
		return new_node;
	}

public:
	BST() :root(0) {};

	treenode* Search(int key) {
		treenode* tmp = root;
		while (tmp && key != tmp->key_value.first) {
			if (key < tmp->key_value.first) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
		return tmp;
	}
	void Insert(int key, string value) {
		treenode* record = 0;
		treenode* finder = 0;
		treenode* tmp = new treenode(key, value);
		
		finder = root;
		while (finder) {
			record = finder;
			if (tmp->key_value.first < finder->key_value.first) {
				finder = finder->left;
			}
			else
			{
				finder = finder->right;
			}
		}
		tmp->parent = record;
		if (!record) {
			this->root = tmp;
		}
		else if (tmp->key_value.first < record->key_value.first) {
			record->left = tmp;
		}
		else
		{
			record->right = tmp;
		}
	}
	void Traversal() {		//inorder
		cout << "Inorder traversal:\n";
		treenode* tmp1 = new treenode;
		treenode* tmp2 = new treenode;
		tmp1 = leftmost(root);
		tmp2 = leftmost(root);
		cout << "key:   ";
		while (tmp1) {
			cout << setw(3) << tmp1->key_value.first;
			tmp1 = successor(tmp1);
		}
		cout << "\nvalue: ";
		while (tmp2) {
			cout << setw(3) << tmp2->key_value.second;
			tmp2 = successor(tmp2);
		}
		cout << "\n\n\n";
	}
	void Delete(int key) {
		treenode* delete_node = Search(key);
		if (delete_node == NULL) {
			cout << "Key " << key << " not found.\n";
			return;
		}
		treenode* d = 0;
		treenode* d_child = 0;
		if (delete_node->left == NULL || delete_node->right == NULL) {
			d = delete_node;
		}
		else
		{
			d = successor(delete_node);
		}
		if (d->left) {
			d_child = d->left;
		}
		else {
			d_child = d->right;
		}
		if (d_child) {
			d_child->parent = d->parent;
		}
		if (d->parent == NULL) {
			this->root = d_child;
		}
		else if (d == d->parent->left) {
			d->parent->left = d_child;
		}
		else {
			d->parent->right = d_child;
		}
		if (d != delete_node) {
			delete_node->key_value.first = d->key_value.first;
			delete_node->key_value.second = d->key_value.second;
		}

		delete d;
		d = 0;
		cout << "Key " << key << " has been deleted.\n";
	}
};

int main() {
	BST t;
	t.Insert(20, "a");
	t.Insert(10, "b");
	t.Insert(40, "c");
	t.Insert(6, "d");
	t.Insert(18, "e");
	t.Insert(30, "f");
	t.Insert(50, "g");
	t.Insert(8, "h");
	t.Insert(35, "i");

	t.Traversal();

	t.Delete(30);
	t.Traversal();

	t.Delete(25);
	t.Delete(20);
	t.Traversal();

}
