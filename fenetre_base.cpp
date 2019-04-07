#include "fenetre_base.h"
#include "ui_fenetre_base.h"

fenetre_base::fenetre_base(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_base)
{
    ui->setupUi(this);
}

fenetre_base::fenetre_base(Bibliotheque *bibliotheque, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_base)
{
    ui->setupUi(this);
    biblio->egale(*bibliotheque);
}

void fenetre_base::on_quitter_clicked()
{
    this->close();
}

void fenetre_base::on_ok_clicked()
{
    FenetrePrincipale *fprincipale = new FenetrePrincipale(biblio);
    fenetre_client *fclient = new fenetre_client;

    if(ui->mdp->text() == "admin"){
        fprincipale->show();
    }
    else {
        fclient->show();
    }
    this->close();
}

fenetre_base::~fenetre_base()
{
    delete ui;
}
