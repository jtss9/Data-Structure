#include<iostream>
#include<ctime>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[100];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
		cout << a[i] << "\t";
	}
	cout << endl << count(a, a + n, a[0]);
}