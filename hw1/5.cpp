#include<iostream>
using namespace std;
class Quadratic {
public:
	int a, b, c;
	Quadratic();
	Quadratic(int,int,int);
	Quadratic operator+ (Quadratic);
};

Quadratic::Quadratic() {
	a = b = c = 0;
}
Quadratic::Quadratic(int a1, int b1, int c1) {
	a = a1;
	b = b1;
	c = c1;
}
Quadratic Quadratic::operator+(Quadratic qu) {
	Quadratic re;
	re.a = a + qu.a;
	re.b = b + qu.b;
	re.c = c + qu.c;
	return re;
}

int main() {
	Quadratic q1(1,5,9);
	Quadratic q2(2,4,-5);
	Quadratic q3;
	q3 = q1 + q2;
	cout << q3.a << " " << q3.b << " " << q3.c << " ";
}