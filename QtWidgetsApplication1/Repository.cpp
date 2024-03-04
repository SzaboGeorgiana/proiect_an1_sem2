#include "Repository.h"
#include <assert.h>


/**/
bool Repository::exists(const Mag& s) {
	try {
		find(s.getnume());
		return true;
	}
	catch (RepoException) {
		return false;}
}



const Mag& Repository::find(string nume) {
	/*for (const Mag& s : this->all) {
		if (s.getnume() == nume) {
			return s;
		}
	}
	throw RepoException("Produsul cu numele " + nume + " nu exista in lista\n");
	*/
	vector<Mag>::iterator f = std::find_if(this->all.begin(), this->all.end(),
		[=](const Mag& s) {
			return s.getnume() == nume;
		});

	if (f != this->all.end())
		return (*f);
	else
		throw RepoException("Produsul cu numele " + nume + " nu exista in lista\n");}




void Repository::store(const Mag& s) {
	if (exists(s)) {
		throw RepoException("Produsul cu numele " + s.getnume() + "  exista in lista\n");
	}
	this->all.push_back(s);
}

void Repository::mod(const Mag& s) {

	if (!exists(s)) {
		throw RepoException("Produsul cu numele " + s.getnume() + " nu exista in lista\n");
	}

	for (int i = 0; i < this->all.size(); i++) {
		if (this->all[i].getnume() == s.getnume()) {
			all[i].setnume(s.getnume());
			all[i].settip(s.gettip());
			all[i].setpret(s.getpret());
			all[i].setprod(s.getprod());
		}
	}
	//del(s);
	//this->all.push_back(s);
}

void Repository::del(const Mag& s) {
	//vector<Mag> s1=getAll();
	if (!exists(s)) {
		throw RepoException("Produsul cu numele " + s.getnume() + " nu exista in lista\n");}
	else
	
		/**/
		for (int i = 0; i < this->all.size(); i++) {
		
			if (this->all[i].getnume() == s.getnume()) {
				for (int j = i; j < this->all.size()-1; j++)
			{ 
				this->all[j]=(this->all[j + 1]);
				
			}
			
			this->all.pop_back();

		}
	}
	

}

const vector<Mag> Repository::getAll() const noexcept{

	return this->all;
}

void Repository::exc() {
	if (true) {
		throw RepoException("No more undo action to do!\n");}}

#include <sstream>



void RepositoryFile::loadfromfile() {
	ifstream fin(this->fName);
	if (!fin.is_open()) {
		throw RepoException("Nu s-a putut deschide fisierul " + fName + "!\n");
	}

	string line;

	if (fin.peek() == EOF) {return;
	}

	while (!fin.eof()) {
		string atribute;
		vector<string> atr;
		getline(fin, line);

		stringstream ss(line);
		while (getline(ss, atribute, ',')) {
			atr.push_back(atribute);
		}

		if (atr.empty()) break;
		
		
				string name = atr[0];
				
				string type=atr[1];
				
				string producer= atr[2];
				
				double  price= stod(atr[3]);
				
				Mag p{ name, type, producer ,price};
				Repository::store(p);

	}

	fin.close();
}


void RepositoryFile::savetofile() {
	std::ofstream out(fName);
	/*if (!out.is_open()) { //verify if the stream is opened
		std::string msg("Unable to open file:");
		throw RepoException(msg);
	}*/
	for (auto& p :Repository::getAll()) {
		out << p.getnume();
		out << ',';
		out << p.gettip();
		out << ',';
		out << p.getprod();
		out << ',';
		out << p.getpret();
		out << endl;
	}
	out.close();
}



void testAddRepo() {
	Repository testRepo;
	Mag song1{ "Yamasha", "Alex Velea","pop",3.45 };
	testRepo.store(song1);
	assert(testRepo.getAll().size() == 1);

	Mag song2{ "Raisa", "Fly Project", "pop", 3.42 };
	Mag song3{ "Yamasha", "Alex Velea", "rock", 4.32 };
	try {
		testRepo.store(song3); assert(false);
	}
	catch (RepoException) {
		assert(true);
	}


}
void testFindRepo() {
	Repository testRepo;

	Mag song1{ "Pictures of Home", "Deep Purple", "rock",3.24 };
	Mag song2{ "Highway Star","Deep Purple", "rock",2.44 };
	Mag song3{ "Holy Diver","Dio", "rock", 4.45 };
	testRepo.store(song1);
	testRepo.store(song2);

	assert(testRepo.exists(song1));
	assert(!testRepo.exists(song3));

	auto foundSong = testRepo.find("Pictures of Home");
	assert(foundSong.gettip() == "Deep Purple");
	assert(foundSong.getpret() == 3.24);
	assert(foundSong.getprod() == "rock");


	try {
		testRepo.find("Baba O'riley"); assert(false);
	}
	catch (RepoException& ve) {
		assert(ve.getErrorMessage() == "Produsul cu numele Baba O'riley nu exista in lista\n");
	}
}



void testModRepo() {
	Repository testRepo;
	Mag song1{ "Yamasha", "Alex Velea","pop",3.45 };
	testRepo.store(song1);
	assert(testRepo.getAll().size() == 1);

	Mag song2{ "Raisa", "Fly Project", "pop", 3.42 };
	Mag song3{ "Yammasha", "Alex Veelea", "rock", 4.32 };
	testRepo.store(song2);
	testRepo.store(song3);
	Mag song4{ "Raisa", "Fly Proooject", "op", 3.42 };


	testRepo.mod(song4);
	assert(true);

	try {
		testRepo.mod({ "Baba O'riley", "Alex Veelea", "rock", 4.32 }); assert(false);
	}
	catch (RepoException& ve) {
		assert(ve.getErrorMessage() == "Produsul cu numele Baba O'riley nu exista in lista\n");
	}

}

void testDelRepo() {
	Repository testRepo;
	Mag song1{ "Yamasha", "Alex Velea","pop",3.45 };
	testRepo.store(song1);
	assert(testRepo.getAll().size() == 1);

	Mag song2{ "Raisa", "Fly Project", "pop", 3.42 };
	Mag song3{ "Yammasha", "Alex Veelea", "rock", 4.32 };
	testRepo.store(song2);
	testRepo.store(song3);
	//Mag song4{ "Raisa", "Fly Proooject", "op", 3.42 };
	assert(testRepo.getAll().size() == 3);

	testRepo.del(song2);

	assert(true);
	assert(testRepo.getAll().size() == 2);
	
	try {
		testRepo.del({ "Baba O'riley", "Alex Veelea", "rock", 4.32 }); assert(false);
	}
	catch (RepoException& ve) {
		assert(ve.getErrorMessage() == "Produsul cu numele Baba O'riley nu exista in lista\n");
	}

}


void testeRepo() {
	testAddRepo();
	testFindRepo();
	testDelRepo();
	testModRepo();

}