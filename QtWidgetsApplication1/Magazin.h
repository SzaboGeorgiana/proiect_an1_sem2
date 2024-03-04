#pragma once
#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Mag {
private:
	string nume;
	string tip;
	string prod;
	double pret;
public:

	Mag() = default;
	Mag(string nume, string tip, string prod, double pret) :nume{ nume }, tip{ tip }, prod{ prod }, pret{ pret } {};
	Mag(const Mag& ot) :nume{ ot.nume }, tip{ ot.tip }, prod{ ot.prod }, pret{ ot.pret } {
		cout << "Copy constructor called.\n";
		
	}
	string getnume() const;
	string gettip() const;
	string getprod() const;
	double getpret() const noexcept;

	void setnume(string numeNou);
	void settip(string tipNou);
	void setprod(string prodNou);
	void setpret(double pretNoua) noexcept;
};

/*
Compara doua produse dupa pret

@return: true daca pretul produsului m1 e mai mica decat
		pretul produsului m2, false altfel
*/
bool cmpPret(const Mag& m1, const Mag& m2)noexcept;

/*
Compara doua produse dupa tipul si numele produsului
@return: true daca tipul prod m1 e inainte (alfabetic)
		 tipului prod m2, false altfel
		 daca avem acelasi tip, atunci comparam numele produselor
		 */
bool cmpNT(const Mag& m1, const Mag& m2);


bool cmpN(const Mag& m1, const Mag& m2);

void testeDomain();