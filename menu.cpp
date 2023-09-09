#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"


Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}






void Menu::on_Logout_clicked()
{
    this->hide();

}


void Menu::on_pushButton_clicked()
{
    I1.show();
}

void Menu::on_pushButton_2_clicked()
{
    I2.show();
}
