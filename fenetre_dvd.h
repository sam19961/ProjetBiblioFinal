#ifndef FENETRE_DVD_H
#define FENETRE_DVD_H

#include <QDialog>
#include "fenetre_video.h"

namespace Ui {
class fenetre_DVD;
}

class fenetre_DVD : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_DVD(QWidget *parent = nullptr);    
    ~fenetre_DVD();
    void get_texte(); //récupère les informations lors de l'ajout d'un dvd
    void ajout_ok(); //incrémente nb_dvd
    int nb_dvd1(); //renvoie nb_dvd

public slots:
    void on_quitter_clicked();
    void on_ok_clicked();
    void on_retour_clicked();

private:
    Bibliotheque *bibliotheque1 = new Bibliotheque;
    Ui::fenetre_DVD *ui;    
    static int nb_dvd;
};

#endif // FENETRE_DVD_H
