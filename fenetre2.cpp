#include "fenetre2.h"
#include "ui_fenetre2.h"

fenetre2::fenetre2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre2)
{
    ui->setupUi(this);     
}

fenetre2::fenetre2(Bibliotheque *bibliotheque, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre2)
{
    ui->setupUi(this);
    QString buffer;    
    buffer = bibliotheque->information_armoire(); //renvoie un QString avec tout ce qui est dans l'armoire de notre bibliothèque
    ui->textEdit->setReadOnly(1);
    ui->textEdit->setText(buffer);   
}

fenetre2::~fenetre2()
{
    delete ui;
}

void fenetre2::on_retour2_clicked()
{
    this->close();
}


