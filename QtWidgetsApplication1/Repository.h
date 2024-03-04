#pragma once
#pragma once
#include "Magazin.h"
//#include "VectorDinamicTemplate.h"
#include <vector>
#include <functional>
#include <fstream>
#include <map>
#include <algorithm>
#include <random>    
//using std::default_random_engine;
#include <chrono> 
//using std::shuffle;
using std::vector;
/*
Clasa de exceptii specifice Repo
*/
class RepoException {
private:
	string errorMsg;
public:
	RepoException(string errorMsg) :errorMsg{ errorMsg } {};
	string getErrorMessage() {
		return this->errorMsg;
	}
};


class RepositoryAbstract {

public:

	virtual void store(const Mag& s) = 0;

	virtual void mod(const Mag& s) = 0;

	virtual void del(const Mag& s) = 0;
	virtual void exc() = 0;
	virtual const Mag& find(string nume) = 0;

	virtual const vector<Mag> getAll() const noexcept = 0;

	//virtual ~RepositoryAbstract() = 0;
};



class Repository: public RepositoryAbstract {
private:
	vector<Mag> all;
public:

	Repository() = default;
	//constructor de copiere

	Repository(const Repository& ot) = delete;
	/*
	Adauga un produs in lista
	@param s: prod care se adauga (Mag)
	@return -
	post: produsul va fi adaugat in lista

	@throws: RepoException daca un prod cu acelasi nume
			 exista deja
	*/
	virtual void store(const Mag& s);



	/*
	Modifica un produs in lista
	@param s: prod care se modifica (Mag)
	@return -
	post: produsul va fi modificat in lista

	@throws: RepoException daca un prod nu
			 exista deja
	*/
	virtual void mod(const Mag& s);


	virtual void del(const Mag& s);

	/*
	Returneaza o lista cu toate produsele
	@return: lista cu produsele (vector of Mag objects)
	*/
	const vector<Mag> getAll() const noexcept;

	/*
	Cauta produsul cu numele dat

	@param nume: numele dupa care se cauta

	@returns: entitatea Mag cu numele dat (daca aceasta exista)
	@throws: RepoException daca nu exista prod cu numele dat*/
	const Mag& find(string nume);

	/*
	Verifica daca un prod exista in lista

	@param s: prod care se cauta in lista
	@return: true daca prod exista, false altfel
	*/
	bool exists(const Mag& s);

	void exc();
	virtual ~Repository() = default;
};

using namespace std;

//ostream& operator<<(ostream& out, const RepoException& ex);



class RepositoryFile : public Repository {
	void loadfromfile();
	void savetofile();
	string fName;
	void clearFile() {
		ofstream f(fName, ios::trunc);
		f.close();
	}

public:
	RepositoryFile(string n) :Repository(), fName{ n } {
		//this->clearFile();
		loadfromfile();
	}


	void store(const Mag& s)override {
		Repository::store(s);
		savetofile();
	}

	void mod(const Mag& s)override {
		Repository::mod(s);
		savetofile();
	}


	void del(const Mag& s)override {
		Repository::del(s);
		savetofile();
	}

	~RepositoryFile()override {
	//	this->clearFile();

	}
};



class RepositoryLab : public RepositoryAbstract {
	
	std::map< string, Mag> map;
	double prob;
	
public:
/**/	
	RepositoryLab(double prob) : prob{prob} {
		//this->clearFile();
		//loadfromfile();
	}

	/**/

	void exceptia() {
		vector <double> p = { 0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9 };

		shuffle(p.begin(), p.end(), default_random_engine(random_device{}())); //amesteca vectorul v
		if (p[0] < this->prob)
		{
			throw RepoException("exceptie\n");
		}
	}
	

	void store(const Mag& s)override {
		/*if (exists(s)) {
			throw RepoException("Produsul cu numele " + s.getnume() + "  exista in lista\n");
		}*/
		exceptia();
		
		this->map[s.getnume()]=s;
	}

	void mod(const Mag& s) override {
		exceptia();

		this->map[s.getnume()]=s;
	}


	void del(const Mag& s)override {
		exceptia();

		this->map.erase(s.getnume());
	}


	const vector<Mag> getAll() const noexcept override {
		/**/
		vector<Mag> songs;
		for (auto i : this->map) {
			songs.push_back(i.second);
		}
		return songs;
	}


	void exc() {
		if (true) {
			throw RepoException("No more undo action to do!\n");
		}
	}


	const Mag& find(string nume) {
		/*for (const Mag& s : this->all) {
			if (s.getnume() == nume) {
				return s;
			}
		}
		throw RepoException("Produsul cu numele " + nume + " nu exista in lista\n");
		*/
		return this->map[nume];

	}


//	~RepositoryLab() override{
		//this->clearFile();

//	}
};




void testeRepo();