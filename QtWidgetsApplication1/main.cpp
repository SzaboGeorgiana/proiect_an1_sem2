#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QtWidgetsApplication1 w;
//    w.show();
//    return a.exec();
//}

#include "dto.h"
#define _CRTDBG_MAP_ALLOC
#include "MagModelGUI.h"
#include "CosGUI.h"

#include <stdlib.h>
#include <crtdbg.h>
#include "UI.h"
#include <iostream>
using std::cout;
using std::endl;
void testAll() {
	testeDomain();
	testeDomain1();
	cout << "Finished domain tests." << endl;
	testeRepo();
	cout << "Finished repo tests." << endl;
	testeService();
	cout << "Finished service tests." << endl;


}


int main(int argc, char* argv[])
{
	testAll();
	QApplication a(argc, argv);
	//SongRepository repo;
	RepositoryFile repo("Fisier.csv");
	Validator val;
	ProdStore srv{ repo,val };
	//ConsoleUI ui{ srv };
	//ui.run();
	MagGUI gui1{ srv };

	//gui.setWindowState(Qt::WindowMaximized);

	gui1.show();
	return a.exec();

//	CosGUI gui{ srv };

	//gui.setWindowState(Qt::WindowMaximized);

	//gui.show();
//	return a.exec();
}