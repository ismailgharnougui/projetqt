#ifndef ACTIVITE_H
#define ACTIVITE_H


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
class Activite
{
    public:
        Activite();
        Activite(QString,QString,QString,QString,QString);

//getters
        QString getID();
        QString gettitre();
        QString gettype();
        QString getDateact();
        QString getnbplaces();


        void setID(QString);
        void settitre(QString);
        void settype(QString );
        void setDateact(QString);
        void setnbplaces(QString );


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifier(QString);
        bool checkIfIdExists(QString);


        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);

private:
    QString id;
    QString titre;
    QString type;
    QString date_act;
    QString nbplaces;

};

#endif // ACTIVITE_H
