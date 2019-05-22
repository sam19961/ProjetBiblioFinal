#include "fenetre_livre.h"
#include "ui_fenetre_livre.h" //open + nom du fichier

int fenetre_livre::nb_livre = 0;

fenetre_livre::fenetre_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_livre)
{
    ui->setupUi(this);
    ui->titre->setText("Doublon"); //on remplit ces champs pour la présentation
    ui->collection->setText("test");
    ui->resume->setText("test");
    ui->nb_pages->setText("777");
    ui->annee->setText("2019");
    ui->auteur->setText("double");
    ui->fid->setText("1");
}


fenetre_livre::~fenetre_livre()
{
    delete ui;
}

void fenetre_livre::on_retourlivre_clicked()
{

    ui->titre->setText("");
    ui->collection->setText("");
    ui->resume->setText("");
    ui->nb_pages->setText("");
    ui->annee->setText("");
    ui->auteur->setText("");
    ui->fid->setText("");
    this->close();
    //delete ui;
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
    ui->fid->setText("");
    this->close();
}

void fenetre_livre::get_texte()
{

    //tests pour savoir si tous les champs sont bien rentrés par l'utilisateur
    if(ui->collection->text() == 0 || ui->annee->text() == 0 || ui->nb_pages->text() == 0 || ui->titre->text() == 0
            || ui->resume->text() == 0 || ui->auteur->text() == 0 || ui->fid->text() == 0){
        qCritical() << "erreur d'ajout d'un livre a cause d'un espace vide" << endl;
        return;
    }

    QFile labaseRecherche(SAUVEGARDE);
    QString buffer1;
    int buffer_livre;
    QTextStream in(&labaseRecherche);

    //verification de l'ouverture du fichier de sauvegarde armoire (armoire et non pas base de donnees)
    if(!labaseRecherche.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",labaseRecherche.errorString());
    }

    //cette partie nous permet de mettre a jour le nombre devant le livre dans l affichage
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
    in << "; [id]:";
    in << ui->fid->text();
    in << "\n\n";

    ajout_ok();
    labaseRecherche.close();
    //tout ce fait dans le fichier texte qu on va ensuite load dans notre biliotheque
    //cette partie aurait pu etre remplace en prenant un pointeur ou une reference sur une bibliotheque au niveau de la fenetre d ajout

}

void fenetre_livre::ajout_ok()
{
    ++nb_livre;
}

int fenetre_livre::nb_livre1()
{
    return nb_livre;
}


