#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

class treenode {
public:
	char alphabat;
	int weight;
	treenode* left;
	treenode* right;
	treenode(char al, int we) {
		alphabat = al;
		weight = we;
		left = right = NULL;
	}
};
class temp {
public:
	char alp;
	int wei;
	int wepl;
	string code;
};
bool cmp(const treenode* t1, const treenode* t2) {
	return t1->weight < t2->weight;
}
bool cmp_letter(temp t1, temp t2) {
	return (int)t1.alp < (int)t2.alp;
};
deque<temp>qq;
void print_codes(const treenode* root, string code) {
	if (root->left == NULL && root->right == NULL) {
		temp tmp;
		tmp.alp = root->alphabat;
		tmp.wei = root->weight;
		tmp.code = code;
		tmp.wepl = code.length();
		qq.push_back(tmp);
	}
	if (root->left) {
		print_codes(root->left, string(code + '0'));
	}
	if (root->right) {
		print_codes(root->right, string(code + '1'));
	}
}
treenode* gen_tree(deque<treenode*> q) {
	while (q.size() != 1) {
		sort(q.begin(), q.end(), cmp);
		treenode* left = q.front();
		q.pop_front();
		treenode* right = q.front();
		q.pop_front();

		treenode* tmp = new treenode('0', left->weight + right->weight);
		tmp->left = left;
		tmp->right = right;
		q.push_back(tmp);
	}
	return q.front();
}
void codes(char alp[], int wei[], int size) {
	deque<treenode*> q1;
	for (int i = 0; i < size; i++) {
		treenode* tmp = new treenode(alp[i], wei[i]);
		q1.push_back(tmp);
	}
	treenode* root = gen_tree(q1);
	string cd = "";
	print_codes(root, cd);
}

