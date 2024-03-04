#pragma once
#include "Service.h"

#include <assert.h>
#include <functional>
#include <algorithm>
#include <string.h>

using std::sort;
void ProdStore::addProd(string nume, string tip, string prod, double pret) {
	Mag s1{ nume, tip, prod, pret };
	val.valideaza(s1);
	repo.store(s1);
	undoActions.push_back(std::make_unique<undoAdd>(s1, this->repo));
}

void ProdStore::modProd(string nume, string tip, string prod, double pret)
{
	Mag s1{ nume, tip, prod, pret };
	Mag s2 = findProd(nume);

	val.valideaza(s1);
	repo.mod(s1);
	undoActions.push_back(std::make_unique<undoModifyBack>(s2, this->repo));

}

Mag ProdStore::findProd(string nume)
{

	vector<Mag> v{ repo.getAll() };
	for (int i = 0; i < v.size(); i++) {


		if (v[i].getnume() == nume) {
			return v[i];
		}

	}


	throw RepoException("Produsul cu numele " + nume + " nu exista in lista\n");

}


void ProdStore::delProd(string nume)
{
	Mag s = findProd(nume);
	repo.del(s);
	undoActions.push_back(std::make_unique<undoRemove>(s, this->repo));
}

/*
vector<Mag> ProdStore::generalSort(bool(*maiMicF)(const Mag&, const Mag&)) {
	vector<Mag> v{ repo.getAll() };
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = i + 1; j < v.size(); j++) {

			if (maiMicF(v[i], v[j]) == false) {
				//interschimbam
				Mag aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	return v;
}*/



vector<Mag> ProdStore::sortByP() {
	/*auto sortedCopy = repo.getAll();
	sort(sortedCopy.begin(), sortedCopy.end(), cmpPret);
	return sortedCopy;*/

	vector<Mag> sortedCopy{ repo.getAll() };
	sort(sortedCopy.begin(), sortedCopy.end(), cmpPret);
	return sortedCopy;
}

vector<Mag> ProdStore::sortByN() {
	//return generalSort(cmpN);
	vector<Mag> sortedCopy{ repo.getAll() };
	sort(sortedCopy.begin(), sortedCopy.end(), cmpN);
	return sortedCopy;

}

vector<Mag> ProdStore::sortByNT() {
	//return generalSort(cmpNT);
	vector<Mag> sortedCopy{ repo.getAll() };
		sort(sortedCopy.begin(), sortedCopy.end(), cmpNT);
		return sortedCopy;
}
/*
vector<Mag> ProdStore::filter(function<bool(const Mag&)> fct) {
	vector<Mag> filteredSongs;
	for (const auto& song : repo.getAll()) {
		if (fct(song)) {
			filteredSongs.push_back(song);
		}
	}
	return filteredSongs;
}*/

vector<Mag> ProdStore::filtrareN(string nume) {
	/*return filter([nume](const Mag& m) {
		return m.getnume() == nume;
		});*/
	const vector<Mag>& allSongs = getAll();
	vector<Mag> filteredSongs;
	std::copy_if(allSongs.begin(), allSongs.end(), back_inserter(filteredSongs),
		[nume](const Mag& m) {
			return m.getnume() == nume;
		});

	return filteredSongs;
}

vector<Mag> ProdStore::filtrareP(string nume) {
	/*return filter([nume](const Mag& m) {
		return m.getprod() == nume;
		});*/
	const vector<Mag>& allSongs = getAll();
	vector<Mag> filteredSongs;
	std::copy_if(allSongs.begin(), allSongs.end(), back_inserter(filteredSongs),
		[nume](const Mag& m) {
			return m.getprod() == nume;
		});

	return filteredSongs;
}

vector<Mag> ProdStore::filtrarePret(double durataStart, double durataEnd) noexcept
{
	//return filter([=](const Mag& m) noexcept { return m.getpret() >= durataStart && m.getpret() <= durataEnd; });
	const vector<Mag>& allSongs = getAll();
	vector<Mag> filteredSongs;
	std::copy_if(allSongs.begin(), allSongs.end(), back_inserter(filteredSongs),
		[=](const Mag& m) noexcept{
			return m.getpret() >= durataStart && m.getpret() <= durataEnd; ;
		});

	return filteredSongs;
}


#include <map>



vector<Mag> ProdStore::filtrareT(string nume) {
	/*return filter([nume](const Mag& m) {
		return m.getprod() == nume;
		});*/
	const vector<Mag>& allSongs = getAll();
	vector<Mag> filteredSongs;
	std::copy_if(allSongs.begin(), allSongs.end(), back_inserter(filteredSongs),
		[nume](const Mag& m) {
			return m.gettip() == nume;
		});

	return filteredSongs;
}


map<string, DTO> ProdStore::raport()
{
	//return filter([=](const Mag& m) noexcept { return m.getpret() >= durataStart && m.getpret() <= durataEnd; });

	const vector<Mag>& allSongs = getAll();
	
	map<string, DTO> map;

	for (auto i : allSongs)
	{

		vector<Mag> filtrare = filtrareT(i.gettip());

	
		DTO s{ i.gettip() ,int(filtrare.size()) };
		
		map[i.gettip()] = s;
	}

	/*std::map<std::string, DTO>::iterator it = map.begin();
	while (it != map.end())
	{
		cout << "key " << it->first << ", Value: ";
		cout <<"Tip:  "<< it->second.gettip() << "  Count:  " << it->second.getcount() << endl;
		it++;
	}
*/

	return map;
}
//COOOOOOOOS


void ProdStore::addCOS(string titlu) {

	const auto& song = repo.find(titlu);
	current.add_prod_in_cos(song);

}
int ProdStore::addRandomCOS(int howMany) {
	current.addRandom_in_cos(this->getAll(), howMany);
	return int(current.getAllProd().size());
}
void ProdStore::emptyCOS() noexcept {
	current.empty_cos();
}
const vector<Mag>& ProdStore::getCOS() noexcept{
	return current.getAllProd();
}

void ProdStore::storeUndo()
{
	if (undoActions.empty()) {
		repo.exc(); }
	else
	{
		undoActions.back()->doUndo();
		undoActions.pop_back();
	}
}


void testAddService() {
	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Raisa", "Fly Project", "pop", 3.42);
	testService.addProd("Raisa2", "Fly Project", "pop", 3.42);
	testService.addProd("Raisa3", "Fly Project", "pop", 3.42);

	assert(testService.getAll().size() == 3);
	try {
		testService.addProd("Raisa", "Fly Project", "pop", 3.42); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

		testService.addProd("Pictures of Home", "Deep Purple", "rock", 1.22);
		assert(true);

	try {
		testService.addProd("", "Deep Purple", "rock", 2.24); assert(false);
	}
	catch (ValidationException& ve) {
		assert(ve.getErrorMessages() == "Numele trebuie sa aiba cel putin 2 caractere.\n");
	}

	try {
		testService.addProd("Smoke on the Water", "", "rock", 2.24); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}

	try {
		testService.addProd("Child in Time", "Deep Purple", "rock", 16000); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}

}

void testFILE() {
	
	try {
		RepositoryFile testRepo1("Teste1.csv"); assert(false);}
	catch (RepoException&) {
		assert(true);
	}
	

	RepositoryFile testRepo("Teste.csv");
	Validator testVal;
	ProdStore testService{ testRepo,testVal };
	assert(testService.getAll().size() == 13);

	testService.addProd("Raisa", "Fly Project", "pop", 3.42);
	testService.addProd("Raisa2", "Fly Project", "pop", 3.42);
	testService.addProd("Raisa3", "Fly Project", "pop", 3.42);

	assert(testService.getAll().size() == 16);
	try {
		testService.addProd("Raisa", "Fly Project", "pop", 3.42); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	testService.addProd("Pictures of Home", "Deep Purple", "rock", 1.22);
	assert(true);

	try {
		testService.addProd("", "Deep Purple", "rock", 2.24); assert(false);
	}
	catch (ValidationException& ve) {
		assert(ve.getErrorMessages() == "Numele trebuie sa aiba cel putin 2 caractere.\n");
	}

	try {
		testService.addProd("Smoke on the Water", "", "rock", 2.24); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}

	try {
		testService.addProd("Child in Time", "Deep Purple", "rock", 16000); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
	

	//MODIFICA
	try {
		testService.modProd("Raisa8", "Fly Project", "pop", 3.42); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	testService.modProd("Lapte11", "Deep Purple", "rock", 1.22);
	assert(true);

	try {
		testService.modProd("Lapte8", "", "rock", 2.24); assert(false);
	}
	catch (ValidationException& ve) {
		assert(ve.getErrorMessages() == "Tipul trebuie sa aiba cel putin 2 caractere.\n");
	}

	testService.modProd("Lapte11", "mmm", "", 2.24); assert(true);


	try {
		testService.modProd("Lapte6", "Deep Purple", "rock", 16000); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}

	//STERGE

testService.delProd("Pictures of Home");
	assert(true);
	testService.delProd("Raisa");
	assert(true);
	testService.delProd("Raisa2");
	assert(true);
	testService.delProd("Raisa3");
	assert(true);


	try {
		testService.delProd("Raisa"); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	
	assert(testService.getAll().size() == 13);



}


void testFilterService() {
	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Pasarea Calandrinon", "Phoenix", "folk-rock", 3.42);
	testService.addProd("Baba Novak", "Phoenix", "folk-rock", 8.31);
	testService.addProd("Apocalipsa", "Phoenix", "folk-rock", 5.27);
	testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);

	vector<Mag> melodiiFolkRock = testService.filtrareP("folk-rock");
	assert(melodiiFolkRock.size() == 3);
	vector<Mag> melodiiHeavyMetal = testService.filtrareP("heavy metal");
	assert(melodiiHeavyMetal.size() == 0);

	vector<Mag> melodiiFolkRock1 = testService.filtrareN("Pasarea Calandrinon");
	assert(melodiiFolkRock1.size() == 1);
	vector<Mag> melodiiHeavyMetal1 = testService.filtrareN("heavy metal");
	assert(melodiiHeavyMetal1.size() == 0);


	vector<Mag> melodii1 = testService.filtrarePret(2.15, 3.44);
	assert(melodii1.size() == 2);
	vector<Mag> melodii2 = testService.filtrarePret(9, 10);
	assert(melodii2.size() == 0);

}

void testSortService() {

	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Pasarea Calandrinon", "Phoenix", "folk-rock", 3.42);
	testService.addProd("Baba Novak", "Phoenix", "folk-rock", 8.31);
	testService.addProd("Apocalipsa", "Phoenix", "folk-rock", 5.27);
	testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);


	vector<Mag> sortedByDurata = testService.sortByP();
	assert(sortedByDurata[0].getnume() == "Padure Verde");
	assert(sortedByDurata[1].getnume() == "Pasarea Calandrinon");
	assert(sortedByDurata[2].getnume() == "Ploile Nu Vin");
	assert(sortedByDurata[5].getnume() == "Baba Novak");

	vector<Mag> sortedByArtistSong = testService.sortByNT();

	assert(sortedByArtistSong[0].gettip() == "Alternosfera");
	assert(sortedByArtistSong[0].getnume() == "Fantanile");

	assert(sortedByArtistSong[2].gettip() == "Phoenix");
	assert(sortedByArtistSong[2].getnume() == "Apocalipsa");

	assert(sortedByArtistSong[5].gettip() == "Via Daca");
	assert(sortedByArtistSong[5].getnume() == "Padure Verde");

	vector<Mag> sortedByArtistSong1 = testService.sortByN();



	assert(sortedByArtistSong1[0].gettip() == "Phoenix");
	assert(sortedByArtistSong1[0].getnume() == "Apocalipsa");

	assert(sortedByArtistSong1[5].gettip() == "Alternosfera");
	assert(sortedByArtistSong1[5].getnume() == "Ploile Nu Vin");

	assert(sortedByArtistSong1[2].gettip() == "Alternosfera");
	assert(sortedByArtistSong1[2].getnume() == "Fantanile");


	//testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	//testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	//testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);
}



void testModService() {

	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Pasarea Calandrinon", "Phoenix", "folk-rock", 3.42);
	testService.addProd("Baba Novak", "Phoenix", "folk-rock", 8.31);
	testService.addProd("Apocalipsa", "Phoenix", "folk-rock", 5.27);
	testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);

	assert(testService.getAll().size() == 6);
	try {
		testService.modProd("Raisa", "Fly Project", "pop", 3.42); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	testService.modProd("Ploile Nu Vin", "Deep Purple", "rock", 1.22);
	assert(true);

	try {
		testService.modProd("Ploile Nu Vin", "", "rock", 2.24); assert(false);
	}
	catch (ValidationException& ve) {
		assert(ve.getErrorMessages() == "Tipul trebuie sa aiba cel putin 2 caractere.\n");
	}

	testService.modProd("Ploile Nu Vin", "mmm", "", 2.24); assert(true);


	try {
		testService.modProd("Apocalipsa", "Deep Purple", "rock", 16000); assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
}




void testFindService() {

	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Pasarea Calandrinon", "Phoenix", "folk-rock", 3.42);
	testService.addProd("Baba Novak", "Phoenix", "folk-rock", 8.31);
	testService.addProd("Apocalipsa", "Phoenix", "folk-rock", 5.27);
	testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);

	/**/
	assert(testService.getAll().size() == 6);
	try {
		testService.findProd("Raisa");
	}
	catch (RepoException&) {
		assert(true);
	}

	Mag v = testService.findProd("Ploile Nu Vin");
	assert(v.getpret() == 3.45);



}



void testDelService() {

	Repository testRepo;
	Validator testVal;
	ProdStore testService{ testRepo,testVal };

	testService.addProd("Pasarea Calandrinon", "Phoenix", "folk-rock", 3.42);
	testService.addProd("Baba Novak", "Phoenix", "folk-rock", 8.31);
	testService.addProd("Apocalipsa", "Phoenix", "folk-rock", 5.27);
	testService.addProd("Fantanile", "Alternosfera", "alternative rock", 4.52);
	testService.addProd("Ploile Nu Vin", "Alternosfera", "alternative rock", 3.45);
	testService.addProd("Padure Verde", "Via Daca", "maybe folk", 3.2);

	assert(testService.getAll().size() == 6);
	try {
		testService.delProd("Raisa"); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	testService.delProd("Ploile Nu Vin");
	assert(true);
	assert(testService.getAll().size() == 5);
}


void testCOS() {
	Repository testRepo;
	Validator testVal;
	ProdStore srv{ testRepo,testVal };

	srv.addProd("Suc", "Aliment", "folk-rock", 4.20);
	srv.addProd("Cascaval", "Aliment", "acoustic", 2.51);
	srv.addProd("Biscuiti", "Aliment", "acoustic", 5.11);
	srv.addProd("Fusta", "Haine", "rock", 40.31);
	srv.addProd("Rochie", "Haine", "folk-rock", 70.20);
	srv.addProd("Pantaloni", "Haine", "rock", 80.51);
	srv.addProd("Tricou", "Haine", "acoustic", 50.11);
	srv.addProd("Masina de spalat", "Electrocasnice", "Altex ", 400.31);
	srv.addProd("Mixer", "Electrocasnice", "Altex ", 100.20);
	srv.addProd("Aspirator", "Electrocasnice", "Altex acoustic", 229.51);
	srv.addProd("Frigider", "Electrocasnice", "Altex acoustic", 599.11);

	srv.addRandomCOS(4);
	assert(srv.getCOS().size() == 4);
	srv.emptyCOS();
	assert(srv.getCOS().size() == 0);

	srv.addRandomCOS(20);
	
	assert(srv.getCOS().size() == 11);

	srv.emptyCOS();
	srv.addCOS("Aspirator");
	assert(srv.getCOS().size() == 1);

	try {
		srv.addCOS("Cocosii Negri");
		//assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}


}


void testRaport() {
	Repository testRepo;
	Validator testVal;
	ProdStore srv{ testRepo,testVal };

	srv.addProd("Suc", "Aliment", "folk-rock", 4.20);
	srv.addProd("Cascaval", "Aliment", "acoustic", 2.51);
	srv.addProd("Biscuiti", "Aliment", "acoustic", 5.11);
	srv.addProd("Fusta", "Haine", "rock", 40.31);
	srv.addProd("Rochie", "Haine", "folk-rock", 70.20);
	srv.addProd("Pantaloni", "Haine", "rock", 80.51);
	srv.addProd("Tricou", "Haine", "acoustic", 50.11);
	srv.addProd("Masina de spalat", "Electrocasnice", "Altex ", 400.31);
	srv.addProd("Mixer", "Electrocasnice", "Altex ", 100.20);
	srv.addProd("Aspirator", "Electrocasnice", "Altex acoustic", 229.51);
	srv.addProd("Frigider", "Electrocasnice", "Altex acoustic", 599.11);
	
	
	map<string, DTO> map = srv.raport();
	std::map<std::string, DTO>::iterator it = map.begin();

	assert(it->first == "Aliment");
	assert(it->second.getcount() == 3);
	assert(it->second.gettip() == "Aliment");
		
	it++;
	assert(it->first == "Electrocasnice");
	assert(it->second.getcount() == 4);
	assert(it->second.gettip() == "Electrocasnice");

	it++;
	assert(it->first == "Haine");
	assert(it->second.getcount() == 4);
	assert(it->second.gettip() == "Haine");


}


void testUNDO() {
	Repository testRepo;
	Validator testVal;
	ProdStore srv{ testRepo,testVal };

	

	try
	{
		srv.storeUndo();
	}
	catch (RepoException&) {
		assert(true);
	}

	srv.addProd("Cascaval", "Aliment", "acoustic", 2.51);
	srv.addProd("Biscuiti", "Aliment", "acoustic", 5.11);
	srv.addProd("Fusta", "Haine", "rock", 40.31);
	srv.addProd("Rochie", "Haine", "folk-rock", 70.20);
	srv.addProd("Pantaloni", "Haine", "rock", 80.51);
	srv.addProd("Tricou", "Haine", "acoustic", 50.11);
	srv.addProd("Masina de spalat", "Electrocasnice", "Altex ", 400.31);
	srv.addProd("Mixer", "Electrocasnice", "Altex ", 100.20);
	srv.addProd("Aspirator", "Electrocasnice", "Altex acoustic", 229.51);
	srv.addProd("Frigider", "Electrocasnice", "Altex acoustic", 599.11);

	assert(srv.getAll().size() == 10);
	srv.storeUndo();
	assert(srv.getAll().size() == 9);
	srv.modProd("Mixer", "11", "11", 100.20);
	assert(srv.findProd("Mixer").getprod() == "11");
	srv.storeUndo();
	assert(srv.findProd("Mixer").getprod() == "Altex ");
	assert(srv.getAll().size() == 9);
	srv.delProd("Mixer");
	assert(srv.getAll().size() == 8);
	srv.storeUndo();
	assert(srv.getAll().size() == 9);


}

void testeService() {
	testAddService();
	testModService();
	testDelService();
	testFILE();
	
	testFindService();
	testFilterService();
	testSortService();
	testCOS();
	testRaport();
	testUNDO();
}