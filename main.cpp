#include "fenetre_base.h"
#include <QApplication>
#include <QtDebug>

// livre->revue->video->dvd->ressource->biblio->fenetrelivre->fenetrerevue->fenetrevideo
//->fenetredvd->fenetreressource->fenetre2->fenetre_recherche->fenetreprincipal->fclient->fbase->fenetreMain
//plusieurs clients qui utilisent des bases de donnees

// includes: livre->revue->video->dvd->ressource->biblio->main (biblio)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bibliotheque b1;
    Livre l1("Albert Einstein",1916,220,"SBP","Relativity","un livre de science", 1);
    Video v1(194, "James Cameron", "20th Century Fox", "Titanic", 2);
    DVD d1(162, "James Cameron", "Dune Entertainment", "Avatar", 2, 1, 3);
    RessourceNum r1(123, "jean michel", PDF, "du lesa.txt", "C//ici/maybela/avoila", 4);
    Livre l2("Stephen Hawking",1988,236,"Flammarion","Une brève histoire","un autre livre de science", 5);
    Revue rev1("myke",2005,200,"hsbc","science et vie","une revue de science","le S",3, 0);
    DVD c1(50,"PLK","Fifou","Polak",12,0, 7);

    b1.ajouter(l1);
    b1.ajouter(v1);
    b1.ajouter(d1);
    b1.ajouter(r1);
    b1.ajouter(l2);
    b1.ajouter(rev1);
    b1.ajouter(c1);
    fenetre_base fbase(&b1);
    fbase.show();
    return a.exec();
}
