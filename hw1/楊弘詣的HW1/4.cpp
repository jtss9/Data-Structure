#include<iostream>
using namespace std;
class Complex {
	public:
		int real,fake;
		Complex();
		Complex(int,int);
};
Complex::Complex(){
	real=0;
	fake=0;
}
Complex::Complex(int a,int b){
	real=a;
	fake=b;
}
int main(){
	return 0;
}
