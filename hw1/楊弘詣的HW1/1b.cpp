#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	srand( time(NULL) );
	int column,row;
	cout<<"Enter the number of column?";
	cin>>column;
	cout<<"Enter the number of row?";
	cin>>row;
	int a[column][row];
	for(int i=0;i<column;i++){
		for(int k=0;k<row;k++){
			a[i][k]=rand()%100;
		}
	}
	cout<<"Ramdon matrix:"<<endl;
	for(int i=0;i<column;i++){
		for(int k=0;k<row;k++){
			cout<<a[i][k]<<"\t";
		}
		cout<<endl;
	}
	cout<<"New matrix:"<<endl;
	for(int i=0;i<row;i++){
		for(int k=0;k<column;k++){
			cout<<a[k][i]<<"\t";
		}
		cout<<endl;
	}
}
