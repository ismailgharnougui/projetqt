#ifndef ELEVE_H
#define ELEVE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QDateTime>
#include <QFile>
#include <QDebug>
class Eleve
{
    public:
        Eleve();
        Eleve(QString,QString,QString,QString,QString,QString);

//getters
        QString getID();
        QString getNom();
        QString getPrenom();
        QString getDateN();
        QString getSexe();
        QString getClasse();


        void setID(QString);
        void setNom(QString);
        void setPrenom(QString );
        void setDateN(QString);
        void setSexe(QString );
        void setClasse(QString);


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifier(QString);

        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);

private:
        QString ID,NOM,PRENOM,SEXE,CLASSE,DATEN;


};


#endif // ELEVE_H
