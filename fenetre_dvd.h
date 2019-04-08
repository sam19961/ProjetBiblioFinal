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
    void get_texte();
    void ajout_ok();
    int nb_dvd1();

public slots:
    void on_quitter_clicked();
    void on_ok_clicked();
    void on_retour_clicked();

private:
    Bibliotheque *bibliotheque1 = new Bibliotheque;
    Ui::fenetre_DVD *ui;
    QString buffer;
    static int nb_dvd;
};

#endif // FENETRE_DVD_H
