QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = projet_bibliotheque
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        ../serveurside/fenserveur.cpp \
        ../clientside/clientside.cpp \
        ../bibliotheque1/livre.cpp \
        ../bibliotheque1/revue.cpp \
        ../bibliotheque1/video.cpp \
        ../bibliotheque1/dvd.cpp \
        ../bibliotheque1/ressource.cpp \
        ../bibliotheque1/bibliotheque.cpp \
        fenetreprincipale.cpp \
        fenetre2.cpp \
        fenetre_livre.cpp \
        fenetre_video.cpp \
        fenetre_dvd.cpp \
        fenetreressource.cpp \
        fenetre_revue.cpp \
        fenetre_recherche.cpp \
        fenetre_base.cpp \
        fenetre_client.cpp



HEADERS += \
        ../serveurside/fenserveur.h \
        ../clientside/clientside.h \
        ../bibliotheque1/livre.h \
        ../bibliotheque1/revue.h \
        ../bibliotheque1/video.h \
        ../bibliotheque1/dvd.h \
        ../bibliotheque1/ressource.h \
        ../bibliotheque1/bibliotheque.h \
        fenetreprincipale.h \
        fenetre2.h \
        fenetre_livre.h \
        fenetre_video.h \
        fenetre_dvd.h \
        fenetreressource.h \
        fenetre_revue.h \
        fenetre_recherche.h \
        fenetre_base.h \
        fenetre_client.h


FORMS += \
        ../serveurside/fenserveur.ui \
        ../clientside/clientside.ui \
        fenetreprincipale.ui \
        fenetre2.ui \
        fenetre_livre.ui \
        fenetre_video.ui \
        fenetre_dvd.ui \
        fenetreressource.ui \
        fenetre_revue.ui \
        fenetre_recherche.ui \
        fenetre_base.ui \
        fenetre_client.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
