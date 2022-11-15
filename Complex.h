#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double real;
	double complex;

public:
	void Unos();
	void Stampaj();
	Complex() { real = 0; complex = 0; };
	Complex(double a, double b) { real = a; complex = b; };
	Complex(Complex& obj);
	
	//pristup clanovima -->
	double getReal() { return real; };
	double getComplex() { return complex;};
	
	friend istream& operator >> (istream& ulaz, Complex& desni);
	friend ostream& operator << (ostream& izlaz,Complex& desni);

	Complex operator = (Complex& desni);
	bool operator == (Complex& desni);

	Complex Saberi(Complex& obj);
};

