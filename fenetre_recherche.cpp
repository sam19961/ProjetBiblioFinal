#include "fenetre_recherche.h"
#include "ui_fenetre_recherche.h"

fenetre_recherche::fenetre_recherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_recherche)
{
    ui->setupUi(this);    
    ui->resultat->setReadOnly(1);
    QFile labase2("../../../../bibliotheque1/sauvegardeArmoire.txt");
    biblio_recherche->load(&labase2);
    biblio_recherche->Clear();
    biblio_recherche->afficher_BaseDeDonnee();
}


fenetre_recherche::~fenetre_recherche()
{
    delete ui;
}

void fenetre_recherche::on_ok_clicked()
{
    QString buffer;
    QFile labase("../../../../bibliotheque1/base_de_donnee.txt");
    buffer = ui->barre_recherche->text();
    biblio_recherche->recherche(buffer, &labase);
    biblio_recherche->sauvegarde_base_de_donnee(&labase);
    ui->resultat->setText(biblio_recherche->information_biblio(&labase));
}


void fenetre_recherche::on_retour_clicked()
{
    ui->barre_recherche->setText("");
    ui->resultat->setText("");
    biblio_recherche->Clear();
    this->close();
}
