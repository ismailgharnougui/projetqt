/*#include "historique.h"

historique::historique()
{

}
*/

#include "historique.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QFileDialog>
#include <QTextDocument>
#include <QObject>
#include<QDate>
historique::historique()
{

}

historique::historique(QString b)
 {
    operation=b;
 }

void historique::ajouter()
{
    QSqlQuery query;


    query.prepare("insert into HISTORIQUES(ID_H,DATEH,TYPE_OPERATION) values(HISRORIQUES_SEQ.nextval, sysdate, :operation)");
   query.bindValue(":operation",operation);


 query.exec();
}
QSqlQueryModel * historique::afficher( )
{
  QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select DATEH, TYPE_OPERATION from HISTORIQUES ;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("date"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Operation"));

 return model;
}
