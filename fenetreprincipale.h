#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include "fenetre_recherche.h"
namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = nullptr);
    explicit FenetrePrincipale(Bibliotheque *bibliotheque, QWidget *parent = nullptr);
    ~FenetrePrincipale();    
    void afficher_bibliotheque();
    void afficher_BaseDeDonnee();

public slots:
    void on_quitter_clicked();
    void on_afficher_clicked();
    void on_ajouter_clicked();    
    void on_recherche_clicked();
    void on_loading_clicked();
    void on_save1_clicked();
    void on_retirer_clicked();
    void on_clear1_clicked();
    void on_tri_clicked();
    void on_afficher_load_clicked();
    void on_chat_utilisateur_clicked();

private:    
    Ui::FenetrePrincipale *ui;
    fenetre_livre* flivre = new fenetre_livre;
    fenetre_revue* frevue = new fenetre_revue;
    fenetre_DVD* fdvd = new fenetre_DVD;
    fenetre_video* fvideo = new fenetre_video;
    fenetreressource* fressource = new fenetreressource;
    Bibliotheque* biblio = new Bibliotheque;    
    fenetre_recherche* frecherche = new fenetre_recherche;

    static int taille_bibliotheque;
    QString buffer;

};

#endif // FENETREPRINCIPALE_H
