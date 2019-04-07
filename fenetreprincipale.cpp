#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
}

FenetrePrincipale::FenetrePrincipale(Bibliotheque *bibliotheque, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
    biblio->egale(*bibliotheque);
    ui->numero_retirer->setMinimum(1);
    ui->numero_retirer->setMaximum(biblio->taille_biblio()+1);
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
    qDebug() << "dans la fct principale \n \n " << endl;
    biblio->affichage();
    biblio->afficher_BaseDeDonnee();
}


FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;    
    delete frecherche;
}


void FenetrePrincipale::on_quitter_clicked()
{
    qApp->quit();
}

void FenetrePrincipale::on_afficher_clicked()
{
    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    biblio->load(&labaseRecherche);
    qDebug() << "print de la FONCTION PRINCIPALE" << endl;
    biblio->affichage();
    qDebug() << "print de la FONCTION PRINCIPALE" << endl;
    fenetre2* f2 = new fenetre2(biblio);
    f2->show();
}

void FenetrePrincipale::on_ajouter_clicked()
{
    if(ui->choix->currentText() == "Livre"){
        fenetre_livre* flivre = new fenetre_livre;
        flivre->show();

    }
    else if(ui->choix->currentText() == "Revue"){       
        fenetre_revue* frevue = new fenetre_revue;
        frevue->show();
    }
    else if(ui->choix->currentText() == "CD/DVD"){
        fenetre_DVD* fdvd = new fenetre_DVD;
        fdvd->show();
    }
    else if(ui->choix->currentText() == "Video"){
        fenetre_video* fvideo = new fenetre_video;
        fvideo->show();
    }
    else {
        fenetreressource* fressource = new fenetreressource;
        fressource->show();
    }

}

void FenetrePrincipale::on_retirer_clicked()
{
    biblio->deleteId(ui->numero_retirer->value());
    ui->numero_retirer->setMaximum(biblio->taille_biblio());
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);

}

void FenetrePrincipale::on_clear1_clicked()
{
    //biblio->Clear();

}


void FenetrePrincipale::on_recherche_clicked()
{
    frecherche->show();
}

void FenetrePrincipale::on_loading_clicked()
{
    QFile exemple_fichier("../../../../bibliotheque1/loadFichier.txt");
    biblio->load(&exemple_fichier);
}


void FenetrePrincipale::on_save1_clicked()
{
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *baseDeDonneeBuffer;
    baseDeDonneeBuffer = biblio->sauvegarde(&labase);
}

void FenetrePrincipale::afficher_bibliotheque()
{
    biblio->affichage();

}

void FenetrePrincipale::afficher_BaseDeDonnee()
{
    biblio->afficher_BaseDeDonnee();

}
