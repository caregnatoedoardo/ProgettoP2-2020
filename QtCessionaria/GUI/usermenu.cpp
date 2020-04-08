#include "usermenu.h"

Usermenu::Usermenu(QWidget* p):parent(p),
    menu(new QMenu("File",this)),
    salva(new QAction("Salva",this)),
    carica(new QAction("Carica",this)),
    esci(new QAction("Esci",this)),

    ricerca(new QAction("Ricerca",this)),
    inserisci(new QAction("Inserisci",this))

{

    QList<QAction*> actionList;
    actionList.push_back(salva);
    actionList.push_back(carica);
    actionList.push_back(esci);

    menu->addActions(actionList);

    addMenu(menu);
    addAction(ricerca);
    addAction(inserisci);

}
