#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

int FenetrePrincipale::taille_bibliotheque = 0;

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
    taille_bibliotheque = biblio->taille_biblio() + 1;
    qDebug() << taille_bibliotheque << endl;
    ui->numero_retirer->setMinimum(1);
    ui->numero_retirer->setMaximum(taille_bibliotheque);
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);        
}


FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;    
    delete frecherche;
    delete flivre;
    delete frevue;
    delete fdvd;
    delete fvideo;
    delete fressource;
    delete biblio;
}


void FenetrePrincipale::on_quitter_clicked()
{
    qApp->quit();
}

void FenetrePrincipale::on_afficher_clicked()
{
    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    biblio->load(&labaseRecherche);
    fenetre2* f2 = new fenetre2(biblio);
    taille_bibliotheque = biblio->taille_biblio() +1;
    qDebug() << taille_bibliotheque << endl;
    ui->numero_retirer->setMaximum(taille_bibliotheque);
    //ui->numero_retirer->setMaximum(taille_bibliotheque); //voir pour changer la valeur max de l'objet a retirer
    f2->show();    
}

void FenetrePrincipale::on_ajouter_clicked()
{
    if(ui->choix->currentText() == "Livre"){        
        flivre->show();
    }
    else if(ui->choix->currentText() == "Revue"){               
        frevue->show();
    }
    else if(ui->choix->currentText() == "CD/DVD"){        
        fdvd->show();
    }
    else if(ui->choix->currentText() == "Video"){        
        fvideo->show();
    }
    else {        
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
    --taille_bibliotheque;

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
    QString command("open ../../../../bibliotheque1/loadFichier.txt");
    system(qPrintable(command));
}


void FenetrePrincipale::on_save1_clicked()
{
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QFile *baseDeDonneeBuffer;
    baseDeDonneeBuffer = biblio->sauvegarde(&labase);
    QString command("open ../../../../bibliotheque1/sauvegardeArmoire.txt");
    system(qPrintable(command));
}

void FenetrePrincipale::afficher_bibliotheque()
{
    biblio->affichage();

}

void FenetrePrincipale::afficher_BaseDeDonnee()
{
    biblio->afficher_BaseDeDonnee();

}
