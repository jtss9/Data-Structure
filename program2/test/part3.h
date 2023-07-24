#include<iostream>
#include<queue>
using namespace std;

void decode(string input, string output, deque<temp> q) {
	string tmp = "";
	for (int i = 0; i < input.length(); i++) {
		tmp += input[i];
		//cout << tmp << "  ";
		for (int j = 0; j < q.size(); j++) {
			if (tmp == q[j].code) {
				output += q[j].alp;
				cout << q[j].alp;
				tmp = "";
				break;
			}
		}
	}
}
