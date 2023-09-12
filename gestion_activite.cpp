#include "gestion_activite.h"
#include "ui_gestion_activite.h"
#include<QMessageBox>
#include"activite.h"

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
#include<QLabel>
#include"QMessageBox"
#include <QPdfWriter>
#include <QtGui/QDesktopServices>
#include <QUrl>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QtSvg/QSvgRenderer>
#include <QFileDialog>
#include <fstream>
#include "QrCode.hpp"
#include <QAxObject>
#include <QObject>
#include <QDesktopServices>

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
#include <QSettings>
#include <QCoreApplication>

using namespace qrcodegen;

gestion_activite::gestion_activite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestion_activite)
{
    ui->setupUi(this);

    QString id = ui->le_id->text();
    QString titre = ui->le_titre->text();
    QString type = ui->le_type->currentText();
    QString date_act = ui->le_date->text();
    QString nbplaces = ui->le_nbplaces->text();


    ui->le_titre->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

    ui->le_nbplaces->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

}

gestion_activite::~gestion_activite()
{
    delete ui;
}


void gestion_activite::on_pb_ajouter_clicked()
{
    // Réinitialisez les étiquettes d'erreur à vide
    ui->lblErreurId->setText("");
    ui->lblErreurTitre->setText("");
    ui->lblErreurType->setText("");
    ui->lblErreurDate->setText("");
    ui->lblErreurNbplaces->setText("");

    // Récupérez les valeurs d'entrée
    QString id = ui->le_id->text();
    QString titre = ui->le_titre->text();
    QString type = ui->le_type->currentText();
    QString date_act = ui->le_date->text();
    QString nbplaces = ui->le_nbplaces->text();

    // Validez les champs d'entrée
    bool isValid = true;

    if (id.isEmpty()) {
        ui->lblErreurId->setText("<font color='red'>ID ne peut pas être vide!!!!</font>");
        isValid = false;
    }

    // Validation pour le titre (exemplaire, assurez-vous qu'il n'est pas vide)
    if (titre.isEmpty()) {
        ui->lblErreurTitre->setText("<font color='red'>Titre ne peut pas être vide!!!</font>");
        isValid = false;
    }

    if (type.isEmpty()) {
        ui->lblErreurType->setText("<font color='red'>Type ne peut pas être vide!!!</font>");
        isValid = false;
    }
    if (date_act.isEmpty()) {
        ui->lblErreurDate->setText("<font color='red'>Date ne peut pas être vide!!!</font>");
        isValid = false;
    }
    if (nbplaces.isEmpty()) {
        ui->lblErreurNbplaces->setText("<font color='red'>Nb places ne peut pas être vide!!!</font>");
        isValid = false;
    }

    // Ajouter une vérification de l'existence de l'ID dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id FROM Activite WHERE id = :id");
    checkQuery.bindValue(":id", id);
    if (checkQuery.exec() && checkQuery.next()) {
        ui->lblErreurId->setText("<font color='red'>ID existe déjà!!!!</font>");
        isValid = false;
    }

    // Continuez avec les autres validations d'entrée...

    if (isValid) {
        // Si l'entrée est valide et que l'ID n'existe pas, procédez à l'ajout de l'activité
        Activite A(id, titre, type, date_act, nbplaces);

        QSqlQuery query;
        bool test = A.ajouter();
        if (test) {
            ui->tableView->setModel(A.afficher()); // Rafraîchir la vue

            QMessageBox::information(nullptr, QObject::tr("Ajout activite"),
                QObject::tr("Activite ajoutée avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

            QFile file("C:/Users/ismae/OneDrive/Documents/session_septembre/img/historique.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                qDebug() << "Erreur lors de l'ouverture du fichier historique.txt";
                return;
            }
            QTextStream cout(&file);
            QString d_info = QDateTime::currentDateTime().toString();
            QString message2 = d_info + " - Une activité a été ajoutée avec l'ID " + id + "\n";
            cout << message2;
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Ajout activite"),
                QObject::tr("Erreur lors de l'ajout de l'activite.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        // Gérez l'erreur d'entrée invalide ou d'ID existant
    }
}



void gestion_activite::on_pushButton_modifier_clicked()
{


  // Récupérez les valeurs d'entrée
  QString id = ui->le_id->text();
  QString titre = ui->le_titre->text();
  QString type = ui->le_type->currentText();
  QString date_act = ui->le_date->text();
  QString nbplaces = ui->le_nbplaces->text();

  // Vérification si l'ID existe
  QSqlQuery checkQuery;
  checkQuery.prepare("SELECT * FROM activite WHERE id = :id");
  checkQuery.bindValue(":id", id);

  if (!checkQuery.exec())
  {
      // Erreur lors de l'exécution de la requête
      qDebug() << "Erreur lors de la vérification de l'ID :" << checkQuery.lastError().text();
      return;
  }

  if (!checkQuery.next())
  {
      // L'ID n'existe pas, affichez un message d'erreur
      QMessageBox::critical(nullptr, QObject::tr("Modifier Activite"),
                            QObject::tr("L'ID n'existe pas dans la base de données.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      return;
  }

  // L'ID existe, vous pouvez maintenant effectuer la modification
  Activite A(id, titre, type, date_act, nbplaces);

  QSqlQuery query;

  bool test = A.modifier(id);
  if (test)
  {
      ui->tableView->setModel(A.afficher()); // refresh

      QMessageBox::information(nullptr, QObject::tr("Modifier Activite"),
                               QObject::tr("Activite Modifiée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Modifier Activite"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
  }
}




void gestion_activite::on_comboBox_tri_activated(const QString &arg1)
{


Activite A;
    QString NOM=ui->comboBox_tri->currentText();
   // QString name=ui->lineEdit->text();
   //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
   ui->tableView->setModel(A.trier(NOM));
   // ui->tableView_2->setModel(cp.rechercher_nom(name));
  ui->tableView->clearSelection();
}

void gestion_activite::on_statistique_clicked()
{
    // Créez un modèle pour exécuter les requêtes SQL
    QSqlQueryModel *model = new QSqlQueryModel();

    // Effectuez les requêtes SQL pour compter les activités de chaque type
    model->setQuery("SELECT COUNT(*) FROM activite WHERE TYPE='Peinture'");
    int dispo1 = model->data(model->index(0, 0)).toInt();

    model->setQuery("SELECT COUNT(*) FROM activite WHERE TYPE='Musique'");
    int dispo2 = model->data(model->index(0, 0)).toInt();

    model->setQuery("SELECT COUNT(*) FROM activite WHERE TYPE='Theatre'");
    int dispo3 = model->data(model->index(0, 0)).toInt();

    int total = dispo1 + dispo2 + dispo3;

    // Créez une série de diagramme circulaire (Pie Chart)
    QPieSeries *series = new QPieSeries();
    if (dispo1 > 0)
        series->append("Peinture", dispo1);
    if (dispo2 > 0)
        series->append("Musique", dispo2);
    if (dispo3 > 0)
        series->append("Theatre", dispo3);

    // Configurez les étiquettes pour les tranches avec des données
    for (QPieSlice *slice : series->slices())
    {
        slice->setLabelVisible();
    }

    // Créez un graphique et configurez-le
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des types d'activité");

    // Créez une vue de graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000, 500);
    chartView->show();
}

void gestion_activite::on_lineEdit_recherche_textChanged(const QString &arg1) //recherche dynamique
{
    Activite A;
        QString NOM=ui->lineEdit_recherche->text();
       // QString name=ui->lineEdit->text();
       //ui->tableView->setModel(p.rechercher(ui->comboBox_tri->currentText()));
       ui->tableView->setModel(A.rechercher(NOM));
       // ui->tableView_2->setModel(cp.rechercher_nom(name));
      ui->tableView->clearSelection();
}


void gestion_activite::on_pushButton_Afficher_clicked()
{

        ui->tableView->setModel(A.afficher());


}






void gestion_activite::on_pushButton_supprimer_clicked()
{
    QString ID = ui->lineEdit_supp->text();

    // Vérifiez si l'ID existe avant de tenter de le supprimer
    if (A.checkIfIdExists(ID)) { // Remplacez "checkIfIdExists" par votre fonction réelle pour vérifier l'existence de l'ID
        bool test = A.supprimer(ID);
        ui->tableView->setModel(A.afficher());
        if (test) {
            QMessageBox::information(nullptr, QObject::tr("Suppression réussie"),
                QObject::tr("Suppression effectuée avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

            QFile file("C:/Users/ismae/OneDrive/Documents/session_septembre/img/historique.txt");

            if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                qDebug() << "Erreur lors de l'ouverture du fichier historique.txt";
                return;
            }

            QTextStream cout(&file);

            QString d_info = QDateTime::currentDateTime().toString();

            QString message2 = d_info + " - Une activité a été supprimée avec l'ID " + ID + "\n";

            cout << message2;
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur de suppression"),
                QObject::tr("Erreur lors de la suppression de l'activité.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("ID introuvable"),
            QObject::tr("L'ID que vous avez saisi n'existe pas.\n"
                        "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}









void gestion_activite::on_qrcodegen_clicked()
{
    QString value = ui->lineEdit_qrcode->text();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM activite WHERE id = :id");
    qry.bindValue(":id", value);
    qry.exec();

    if (qry.next()) {
        // ID exists in the database
        QString id = qry.value(0).toString();
        QString titre = qry.value(1).toString();
        QString type = qry.value(2).toString();
        QString date_act = qry.value(3).toString();
        QString nbplaces = qry.value(4).toString();

        QString text = "ID " + id + "\n" + "titre " + titre + "\n" + "type " + type + "\n" +
                       "date_act " + date_act + "\n" + "nbplaces " + nbplaces;

        // Create the QR Code object
        QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

        qint32 sz = qr.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
        QRgb black = qRgb(191, 112, 105);
        QRgb white = qRgb(255, 255, 255);

        for (int y = 0; y < sz; y++) {
            for (int x = 0; x < sz; x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? black : white);
            }
        }

        ui->qrcodecommande->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
    } else {
        // ID does not exist in the database
        QMessageBox::critical(nullptr, QObject::tr("ID introuvable"),
            QObject::tr("L'ID que vous avez saisi n'existe pas.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestion_activite::on_PDF_clicked()
{

    QPdfWriter pdf("C:/Users/ismae/OneDrive/Documents/session_septembre/img/list-activite.pdf");

        QPainter painter(&pdf);


               int i = 4000;
               painter.setPen(Qt::black);
               painter.setFont(QFont("Book Script",20));
               painter.drawText(2500, 1400, "LISTE DES ACTIVITE");
               painter.setPen(Qt::red);
               painter.setFont(QFont("Time New Roman", 10));
               painter.drawRect(100, 100, 9200, 2700); // dimension ta3 rectangle
               painter.drawRect(100, 3000, 9200, 500);


               painter.drawText(300,3300,"ID");
               painter.drawText(2000,3300,"TITRE");
               painter.drawText(3500,3300,"TYPE");
               painter.drawText(4500,3300,"DATE ACTIVITE");
               painter.drawText(6500,3300,"NB PLACES");





               QImage image("C:/Users/ismae/OneDrive/Documents/session_septembre/img/photo.png");
               painter.drawImage(QRectF(200, 200, 2000, 2000), image);

               QImage image1("C:/Users/ismae/OneDrive/Documents/session_septembre/img/photo3.png");
               painter.drawImage(QRectF(7000, 200, 2000, 2000), image1);

               painter.drawRect(100, 3700, 9200, 9000);

               QSqlQuery query;
               query.prepare("select * from ACTIVITE");
               query.exec();
               while (query.next())
               {
                   painter.drawText(300, i, query.value(0).toString());
                   painter.drawText(2000, i, query.value(1).toString());
                   painter.drawText(3500, i, query.value(2).toString());
                   painter.drawText(4500, i, query.value(3).toString());
                   painter.drawText(6500, i, query.value(4).toString());

                   i = i + 350;
               }

               QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                   QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_activite::on_Perso_push_Supprimer_10_clicked()
{
    QFile file("C:/Users/ismae/OneDrive/Documents/session_septembre/img/historique.txt"); // Remplacez "chemin/vers/votre/fichier.txt" par le chemin de votre fichier texte
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString text = in.readAll();
        file.close();

        // Affichez le texte dans le QTextBrowser
        ui->histo->setPlainText(text); // Remplacez "textBrowser" par le nom de votre QTextBrowser
    } else {
        qDebug() << "Impossible d'ouvrir le fichier.";
    }
}
