//#pragma once
//#include <vector>
//#include <string>
//#include <QtWidgets/QApplication>
//#include <QLabel>
//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QFormLayout>
//#include <QLineEdit>
//#include <QTableWidget>
//#include <QMessageBox>
//#include <QHeaderView>
//#include <QGroupBox>
//#include <QRadioButton>
//#include <QVBoxLayout>
//#include <QListWidget>
//
//#include "Service.h"
//#include <map>
//
//using std::vector;
//using std::string;
//class CosGUI : public QWidget {
//private:
//
//	ProdStore& srv;
//	//	tblHeaderList << "Nume" << "Tip" << "Producator" << "Pret";
//
//	QLabel* lblNume = new QLabel{ "Numele produsului:" };
//
//	QLineEdit* editNume;
//
//	QPushButton* btnAddtoCart;
//
//
//	QLabel* lblRandom = new QLabel{ "Numarul de produse ce se vor adauga in cos:" };
//	QLineEdit* editRandom;
//	QPushButton* btnRandomData;
//
//
//	QLabel* lblExport = new QLabel{ "Numele fisierului unde se vor exporta datele:" };
//	QLineEdit* editExport;
//	QPushButton* btnExportData;
//
//	QPushButton* btnEmptyData;
//
//	QPushButton* btnReloadData;
//
//	QTableWidget* tableCos;
//
//	QListWidget* lst;
//
//	QTableWidget* tableProd;
//
//
//	void initializeGUIComponents1();
//
//	void connectSignalsSlots1();
//	void reloadSongList1(vector<Mag> songs);
//
//	void reloadList(vector<Mag> songs);
//
//	void reloadSongList1p(vector<Mag> songs);
//
//	
//
//public:
//	CosGUI(ProdStore& songSrv) : srv{ songSrv } {
//		initializeGUIComponents1();
//		connectSignalsSlots1();
//		reloadSongList1(srv.getCOS());
//		reloadList(srv.getCOS());
//
//		reloadSongList1p(srv.getAll());
//
//		//generateButton(srv.raport());
//	}
//	void guiAddtoCart();
///*
//	void generateButton(std::map<string, DTO> map);
//
//	void guiModSong();
//
//	void guiDelSong();
//
//	void guiFindSong();*/
//
//};


#pragma once
#include <QtWidgets/QApplication>
#include <QWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFormLayout>
#include "Service.h"
#include <QMessageBox>
#include <string>
#include <set>
#include <vector>
#include <QDebug>
#include <QPainter>
#include <cstdlib>

//#include "Observer.h"

using std::to_string;
using std::set;
using std::vector;

class PlaylistGUI : public QWidget, public Observer {
private:
	QBrush bgBrush;
	ProdStore& srv;
	QHBoxLayout* lyMain;
	QListWidget* songList;

	QLabel* lblTitlu;
	QLabel* lblArtist;
	QLineEdit* editTitlu;
	QLineEdit* editArtist;

	QPushButton* btnAdd;
	QPushButton* btnGenerate;
	QPushButton* btnEmpty;
	QPushButton* btnExport;
	QPushButton* btnClose;
	QPushButton* btnLabelWindow;
	QPushButton* btnTableWindow;
	QPushButton* btnDrawWindow;


	QLineEdit* editNoSlider;
	QLabel* lblSlider;
	QSlider* sliderGenerate;

	QWidget* widgetDynamic;
	QVBoxLayout* lyBtnDynamic;
	void initGUI();
	void connectSignalsSlots();

	void reloadPlaylist();
	void addToPlaylist();

	//ar trebui ca aceasta metoda sa fie aici sau in service?
	set<string> getGenres(const vector<Mag>& playlistSongs);
	void reloadDynamicButtons();
	void update() override {
		reloadPlaylist();
	}

public:
	PlaylistGUI(ProdStore& songStore) : srv{ songStore } {
		initGUI();
		connectSignalsSlots();
		update();
	}

};

class PlaylistGUILabel :public QWidget, public Observer {
private:
	Cos& p;
	QLabel* lblNoSongs;
	QLineEdit* editNoSongs;
	void initGUI() {
		QHBoxLayout* ly = new QHBoxLayout{};
		this->setLayout(ly);
		lblNoSongs = new QLabel{ "Numar de produse:" };
		editNoSongs = new QLineEdit{};
		ly->addWidget(lblNoSongs);
		ly->addWidget(editNoSongs);
		setAttribute(Qt::WA_DeleteOnClose);
		p.addObserver(this);
	};
	void update() override {
		this->editNoSongs->setText(QString::number(p.getAllProd().size()));
	};
	~PlaylistGUILabel() {
		p.removeObserver(this);
	}

public:
	PlaylistGUILabel(Cos& playlist) :p{ playlist } {
		initGUI();
		update();
	};

};
class PlaylistGUITable :public QWidget, public Observer {
private:
	Cos& p;
	QTableWidget* table;
	QPushButton* btnEmpty;
	void initGUI() {
		QHBoxLayout* ly = new QHBoxLayout{};
		this->setLayout(ly);
		table = new QTableWidget{};
		btnEmpty = new QPushButton{ "Goleste playlist" };
		ly->addWidget(table);
		ly->addWidget(btnEmpty);
		setAttribute(Qt::WA_DeleteOnClose);
		p.addObserver(this);
	};
	void reloadTableData(const vector<Mag>& songs) {
		this->table->setColumnCount(4);
		this->table->setRowCount(songs.size());
		for (int i = 0; i < songs.size(); i++) {
			table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(songs[i].getnume())));
			table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(songs[i].gettip())));
			table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(songs[i].getprod())));
			table->setItem(i, 3, new QTableWidgetItem(QString::number(songs[i].getpret())));
		}

	};

	void connectSignalsSlots() {
		p.addObserver(this);
		QObject::connect(btnEmpty, &QPushButton::clicked, [&]() {
			p.empty_cos();
			reloadTableData(p.getAllProd());
			});
	}


public:
	PlaylistGUITable(Cos& playlist) :p{ playlist } {
		initGUI();
		connectSignalsSlots();
		//reloadTableData(p.getAllProd());
		this->update();
	};

	void update() override {
		this->reloadTableData(p.getAllProd());
	}
	~PlaylistGUITable() {
		p.removeObserver(this);
	}

};

class PlaylistGUIDraw :public QWidget, public Observer {
private:
	Cos& playlist;
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int x = 0;
		int y = 0;
		for (auto song : playlist.getAllProd()) {
			//p.drawRect(x, y, 10, song.getDurata() * 10);
			x = rand() % 400 + 1;
			y = rand() % 400 + 1;
			qDebug() << x << " " << y;
			QRectF target(x, y, 100, 94);
			QRectF source(0, 0, 732, 720);
			QImage image("wall1");

			p.drawImage(target, image, source);

			x += 40;

		}
	}

	void update() override {
		repaint();
	};
	~PlaylistGUIDraw() {
		playlist.removeObserver(this);
	}

public:
	PlaylistGUIDraw(Cos& playlist) :playlist{ playlist } {
		playlist.addObserver(this);
	};

};

