#ifndef GESTION_ELEVE_H
#define GESTION_ELEVE_H


#include <QMessageBox>
#include <QMainWindow>
#include "eleve.h"
#include "ui_gestion_eleve.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QDebug>
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QSound>
#include <QMainWindow>
#include <QPainter>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include "smtp.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include "historique.h"


#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
QT_BEGIN_NAMESPACE


struct Position {
    int x;
    int y;
};

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

namespace Ui {
class gestion_eleve;
}

class gestion_eleve : public QDialog
{
    Q_OBJECT

public:
     gestion_eleve(QWidget *parent = nullptr);
    ~gestion_eleve();

private slots:




     void on_comboBox_tri_activated(const QString &arg1);
     void on_pushButton_Afficher_clicked();
     void on_lineEdit_recherche_textChanged(const QString &arg1);
     void on_pb_ajouter_clicked();
     void on_pushButton_supprimer_clicked();
     void on_statistique_clicked();

     void on_pushButton_modifier_clicked();

     void on_qrcodegen_clicked();

     void on_PDF_clicked();



private:
    Ui::gestion_eleve *ui;
    Eleve E;
    historique H;

    QStringList files;

      QString mnomemp="localhost";
      quint16 mport=3333;
      QTcpSocket *mSocket;

      QCamera *mCamera;
      QCameraViewfinder *mCameraViewfinder;
      QCameraImageCapture *mCameraImageCapture;
      QVBoxLayout *mLayout;
      QMenu *mOpcionesMenu;
      QAction *mEncenderAction;
      QAction *mApagarAction;
      QAction *mCapturarAction;

};



#endif // GESTION_ELEVE_H
