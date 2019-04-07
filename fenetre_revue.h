#ifndef FENETRE_REVUE_H
#define FENETRE_REVUE_H

#include "fenetre_livre.h"

namespace Ui {
class fenetre_revue;
}

class fenetre_revue : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_revue(QWidget *parent = nullptr);    
    ~fenetre_revue();
    void get_texte();

public slots:
    void on_quitter_clicked();
    void on_ok_clicked();    
    void on_retour_clicked();

private:
    Bibliotheque *bibliotheque1 = new Bibliotheque;
    Ui::fenetre_revue *ui;    
};

#endif // FENETRE_REVUE_H
