#pragma once
#pragma once
#include <QAbstractTableModel>
#include <QBrush>
#include <Qt>
#include <qfont.h>
#include "Magazin.h"
#include <vector>
#include <qdebug.h>
using std::vector;



class MyTableModel :public QAbstractTableModel {
	std::vector<Mag> songs;
public:
	MyTableModel(const std::vector<Mag>& songs) :songs{ songs } {
	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return songs.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 4;
	}
	//Returns the data stored under the given role for the item referred to by the index.
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		qDebug() << "row:" << index.row() << " col:" << index.column() << " role" << role;
		//qDebug() << index.data(role);

		if (role == Qt::ForegroundRole) {
			auto song = this->songs[index.row()];
			if (song.getprod() == "rock") {
				return QBrush(Qt::magenta);
			}
		}
		if (role == Qt::FontRole) {
			QFont f;
			f.setItalic(index.row() % 10 == 1);
			f.setBold(index.row() % 10 == 1);
			return f;
		}
		if (role == Qt::BackgroundRole) {

			int row = index.row();
			QModelIndex i = index.sibling(index.row(), 1);
			if (i.data().toString() == "Aliment") {
				QLinearGradient linearGrad(QPointF(70,70), QPointF(30, 30));
				linearGrad.setColorAt(0.1, Qt::blue);
				linearGrad.setColorAt(0.3, Qt::green);
				linearGrad.setColorAt(0.5, Qt::red);
				linearGrad.setColorAt(0.8, Qt::magenta);
				linearGrad.setColorAt(1, Qt::yellow);
			//	QBrush bg(QImage("gradient"));
				QBrush bg(linearGrad);
				return bg;
			}
		}

		if (role == Qt::DisplayRole) {

			Mag p = songs[index.row()];
			if (index.column() == 0) {
				return QString::fromStdString(p.getnume());
			}
			else if (index.column() == 1) {
				return QString::fromStdString(p.gettip());
			}
			else if (index.column() == 2) {
				return QString::fromStdString(p.getprod());
			}
			else if (index.column() == 3) {
				return QString::number(p.getpret());
			}
		}

		return QVariant{};
	}

	void setSongs(const vector<Mag> songs1) {
		this->songs = songs1;
		auto topLeft = createIndex(0, 0);
		auto bottomR = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomR);
	}

	Qt::ItemFlags flags(const QModelIndex& /*index*/) const {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const
	{
		if (role == Qt::DisplayRole)
		{
			if (orientation == Qt::Horizontal) {
				switch (section)
				{
				case 0:
					return tr("Nume");
				case 1:
					return tr("Tip");
				case 2:
					return tr("Producator");
				case 3:
					return tr("Pret");
				default:
					return QString("");
				}
			}
		}
		return QVariant();
	}
};
