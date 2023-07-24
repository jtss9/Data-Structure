#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	srand( time(NULL) );
	for(int i=0;i<n;i++){
		a[i]=rand()%10;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	int first=a[0];
	cout<<"The number of the first number: "<<count(a,a+n,first);
}
