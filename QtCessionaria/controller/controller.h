#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QObject>
#include<QWidget>
#include "container/container.h"
#include "GUI/usermenu.h"
#include "GUI/insertveicolo.h"
#include "GUI/groupview.h"
#include "GUI/viewveicolo.h"
#include "GUI/ricerca.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "model.h"

class Controller:public QWidget{
     Q_OBJECT
private:


   Model* model;
   Usermenu* menuUtente;
   QHBoxLayout* mainLayout;
   InsertVeicolo* inserisciVeicolo;
   Ricerca* ricercaView;
   GroupView* groupView;
   ViewVeicolo* dialog;
public:
   Controller(Model*,QWidget* = nullptr);
   Model *getModel();
   ~Controller();
   string getTarga()const;
public slots:
   /*



    void slotResetRicerca() const;
*/
    void closeEvent(QCloseEvent*);
    void slotShowRicerca() const;
    void slotRicerca()const;
    void slotEliminaElemento() const;
    void slotSalva() const;
    void slotLoad();
    void slotAggiungiVeicolo() const;
    void slotFlagDataChange(bool flag)const;
    void slotShowInserisci() const;
    void slotShowVisualizza() const;
    void slotShowModifica() ;
};

#endif // CONTROLLER_H
