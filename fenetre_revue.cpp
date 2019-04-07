#include "fenetre_revue.h"
#include "ui_fenetre_revue.h"

fenetre_revue::fenetre_revue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_revue)
{
    ui->setupUi(this);
    QObject::connect(ui->retour, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->ok, SIGNAL(clicked()), this, SLOT(close()));
}


fenetre_revue::~fenetre_revue()
{
    delete ui;
}
void fenetre_revue::on_retour_clicked()
{
    delete ui;
}

void fenetre_revue::on_quitter_clicked()
{
    qApp->quit();
}


void fenetre_revue::on_ok_clicked()
{
    get_texte();
    ui->titre->setText("");
    ui->collection->setText("");
    ui->resume->setText("");
    ui->nb_page->setText("");
    ui->annee->setText("");
    ui->editeur->setText("");
    ui->auteur->setText("");
    ui->nb_article->setText("");
}

void fenetre_revue::get_texte()
{    
    if(ui->collection->text() == 0 || ui->annee->text() == 0 || ui->nb_page->text() == 0 || ui->titre->text() == 0
            || ui->resume->text() == 0 || ui->auteur == 0 || ui->editeur == 0 || ui->nb_article == 0){
        qCritical() << "erreur dans l'ajout d'une revue espace vide" << endl;
        return;
    }


    QFile labaseRecherche("../../../../bibliotheque1/sauvegardeArmoire.txt");
    QString buffer1;
    int buffer_revue;
    QTextStream in(&labaseRecherche);

    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    while(!in.atEnd()){
        QString word = in.read(4);

        if(word.contains("REV")){
            buffer_revue = word.front().digitValue();
        }

        buffer1 = in.readLine();
        QString word_buffer = in.read(1);
    }
    labaseRecherche.close();


    if(!labaseRecherche.open(QIODevice::Append)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }


    in << QString::number(buffer_revue+1);
    in << "REVUE: ";
    in << "[titre]:";
    in << ui->titre->text();
    in << "; [auteur]:";
    in << ui->auteur->text();
    in << "; [annee]:";
    in << ui->annee->text();
    in << "; [nombre de pages]:";
    in << ui->nb_page->text();
    in << "; [collection]:";
    in << ui->collection->text();
    in << "; [resume]:";
    in << ui->resume->text();
    in << ";[editeur]:";
    in << ui->editeur->text();
    in << ";[nombre d'articles]:";
    in << ui->nb_article->text();
    in << "\n\n";

    labaseRecherche.close();
}


