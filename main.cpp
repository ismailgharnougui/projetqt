#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include "connection.h"
#include"mainwindow.h"
#include "gestion_eleve.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    w.show();

    return a.exec();
}

