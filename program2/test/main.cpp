#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <deque>
#include <algorithm>
#include"part1.h"
#include"part2.h"
#include"part3.h"

using namespace std;
int main(int argc, const char* argv[]) {
    vector<string> all_args;
    all_args.assign(argv, argv + argc); // convert command line argument to string 

    cout << "DSOO-Program2-Demo: ";
    for (auto a : all_args) {
        cout << a << " ";
    }
    cout << "\n\n";

    if (argc != 2) {
		char alp[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		int wei[26] = { 11,5,2,3,12,3,5,6,8,1,2,4,8,7,2,2,1,9,6,2,4,1,10,10,1,1 };
		int size = sizeof(alp) / sizeof(alp[0]);
		for (int i = 0; i < size; i++) {
			cout << alp[i] << " = " << setw(2) << wei[i] << " | ";
		}
		cout << "\n\n";
		codes(alp, wei, size);
		sort(qq.begin(), qq.end(), cmp_letter);
		int wepl = 0;
		while (!qq.empty()) {
			temp tmp = qq.front();
			qq.pop_front();
			cout << tmp.alp << " : " << tmp.code << endl;
			wepl += tmp.wei * tmp.wepl;
		}
		cout << endl << "WEPL : " << wepl << endl;
    }
    else {
        string filename = argv[1];
        cout << "read file from : " << "test/" << filename << endl;
		fstream f;
		f.open(filename);
		string str1, str2;
		f >> str1;
		f >> str2;
		//cout << str1 << " " << str2;
		cout << "characters : " << str1 << "\n\n";
		char ch[52];
		int wei[52] = { 0 };
		int sz = 52;
		get_huff(str1, ch, wei, str1.length());
		for (int i = 0; i < 52; i++) {
			if (wei[i] == 0) {
				sz = i;
				break;
			}
		}
		deque<two> q3;		// first part of part 2
		for (int i = 0; i < sz; i++) {
			two tmp;
			tmp.ch = ch[i];
			tmp.wei = wei[i];
			q3.push_back(tmp);
		}
		sort(q3.begin(), q3.end(), compare);
		deque<two> q33(q3);
		while (!q3.empty()) {
			two tmp = q3.front();
			q3.pop_front();
			cout << tmp.ch << " = " << setw(2) << tmp.wei << " | ";
		}
		cout << "\n\n";

		char ch_new[52];
		int wei_new[52] = { 0 };

		q_array(q33, ch_new, wei_new, sz);

		codes(ch_new, wei_new, sz);
		sort(qq.begin(), qq.end(), cmp_letter);
		int wepl = 0;
		deque<temp> q22(qq);		// copy a qq for part3
		while (!qq.empty()) {				// second part of part 2
			temp tmp = qq.front();
			qq.pop_front();
			cout << tmp.alp << " : " << tmp.code << endl;
			wepl += tmp.wei * tmp.wepl;
		}

		cout << "\nHuffman code : " << str2 << endl;
		cout << "decode : ";
		string output = "";
		decode(str2, output, q22);
		//cout << output << endl;
		cout << "\nWEPL : " << wepl << endl;
    }
    return 0;
}