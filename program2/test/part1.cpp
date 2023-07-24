/*#include<iostream>
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
	int wpl;
	string code;
};
bool cmp(const treenode* t1, const treenode* t2) {
	return t1->weight < t2->weight;
}
bool cmp_letter(temp t1, temp t2){
	return (int)t1.alp < (int)t2.alp;
};
deque<temp> dq;
void print_codes(const treenode* root, string code) {
	if (root->left == NULL && root->right == NULL) {
		temp temp;
		temp.alp = root->alphabat;
		temp.wei = root->weight;
		temp.code = code;
		temp.wpl = code.length();
		dq.push_back(temp);
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
	deque<treenode*> q;
	for (int i = 0; i < size; i++) {
		treenode* tmp = new treenode(alp[i], wei[i]);
		q.push_back(tmp);
	}
	treenode* root = gen_tree(q);
	string cd = "";
	print_codes(root, cd);
}
int main(int agrc, const char* agrv[]) {
	vector<string> all_agrs;
	all_agrs.assign(agrv, agrv + agrc);
	cout << "DSOO-Program2-Demo: ";
	for (auto a : all_agrs) {
		cout << a << " ";
	}
	cout << "\n";
	if (agrc != 2) {
		cout << "part1\n\n";
	}
	else {
		string filename = agrv[1];
		cout << "read file from : " << "test/" << filename << endl;
	}
	char alp[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int wei[26] = { 11,5,2,3,12,3,5,6,8,1,2,4,8,7,2,2,1,9,6,2,4,1,10,10,1,1 };
	int size = sizeof(alp) / sizeof(alp[0]);
	for (int i = 0; i < size; i++) {
		cout << alp[i] << " = " << setw(2) << wei[i] << " | ";
	}
	cout << "\n\n";
	codes(alp, wei, size);
	sort(dq.begin(), dq.end(), cmp_letter);
	int wepl = 0;
	while (!dq.empty()) {
		temp tmp = dq.front();
		dq.pop_front();
		cout << " " << tmp.alp << " : " << tmp.code << endl;
		wepl += tmp.wei * tmp.wpl;
	}
	cout << endl << "WEPL : " << wepl << endl;
}*/