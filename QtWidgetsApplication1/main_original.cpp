//#include "UI.h"
//#include "dto.h"
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
////#include "VectorDinamicTemplate.h"
//#include <iostream>
//using std::cout;
//using std::endl;
//
//void testAll() {
//
//	testeDomain();
//	testeDomain1();
//	cout << "Finished domain tests." << endl;
//	testeRepo();
//	cout << "Finished repo tests." << endl;
//	testeService();
//	cout << "Finished service tests." << endl;
//
//}
//
///**/
//void startApp() {
//	cout << "1. Pentru citirea datelor din fisier" << endl << "2. Pentru citirea de la tastatura" << endl<<"3. Pentru repoLab\n";
//	cout << "Comanda este:";
//	int cmd;
//	cin >> cmd;
//	if (cmd == 1)
//	{
//
//		RepositoryFile repo("Fisier.csv");
//		Validator val;
//		ProdStore srv{ repo,val };
//		ConsoleUI ui{ srv };
//		ui.run();
//	}
//	else
//		if (cmd == 2)
//		{
//
//			Repository repo;
//			Validator val;
//			ProdStore srv{ repo,val };
//			ConsoleUI ui{ srv };
//			ui.run();
//
//		}/**/
//		else
//
//			if (cmd == 3)
//			{
//
//				RepositoryLab repo(0.5);
//				Validator val;
//				ProdStore srv{ repo,val };
//				ConsoleUI ui{ srv };
//				ui.run();
//
//			}
//				else
//					cout << "optiune invalida";
//	
//}
//
//
//int main() {
//	testAll();
////	startApp();
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//
//
