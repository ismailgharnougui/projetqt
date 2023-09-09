#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "gestion_eleve.h"
#include "gestion_activite.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:




    void on_Logout_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    Ui::Menu *ui;
private:
gestion_eleve I1;
gestion_activite I2;

};

#endif // MENU_H
