#include<iostream>
using namespace std;
void insertionsort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j>=0) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int array[7] = { 4, 2, 5, 6, 3, 9, 1 };
	print(array, 7);
	insertionsort(array, 7);
	print(array, 7);

}