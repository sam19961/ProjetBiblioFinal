#ifndef FENETRERESSOURCE_H
#define FENETRERESSOURCE_H

#include <QDialog>
#include "fenetre_dvd.h"

namespace Ui {
class fenetreressource;
}

class fenetreressource : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreressource(QWidget *parent = nullptr);    
    ~fenetreressource();
    void get_texte();
    void ajout_ok();
    int nb_ressource1();

public slots:
    void on_quitter_clicked();
    void on_ok_clicked();
    void on_retour_clicked();

private:
    Bibliotheque *bibliotheque1 = new Bibliotheque;
    Ui::fenetreressource *ui;    
    static int nb_ressource;
};

#endif // FENETRERESSOURCE_H
