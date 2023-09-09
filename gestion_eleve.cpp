#include "gestion_eleve.h"
#include "ui_gestion_eleve.h"
#include<QMessageBox>
#include"eleve.h"

#include<QComboBox>
#include<QtCharts>
#include<QtCharts>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include<QRegExpValidator>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>


#include <QMessageBox>
#include<QIntValidator>
#include <QApplication>
#include<QSound>
#include<QDebug>
#include<QMediaPlayer>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDataStream>
#include <QPrintDialog>
#include <QSqlQuery>
#include<QComboBox>
#include<QSaveFile>
#include<QBuffer>
#include<QFileDialog>
#include<QFile>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>

#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include"smtp.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include <QPrinter>

#include "QrCode.hpp"
#include"historique.h"

#include<QCamera>
#include <QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
#include "qmessagebox.h"
#include "connection.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

#include <QPrintDialog>
#include <QFileDialog>

QString rep;
using namespace qrcodegen;

gestion_eleve::gestion_eleve(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestion_eleve)
{
    ui->setupUi(this);


    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_age->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

    ui->tableView->setModel(E.afficher());
    ui->tableView_historique->setModel(H.afficher());



    mCamera = new QCamera (this);
    mCameraViewfinder= new QCameraViewfinder(this);
    mCameraImageCapture= new QCameraImageCapture(mCamera,this);
    mLayout=new QVBoxLayout;
    mOpcionesMenu =new QMenu("Allumer",this);
mEncenderAction=new QAction("Ouvrir",this);
mApagarAction=new QAction("Eteindre",this);
mCapturarAction =new QAction ("Capturer",this);
mOpcionesMenu->addActions({mEncenderAction,mApagarAction,
                          mCapturarAction});
ui->opcionesPushButton->setMenu(mOpcionesMenu);
mCamera->setViewfinder(mCameraViewfinder);

mLayout->addWidget(mCameraViewfinder);
mLayout->setMargin(0);


ui->scrollArea->setLayout(mLayout);
connect(mEncenderAction,&QAction::triggered,[&]() {
    mCamera->start();

});
connect(mApagarAction,&QAction::triggered,[&]() {
    mCamera->stop();
});
connect(mCapturarAction, &QAction::triggered, [&]() {
   auto filename= QFileDialog::getSaveFileName(this,"Capturer","/",
                                 "Imagen(*.jpg;*.jpeg)");
   if (filename.isEmpty()) {
       return;
   }
   mCameraImageCapture->setCaptureDestination(
               QCameraImageCapture::CaptureToFile);
   QImageEncoderSettings imageEcoderSettings;
   imageEcoderSettings.setCodec("image/jpeg");
   imageEcoderSettings.setResolution(1600,1200);
   mCameraImageCapture->setEncodingSettings(imageEcoderSettings);
   mCamera->setCaptureMode(QCamera::CaptureStillImage);
   mCamera->start();
   mCamera->searchAndLock();
   mCameraImageCapture->capture(filename);
   mCamera->unlock();
   });
}

gestion_eleve::~gestion_eleve()
{
    delete ui;
}


void gestion_eleve::on_pb_ajouter_clicked()
{


    QString NUMINSC=ui->le_id->text();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DATEN = ui->le_date->text();
    QString SEXE=ui->comboBox_sexe->currentText();
    QString AGE=ui->le_age->text();


    Eleve E(NUMINSC,NOM, PRENOM, DATEN, SEXE, AGE);

            QSqlQuery query;



            bool test=E.ajouter();
            if(test)
            {

                ui->tableView->setModel(E.afficher());//refresh




                QMessageBox::information(nullptr, QObject::tr("Ajout eleve"),
                            QObject::tr("Eleve Ajouter.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

                QString operation="Ajout";
                historique H(operation);
                H.ajouter();
                 ui->tableView_historique->setModel(H.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajout eleve"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void gestion_eleve::on_comboBox_tri_activated(const QString &arg1)
{


Eleve E;
    QString NOM=ui->comboBox_tri->currentText();
   // QString name=ui->lineEdit->text();
   //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
   ui->tableView->setModel(E.trier(NOM));
   // ui->tableView_2->setModel(cp.rechercher_nom(name));
  ui->tableView->clearSelection();
}

void gestion_eleve::on_statistique_clicked()
{


        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM ELEVE WHERE sexe='Femme'");
        float dispo1 = model->rowCount();

        model->setQuery("SELECT * FROM ELEVE WHERE sexe='Homme'");
        float dispo = model->rowCount();

        float total = dispo1 + dispo;
        QString a = QString("FEMME  " + QString::number((dispo1 * 100) / total, 'f', 2) + "%");
        QString b = QString("HOMME  " + QString::number((dispo * 100) / total, 'f', 2) + "%");

        QPieSeries *series = new QPieSeries();
        series->append(a, dispo1);
        series->append(b, dispo);

        if (dispo1 != 0)
        {
            QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());
        }

        if (dispo != 0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("SEXE D ELEVE : nombre d'eleve" + QString::number(total));

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000, 500);
        chartView->show();


        }



void gestion_eleve::on_lineEdit_recherche_textChanged(const QString &arg1) //recherche dynamique
{
    Eleve E;
        QString NOM=ui->lineEdit_recherche->text();
       // QString name=ui->lineEdit->text();
       //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
       ui->tableView->setModel(E.rechercher(NOM));
       // ui->tableView_2->setModel(cp.rechercher_nom(name));
      ui->tableView->clearSelection();
}


void gestion_eleve::on_pushButton_Afficher_clicked()
{

        ui->tableView->setModel(E.afficher());


}





void gestion_eleve::on_pushButton_supprimer_clicked()
{
    QString ID=ui->lineEdit_supp->text();
            bool test=E.supprimer(ID);
            ui->tableView->setModel(E.afficher());
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("suppression effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView->setModel(E.afficher());
                QString operation="Suppression";
                historique H(operation);
                H.ajouter();
                 ui->tableView_historique->setModel(H.afficher());


        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("suppression non effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion_eleve::on_pushButton_modifier_clicked()
{
    QString NUMINSC=ui->le_id->text();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DATEN = ui->le_date->text();
    QString SEXE=ui->comboBox_sexe->currentText();
    QString AGE=ui->le_age->text();


    Eleve E(NUMINSC,NOM, PRENOM, DATEN, SEXE, AGE);

            QSqlQuery query;



            bool test=E.modifier(NUMINSC);
            if(test)
            {

                ui->tableView->setModel(E.afficher());//refresh




                QMessageBox::information(nullptr, QObject::tr("Modifier Eleve"),
                            QObject::tr("Eleve Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

                QString operation="Modifier";
                historique H(operation);
                H.ajouter();
                ui->tableView_historique->setModel(H.afficher());



            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier Eleve"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void gestion_eleve::on_qrcodegen_clicked()
{
    using namespace qrcodegen;


                QTableView tableView;
                QSqlQueryModel * Mod=new  QSqlQueryModel();
                QString value=ui->lineEdit_qrcode->text();


                     QSqlQuery qry;




                     qry.prepare("select * from eleve where numinsc='"+value+"'");
                     qry.exec();
                     Mod->setQuery(qry);
                     tableView.setModel(Mod);



                    QString numinsc = tableView.model()->data(tableView.model()->index(0, 0)).toString().simplified();
                    QString nom= tableView.model()->data(tableView.model()->index(0, 1)).toString().simplified();
                    QString prenom = tableView.model()->data(tableView.model()->index(0, 2)).toString().simplified();
                    QString daten = tableView.model()->data(tableView.model()->index(0, 3)).toString().simplified();
                    QString sexe = tableView.model()->data(tableView.model()->index(0, 4)).toString().simplified();
                    QString age = tableView.model()->data(tableView.model()->index(0, 5)).toString().simplified();




                QString text = "Numero d'inscription  "+numinsc+"\n"+"Nom  "+nom+"\n"+"Prenom  "+prenom+"\n"+"Date Naissance  "+daten+"\n"+"Sexe  "+sexe+"\n"+"Age  "+age+"\n";
                  // Create the QR Code object
                  QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );

                  qint32 sz = qr.getSize();
                  QImage im(sz,sz, QImage::Format_RGB32);
                    QRgb black = qRgb( 191,112,105 );
                    QRgb white = qRgb(255,255,255);
                  for (int y = 0; y < sz; y++)
                    for (int x = 0; x < sz; x++)
                      im.setPixel(x,y,qr.getModule(x, y) ? black : white );//setpixelmap tafichilek qr code
                  ui->qrcodecommande->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );


}

void gestion_eleve::on_PDF_clicked()
{







                            QPdfWriter pdf("C:/Users/ismae/OneDrive/Documents/session_septembre/img/listdeseleves.pdf");

                                QPainter painter(&pdf);


                                       int i = 4000;
                                       painter.setPen(Qt::black);
                                       painter.setFont(QFont("Book Script", 25));
                                       painter.drawText(3000, 1400, "LISTE DES ELEVES");
                                       painter.setPen(Qt::red);
                                       painter.setFont(QFont("Time New Roman", 10));
                                       painter.drawRect(100, 100, 9200, 2700); // dimension ta3 rectangle
                                       painter.drawRect(100, 3000, 9200, 500);

                                       /*
                                       painter.drawText(0,1300+i,"");
                                       painter.drawText(0,1600+i,"NOM");
                                       painter.drawText(0,1900+i,"PRENOM");
                                       painter.drawText(0,2200+i,"DATE NAISSANCE");
                                       painter.drawText(0,2500+i,"SEXE");
                                       painter.drawText(0,2800+i,"AGE");
                                       */
                                       painter.drawText(300,3300,"NUM INSCRIPTION");
                                       painter.drawText(2000,3300,"NOM");
                                       painter.drawText(3500,3300,"PRENOM");
                                       painter.drawText(4500,3300,"DATE NAISSANCE");
                                       painter.drawText(6500,3300,"SEXE");
                                       painter.drawText(7500,3300,"AGE");





                                       QImage image("C:/Users/ismae/OneDrive/Documents/session_septembre/img/photo.png");
                                       painter.drawImage(QRectF(200, 200, 2000, 2000), image);



                                       QImage image1("C:/Users/ismae/OneDrive/Documents/session_septembre/img/photo2.jpg");
                                       painter.drawImage(QRectF(7000, 200, 2000, 2000), image1);

                                       painter.drawRect(100, 3700, 9200, 9000);

                                       QSqlQuery query;
                                       query.prepare("select * from eleve");
                                       query.exec();
                                       while (query.next())
                                       {
                                           painter.drawText(300, i, query.value(0).toString());
                                           painter.drawText(2000, i, query.value(1).toString());
                                           painter.drawText(3500, i, query.value(2).toString());
                                           painter.drawText(4500, i, query.value(3).toString());
                                           painter.drawText(6500, i, query.value(4).toString());
                                           painter.drawText(7500, i, query.value(5).toString());

                                           i = i + 350;
                                       }

                                       QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                           QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                        }





