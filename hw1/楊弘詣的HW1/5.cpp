#include<iostream>
using namespace std;
class Quadratic {
	public:
		int fir,sec,thi;
		Quadratic(){};
		Quadratic(int,int,int);
		Quadratic operator+ (Quadratic);
};
Quadratic::Quadratic(int a,int b,int c){
	fir=a;
	sec=b;
	thi=c;
}
Quadratic Quadratic::operator+(Quadratic param){
	Quadratic temp;
	temp.fir=fir+param.fir;
	temp.sec=sec+param.sec;
	temp.thi=thi+param.thi;
	return(temp);
}
int main(){
	Quadratic a(2,1,3);
	Quadratic b(5,3,6);
	Quadratic d;
	d=a+b;
	cout<<d.fir<<endl<<d.sec<<endl<<d.thi;
	return 0;
}
