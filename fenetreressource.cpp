#include "fenetreressource.h"
#include "ui_fenetreressource.h"

int fenetreressource::nb_ressource = 0;

fenetreressource::fenetreressource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreressource)
{
    ui->setupUi(this);        
}

fenetreressource::~fenetreressource()
{
    delete ui;
}

void fenetreressource::on_retour_clicked()
{
    ui->type->setText("");
    ui->nom->setText("");
    ui->auteur->setText("");
    ui->chemin->setText("");
    ui->taille->setText("");
    ui->fid->setText("");
    this->close();
}

void fenetreressource::on_quitter_clicked()
{
    qApp->quit();
}


void fenetreressource::on_ok_clicked()
{
    get_texte();
    ui->type->setText("");
    ui->nom->setText("");
    ui->auteur->setText("");
    ui->chemin->setText("");
    ui->taille->setText("");
    ui->fid->setText("");

}

void fenetreressource::get_texte()
{

    if(ui->nom->text() == 0 || ui->taille->text() == 0 || ui->chemin->text() == 0 || ui->type->text() == 0
            || ui->auteur->text() == 0 || ui->fid->text() == 0){
        qCritical() << "erreur ajout de ressource num espace vide" << endl;
        return;
    }

    QFile labaseRecherche(SAUVEGARDE);
    QString buffer1;
    int buffer_ressource;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("Res")){
            buffer_ressource = word.front().digitValue();
        }
        buffer1 = in.readLine();
        QString word_buffer = in.read(1);
    }
    labaseRecherche.close();


    if(!labaseRecherche.open(QIODevice::Append)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    in << QString::number(buffer_ressource+1);
    in << "Ressource Numerique: ";
    in << "[nom]:";
    in << ui->nom->text();
    in << "; [auteur]:";
    in << ui->auteur->text();
    in << "; [taille]:";
    in << ui->taille->text();
    in << "; [chemin d'acces]:";
    in << ui->chemin->text();
    in << "; [format]:";
    in << ui->type->text();
    in << "; [id]:";
    in << ui->fid->text();
    in << "\n\n";
    ajout_ok();    
    labaseRecherche.close();

}

void fenetreressource::ajout_ok()
{
    ++nb_ressource;
}

int fenetreressource::nb_ressource1()
{
    return nb_ressource;
}
