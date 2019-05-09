#ifndef FENETRE2_H
#define FENETRE2_H

#include <QDialog>
#include "fenetreressource.h"
//fenetre d'affichage du QTextEdit (lorsqu'on appuie sur le bouton afficher)
namespace Ui {
class fenetre2;
}

class fenetre2 : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre2(QWidget *parent = nullptr);
    explicit fenetre2(Bibliotheque *bibliotheque, QWidget *parent = nullptr);
    ~fenetre2();    

public slots:
    void on_retour2_clicked(); //on utilise les slots uniquement pour les click sur les QPushbutton dans ce projet
private:
    Ui::fenetre2 *ui;
};

#endif // FENETRE2_H
