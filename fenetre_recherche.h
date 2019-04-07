#ifndef FENETRE_RECHERCHE_H
#define FENETRE_RECHERCHE_H

#include <QDialog>
#include "fenetre2.h"
namespace Ui {
class fenetre_recherche;
}

class fenetre_recherche : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_recherche(QWidget *parent = nullptr);    
    ~fenetre_recherche();

public slots:
    void on_ok_clicked();
    void on_retour_clicked();

private:
    Bibliotheque *biblio_recherche = new Bibliotheque;
    Ui::fenetre_recherche *ui;
};

#endif // FENETRE_RECHERCHE_H
