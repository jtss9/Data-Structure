/*#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100

using namespace std;

class Element{
    public:
        Element(int row = -1, int col = -1, int val = -1): row(row), col(col), val(val){}
        int row;
        int col;
        int val; 
};

class SparseMatrix{
    public:
        SparseMatrix(){}
        SparseMatrix(int row_num, int col_num, int r): row_num(row_num), col_num(col_num), r(r){}
        SparseMatrix(const SparseMatrix &other);
        SparseMatrix operator*(SparseMatrix &other);
        void set_M();
        void set_vec();
        void display();

        int row_num;
        int col_num;
        int r;
        int M[MAX][MAX];
        vector<Element> vec;
};

SparseMatrix::SparseMatrix(const SparseMatrix &other)
{
    // your implementation here
    row_num=other.row_num;
    col_num=other.col_num;
    r=other.r;
    for(int x=0;x<MAX;x++){
    	for(int y=0;y<MAX;y++){
    		M[x][y]=other.M[x][y];
		}
	}
	for(int x=0;x<vec.size();x++){
		vec.push_back(other.vec[x]);
	}
}

void SparseMatrix::set_M()
{
    memset(M, 0, sizeof(M));
    for (int i = 0; i < r; i++)
        M[vec[i].row][vec[i].col] = vec[i].val;
}

void SparseMatrix::set_vec()
{
    int count = 0;
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            if (M[i][j] != 0){
                Element element(i, j, M[i][j]);
                vec.push_back(element);
                count++;
            }
        }
    }
    
    r = count;
}

void SparseMatrix::display()
{
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

SparseMatrix SparseMatrix::operator*(SparseMatrix &other)
{
    SparseMatrix mul_SM(row_num, other.col_num, 0);

    if (other.col_num * r <= row_num * other.r){
        // your implementation here
        for(int i=0;i<row_num;i++){
        	for(int k=0;k<col_num;k++){
        		if (M[i][k] != 0){
        			for(int j=0;j<other.col_num;j++){
						mul_SM.M[i][j]=mul_SM.M[i][j]+M[i][k]*other.M[k][j];
					}
				}
			}
		}
    }
    else{
        // your implementation here
        for(int k=0;k<other.col_num;k++){
        	for(int i=0;i<other.row_num;i++){
        		if (other.M[i][k] != 0){
        			for(int j=0;j<row_num;j++){
						mul_SM.M[j][k]=mul_SM.M[j][k]+other.M[i][k]*M[k][j];
					}
				}
			}
		}
    }

    mul_SM.set_vec();
    return mul_SM;
}

void set_input(SparseMatrix &SM)
{
    cin >> SM.row_num >> SM.col_num >> SM.r;
    for (int i = 0; i < SM.r; i++){
        int row, col, val;
        cin >> row >> col >> val;
        Element element(row, col, val);
        SM.vec.push_back(element);
    }
    SM.set_M();
}

int main()
{
    SparseMatrix SM1;
    SparseMatrix SM2;
    set_input(SM1);
    set_input(SM2);

    // multiplication
    SparseMatrix mul_SM = SM1 * SM2;
    cout << "multiplication result: " << endl;
    mul_SM.display();
    
    // copy 
    SparseMatrix copy_SM = SM1;
    cout << "copy result: " << endl;
    copy_SM.display();

    return 0;
}*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Element {
public:
	Element(int row = -1, int col = -1, int val = -1) :row(row), col(col), val(val) {};
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
		SM.set_Matrix();
	}
}

int main() {
	SparseMatrix SM;
	input(SM);
	SM.DisplayMatrix();
	cout << endl;
	SparseMatrix sm_copy = SM;
	sm_copy.DisplayMatrix();
}
