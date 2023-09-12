#include "eleve.h"
#include "gestion_eleve.h"
#include "ui_gestion_eleve.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include<QDate>
#include<QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

Eleve::Eleve()
{

}
Eleve::Eleve(QString ID,QString NOM,QString PRENOM,QString DATEN,QString SEXE,QString AGE)
{this->ID=ID;
    this->NOM = NOM;
    this->PRENOM = PRENOM;
    this->DATEN = DATEN;
    this->SEXE = SEXE;
    this->AGE = AGE;

}

  QString Eleve::getID(){return ID;}
  QString Eleve::getNom(){return NOM;}
  QString Eleve::getPrenom(){return PRENOM;}
  QString Eleve::getDateN(){return DATEN;}
  QString Eleve::getSexe(){return SEXE;}
  QString Eleve::getClasse(){return AGE;}

  void Eleve::setID(QString ID){this->ID=ID;}
  void Eleve::setNom(QString NOM){this->NOM=NOM;}
  void Eleve::setPrenom(QString PRENOM){this->PRENOM=PRENOM;}
  void Eleve::setDateN(QString DATEN){this->DATEN=DATEN;}
  void Eleve::setSexe(QString SEXE ){this->SEXE=SEXE;}
  void Eleve::setClasse(QString AGE){this->AGE=AGE;}



bool Eleve::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO eleve (NUMINSC,NOM,PRENOM,DATEN,SEXE,AGE)"
                  "values(:NUMINSC,:NOM,:PRENOM,:DATEN,:SEXE,:AGE)");
    query.bindValue(":NUMINSC",ID);
        query.bindValue(":NOM",NOM);
         query.bindValue(":PRENOM",PRENOM);
         query.bindValue(":DATEN",DATEN);
         query.bindValue(":SEXE",SEXE);
         query.bindValue(":AGE",AGE);


          return query.exec();

   };



QSqlQueryModel * Eleve::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from ELEVE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("AGE"));


    return model;
}

bool Eleve::supprimer(QString ID)
{
    QSqlQuery query;
         QString res=ID;
         query.prepare("Delete from ELEVE where NUMINSC=:NUMINSC");
         query.bindValue(":ID",res);
         return query.exec();
}

bool Eleve::modifier(QString ID)
{
QSqlQuery query;
        QString res= ID;


        query.prepare("UPDATE eleve SET NOM=:NOM,PRENOM=:PRENOM,DATEN=:DATEN,SEXE=:SEXE,AGE=:AGE where NUMINSC=:NUMINSC");
        query.bindValue(":NUMINSC", ID);
        query.bindValue(":NOM",NOM);
         query.bindValue(":PRENOM",PRENOM);
         query.bindValue(":DATEN",DATEN);
         query.bindValue(":SEXE",SEXE);
          query.bindValue(":AGE",AGE);


        return    query.exec();
}

QSqlQueryModel* Eleve::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from ELEVE where (NOM like '%"+a+"%' or NOM like '"+a+"%' or  NOM like '%"+a+"' or PRENOM like '%"+a+"%' or PRENOM like '"+a+"%' or  PRENOM like '%"+a+"'or ID like '%"+a+"%' or ID like '"+a+"%' or  ID like '%"+a+"') ");



    query->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEN"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
    query->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSE"));
    return query;
}
QSqlQueryModel *Eleve::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;

    if(x=="nom (A->Z)")
        model->setQuery("select*  from ELEVE order by NOM");
    else if(x=="prenom (A->Z)")
        model->setQuery("select*  from ELEVE order by PRENOM");
    else if (x=="DATEN (des)")
        model->setQuery("select*  from ELEVE order by DATEN desc");
    else if (x=="Default")
            model->setQuery("select * from ELEVE");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMINSC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("AGE"));
        return model;
}
