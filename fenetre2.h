#ifndef FENETRE2_H
#define FENETRE2_H

#include <QDialog>
#include "fenetreressource.h"

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
    void on_retour2_clicked();
private:
    Ui::fenetre2 *ui;
};

#endif // FENETRE2_H
