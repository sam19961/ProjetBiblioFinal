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

    //fond de la fenetre principale
    ui->image1->setPixmap(QPixmap("/Users/sam/Documents/projet_bibliotheque/image12.png"));

    QPixmap bkgnd("/Users/sam/Documents/projet_bibliotheque/fond2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
    ui->Date_heure->setText("Date et Heure: " + dateTimeString);


    //initialisation de la biblotheque de la fenetre, de la taille de la bibliotheque et sauvegarde dans le fichier
    //sauvegardeArmoire.txt
    biblio->egale(*bibliotheque);
    taille_bibliotheque = biblio->taille_biblio();    
    ui->lcdNombre->display(taille_bibliotheque);
    ui->numero_retirer->setMinimum(1);
    ui->numero_retirer->setMaximum(taille_bibliotheque);
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;   
    biblio_buffer = biblio->sauvegarde(&labase);
}


FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;        
    delete flivre;
    delete frevue;
    delete fdvd;
    delete fvideo;
    delete fressource;
    delete biblio;
    delete fserv;
    delete fclientS;
}


void FenetrePrincipale::on_quitter_clicked()
{
    qApp->quit();
}

void FenetrePrincipale::on_afficher_clicked()
{
    QFile labaseRecherche(SAUVEGARDE);
    biblio->load(&labaseRecherche);
    int nb_exemple = biblio->doublon();
    --nb_exemple;
    while(nb_exemple > 0){
        biblio->doublon(); //evite de mettre un doublon dans notre bibliotheque
        --nb_exemple;
    }    
    biblio->sauvegarde(&labaseRecherche);
    fenetre2* f2 = new fenetre2(biblio);
    taille_bibliotheque = biblio->taille_biblio();   
    ui->numero_retirer->setMaximum(taille_bibliotheque);
    ui->lcdNombre->display(taille_bibliotheque);
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
    biblio->deleteId(ui->numero_retirer->value()); //retire l element en fonction de sa place et pas de son id
    ui->numero_retirer->setMaximum(biblio->taille_biblio());
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
    --taille_bibliotheque;

}

void FenetrePrincipale::on_recherche_clicked()
{
    fenetre_recherche* frecherche = new fenetre_recherche;
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
    QFile labase(SAUVEGARDE);
    QFile *baseDeDonneeBuffer;
    baseDeDonneeBuffer = biblio->sauvegarde(&labase);
    QString command("open "  SAUVEGARDE);
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

void FenetrePrincipale::on_tri_clicked()
{

    if(ui->tri_choix->currentText() == "auteur"){
        biblio->tri_donnee(auteur);
    }
    else if(ui->tri_choix->currentText() == "id"){
        biblio->tri_donnee(id);
    }

    biblio->affichage();
    QFile labase(SAUVEGARDE);
    QFile *biblio_buffer;
    biblio_buffer = biblio->sauvegarde(&labase);
}

void FenetrePrincipale::on_afficher_load_clicked()
{
    fenetre2* fload = new fenetre2(biblio);
    fload->show();
}

void FenetrePrincipale::on_chat_utilisateur_clicked()
{    
    fclientS->show();
}

void FenetrePrincipale::on_server1_clicked()
{
    fserv->show();
}
