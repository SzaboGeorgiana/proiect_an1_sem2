#pragma once
#include "Repository.h"
#include "Cos.h"
#include "Validators.h"
#include "dto.h"
#include <functional>
#include <iostream>
#include <map>
#include "undo.h"

using namespace std;

using std::function;
class ProdStore {
private:
	RepositoryAbstract& repo;
	Validator& val;

	vector<unique_ptr<undoAction>> undoActions;
	Cos current;
	/*
	Filtreaza lista de produse pe baza unui criteriu

	@param fct: functia dupa care se filtreaza lista de prod
	@return: lista cu prod care indeplinesc criteriul dat
	*/
	vector<Mag> filter(function<bool(const Mag&)> fct);

	/*
	* Functie de sortare proprie
	*
	* @param maiMicF: functia de comparare folosita pentru sortare
	*
	* @return: lista de produse sortata dupa criteriul dat (vector cu elemente de
	*			tip Mag)
	*/
	vector<Mag> generalSort(bool(*maiMicF)(const Mag&, const Mag&));

public:
	ProdStore(RepositoryAbstract& Repo, Validator& val) noexcept :repo{ Repo }, val{ val } {};

	//constructor de copiere

	ProdStore(const ProdStore& ot) = delete;

	/*
	Adauga un prod cu numele nume, tipul tip, producatorul prod si pretul pret
	*@param nume: numele prod care se adauga (string)
	*@param tip: tipul prod care se adauga (string)
	*@param prod: producatorul prod care se adauga (string)
	*@durata pret: pretul prod care se adauga (double)
	*
	* @throws:
	*	RepoException daca mai exista prod cu numele dat
	*	ValidationException daca prod nu este valid
	*/

	void addProd(string nume, string tip, string prod, double pret);

	/*
	Modifica un prod cu numele nume
	*@param nume: numele prod care se modifica (string)
	*@param tip: tipul nou al prod care se adauga (string)
	*@param prod: producatorul nou al  prod care se adauga (string)
	*@durata pret: pretul prod  nou al care se adauga (double)
	*
	* @throws:
	*	RepoException daca nu exista prod cu numele dat
	*	ValidationException daca prod nu este valid
	*/


	void modProd(string nume, string tip, string prod, double pret);

	Mag findProd(string nume);

	void delProd(string nume);
	/*
	Returneaza un vector cu toate prodsele disponibile

	@return: lista cu toate prodele disponibile (vector cu obiecte de tip Mag)
	*/

	const vector<Mag> getAll() const noexcept{
		return this->repo.getAll();
	}


	/*
	* Returneaza o lista de prod cu numele dat
	*
	* @param nume: numele dupa care se filtreaza
	* @return: lista cu prodse care au numele dat (vector cu elemente de tip Mag)
	*/
	vector<Mag> filtrareN(string nume);

	/*
	* Returneaza o lista de melodii cu producatorul dat
	*
	* @param prod: prodcatorul dupa care se filtreaza
	* @return: lista cu prod care au producatorul dat (vector cu elemente de tip Mag)
	*/
	vector<Mag> filtrareP(string prod);



	/*
	* Returneaza o lista de prod cu pretul cuprinsa intre
	* durataStart si durataEnd
	*
	* @param durataStart: pretul minim al prod cautate (double)
	* @param durataEnd: pretu; maxim al prod cautate (double)
	*
	* @return: lista cu prod care au un pret care indeplineste
	*			criteriile date (vector cu elemente de tip Mag)
	*/
	vector<Mag> filtrarePret(double durataStart, double durataEnd) noexcept;


	vector<Mag> filtrareT(string nume);

	

	map<string, DTO> raport();


	/*
	* Sorteaza prod dupa pret
	*
	* @return: lista cu prod sortate dupa pret
	*/
	vector<Mag> sortByP();

	/*
	* Sorteaza prod dupa tip si nume prod
	*
	* @return: lista cu prod sortate dupa tip si nume
	*/
	vector<Mag> sortByNT();

	/*
	* Sorteaza prod dupa nume prod
	*
	* @return: lista cu prod sortate dupa nume
	*/
	vector<Mag> sortByN();


	/*
	* Adauga un prod cu numele dat in cos
	*
	* @param titlu: numrle melodiei care se adauga (string)
	
	*
	* post: produsul este adaugat in cos
	* @throws: RepoException daca nu exista prod cu numele dat
	*/
	void addCOS(string titlu);

	/*
	* Adauga un numar random de produse in cos 
	*
	* @param howMany: cate produse se adauga (int)
	*
	* @return: numarul de produse adaugate in cos
	* post: se adauga un numar random de produse in cos 
	*/
	int addRandomCOS(int howMany);
	/*
	* Elimina toate produsele din cos
	* post: cosul nu contine niciun produs
	*/
	void emptyCOS() noexcept;
	/*
	* Returneaza un vector cu toate produsele din cos
	*/
	const vector<Mag>& getCOS() noexcept;

	Cos& getPlaylist() {
		return this->current;
	}


	void storeUndo();

};
void testeService();