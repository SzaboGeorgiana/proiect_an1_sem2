//#include "MagGUI.h"
//
//void MagGUI::initializeGUIComponents() {
//
//	//impartim fereastra in 2: in stanga, butoane+labels+qlineedits
//	//iar in dreapta: tabelul cu melodii
//
//	//"stanga" si "dreapta" pentru ca este QHBoxLayout
//	//se adauga componente incepand din stanga, pe orizontala
//	//aici: "left" component, then "right" component
//	//care la randul lor contin alte componente
//
//	//main layout
//	QHBoxLayout* lyMain = new QHBoxLayout;
//	this->setLayout(lyMain);
//
//
//	//left part of the window
//	//pentru aceasta parte setam layout vertical
//	QWidget* left = new QWidget;
//	QVBoxLayout* lyLeft = new QVBoxLayout;
//	left->setLayout(lyLeft);
//
//	//componente pentru functionalitatea de adaugare a unei melodii
//	//folosim un QFormLayout pentru detaliile de adaugare a unei melodii
//	QWidget* form = new QWidget;
//	QFormLayout* lyForm = new QFormLayout;
//	form->setLayout(lyForm);
//	editTitlu = new QLineEdit;
//	editArtist = new QLineEdit;
//	editGen = new QLineEdit;
//	editDurata = new QLineEdit;
//
//	lyForm->addRow(lblTitlu, editTitlu);
//	lyForm->addRow(lblArtist, editArtist);
//	lyForm->addRow(lblGen, editGen);
//	lyForm->addRow(lblDurata, editDurata);
//	btnAddSong = new QPushButton("Adauga produs");
//	lyForm->addWidget(btnAddSong);
//
//	btnModSong = new QPushButton("Modifica produs");
//	lyForm->addWidget(btnModSong);
//
//	btnDelSong = new QPushButton("Sterge produs");
//	lyForm->addWidget(btnDelSong);
//
//	btnFindSong = new QPushButton("Cauta produs");
//	lyForm->addWidget(btnFindSong);
//
//	//adaugam toate componentele legate de adaugare melodie
//	//in layout-ul care corespunde partii din stanga a ferestrei
//	lyLeft->addWidget(form);
//
//
//	//Radio Buttons: ne ajuta cand trebuie sa selectam doar o 
//	//optiune din mai multe (doar un RadioButton poate fi selectat
//	//la un moment dat)
//
//
//	//vs. CheckBox (see documentation)
//	//also see documentation on QGroupBox, QRadioButton pentru detalii
//
//	//cream un GroupBox pentru radiobuttons care corespund 
//	//criteriilor de sortare pe care le avem (dupa artist+titlu 
//	//si durata) + butonul de sortare
//
//	QVBoxLayout* lyRadioBox = new QVBoxLayout;
//	this->groupBox->setLayout(lyRadioBox);
//	lyRadioBox->addWidget(radioSrtArtistTitlu);
//	lyRadioBox->addWidget(radioSrtDurata);
//	lyRadioBox->addWidget(radioSrtNume);
//
//	btnSortSongs = new QPushButton("Sorteaza produse");
//	lyRadioBox->addWidget(btnSortSongs);
//
//	//adaugam acest grup in partea stanga, 
//	//dupa componentele pentru adaugare in layout-ul vertical
//	lyLeft->addWidget(groupBox);
//
//	//cream un form pentru filtrarea dupa gen 
//	QWidget* formFilter = new QWidget;
//	QFormLayout* lyFormFilter = new QFormLayout;
//	formFilter->setLayout(lyFormFilter);
//	editFilterGen = new QLineEdit();
//	lyFormFilter->addRow(lblFilterCriteria, editFilterGen);
//	btnFilterSongs = new QPushButton("Filtreaza produse dupa producator");
//	lyFormFilter->addWidget(btnFilterSongs);
//
//	editFilterNume = new QLineEdit();
//	lyFormFilter->addRow(lblFilterCriteriaN, editFilterNume);
//	btnFilterSongsN = new QPushButton("Filtreaza produse dupa nume");
//	lyFormFilter->addWidget(btnFilterSongsN);
//
//	editFilterPretINC = new QLineEdit();
//	lyFormFilter->addRow(lblFilterCriteriaPinc, editFilterPretINC);
//	editFilterPretSF = new QLineEdit();
//	lyFormFilter->addRow(lblFilterCriteriaPfin, editFilterPretSF);
//	btnFilterSongsP = new QPushButton("Filtreaza produse dupa pret");
//	lyFormFilter->addWidget(btnFilterSongsP);
//	
//	lyLeft->addWidget(formFilter);
//
//	//Buton folosit pentru a reincarca datele
//	//i.e. afisam toate melodiile in tabel, in ordinea initiala din fisier
//	btnReloadData = new QPushButton("Reload data");
//	lyLeft->addWidget(btnReloadData);
//
//	btnUndoData = new QPushButton("Undo");
//	lyLeft->addWidget(btnUndoData);
//
//
//	btnSpreCos = new QPushButton("Cos de cumparaturi");
//	lyLeft->addWidget(btnSpreCos);
//
//	//componenta right - contine doar tabelul cu melodii
//	QWidget* right = new QWidget;
//	QHBoxLayout* lyRight = new QHBoxLayout;
//	right->setLayout(lyRight);
//
//	int noLines = 10;
//	int noColumns = 4;
//	this->tableSongs = new QTableWidget{ noLines, noColumns };
//	//string nume, string tip, string prod, double pret
//	//setam header-ul tabelului
//	QStringList tblHeaderList;
//	tblHeaderList << "Nume" << "Tip" << "Producator" << "Pret";
//	this->tableSongs->setHorizontalHeaderLabels(tblHeaderList);
//
//	//optiune pentru a se redimensiona celulele din tabel in functie de continut
//	this->tableSongs->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//
//
//	lyRight->addWidget(tableSongs);
//
//	lyRight->addLayout(buttonTip);
//
//	lyMain->addWidget(left);
//	lyMain->addWidget(right);
//
//}
//void MagGUI::reloadSongList(vector<Mag> songs) {
//	this->tableSongs->clearContents();
//	this->tableSongs->setRowCount(songs.size());
//
//	int lineNumber = 0;
//	for (auto& song : songs) {
//		this->tableSongs->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(song.getnume())));
//		this->tableSongs->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(song.gettip())));
//		this->tableSongs->setItem(lineNumber, 2, new QTableWidgetItem(QString::fromStdString(song.getprod())));
//		this->tableSongs->setItem(lineNumber, 3, new QTableWidgetItem(QString::number(song.getpret())));
//		lineNumber++;
//	}
//}
//
//void MagGUI::connectSignalsSlots() {
//	QObject::connect(btnAddSong, &QPushButton::clicked, this, &MagGUI::guiAddSong);
//
//	QObject::connect(btnModSong, &QPushButton::clicked, this, &MagGUI::guiModSong);
//
//	QObject::connect(btnDelSong, &QPushButton::clicked, this, &MagGUI::guiDelSong);
//
//	QObject::connect(btnFindSong, &QPushButton::clicked, this, &MagGUI::guiFindSong);
//
//	QObject::connect(btnSortSongs, &QPushButton::clicked, [&]() {
//		if (this->radioSrtArtistTitlu->isChecked())
//			this->reloadSongList(srv.sortByNT());
//		else if (this->radioSrtDurata->isChecked())
//			this->reloadSongList(srv.sortByP());
//		else if (this->radioSrtNume->isChecked())
//			this->reloadSongList(srv.sortByN());
//		});
//
//	QObject::connect(btnFilterSongs, &QPushButton::clicked, [&]() {
//		string filterC = this->editFilterGen->text().toStdString();
//		this->reloadSongList(srv.filtrareP(filterC));
//		});
//
//
//	QObject::connect(btnFilterSongsN, &QPushButton::clicked, [&]() {
//		string filterC = this->editFilterNume->text().toStdString();
//		this->reloadSongList(srv.filtrareN(filterC));
//		});
//
//
//	QObject::connect(btnFilterSongsP, &QPushButton::clicked, [&]() {
//		double filterC = this->editFilterPretINC->text().toDouble();
//		double filterC1 = this->editFilterPretSF->text().toDouble();
//
//		this->reloadSongList(srv.filtrarePret(filterC, filterC1));
//		});
//
//	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
//		this->reloadSongList(srv.getAll());
//		});
//
//	QObject::connect(btnUndoData, &QPushButton::clicked, [&]() {
//		try {
//			srv.storeUndo();
//			this->reloadSongList(srv.getAll());
//		}
//		catch (RepoException& re) {
//			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//		}
//		});
//
//	QObject::connect(btnSpreCos, &QPushButton::clicked, [&]() {
//		/*RepositoryFile repo("Fisier.csv");
//		Validator val;
//		ProdStore srv{ repo,val };*/
//		
//	//	auto gui1 = new CosGUI(srv);
//		playlistWindow.show();
//		//return a.exec();
//		});
//
//}
//
//
//void MagGUI::guiAddSong() {
//	try {
//		clearLayout(buttonTip);
//		//preluare detalii din QLineEdit-uri
//		//string nume, string tip, string prod, double pret
//		string titlu = editTitlu->text().toStdString();
//		string artist = editArtist->text().toStdString();
//		string gen = editGen->text().toStdString();
//		double durata = editDurata->text().toDouble();
//
//		//optional - golim QLineEdit-urile dupa apasarea butonului
//		editTitlu->clear();
//		editArtist->clear();
//		editGen->clear();
//		editDurata->clear();
//
//		this->srv.addProd(titlu, artist, gen, durata);
//		this->reloadSongList(this->srv.getAll());
//
//		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
//		QMessageBox::information(this, "Info", QString::fromStdString("Produs adaugat cu succes."));
//		generateButton(srv.raport());
//	}
//	catch (RepoException& re) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//	}
//	catch (ValidationException& ve) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
//	}
//}
//
//void MagGUI::generateButton(std::map<string, DTO> map)
//{
//	for(auto m: map)
//	{
//		auto btn = new QPushButton{ QString::fromStdString(m.second.gettip()) };
//		int nr = m.second.getcount();
//		
//		this->buttonTip->addWidget(btn);
//		QObject::connect(btn, &QPushButton::clicked, [this, btn, nr]() {
//			QMessageBox::information(nullptr, "Info", QString::number(nr));
//			});
//	}
//}
//
//
//void MagGUI::guiModSong() {
//	try {
//		clearLayout(buttonTip);
//		//preluare detalii din QLineEdit-uri
//		//string nume, string tip, string prod, double pret
//		string titlu = editTitlu->text().toStdString();
//		string artist = editArtist->text().toStdString();
//		string gen = editGen->text().toStdString();
//		double durata = editDurata->text().toDouble();
//
//		//optional - golim QLineEdit-urile dupa apasarea butonului
//		editTitlu->clear();
//		editArtist->clear();
//		editGen->clear();
//		editDurata->clear();
//
//		this->srv.modProd(titlu, artist, gen, durata);
//		this->reloadSongList(this->srv.getAll());
//
//		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
//		QMessageBox::information(this, "Info", QString::fromStdString("Produs modificat cu succes."));
//		generateButton(srv.raport());
//	}
//	catch (RepoException& re) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//	}
//	catch (ValidationException& ve) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
//	}
//}
//
//
//void MagGUI::guiDelSong() {
//	try {
//		clearLayout(buttonTip);
//		//preluare detalii din QLineEdit-uri
//		//string nume, string tip, string prod, double pret
//		string titlu = editTitlu->text().toStdString();
//		//string artist = editArtist->text().toStdString();
//		//string gen = editGen->text().toStdString();
//		//double durata = editDurata->text().toDouble();
//
//		//optional - golim QLineEdit-urile dupa apasarea butonului
//		editTitlu->clear();
//		editArtist->clear();
//		editGen->clear();
//		editDurata->clear();
//
//		this->srv.delProd(titlu);
//		this->reloadSongList(this->srv.getAll());
//
//		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
//		QMessageBox::information(this, "Info", QString::fromStdString("Produs sters cu succes."));
//		generateButton(srv.raport());
//	}
//	catch (RepoException& re) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//	}
//	catch (ValidationException& ve) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
//	}
//}
//
//#include <string>
//void MagGUI::guiFindSong() {
//	try {
//		clearLayout(buttonTip);
//		//preluare detalii din QLineEdit-uri
//		//string nume, string tip, string prod, double pret
//		string titlu = editTitlu->text().toStdString();
//		//string artist = editArtist->text().toStdString();
//		//string gen = editGen->text().toStdString();
//		//double durata = editDurata->text().toDouble();
//
//		//optional - golim QLineEdit-urile dupa apasarea butonului
//		editTitlu->clear();
//		editArtist->clear();
//		editGen->clear();
//		editDurata->clear();
//
//		Mag gasit=this->srv.findProd(titlu);
//
//		QString str = QString::fromUtf8(gasit.getnume().c_str());
//		editTitlu->setText(str);
//		//editTitlu->text()= gasit.getnume();
//		QString str1 = QString::fromUtf8(gasit.gettip().c_str());
//		editArtist->setText(str1);
//		//editArtist->text() = gasit.gettip();
//		QString str2 = QString::fromUtf8(gasit.getprod().c_str());
//		editGen->setText(str2);
//		//editGen->text() = gasit.getprod();
//		string str4 = std::to_string(gasit.getpret());
//		QString str3 = QString::fromUtf8(str4.c_str());
//		editDurata->setText(str3);
//		//editDurata->text() = gasit.getpret();
//
//		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
//		QMessageBox::information(this, "Info", QString::fromStdString("Produs gasit."));
//		generateButton(srv.raport());
//	}
//	catch (RepoException& re) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//	}
//	catch (ValidationException& ve) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
//	}
//}