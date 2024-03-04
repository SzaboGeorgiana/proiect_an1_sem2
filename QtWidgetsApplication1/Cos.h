#pragma once
#pragma once
#include "Magazin.h"
#include <vector>
#include <algorithm>
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock
#include "Observer.h"

using std::vector;
class Cos :public Observable {
private:
	vector<Mag> produseCOS;
public:
	Cos() = default;
	/*
	* Adauga un produs in cos
	* @param s: prod care se adauga (Mag)
	*
	* post: produsul va fi adaugata la cosul de cumparaturi
	*/
	void add_prod_in_cos(const Mag& s);
	/*
	* Elimina toate produsele din cos
	* post: cosul este gol
	*/
	void empty_cos() noexcept;
	/*
	* Adauga un numar random de produse in cos 
	*
	* @param prod: produsele din care se alege (vector<Mag>)
	* @param howMany: cate prod se adauga (int)
	*
	* post: prod sunt adaugate in cosul curent
	*/
	void addRandom_in_cos(vector<Mag> prod, int howMany);
	/*
	* Returneaza un vector care contine toate produsele din cos 
	*/
	const vector<Mag>& getAllProd() noexcept;
};
