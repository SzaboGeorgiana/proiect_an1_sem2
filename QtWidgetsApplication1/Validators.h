#pragma once
#pragma once

#include "Magazin.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
class ValidationException {
	vector<string> errorMsg;
public:
	ValidationException(vector<string> errorMessages) :errorMsg{ errorMessages } {};

	string getErrorMessages() {
		string fullMsg = "";
		for (const string e : errorMsg) {
			fullMsg += e + "\n";
		}
		return fullMsg;
	}
};
/*
Clasa pentru validarea prod
O melodie este valida daca:
	are numele format din mai mult de 2 caractere
	are tipul format din mai mult de 2 caractere
	pretul prod este intre 1 si 15000;

*/
class Validator {

public:
	void valideaza(const Mag& m) {
		vector<string> errors;
		if (m.getnume().length() < 2)
			errors.push_back("Numele trebuie sa aiba cel putin 2 caractere.");
		if (m.gettip().length() < 2)
			errors.push_back("Tipul trebuie sa aiba cel putin 2 caractere.");
		if (m.getpret() < 0 || m.getpret() > 15000)
			errors.push_back("Pretul trebuie sa fie intre 0 si 15000.");

		if (errors.size() > 0)
			throw ValidationException(errors);
	}
};
