#include "fenetre_video.h"
#include "ui_fenetre_video.h"

int fenetre_video::nb_video = 0;

fenetre_video::fenetre_video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_video)
{
    ui->setupUi(this);        
}

fenetre_video::~fenetre_video()
{
    delete ui;
}

void fenetre_video::on_retour_clicked()
{    
    ui->nom->setText("");
    ui->maison->setText("");
    ui->duree->setText("");
    ui->auteur->setText("");
    ui->fid->setText("");
    this->close();
}

void fenetre_video::on_ok_clicked()
{
    get_texte();
    ui->nom->setText("");
    ui->maison->setText("");
    ui->duree->setText("");
    ui->auteur->setText("");
    ui->fid->setText("");
    this->close();
}

void fenetre_video::on_quitter_clicked()
{
    qApp->quit();
}


void fenetre_video::get_texte()
{    
    if(ui->nom->text() == 0 || ui->maison->text() == 0 || ui->auteur->text() == 0 || ui->duree->text() == 0 || ui->fid->text() == 0){
        qCritical() << "erreur dans l'ajout d'une video espace vide" << endl;
        return;
    }

    QFile labaseRecherche(SAUVEGARDE);
    QString buffer1;
    int buffer_video;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("VID")){
            buffer_video = word.front().digitValue();
        }

        buffer1 = in.readLine();
        QString word_buffer = in.read(1);
    }
    labaseRecherche.close();


    if(!labaseRecherche.open(QIODevice::Append)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    in << QString::number(buffer_video+1);
    in << "VIDEO: ";
    in << "[nom]:";
    in << ui->nom->text();
    in << "; [duree]:";
    in << ui->duree->text();
    in << "; [auteur]:";
    in << ui->auteur->text();
    in << "; [maison de prod]:";
    in << ui->maison->text();
    in << "; [id]:";
    in << ui->fid->text();
    in << "\n\n";
    ajout_ok();
    labaseRecherche.close();
}

void fenetre_video::ajout_ok()
{
    ++nb_video;
}

int fenetre_video::nb_video1()
{
    return nb_video;
}

