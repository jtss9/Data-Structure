#include<iostream>
#include<string>
using namespace std;
string ispalin(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1]) return "NO";
	}
	return "YES";
}
int main() {
	string str;
	str = "level";
	cout << str << " " << ispalin(str) << endl;
	str = "apple";
	cout << str << " " << ispalin(str) << endl;
}