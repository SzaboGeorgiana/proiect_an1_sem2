#include "Cos.h"
using std::shuffle;

void Cos::add_prod_in_cos(const Mag& s) {
	this->produseCOS.push_back(s);
	notify();
}
void Cos::empty_cos() noexcept {
	this->produseCOS.clear();
	notify();
}

void Cos::addRandom_in_cos(vector<Mag> prod, int howMany) {
	shuffle(prod.begin(), prod.end(), std::default_random_engine(std::random_device{}())); //amesteca vectorul v
	while (produseCOS.size() < howMany && prod.size() > 0) {
		produseCOS.push_back(prod.back());
		prod.pop_back();
	notify();
	}
}
const vector<Mag>& Cos::getAllProd() noexcept {
	return this->produseCOS;
}