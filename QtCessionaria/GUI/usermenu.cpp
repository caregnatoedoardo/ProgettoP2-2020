#include "usermenu.h"

Usermenu::Usermenu(QWidget* p):parent(p),
    menu(new QMenu("File",this)),
    menuOperation(new QMenu("Azioni Operative",this)),
    salva(new QAction("Salva",this)),
    carica(new QAction("Carica",this)),
    visualizza(new QAction("Visualizza",this)),
    visualizzaVenduti(new QAction("Visualizza Venduti",this)),
    ricerca(new QAction("Ricerca",this)),
    inserisci(new QAction("Inserisci",this)),
    esci(new QAction("Esci",menu))

{
    QList<QAction*> actionList;

    actionList.push_back(salva);
    actionList.push_back(carica);

    actionList.push_back(esci);

    QList<QAction*> operationList;
    operationList.push_back(inserisci);
    operationList.push_back(visualizza);
    operationList.push_back(visualizzaVenduti);
    operationList.push_back(ricerca);

    menu->addActions(actionList);
    menuOperation->addActions(operationList);

    operationList.clear();
    actionList.clear();

    addMenu(menu);
    addMenu(menuOperation);


    connect(salva, SIGNAL(triggered()),parent,SLOT(slotSalva()));
    connect(carica, SIGNAL(triggered()),parent,SLOT(slotLoad()));
    connect(ricerca, SIGNAL(triggered()),parent,SLOT(slotShowRicerca()));
    connect(inserisci, SIGNAL(triggered()),parent,SLOT(slotShowInserisci()));
    connect(visualizza,SIGNAL(triggered()),parent,SLOT(slotShowVisualizza()));
    connect(visualizzaVenduti,SIGNAL(triggered()),parent,SLOT(slotShowVisualizzaVenduti()));
    connect(esci,SIGNAL(triggered()),parent,SLOT(slotSalva()));
    connect(esci,SIGNAL(triggered()),parent,SLOT(close()));

}

QMenu* Usermenu::getMenu()const{return menu;}

QAction* Usermenu::getSalva() const{return salva;}

QAction* Usermenu::getCarica() const{return carica;}

QAction* Usermenu::getEsci() const{return esci;}
