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
    ui->image->setPixmap(QPixmap("/Users/sam/Documents/projet_bibliotheque/image.png"));

    QPixmap bkgnd("/Users/sam/Documents/projet_bibliotheque/fond2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    biblio->egale(*bibliotheque1);
    taille_bibliotheque = biblio->taille_biblio();
    ui->numero_emprunter->setMinimum(1);
    ui->numero_emprunter->setMaximum(taille_bibliotheque);
    ui->numero_rendre->setMinimum(1);
    ui->numero_rendre->setMaximum(taille_bibliotheque);

    ui->lcdNombre->display(taille_bibliotheque);

}

void fenetre_client::on_quitter_clicked()
{
    qApp->quit();
}

void fenetre_client::on_recherche_clicked()
{
    fenetre_recherche* frecherche = new fenetre_recherche;
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
    frecherche->show();
}

void fenetre_client::on_afficher_clicked()
{    
    QFile labaseRecherche(SAUVEGARDE);
    biblio->load(&labaseRecherche);        
    taille_bibliotheque = biblio->taille_biblio();
    ui->numero_emprunter->setMaximum(taille_bibliotheque);
    ui->numero_rendre->setMaximum(taille_bibliotheque);
    fenetre2* f2 = new fenetre2(biblio);
    ui->lcdNombre->display(taille_bibliotheque);      
    f2->show();
}

fenetre_client::~fenetre_client()
{
    delete ui;
    delete f2;
    delete biblio;
}

void fenetre_client::on_emprunter_clicked()
{
    biblio->emprunter_objet(ui->numero_emprunter->value());
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);

}

void fenetre_client::on_rendre_clicked()
{
    biblio->rendre_objet(ui->numero_rendre->value());
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
}

void fenetre_client::on_chat1_clicked()
{
    fclientS->show();
}
