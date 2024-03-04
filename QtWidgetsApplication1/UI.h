#pragma once
#pragma once
#include "Service.h"
//#include "undo.h"

class ConsoleUI {

	ProdStore& srv;
	void printMenu();
	void printCosMenu();
	void uiAdd();
	void uiSort();
	void uiFilter();
	void addDefaultSongs();
	void print(const vector<Mag>& all);
	void uiMod();
	void uiFind();
	void uiDel();
	void uiCos();
	void uiAddCOS();
	void uiAddRandomCOS();
	void uiEmptyCOS();
	void uiExportCOS();
	void uipretCOS();
	void uiRaport();
	void uiUndo();

public:

	ConsoleUI(ProdStore& srv)noexcept :srv{ srv } {};
	ConsoleUI(const ConsoleUI& ot) = delete;

	void run();
};
