#include "fenetre_livre.h"
#include "ui_fenetre_livre.h" //open + nom du fichier

int fenetre_livre::nb_livre = 0;

fenetre_livre::fenetre_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_livre)
{
    ui->setupUi(this);
    QObject::connect(ui->retourlivre, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->oklivre, SIGNAL(clicked()), this, SLOT(close()));

}


fenetre_livre::~fenetre_livre()
{
    delete ui;
}

void fenetre_livre::on_retourlivre_clicked()
{
    delete ui;
}


void fenetre_livre::on_quitterlivre_clicked()
{
    qApp->quit();
}


void fenetre_livre::on_oklivre_clicked()
{    
    get_texte();   
    ui->titre->setText("");
    ui->collection->setText("");
    ui->resume->setText("");
    ui->nb_pages->setText("");
    ui->annee->setText("");
    ui->auteur->setText("");
}

void fenetre_livre::get_texte()
{

    if(ui->collection->text() == 0 || ui->annee->text() == 0 || ui->nb_pages->text() == 0 || ui->titre->text() == 0
            || ui->resume->text() == 0 || ui->auteur->text() == 0){
        qCritical() << "erreur d'ajout d'un livre a cause d'un espace vide" << endl;
        return;
    }

    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QString buffer1;
    int buffer_livre;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("LIV")){
            buffer_livre = word.front().digitValue();
        }

        buffer1 = in.readLine();
        QString word_buffer = in.read(1);
    }
    labaseRecherche.close();


    if(!labaseRecherche.open(QIODevice::Append)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }


    in << QString::number(buffer_livre+1);
    in << "LIVRE: ";
    in << "[titre]:";
    in << ui->titre->text();
    in << "; [auteur]:";
    in << ui->auteur->text();
    in << "; [annee]:";
    in << ui->annee->text();
    in << "; [nombre de pages]:";
    in << ui->nb_pages->text();
    in << "; [collection]:";
    in << ui->collection->text();
    in << "; [resume]:";
    in << ui->resume->text();
    in << "\n\n";

    ajout_ok();
    labaseRecherche.close();

}

void fenetre_livre::ajout_ok()
{
    ++nb_livre;
}

int fenetre_livre::nb_livre1()
{
    return nb_livre;
}


