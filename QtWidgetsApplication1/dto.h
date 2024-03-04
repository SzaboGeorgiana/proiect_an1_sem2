#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class DTO {
private:
	string tip;
	int count;
public:

	DTO() = default;


	DTO( string tip, int count) :tip{tip}, count{count} {};
	/*Mag(const Mag& ot) :nume{ ot.nume }, tip{ ot.tip }, prod{ ot.prod }, pret{ ot.pret } {
		cout << "Copy constructor called.\n";
	}*/

	string gettip() const;
	
	int getcount() const noexcept;

	
	void settip(string tipNou);
	
	void setcount(int pretNoua) noexcept;/**/
};
void testeDomain1();