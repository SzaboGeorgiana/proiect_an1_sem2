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
//#include "CosGUI.h"
//
//#include "Service.h"
//#include <map> 
//
//using std::vector;
//using std::string;
//class MagGUI : public QWidget {
//private:
//
//	ProdStore& srv;
////	tblHeaderList << "Nume" << "Tip" << "Producator" << "Pret";
//	PlaylistGUI playlistWindow{ srv };
//
//	QLabel* lblTitlu = new QLabel{ "Numele produsului:" };
//	QLabel* lblArtist = new QLabel{ "Tipul produsului:" };
//	QLabel* lblGen = new QLabel{ "Producatorul produsului:" };
//	QLabel* lblDurata = new QLabel{ "Pretul produsului:" };
//
//	QLineEdit* editTitlu;
//	QLineEdit* editArtist;
//	QLineEdit* editGen;
//	QLineEdit* editDurata;
//
//	QPushButton* btnAddSong;
//	
//	QPushButton* btnModSong;
//	
//	QPushButton* btnDelSong;
//
//	QPushButton* btnFindSong;
//
//	QGroupBox* groupBox = new QGroupBox(tr("Tip sortare"));
//
//	QRadioButton* radioSrtArtistTitlu = new QRadioButton(QString::fromStdString("Tip+Nume"));
//	QRadioButton* radioSrtDurata = new QRadioButton(QString::fromStdString("Pret"));
//	QRadioButton* radioSrtNume = new QRadioButton(QString::fromStdString("Nume"));
//	QPushButton* btnSortSongs;
//
//	QGroupBox* groupBox1 = new QGroupBox(tr("Tip Filtrare"));
//
//	QLabel* lblFilterCriteria = new QLabel{ "Producatorul dupa care se filtreaza:" };
//	QLineEdit* editFilterGen;
//	QPushButton* btnFilterSongs;
//
//	QLabel* lblFilterCriteriaN = new QLabel{ "Numele dupa care se filtreaza:" };
//	QLineEdit* editFilterNume;
//	QPushButton* btnFilterSongsN;
//
//	/**/
//	QLabel* lblFilterCriteriaPinc = new QLabel{ "Limita inferioara a pretului:" };
//	QLineEdit* editFilterPretINC;
//	QLabel* lblFilterCriteriaPfin = new QLabel{ "Limita superioara a pretului:" };
//	QLineEdit* editFilterPretSF;
//	QPushButton* btnFilterSongsP;
//
//	QPushButton* btnReloadData;
//
//	QPushButton* btnUndoData;
//
//	QTableWidget* tableSongs;
//
//	QVBoxLayout* buttonTip=new QVBoxLayout;
//
//	QPushButton* btnSpreCos;
//
//
//	void initializeGUIComponents();
//
//	void connectSignalsSlots();
//	void reloadSongList(vector<Mag> songs);
//
	/*void clearLayout(QLayout* layout) {
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
	}*/
//public:
//	MagGUI(ProdStore& songSrv) : srv{ songSrv } {
//		initializeGUIComponents();
//		connectSignalsSlots();
//		reloadSongList(srv.getAll());
//		generateButton(srv.raport());
//	}
//	void guiAddSong();
//
//	void generateButton(std::map<string, DTO> map);
//	
//	void guiModSong();
//
//	void guiDelSong();
//
//	void guiFindSong();
//
//};
