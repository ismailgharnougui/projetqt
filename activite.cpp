#include "activite.h"
#include "gestion_activite.h"
#include "ui_gestion_activite.h"
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

Activite::Activite()
{

}

Activite::Activite(QString id,QString titre,QString type,QString date_act,QString nbplaces)
{this->id=id;
    this->titre = titre;
    this->type = type;
    this->date_act = date_act;
    this->nbplaces = nbplaces;

}

  QString Activite::getID(){return id;}
  QString Activite::gettitre(){return titre;}
  QString Activite::gettype(){return type;}
  QString Activite::getDateact(){return date_act;}
  QString Activite::getnbplaces(){return nbplaces;}

  void Activite::setID(QString id){this->id=id;}
  void Activite::settitre(QString titre){this->titre=titre;}
  void Activite::settype(QString type){this->type=type;}
  void Activite::setDateact(QString date_act){this->date_act=date_act;}
  void Activite::setnbplaces(QString nbplaces ){this->nbplaces=nbplaces;}



bool Activite::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO Activite (ID,titre,type,date_act,nbplaces)"
                  "values(:ID,:titre,:type,:date_act,:nbplaces)");
    query.bindValue(":ID",id);
        query.bindValue(":titre",titre);
         query.bindValue(":type",type);
         query.bindValue(":date_act",date_act);
         query.bindValue(":nbplaces",nbplaces);

          return query.exec();

   };



QSqlQueryModel * Activite::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Activite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_act"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbplaces"));


    return model;
}

bool Activite::supprimer(QString ID)
{
    QSqlQuery query;
         QString res=ID;
         query.prepare("Delete from Activite where ID=:ID");
         query.bindValue(":ID",res);
         return query.exec();
}



bool Activite::modifier(QString id)
{
QSqlQuery query;
        QString res= id;


        query.prepare("UPDATE Activite SET titre=:titre,type=:type,date_act=:date_act,nbplaces=:nbplaces where id=:id");
        query.bindValue(":id",id);
            query.bindValue(":titre",titre);
             query.bindValue(":type",type);
             query.bindValue(":date_act",date_act);
             query.bindValue(":nbplaces",nbplaces);



        return    query.exec();
}
bool Activite::checkIfIdExists(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM Activite WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // The ID exists in the database
        return true;
    } else {
        // The ID does not exist in the database
        return false;
    }
}

QSqlQueryModel* Activite::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from Activite where (titre like '%"+a+"%' or titre like '"+a+"%' or  titre like '%"+a+"' or type like '%"+a+"%' or type like '"+a+"%' or  type like '%"+a+"'or id like '%"+a+"%' or ID like '"+a+"%' or  ID like '%"+a+"') ");



    query->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("date_act"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("nbplaces"));
    return query;
}
QSqlQueryModel *Activite::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;

    if(x=="titre (A->Z)")
        model->setQuery("select*  from Activite order by titre");
    else if(x=="type (A->Z)")
        model->setQuery("select*  from Activite order by type");
    else if (x=="nbplaces (des)")
        model->setQuery("select*  from Activite order by nbplaces desc");
    else if (x=="Default")
            model->setQuery("select * from Activite");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ACT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NBPLACES"));
        return model;

}

