#include "fenetreressource.h"
#include "ui_fenetreressource.h"

fenetreressource::fenetreressource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetreressource)
{
    ui->setupUi(this);
    QObject::connect(ui->retour, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->ok, SIGNAL(clicked()), this, SLOT(close()));
}

fenetreressource::~fenetreressource()
{
    delete ui;
}

void fenetreressource::on_retour_clicked()
{
    delete ui;
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

}

void fenetreressource::get_texte()
{

    if(ui->nom->text() == 0 || ui->taille->text() == 0 || ui->chemin->text() == 0 || ui->type->text() == 0 || ui->auteur->text() == 0){
        qCritical() << "erreur ajout de ressource num espace vide" << endl;
        return;
    }

    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QString buffer1;
    int buffer_ressource;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("RES")){
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
    in << "\n\n";

    labaseRecherche.close();

}


