#ifndef FENETRE_VIDEO_H
#define FENETRE_VIDEO_H

#include <QDialog>
#include "fenetre_revue.h"

namespace Ui {
class fenetre_video;
}

class fenetre_video : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_video(QWidget *parent = nullptr);    
    ~fenetre_video();
    void get_texte();


public slots:
    void on_quitter_clicked();
    void on_ok_clicked();
    void on_retour_clicked();

private:
    Bibliotheque *bibliotheque1 = new Bibliotheque;
    Ui::fenetre_video *ui;    
};

#endif // FENETRE_VIDEO_H
