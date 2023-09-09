/*#ifndef HISTORIQUE_H
#define HISTORIQUE_H


class historique
{
public:
    historique();
};

#endif // HISTORIQUE_H
*/

#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class historique
{
private:
    QString operation;

public:
    historique();
    historique(QString);
    void ajouter();
    QSqlQueryModel * afficher( );

};

#endif // HISTORIQUE_H
