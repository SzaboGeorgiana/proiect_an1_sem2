#include "dto.h"
#include <assert.h>

string DTO::gettip() const {
	return this->tip;
}
int DTO::getcount()  const noexcept {
	return this->count;
}

void DTO::settip(string tipNou) {
	this->tip = tipNou;
}
void DTO::setcount(int pretNoua) noexcept {
	this->count = pretNoua;
}

void testGetSet1() {
	DTO song1{ "a", 8};

	assert(song1.gettip() == "a");
	
	assert(song1.getcount() == 8);

	

	song1.settip("a");
	
	song1.setcount(5);
	assert(song1.gettip() == "a");

	assert(song1.getcount() == 5);




}

void testeDomain1() {
	testGetSet1();
}