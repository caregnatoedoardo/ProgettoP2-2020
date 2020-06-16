#include "usermenu.h"

Usermenu::Usermenu(QWidget* p):parent(p),
    menu(new QMenu("File",this)),
    salva(new QAction("Salva",this)),
    carica(new QAction("Carica",this)),
    visualizza(new QAction("Visualizza",this)),
    visualizzaVenduti(new QAction("Visualizza Venduti",this)),
    ricerca(new QAction("Ricerca",this)),
    inserisci(new QAction("Inserisci",this))

{
    QList<QAction*> actionList;
    actionList.push_back(ricerca);
    actionList.push_back(salva);
    actionList.push_back(carica);
    actionList.push_back(inserisci);
    actionList.push_back(visualizza);
    actionList.push_back(visualizzaVenduti);


    menu->addActions(actionList);
    actionList.clear();

    addMenu(menu);
    addAction(inserisci);
    addAction(visualizza);
    addAction(ricerca);

    actionList.clear();


    connect(salva, SIGNAL(triggered()),parent,SLOT(slotSalva()));
    connect(carica, SIGNAL(triggered()),parent,SLOT(slotLoad()));
    connect(ricerca, SIGNAL(triggered()),parent,SLOT(slotShowRicerca()));
    connect(inserisci, SIGNAL(triggered()),parent,SLOT(slotShowInserisci()));
    connect(visualizza,SIGNAL(triggered()),parent,SLOT(slotShowVisualizza()));
    connect(visualizzaVenduti,SIGNAL(triggered()),parent,SLOT(slotShowVisualizzaVenduti()));
}

QMenu* Usermenu::getMenu()const{return menu;}

QAction* Usermenu::getSalva() const{return salva;}

QAction* Usermenu::getCarica() const{return carica;}

QAction* Usermenu::getEsci() const{return esci;}
