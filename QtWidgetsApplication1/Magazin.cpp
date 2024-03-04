#include "Magazin.h"
#include <assert.h>
string Mag::getnume() const {
	return this->nume;
}
string Mag::gettip() const {
	return this->tip;
}
string Mag::getprod() const {
	return this->prod;
}
double Mag::getpret()  const noexcept {
	return this->pret;
}

void Mag::setprod(string prodNou) {
	this->prod = prodNou;
}
void Mag::settip(string tipNou) {
	this->tip = tipNou;
}
void Mag::setnume(string numeNou) {
	this->nume = numeNou;
}
void Mag::setpret(double pretNoua) noexcept {
	this->pret = pretNoua;
}



bool cmpPret(const Mag& m1, const Mag& m2) noexcept {
	return m1.getpret() < m2.getpret();
}

bool cmpNT(const Mag& m1, const Mag& m2) {
	if (m1.gettip() == m2.gettip())
		return m1.getnume() < m2.getnume();
	else
		return m1.gettip() < m2.gettip();
}

bool cmpN(const Mag& m1, const Mag& m2) {
	return (m1.getnume() < m2.getnume());

}


void testGetSet() {
	Mag song1{ "Pictures of Home", "Deep Purple","rock",1.22 };
	assert(song1.getnume() == "Pictures of Home");
	assert(song1.gettip() == "Deep Purple");
	assert(song1.getprod() == "rock");
	assert(song1.getpret() == 1.22);

	Mag song2{ "Lucky Man", "Emerson, Lake & Palmer","rock",3.44 };
	assert(song2.getnume() == "Lucky Man");
	assert(song2.gettip() == "Emerson, Lake & Palmer");
	assert(song2.getprod() == "rock");
	assert(song2.getpret() == 3.44);

	song2.setnume("Goodbye Blue Sky");
	song2.settip("Pink Floyd");
	song2.setprod("psychedelic rock");
	song2.setpret(5.22);

	assert(song2.getnume() == "Goodbye Blue Sky");
	assert(song2.gettip() == "Pink Floyd");
	assert(song2.getprod() == "psychedelic rock");
	assert(song2.getpret() == 5.22);



}

void testeDomain() {
	testGetSet();
}

