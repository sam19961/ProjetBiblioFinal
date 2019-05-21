#include "fenetre_base.h"
#include <QApplication>
#include <QtDebug>

// livre->revue->video->dvd->ressource->biblio->fenetrelivre->fenetrerevue->fenetrevideo
//->fenetredvd->fenetreressource->fenetre2->fenetre_recherche->fenetreprincipal->fclient->fbase->fenetreMain
//plusieurs clients qui utilisent des bases de donnees
//recup la date du fichier.

// includes: livre->revue->video->dvd->ressource->biblio->main (biblio)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bibliotheque b1;
    Livre l1("Albert Einstein",1916,220,"SBP","Relativity","un livre de science", 1, "dispo");
    Video v1(194, "James Cameron", "20th Century Fox", "Titanic", 2, "dispo");
    DVD d1(162, "James Cameron", "Dune Entertainment", "Avatar", 2, 1, 3, "dispo");
    RessourceNum r1(123, "jean michel", PDF, "du lesa.txt", "C//ici/maybela/avoila", 4, "dispo");
    Livre l2("Stephen Hawking",1988,236,"Flammarion","Une brève histoire","un autre livre de science", 5, "dispo");
    Revue rev1("myke",2005,200,"hsbc","science et vie","une revue de science","le S",3, 0, "dispo");
    DVD c1(110,"PLK","Fifou","Polak",12,0, 7, "dispo");
    Livre l3("Victor Hugo",1862,2400,"Kindle","Les misérables","un livre connu",16,"dispo");
    Livre l4("JK Rowling",2001,308,"Bloomsburry","Harry Potter","un beau livre",22,"dispo");
    DVD c2(120,"PNL","QLF records","Nabil et Tarek",17,0,58,"dispo");
    DVD c3(140,"Alpha Wann","Universal","Omar",20,0,777,"dispo");
    Video v2(180,"Russo","Marvel studio","Avengers",54,"dispo");
    Video v3(111,"Alan Moore","DC Comics","Watchmen",19,"dispo");
    Video v4(121,"Ryan Coogler","New line","Creed",27,"dispo");


    b1.ajouter(l1);
    b1.ajouter(v1);
    b1.ajouter(d1);
    b1.ajouter(r1);
    b1.ajouter(l2);
    b1.ajouter(rev1);
    b1.ajouter(c1);
    b1.ajouter(l3);
    b1.ajouter(l4);
    b1.ajouter(c2);
    b1.ajouter(c3);
    b1.ajouter(v2);
    b1.ajouter(v3);
    b1.ajouter(v4);
    b1.affichage();

    fenetre_base fbase(&b1);
    fenetre_base fbase1(&b1);
    fenetre_base fbase2(&b1);
    fbase.show();
    fbase1.show();
    fbase2.show();
    return a.exec();
}
