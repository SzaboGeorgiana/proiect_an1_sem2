//#include "CosGUI.h"
//
//void CosGUI::initializeGUIComponents1() {
//
//	QHBoxLayout* lyMain1 = new QHBoxLayout;
//	this->setLayout(lyMain1);
//
//
//	QWidget* left1 = new QWidget;
//	QVBoxLayout* lyLeft1 = new QVBoxLayout;
//	left1->setLayout(lyLeft1);
//
//	
//	QWidget* form1 = new QWidget;
//	QFormLayout* lyForm1 = new QFormLayout;
//	form1->setLayout(lyForm1);
//	editNume = new QLineEdit;
//
//
//	lyForm1->addRow(lblNume, editNume);
//	btnAddtoCart = new QPushButton("Adauga produs in cos");
//	lyForm1->addWidget(btnAddtoCart);
//	lyLeft1->addWidget(form1);
//	
//	QWidget* form11 = new QWidget;
//	QFormLayout* lyForm11 = new QFormLayout;
//	form11->setLayout(lyForm11);
//	editRandom = new QLineEdit;
//
//
//	lyForm11->addRow(lblRandom, editRandom);
//	btnRandomData = new QPushButton("Adauga produse random in cos");
//	lyForm11->addWidget(btnRandomData);
//	lyLeft1->addWidget(form11);
//
//	QWidget* form1e = new QWidget;
//	QFormLayout* lyForm1e = new QFormLayout;
//	form1e->setLayout(lyForm1e);
//	editExport = new QLineEdit;
//
//
//	lyForm1e->addRow(lblExport, editExport);
//	btnExportData = new QPushButton("Exporta cos in fisier");
//	lyForm1e->addWidget(btnExportData);
//	lyLeft1->addWidget(form1e);
//	
//
//	btnEmptyData = new QPushButton("Goleste cos");
//	lyLeft1->addWidget(btnEmptyData);
//
//	btnReloadData = new QPushButton("Reload data");
//	lyLeft1->addWidget(btnReloadData);
//
//	//componenta right - contine doar tabelul cu melodii
//	QWidget* right1 = new QWidget;
//	QHBoxLayout* lyRight1 = new QHBoxLayout;
//	right1->setLayout(lyRight1);
//
//	int noLines = 10;
//	int noColumns = 4;
//	this->tableCos = new QTableWidget{ noLines, noColumns };
//	//string nume, string tip, string prod, double pret
//	//setam header-ul tabelului
//	QStringList tblHeaderList1;
//	tblHeaderList1 << "Nume" << "Tip" << "Producator" << "Pret";
//	this->tableCos->setHorizontalHeaderLabels(tblHeaderList1);
//
//	//optiune pentru a se redimensiona celulele din tabel in functie de continut
//	this->tableCos->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//
//
//	lyRight1->addWidget(tableCos);
//
//	lyMain1->addWidget(left1);
//	lyMain1->addWidget(right1);
//
//	lst = new QListWidget;
//	lyRight1->addWidget(lst);
//
//
//
//
//	//componenta right - contine doar tabelul cu PROD
//	QWidget* right1p = new QWidget;
//	QHBoxLayout* lyRight1p = new QHBoxLayout;
//	right1p->setLayout(lyRight1p);
//
//	int noLinesp = 10;
//	int noColumnsp = 4;
//	this->tableProd = new QTableWidget{ noLinesp, noColumnsp };
//	//string nume, string tip, string prod, double pret
//	//setam header-ul tabelului
//	QStringList tblHeaderList1p;
//	tblHeaderList1p << "Nume" << "Tip" << "Producator" << "Pret";
//	this->tableProd->setHorizontalHeaderLabels(tblHeaderList1p);
//
//	//optiune pentru a se redimensiona celulele din tabel in functie de continut
//	this->tableProd->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//
//	lyRight1->addWidget(tableProd);
//
//	//lyMain1->addWidget(left1);
//	lyMain1->addWidget(right1p);
//
//}
//
//
//void CosGUI::reloadSongList1(vector<Mag> songs) {
//	this->tableCos->clearContents();
//	this->tableCos->setRowCount(songs.size());
//
//	int lineNumber = 0;
//	for (auto& song : songs) {
//		this->tableCos->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(song.getnume())));
//		this->tableCos->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(song.gettip())));
//		this->tableCos->setItem(lineNumber, 2, new QTableWidgetItem(QString::fromStdString(song.getprod())));
//		this->tableCos->setItem(lineNumber, 3, new QTableWidgetItem(QString::number(song.getpret())));
//		lineNumber++;
//	}
//}
//
//void CosGUI::reloadList(vector<Mag> pets) {
//		lst->clear(); 
//		for (auto& p : pets) {
//			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getnume()), lst);   item->setData(Qt::UserRole, p.getpret());//adaug in lista (invizibil) si type   //lst->addItem(p.getSpecies());
//	} 
//
//} 
//
//
//
//void CosGUI::reloadSongList1p(vector<Mag> songs) {
//	this->tableProd->clearContents();
//	this->tableProd->setRowCount(songs.size());
//
//	int lineNumber = 0;
//	for (auto& song : songs) {
//		this->tableProd->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(song.getnume())));
//		this->tableProd->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(song.gettip())));
//		this->tableProd->setItem(lineNumber, 2, new QTableWidgetItem(QString::fromStdString(song.getprod())));
//		this->tableProd->setItem(lineNumber, 3, new QTableWidgetItem(QString::number(song.getpret())));
//		lineNumber++;
//	}
//}
//
//void CosGUI::connectSignalsSlots1() {
//	QObject::connect(btnAddtoCart, &QPushButton::clicked, this, &CosGUI::guiAddtoCart);
//
//	QObject::connect(btnRandomData, &QPushButton::clicked, [&]() {
//		
//		 string howManyToAdd = editRandom->text().toStdString();
//		
//		editRandom->clear();
//		try {
//			const int howManyAdded = srv.addRandomCOS(stoi(howManyToAdd));
//			QMessageBox::information(this, "Info", QString::fromStdString("S-au adaugat produsele in cos."));
//			reloadSongList1(srv.getCOS());
//			this->reloadList(this->srv.getCOS());
//
//
//		}
//		catch (RepoException& re) {
//			QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//		}
//		
//	});
//
//	
//	
//
//	QObject::connect(btnExportData, &QPushButton::clicked, [&]() {
//		const vector<Mag> m = srv.getCOS();
//		
//		string titlu = editExport->text().toStdString();
//		editExport->clear();
//		if (m.size() != 0)
//			if (titlu.size() != 0)
//			{
//				ofstream fout(titlu);
//				for (const auto& mag : m) {
//					fout << "Nume: " << mag.getnume() << " | Tip: " << mag.gettip() << " | Producator: " << mag.getprod() << " | Pret: " << mag.getpret() << "\n";
//					
//				}
//				QMessageBox::information(this, "Info", QString::fromStdString("S-au exportat cu succes toate produsele din cosul curent."));
//			}
//			else
//				
//				QMessageBox::warning(this, "Warning", QString::fromStdString("Numele fisierului nu e valid."));
//		else
//			QMessageBox::warning(this, "Warning", QString::fromStdString("Cosul nu exista."));
//		
//		});
//
//
//
//	QObject::connect(btnEmptyData, &QPushButton::clicked, [&]() {
//		srv.emptyCOS();
//		QMessageBox::information(this, "Info", QString::fromStdString("S-au sters toate produsele din cosul curent."));
//		reloadSongList1(srv.getCOS());
//		this->reloadList(this->srv.getCOS());
//
//		
//		});
//
//	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
//		this->reloadSongList1(srv.getCOS());
//		this->reloadList(this->srv.getCOS());
//
//		});
//
//}
////
//
//void CosGUI::guiAddtoCart() {
//	try {
//		
//		//preluare detalii din QLineEdit-uri
//		//string nume, string tip, string prod, double pret
//		string titlu = editNume->text().toStdString();
//		
//
//		//optional - golim QLineEdit-urile dupa apasarea butonului
//		editNume->clear();
//	
//
//		this->srv.addCOS(titlu);
//		this->reloadSongList1(this->srv.getCOS());
//		this->reloadList(this->srv.getCOS());
//
//		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
//		QMessageBox::information(this, "Info", QString::fromStdString("Produs adaugat cu succes."));
//		
//	}
//	catch (RepoException& re) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
//	}
//	catch (ValidationException& ve) {
//		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
//	}
//}
//

#include "CosGUI.h"



void PlaylistGUI::initGUI() {
	lyMain = new QHBoxLayout{};
	this->setLayout(lyMain);

	QWidget* leftSide = new QWidget{};
	QVBoxLayout* lyLeft = new QVBoxLayout{};
	leftSide->setLayout(lyLeft);

	QWidget* formW = new QWidget{};
	QFormLayout* lyEdits = new QFormLayout{};
	lblTitlu = new QLabel{ "Numele produsului" };
	lblArtist = new QLabel{ "Numele fisierului in care sa se exporte cosul:" };
	editTitlu = new QLineEdit{};
	editArtist = new QLineEdit{};

	lblSlider = new QLabel{ "Nr. melodii de generat" };
	editNoSlider = new QLineEdit{};
	lyEdits->addRow(lblTitlu, editTitlu);
	lyEdits->addRow(lblArtist, editArtist);
	lyEdits->addRow(lblSlider, editNoSlider);
	formW->setLayout(lyEdits);


	btnAdd = new QPushButton{ "Adauga in cos" };
	btnGenerate = new QPushButton{ "Genereaza random" };
	btnEmpty = new QPushButton{ "Goleste cosul" };
	btnExport = new QPushButton{ "Export cos" };
	btnClose = new QPushButton{ "Close" };

	btnLabelWindow = new QPushButton{ "Fereastra label" };
	btnLabelWindow->setStyleSheet("background-color: cyan");

	btnTableWindow = new QPushButton{ "Fereastra cos tabel(CosCRUDGUI)" };
	btnTableWindow->setStyleSheet("background-color: magenta");

	btnDrawWindow = new QPushButton{ "Fereastra desen(CosReadOnlyGUI)" };
	btnDrawWindow->setStyleSheet("background-color: yellow");


	sliderGenerate = new QSlider{};
	sliderGenerate->setMinimum(1);
	sliderGenerate->setMaximum(srv.getAll().size());

	lyLeft->addWidget(formW);
	lyLeft->addWidget(btnAdd);
	lyLeft->addWidget(btnGenerate);
	lyLeft->addWidget(btnEmpty);
	lyLeft->addWidget(btnExport);
	lyLeft->addWidget(btnClose);
	lyLeft->addWidget(btnLabelWindow);
	lyLeft->addWidget(btnTableWindow);
	lyLeft->addWidget(btnDrawWindow);

	QWidget* rightSide = new QWidget{};
	QVBoxLayout* lyRight = new QVBoxLayout{};
	rightSide->setLayout(lyRight);

	songList = new QListWidget{};
	songList->setFixedWidth(320);
	bgBrush = QBrush();

	songList->setSelectionMode(QAbstractItemView::SingleSelection);

	lyRight->addWidget(songList);

	widgetDynamic = new QWidget{};
	lyBtnDynamic = new QVBoxLayout{};
	widgetDynamic->setLayout(lyBtnDynamic);
	reloadDynamicButtons();

	lyMain->addWidget(leftSide);
	lyMain->addWidget(sliderGenerate);
	lyMain->addWidget(rightSide);
	lyMain->addWidget(widgetDynamic);


}
set<string> PlaylistGUI::getGenres(const vector<Mag>& playlistSongs) {
	set<string> genres;

	for (const auto& s : playlistSongs) {
		genres.insert(s.getprod());
	}
	return genres;
}
int howManyWithGenre(const vector<Mag>& songs, string genre) {
	int noSongs = count_if(songs.begin(), songs.end(), [&](Mag s) {
		return s.getprod() == genre; });
	return noSongs;
}
void clearLayout(QLayout* layout) {
	if (layout == NULL)
		return;
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			clearLayout(item->layout());
			delete item->layout();
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
}

void PlaylistGUI::reloadDynamicButtons() {
	clearLayout(this->lyBtnDynamic);
	const vector<Mag>& playlistSongs = this->srv.getCOS();
	set<string> genres = this->getGenres(playlistSongs);

	for (string genre : genres) {
		QPushButton* btn = new QPushButton{ QString::fromStdString(genre) };
		lyBtnDynamic->addWidget(btn);
		int howMany = howManyWithGenre(playlistSongs, genre);
		QObject::connect(btn, &QPushButton::clicked, [genre, howMany]() {
			QMessageBox::information(nullptr, "Info", QString::fromStdString("Melodii cu genul " + genre + " : " + to_string(howMany)));

			});
	}

}
void PlaylistGUI::connectSignalsSlots() {
	srv.getPlaylist().addObserver(this);
	QObject::connect(btnAdd, &QPushButton::clicked, this, &PlaylistGUI::addToPlaylist);
	QObject::connect(sliderGenerate, &QSlider::sliderReleased, [&]() {
		qDebug() << sliderGenerate->value();
		});
	QObject::connect(btnGenerate, &QPushButton::clicked, [&]() {
		int noSongs = this->sliderGenerate->value();
		editNoSlider->setText(QString::number(noSongs));
		qDebug() << "This many songs to add:" << noSongs;
		int howManyAdded = srv.addRandomCOS(noSongs);
		this->reloadPlaylist();
	//	this->update();
		});
	QObject::connect(btnEmpty, &QPushButton::clicked, [&]() {
		srv.emptyCOS();
		this->reloadPlaylist();
		});
	QObject::connect(btnExport, &QPushButton::clicked, [&]() {
		string titlu = editArtist->text().toStdString();
		editArtist->clear();
		vector <Mag>m = this->srv.getCOS();
		if (m.size() != 0)
			if (titlu.size() != 0)
			{
				ofstream fout(titlu);
				for (const auto& mag : m) {
					fout << "Nume: " << mag.getnume() << " | Tip: " << mag.gettip() << " | Producator: " << mag.getprod() << " | Pret: " << mag.getpret() << "\n";

				}
				QMessageBox::information(this, "Info", QString::fromStdString("S-au exportat cu succes toate produsele din cosul curent."));
			}
			else

				QMessageBox::warning(this, "Warning", QString::fromStdString("Numele fisierului nu e valid."));
		else
			QMessageBox::warning(this, "Warning", QString::fromStdString("Cosul nu exista."));
		});
	QObject::connect(btnClose, &QPushButton::clicked, this, &PlaylistGUI::close);

	QObject::connect(sliderGenerate, &QSlider::valueChanged, this, [&] {
		editNoSlider->setText(QString::number(sliderGenerate->value()));
		});

	QObject::connect(btnLabelWindow, &QPushButton::clicked, this, [&]() {
		auto labelWindow = new PlaylistGUILabel{ srv.getPlaylist() };
		labelWindow->show();
		});
	QObject::connect(btnTableWindow, &QPushButton::clicked, this, [&]() {
		auto tableWindow = new PlaylistGUITable{ srv.getPlaylist() };
		tableWindow->show();
		});

	QObject::connect(btnDrawWindow, &QPushButton::clicked, this, [&]() {
		auto drawWindow = new PlaylistGUIDraw{ srv.getPlaylist() };
		drawWindow->show();
		});

	QObject::connect(songList, &QListWidget::itemSelectionChanged, [&]() {
		auto selItms = songList->selectedItems();
		for (int i = 0; i < songList->count(); ++i)
		{
			QListWidgetItem* item = songList->item(i);
			item->setBackground(bgBrush);
		}
		for (auto item : selItms) {
			qDebug() << item->text();
			item->setBackground(Qt::green); // sets green background
		}

		});




}


void PlaylistGUI::reloadPlaylist() {

	this->songList->clear();

	const vector<Mag>& songs = srv.getCOS();
	for (auto& song : songs) {
		QString currentItem = QString::fromStdString(song.getnume() + "\t" + song.gettip() + "\t" + song.getprod() + "\t" + to_string(song.getpret()));
		this->songList->addItem(currentItem);
	}
	reloadDynamicButtons();

}


void PlaylistGUI::addToPlaylist() {
	try {
		string titlu = editTitlu->text().toStdString();
	//	string artist = editArtist->text().toStdString();

		editTitlu->clear();
		//editArtist->clear();


		this->srv.addCOS(titlu);
		this->reloadPlaylist();

		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
		QMessageBox::information(this, "Info", QString::fromStdString("Melodie adaugata cu succes."));

	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMessages()));
	}

}



