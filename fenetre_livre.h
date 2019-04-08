#ifndef FENETRE_LIVRE_H
#define FENETRE_LIVRE_H

#include <QDialog>
#include "../bibliotheque1/bibliotheque.h"

namespace Ui {
class fenetre_livre;
}

class fenetre_livre : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_livre(QWidget *parent = nullptr);
    ~fenetre_livre();
    void get_texte();
    void ajout_ok();
    int nb_livre1();

public slots:
    void on_quitterlivre_clicked();
    void on_oklivre_clicked();    
    void on_retourlivre_clicked();

private:    
    Bibliotheque *bibliotheque1 = new Bibliotheque;    
    Ui::fenetre_livre *ui;
    static int nb_livre;

};

#endif // FENETRE_LIVRE_H
