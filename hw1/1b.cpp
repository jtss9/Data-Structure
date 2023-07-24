#include<iostream>
#include<ctime>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int matrix[100][100];
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 100;
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[j][i] << "\t";
		}
		cout << endl;
	}
}