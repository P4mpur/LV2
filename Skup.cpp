#include "Skup.h"
#include <iostream>
using namespace std;

bool Skup::pripada_Skupu(double real, double complex) {
	int flag = 0;
	for (int i = 0; i < br_el; i++)
	{
		if (real == niz[i].getReal() && complex == niz[i].getComplex())
		{
			flag++;
		}
	}
	if (flag!=0)
	{
		return 1;
	}
	return 0;
}
Skup::~Skup(){
	if (niz != 0)
	{
		delete[] niz;
	}
}

void Skup::Set() {
	cout << "Unesite elemente niza: " << endl;
	if (br_el == 0)
	{
		cout << "Unesite prvo broj elementa!! " << endl;
	}
	else
	{
		for (int i = 0; i < br_el; i++)
		{
			cout << "Element : " << i << endl;
			cin >> niz[i];
		}
	}
}

void Skup::Get() {
	if (br_el == 0)
	{
		cout << "Prvo Unesite Elemente" << endl;
	}
	else
	{
		cout << "Vasi Elementi su: " << endl;
		for (int i = 0; i < br_el; i++)
		{
			cout << niz[i] << " ";
		}
	}
} 

void Skup::isteraj_Dupli() {
	int k = 0;
	for (int i = 0; i < br_el; i++)
	{
		for (int j = i+1; j < br_el; j++)
		{
			if (niz[i].getReal() == niz[j].getReal() && niz[i].getComplex() == niz[j].getComplex())
			{
				for (int k = j; k < br_el - 1; k++)
				{
					niz[k] = niz[k+1];
				}
				br_el--;
				j--;
			}
		}
	}
}

void Skup::Sortiraj() {
	Complex pom;
	for (int i = 0; i < br_el-1; i++)
	{
		for (int j = i+1; j < br_el; j++)
		{
			if (j>=i)
			{
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
}



Skup& Skup::operator=(const Skup& v){
	if (this != &v)
	{
		this->br_el = v.br_el;
		//delete[] niz;
		niz = new Complex[br_el];
		for (int i = 0; i < br_el; i++)
		{
			niz[i] = v.niz[i];
		}
	}
	
	return *this;
}

istream& operator>>(istream& ulaz,Skup& desni)
{
	ulaz >> desni.br_el;
	for (int i = 0; i < desni.br_el; i++)
	{
		ulaz >> desni.niz[i];
	}
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Skup& desni)
{
	izlaz << desni.br_el << endl;
	for (int i = 0; i < desni.br_el; i++)
	{
		izlaz << desni.niz[i];
	}
	return izlaz;
}

//Skup& Skup::operator=(Complex& obj)
//{
//	this->niz = obj;
//	return this;
//}

Skup* Skup::Razlika(Skup& obj) {
	int flag = 0;
	int k = 0;
	int n = this->br_el < obj.br_el ? this->br_el : obj.br_el;
	Skup* novi;
	novi = new Skup(n);
	for (int i = 0; i < this->br_el; i++)
	{
		flag = 0;
		for (int j = 0; j < obj.br_el; j++)
		{
			if (this->niz[i] == obj.niz[j])
			{
				flag++;
			}
		}
		if (flag==0)
		{
			novi->niz[k] = this->niz[i];
			k++;
		}
	}
	novi->br_el = k;
	
	return novi;
}

Skup* Skup::Presek(const Skup& obj) {
	int n = this->br_el < obj.br_el ? this->br_el : obj.br_el;
	Skup* pom;
	pom = new Skup(n);
	int flag = 0,k=0;
	for (int i = 0; i < this->br_el; i++)
	{
		flag = 0;
		for (int j = 0; j < obj.br_el; j++)
		{
			if (this->niz[i]==obj.niz[j])
			{
				flag++;
			}
		}
		if (flag!=0)
		{
			pom->niz[k] = this->niz[i];
			k++;
		}
	}
	pom->br_el = k;
	return pom;
}

Skup* Skup::Unija(const Skup& obj) {
	int n = this->br_el+obj.br_el;
	Skup* pom;
	pom = new Skup(n);
	for (int i = 0; i < this->br_el; i++)
	{
		pom->niz[i] = this->niz[i];
	}
	for (int i = 0; i <obj.br_el ; i++)
	{
		pom->niz[i + this->br_el] = obj.niz[i];
	}
	return pom;
}