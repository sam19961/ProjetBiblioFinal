#include "fenetre2.h"
#include "ui_fenetre2.h"

fenetre2::fenetre2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre2)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(1);
    QObject::connect(ui->retour2, SIGNAL(clicked()), this, SLOT(close()));
}

fenetre2::fenetre2(Bibliotheque *bibliotheque, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre2)
{
    QString buffer;
    QFile labase("../../../../bibliotheque1/sauvegardeArmoire.txt");
    buffer = bibliotheque->information_biblio(&labase);
    ui->setupUi(this);
    ui->textEdit->setReadOnly(1);
    ui->textEdit->setText(buffer);
    QObject::connect(ui->retour2, SIGNAL(clicked()), this, SLOT(close()));

}

fenetre2::~fenetre2()
{
    delete ui;
}

void fenetre2::on_retour2_clicked()
{
    delete ui;
}


