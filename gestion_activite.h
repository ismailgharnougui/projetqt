#ifndef GESTION_ACTIVITE_H
#define GESTION_ACTIVITE_H

#include <QDialog>
#include "activite.h"
namespace Ui {
class gestion_activite;
}

class gestion_activite : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_activite(QWidget *parent = nullptr);
    ~gestion_activite();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_Afficher_clicked();
    void on_pushButton_supprimer_clicked();

    void on_statistique_clicked();

    void on_comboBox_tri_activated(const QString &arg1);
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_qrcodegen_clicked();

    void on_PDF_clicked();

    void on_Perso_push_Supprimer_10_clicked();

private:
    Ui::gestion_activite *ui;
    Activite A;
};

#endif
