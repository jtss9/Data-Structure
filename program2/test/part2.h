#include<iostream>
#include<string>
#include<queue>
using namespace std;

class two {
public:
	char ch;
	int wei;
};
bool compare(two t1, two t2) {
	return (int)t1.ch < (int)t2.ch;
}
void get_huff(string str, char ch[], int weight[], int size) {
	int ind = 0, flag = 1;
	for (int i = 0; i < size; i++) {
		flag = 1;
		for (int j = 0; j <= ind; j++) {
			if (str[i] == ch[j]) {
				weight[j]++;
				flag = 0;
				break;
			}
		}
		if (flag) {
			ch[ind] = str[i];
			weight[ind] = 1;
			ind++;
		}
	}
}
void q_array(deque<two> q, char ch[], int wei[], int size) {
	for (int i = 0; i < size; i++) {
		two tmp = q.front();
		q.pop_front();
		ch[i] = tmp.ch;
		wei[i] = tmp.wei;
	}
}

