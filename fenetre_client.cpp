#include "fenetre_client.h"
#include "ui_fenetre_client.h"

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
    qDebug() << "print de la FONCTION PRINCIPALE" << endl;
    biblio->affichage();
    qDebug() << "print de la FONCTION PRINCIPALE" << endl;
    fenetre2* f2 = new fenetre2(biblio);
    f2->show();
}

fenetre_client::~fenetre_client()
{
    delete ui;
}
