#ifndef USERMENU_H
#define USERMENU_H


#include <QObject>
#include <qmenubar.h>
#include <qwidget.h>


class Usermenu : public QMenuBar {
    Q_OBJECT
private:
    QWidget* parent;
    QMenu* menu;
    QMenu* menuOperation;

    QAction* salva;
    QAction* carica;
    QAction* visualizza;
    QAction* visualizzaVenduti;
    QAction* ricerca;
    QAction* inserisci;
    QAction* esci;

public:

    Usermenu(QWidget* = nullptr);
    QMenu *getMenu() const;
    QAction *getSalva() const;
    QAction *getCarica() const;
    QAction *getRicerca() const;
    QAction *getInserici() const;
    QAction *getEsci() const;

};


#endif // USERMENU_H
