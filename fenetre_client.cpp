#include "fenetre_client.h"
#include "ui_fenetre_client.h"

int fenetre_client::taille_bibliotheque = 0;

fenetre_client::fenetre_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_client)
{
    ui->setupUi(this);
}


fenetre_client::fenetre_client(Bibliotheque* bibliotheque1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_client)
{
    ui->setupUi(this);
    biblio->egale(*bibliotheque1);
    taille_bibliotheque = biblio->taille_biblio() + 1;
    ui->numero_retirer->setMinimum(1);
    ui->numero_retirer->setMaximum(taille_bibliotheque);

    qDebug() << taille_bibliotheque << endl;

    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
}

void fenetre_client::on_quitter_clicked()
{
    qApp->quit();
}

void fenetre_client::on_recherche_clicked()
{
    frecherche->show();
}

void fenetre_client::on_afficher_clicked()
{
    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    biblio->load(&labaseRecherche);        
    taille_bibliotheque = biblio->taille_biblio() + 1;
    ui->numero_retirer->setMaximum(taille_bibliotheque);
    fenetre2* f2 = new fenetre2(biblio);
    f2->show();
}

fenetre_client::~fenetre_client()
{
    delete ui;
}

void fenetre_client::on_retirer_clicked()
{
    biblio->deleteId(ui->numero_retirer->value());
    ui->numero_retirer->setMaximum(biblio->taille_biblio());
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
    --taille_bibliotheque;
    ui->numero_retirer->setMaximum(taille_bibliotheque);

}
