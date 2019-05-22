#ifndef FENETRE_BASE_H
#define FENETRE_BASE_H

#include <QDialog>
#include "fenetre_client.h"
//fenetre pour entrer le mot de passe
//"admin" pour la session admin ou n'importe quel autre mot de passe pour la session client

//c est cette fenetre qui est appele dans le main et qui va creer les fenetres admin et client

namespace Ui {
class fenetre_base;
}

class fenetre_base : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_base(QWidget *parent = nullptr);
    explicit fenetre_base(Bibliotheque *bibliotheque, QWidget *parent = nullptr);
    ~fenetre_base();

public slots:
    void on_quitter_clicked();
    void on_ok_clicked();

private:
    Bibliotheque *biblio = new Bibliotheque;
    Ui::fenetre_base *ui;
};

#endif // FENETRE_BASE_H
