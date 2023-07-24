#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Element {
public:
	Element(int row, int col, int val) :row(row), col(col), val(val) {};
	int row, col, val;
};

class SparseMatrix {
public:
	SparseMatrix() {}
	SparseMatrix(int row_num, int col_num ,int val_num) :row_num(row_num), col_num(col_num), val_num(val_num) {}
	SparseMatrix(const SparseMatrix& copy);
	int row_num, col_num, val_num;
	void DisplayMatrix();
	void set_Matrix();
	vector<Element> vec;
	int M[10][10];
};

SparseMatrix::SparseMatrix(const SparseMatrix& copy) {
	row_num = copy.row_num;
	col_num = copy.col_num;
	val_num = copy.val_num;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			M[i][j] = copy.M[i][j];
		}
	}
	for (int i = 0; i < val_num; i++) {
		vec.push_back(copy.vec[i]);
	}
}

void SparseMatrix::DisplayMatrix() {
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void SparseMatrix::set_Matrix() {
	memset(M, 0, sizeof(M));
	for (int i = 0; i < val_num; i++) {
		M[vec[i].row][vec[i].col] = vec[i].val;
	}
}

void input(SparseMatrix& SM) {
	cin >> SM.row_num >> SM.col_num >> SM.val_num;
	for (int i = 0; i < SM.val_num; i++) {
		int row, col, val;
		cin >> row >> col >> val;
		Element element(row, col, val);
		SM.vec.push_back(element);
	}
	SM.set_Matrix();
}

int main() {
	SparseMatrix SM;
	input(SM);
	cout << "original matrix: \n";
	SM.DisplayMatrix();
	cout << endl << "copy matrix: \n";
	SparseMatrix sm_copy = SM;
	sm_copy.DisplayMatrix();
}