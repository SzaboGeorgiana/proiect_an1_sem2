#pragma once

/*1 Magazin
Creați o aplicație care permite:
· gestiunea unei liste de produse.
Produs: nume, tip, preț, producător
· adăugare, ștergere, modificare și afișare produse
· căutare produs
· filtrare produse după: preț, nume, producător
· sortare produse după: nume, preț, nume + tip  */


#include "dto.h"
#include "UI.h"
#include <iostream>
using namespace std;
void ConsoleUI::printMenu() {
	cout << "Comenzi disponibile:" << endl;
	cout << "1. Adauga produs" << endl;
	cout << "2. Filtreaza produs" << endl;
	cout << "3. Sorteaza produs" << endl;
	cout << "4. Afiseaza toate produsele" << endl;
	cout << "5. Cauta produs" << endl;
	cout << "6. Modifica produs" << endl;
	cout << "7. Sterge produs" << endl;
	cout << "8. Cos de cumparaturi" << endl;
	cout << "9. Raport (cate produse de fiecare tip exista)" << endl;
	cout << "10. Undo" << endl;
	cout << "11. Exit" << endl;
}



void ConsoleUI::printCosMenu() {
	cout << "MENIU COS DE CUMPARATURI" << endl;
	cout << "1. Adauga produs(dupa nume) in cos" << endl;
	cout << "2. Adauga produse random in cos (genereaza cos)" << endl;
	cout << "3. Goleste cos" << endl;
	cout << "4. Afiseaza cosul curent" << endl;
	cout << "5. Export. " << endl;
	cout << "6. Inapoi la meniul principal" << endl;
}

void ConsoleUI::uiAdd() {
	string nume, tip, prod;
	double pret;
	cout << "Numele produsului este:";
	getline(cin >> ws, nume);

	cout << "Tipul produsului este:";
	getline(cin >> ws, tip);
	cout << "Producatorul produsului este:";
	getline(cin >> ws, prod);

	cout << "Pretul produsului este:";
	cin >> pret;
	try {
		srv.addProd(nume, tip, prod, pret);
	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}
	catch (ValidationException& ve) {
		cout << "Produsul nu este valid!" << endl;
		cout << ve.getErrorMessages();
	}

}


void ConsoleUI::uiMod() {
	string nume, tip, prod;
	double pret;
	cout << "Numele produsului care se modifica este:";
	getline(cin >> ws, nume);

	cout << "Tipul nou al produsului este:";
	getline(cin >> ws, tip);
	cout << "Producatorul nou al produsului este:";
	getline(cin >> ws, prod);

	cout << "Pretul nou al produsului este:";
	cin >> pret;
	try {
		srv.modProd(nume, tip, prod, pret);
	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}
	catch (ValidationException& ve) {
		cout << "Produsul nu este valid!" << endl;
		cout << ve.getErrorMessages();
	}

}

void ConsoleUI::uiFind() {
	string nume;
	cout << "Numele produsului care se cauta este:";
	getline(cin >> ws, nume);

	try {
		Mag mag = srv.findProd(nume);
		cout << "Nume: " << mag.getnume() << " | Tip: " << mag.gettip() << " | Producator: " << mag.getprod() << " | Pret: " << mag.getpret() << endl;
	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}

}

void ConsoleUI::uiDel() {
	string nume;
	cout << "Numele produsului care se sterge este:";
	getline(cin >> ws, nume);

	try {
		srv.delProd(nume);

	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}

}
void ConsoleUI::uiSort() {
	cout << "Criteriul de sortare este ( nume/ pret/ nume+tip  ):";
	string criteriu;
	cin >> criteriu;

	if (criteriu == "nume")
		print(srv.sortByN());
	else if (criteriu == "pret")
		print(srv.sortByP());
	else if (criteriu == "nume+tip")
		print(srv.sortByNT());
	else
		cout << "Nu se poate sorta dupa criteriul dat." << endl;

}

void ConsoleUI::uiFilter() {
	cout << "Criteriul de filtrare este (pret/ nume/ producator ):";
	string criteriu;
	cin >> criteriu;

	if (criteriu == "nume") {
		cout << "Numele pentru care se afiseaza:" << endl;
		string searched;
		cin >> searched;
		print(srv.filtrareN(searched));
	}
	else if (criteriu == "pret") {
		double durataStart, durataEnd;
		cout << "Limita inferioara a pretului:" << endl;
		cin >> durataStart;
		cout << "Limita superioara a pretului:" << endl;
		cin >> durataEnd;

		print(srv.filtrarePret(durataStart, durataEnd));
	}
	else if (criteriu == "producator") {
		cout << "Numele producatorului pentru care se afiseaza:" << endl;
		string searched;
		cin >> searched;
		print(srv.filtrareP(searched));
	}

	else
		cout << "Nu se poate sorta dupa criteriul dat." << endl;
}

void ConsoleUI::print(const vector<Mag>& all) {

	if (all.size() == 0)
		cout << "Nu exista produse." << endl;
	else
		for (const auto& mag : all) {
			cout << "Nume: " << mag.getnume() << " | Tip: " << mag.gettip() << " | Producator: " << mag.getprod() << " | Pret: " << mag.getpret() << endl;
		}
}


void ConsoleUI::uiRaport() {
	map<string, DTO> map; map=srv.raport();
	std::map<std::string, DTO>::iterator it = map.begin();
	while (it != map.end())
	{
		cout << "key " << it->first << ", Value: ";
		cout << "Tip:  " << it->second.gettip() << "  Count:  " << it->second.getcount() << endl;
		it++;
	}
}

/**/
void ConsoleUI::addDefaultSongs() {
	srv.addProd("Lapte", "Aliment", "rock", 5.3);
	srv.addProd("Oua", "Aliment", "indie rock", 3.32);
	srv.addProd("Carne", "Aliment", "indie rock", 13.48);
	srv.addProd("Paine", "Aliment", "indie rock", 4.21);
	srv.addProd("Apa", "Aliment", "rock", 1.31);
	srv.addProd("Suc", "Aliment", "folk-rock", 4.20);
	srv.addProd("Cascaval", "Aliment","acoustic", 2.51);
	srv.addProd("Biscuiti", "Aliment", "acoustic", 5.11);
	srv.addProd("Fusta", "Haine", "rock", 40.31);
	srv.addProd("Rochie", "Haine", "folk-rock", 70.20);
	srv.addProd("Pantaloni", "Haine","rock", 80.51);
	srv.addProd("Tricou", "Haine", "acoustic", 50.11);
	srv.addProd("Masina de spalat", "Electrocasnice", "Altex ", 400.31);
	srv.addProd("Mixer", "Electrocasnice", "Altex ", 100.20);
	srv.addProd("Aspirator", "Electrocasnice","Altex acoustic", 229.51);
	srv.addProd("Frigider", "Electrocasnice", "Altex acoustic", 599.11);
}



void ConsoleUI::uiAddCOS() {
	string titlu;
	cout << "Numele produsului este:";
	getline(cin >> ws, titlu);

	try {
		srv.addCOS(titlu);
		cout << "Produsul s-a adaugat cu succes in cos." << endl;
	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}
	catch (ValidationException& ve) {
		cout << "Produsul nu este valid!" << endl;
		cout << ve.getErrorMessages();
	}
}
void ConsoleUI::uiAddRandomCOS() {
	int howManyToAdd;
	cout << "Cate produse sa se adauge in cos?";
	cin >> howManyToAdd;


	try {
		const int howManyAdded = srv.addRandomCOS(howManyToAdd);
		cout << "S-au adaugat " << howManyAdded << " produse in cos." << endl;
	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}
}


void ConsoleUI::uiEmptyCOS() {
	srv.emptyCOS();
	cout << "S-au sters toate produsele din cosul curent." << endl;
}

#include <fstream>


void ConsoleUI::uiExportCOS() {
	const vector<Mag> m = srv.getCOS();
	string titlu;
	cout << "Numele fisierului este:";
	getline(cin >> ws, titlu);
	
	if (m.size() != 0)
		if (titlu.size() != 0)
		{
			ofstream fout(titlu);
			for (const auto& mag : m) {
				fout << "Nume: " << mag.getnume() << " | Tip: " << mag.gettip() << " | Producator: " << mag.getprod() << " | Pret: " << mag.getpret() << "\n";
			}

		}
		else
			cout << "Numele fisierului nu e valid.\n" << endl;
	else
		cout << "Cosul nu exista.\n";
}
void ConsoleUI::uipretCOS() {
	const vector<Mag> m = srv.getCOS();
	double suma=0;
	if (m.size() != 0)
	{
			for (const auto& mag : m) {
				 suma+=mag.getpret() ;
			}
			cout << "Suma din cos e: " << suma << endl;
 }
		
	else
		cout << "Cosul nu exista inca.\n";
}




void ConsoleUI::uiUndo() {
	try {
		srv.storeUndo();

	}
	catch (RepoException& re) {
		cout << re.getErrorMessage();
	}

	

}







void ConsoleUI::uiCos() {
	int cmd;
	int runningCump = 1;
	while (runningCump) {
		printCosMenu();
		uipretCOS();
		cout << "Comanda este:";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			uiAddCOS();
			break;
		case 2:
			uiAddRandomCOS();
			break;
		case 3:
			uiEmptyCOS();
			break;

		case 4:
			print(srv.getCOS());
			break;

		case 5:
			uiExportCOS();
			break;

		case 6:
			runningCump = 0;
			break;
		default:
			break;
		}

	}
}



void ConsoleUI::run() {
//	addDefaultSongs();
	int running = 1;
	int cmd;
	//	addDefaultSongs();
	while (running) {
		printMenu();
		cout << "Comanda este:";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			uiAdd();
			break;
		case 2:
			uiFilter();
			break;
		case 3:
			uiSort();
			break;
		case 4:
			print(srv.getAll());
			break;
		case 5:
			uiFind();
			break;
		case 6:
			uiMod();
			break;
		case 7:
			uiDel();
			break;
		case 8:
			uiCos();
			break;
		case 9:
			uiRaport();
			break;
		case 10:
			uiUndo();
			break;

		case 11:
			running = 0;
			break;
		default:
			break;
		}

	}
}