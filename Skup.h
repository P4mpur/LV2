#pragma once
#include "Complex.h"
class Skup
{
private: 
	unsigned int br_el;
	Complex* niz;
public:
	Skup(){ br_el = 0; };
	Skup(unsigned int x) { br_el = x; niz = new Complex[br_el]; };
	~Skup();
	int duzina_Niza();
	bool pripada_Skupu(double real, double complex);
	void Set();
	void Get();
	void isteraj_Dupli();
	void Sortiraj();
	Skup& operator=(const Skup& obj);
	friend istream& operator >>(istream& ulaz, Skup& desni);
	friend ostream& operator <<(ostream& izlaz,Skup& desni);
	
	//Skup& operator=(const Complex& obj);
	Skup* Razlika(Skup& obj);
	Skup* Unija(const Skup& obj);
	Skup* Presek(const Skup& obj);
};


inline int Skup::duzina_Niza() {
	return br_el;
};
