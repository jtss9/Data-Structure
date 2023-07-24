#include<iostream>
using namespace std;
class Complex {
public:
	int r, i;
	Complex();
	Complex(int, int);
};
Complex::Complex() {
	r = 0;
	i = 0;
}

Complex::Complex(int a, int b) {
	r = a;
	i = b;
}

int main() {
	return 0;
}