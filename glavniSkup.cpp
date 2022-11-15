#include <iostream>
#include <fstream>
#include "Complex.h"
#include "Skup.h"
using namespace std;

int main()
{
	Skup obj(5);
	Skup* obj3;
	Skup obj1(3);
	Skup obj2(2);
	/*ifstream uldat("Ulaz.txt");

	if (uldat.good())
	{
		uldat >> obj;
		uldat.close();
		cout << obj;
	}
	ofstream izldat("Izlaz.txt");

	if (izldat.good())
	{
		izldat << obj;
		izldat.close();
	}*/

	cin >> obj1;
	cin >> obj2;
	obj3 = obj1.Razlika(obj2);
	cout << *obj3;
	obj3 = obj1.Unija(obj2);
	cout << *obj3;
	obj3 = obj1.Presek(obj2);
	cout << *obj3;
}