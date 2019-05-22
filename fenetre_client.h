#ifndef FENETRE_CLIENT_H
#define FENETRE_CLIENT_H

#include <QDialog>
#include "fenetreprincipale.h"
namespace Ui {
class fenetre_client;
}

class fenetre_client : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_client(QWidget *parent = nullptr);
    explicit fenetre_client(Bibliotheque* bibliotheque1,QWidget *parent = nullptr);
    ~fenetre_client();

public slots:    
    void on_quitter_clicked();
    void on_recherche_clicked();
    void on_afficher_clicked();
    void on_emprunter_clicked();
    void on_rendre_clicked();
    void on_chat1_clicked();

private:
    Ui::fenetre_client *ui;
    //fenetre_recherche* frecherche = new fenetre_recherche;
    fenetre2* f2 = new fenetre2;
    Bibliotheque* biblio = new Bibliotheque;
    Fenserveur* fserv = new Fenserveur;
    clientside* fclientS = new clientside;
    static int taille_bibliotheque;

};

#endif // FENETRE_CLIENT_H
