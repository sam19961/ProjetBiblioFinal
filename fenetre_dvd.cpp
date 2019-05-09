#include "fenetre_dvd.h"
#include "ui_fenetre_dvd.h"

int fenetre_DVD::nb_dvd = 0;

fenetre_DVD::fenetre_DVD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_DVD)
{    
    ui->setupUi(this);       
}


fenetre_DVD::~fenetre_DVD()
{
    delete ui;
}

void fenetre_DVD::on_retour_clicked()
{

    ui->nom->setText("");
    ui->maison->setText("");
    ui->duree->setText("");
    ui->auteur->setText("");
    ui->fid->setText("");
    this->close();
}

void fenetre_DVD::on_ok_clicked()
{

    get_texte();
    ui->nom->setText("");
    ui->maison->setText("");
    ui->duree->setText("");
    ui->auteur->setText("");
    ui->fid->setText("");
    this->close();
}

void fenetre_DVD::on_quitter_clicked()
{
    qApp->quit();
}


void fenetre_DVD::get_texte()
{    
    //test qu'aucun champ ne soit vide
    if(ui->nom->text() == 0 || ui->maison->text() == 0 || ui->auteur->text() == 0 || ui->duree->text() == 0 || ui->nbPiste->text() == 0 || ui->fid->text() == 0){
        qCritical() << "erreur dans l'ajout d'un DVD/CD espace vide" << endl;
        return;
    }

    QFile labaseRecherche(SAUVEGARDE);
    QString buffer1;
    int buffer_dvd, buffer_cd;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("DVD")){
            buffer_dvd = word.front().digitValue();
        }
        else if(word.contains("CD")){
            buffer_cd = word.front().digitValue();
        }

        buffer1 = in.readLine();
        QString word_buffer = in.read(1);
    }
    labaseRecherche.close();


    if(!labaseRecherche.open(QIODevice::Append)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    if(ui->iscd->isChecked()){
        in << QString::number(buffer_cd+1);
        in << "CD: ";
    }
    else{
        in << QString::number(buffer_dvd+1);
        in << "DVD: ";
    }
    in << "[nom]:";
    in << ui->nom->text();
    in << "; [duree]:";
    in << ui->duree->text();
    in << "; [auteur]:";
    in << ui->auteur->text();
    in << "; [maison de prod]:";
    in << ui->maison->text();
    in << "; [nombre de pistes]:";
    in << ui->nbPiste->text();
    in << "; [id]:";
    in << ui->fid->text();
    in << "\n\n";
    ajout_ok();
    labaseRecherche.close();
}

void fenetre_DVD::ajout_ok()
{
    ++nb_dvd;
}

int fenetre_DVD::nb_dvd1()
{
    return nb_dvd;
}
