#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("ismael");//inserer nom de l'utilisateur
db.setPassword("ismael");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
