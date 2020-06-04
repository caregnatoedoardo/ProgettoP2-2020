#include "usermenu.h"

Usermenu::Usermenu(QWidget* p):parent(p),
    menu(new QMenu("File",this)),
    salva(new QAction("Salva",this)),
    carica(new QAction("Carica",this)),
    visualizza(new QAction("Visualizza",this)),
    ricerca(new QAction("Ricerca",this)),
    esci(new QAction("Esci",this)),
    inserisci(new QAction("Inserisci",this))

{

    QList<QAction*> actionList;
    actionList.push_back(ricerca);
    actionList.push_back(salva);
    actionList.push_back(carica);
    actionList.push_back(inserisci);
    actionList.push_back(visualizza);
    actionList.push_back(esci);

    menu->addActions(actionList);
   actionList.clear();

    addMenu(menu);
    addAction(inserisci);
    addAction(visualizza);
    addAction(ricerca);

    actionList.clear();

   connect(esci, SIGNAL(triggered()),parent,SLOT(slotClose()));
   connect(salva, SIGNAL(triggered()),parent,SLOT(slotSalva()));
   connect(carica, SIGNAL(triggered()),parent,SLOT(slotCarica()));
   connect(ricerca, SIGNAL(triggered()),parent,SLOT(slotShowRicerca()));
   connect(inserisci, SIGNAL(triggered()),parent,SLOT(slotShowInserisci()));
   connect(visualizza,SIGNAL(triggered()),parent,SLOT(slotShowVisualizza()));
}


QMenu* Usermenu::getMenu()const {
    return menu;
}

QAction* Usermenu::getSalva() const {
    return salva;
}

QAction* Usermenu::getCarica() const {
    return carica;
}

QAction* Usermenu::getEsci() const {
    return esci;
}
