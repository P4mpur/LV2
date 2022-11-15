#include "Complex.h"
#include <iostream>
using namespace std;
void  Complex::Unos() {
	cin >> this->real;
	cout << " i";
	cin >> this->complex;
}

void Complex::Stampaj() {
	cout << this->real;
	cout << " i";
	cout << this->complex;
};

ostream& operator << (ostream& izlaz,Complex& desni){
	izlaz << desni.real << desni.complex;
	izlaz << endl;
	return izlaz;
}

istream& operator >> (istream& ulaz, Complex& desni) {
	ulaz >> desni.real >> desni.complex;
	return ulaz;
}

Complex Complex::Saberi(Complex& obj) {
	Complex t;
	t.real = this->real + obj.real;
	t.complex = this->complex + obj.complex;

	return t;
}

Complex::Complex(Complex& obj) {
	if (this != &obj)
	{
		this->real = obj.real;
		this->complex = obj.complex;
	}
}

Complex Complex::operator=(Complex& obj) {
	if (this != &obj)
	{
		this->real = obj.real;
		this->complex = obj.complex;
	}

	return *this;
}

bool Complex::operator==(Complex& desni)
{
	if (this->real == desni.real && this->complex == desni.complex)
	{
		return true;
	}
	return false;
}