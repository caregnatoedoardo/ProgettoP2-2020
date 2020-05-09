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
private:
   Q_OBJECT

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

   /* void slotSalva() const;
    void slotDataChanged(bool) const;
    void slotRicerca();
    void slotLoad();

    void slotShowRicerca() const;

    void slotEliminaElemento() const;
    void slotShowVisualizza() const;
    void slotShowModifica();
    void slotResetRicerca() const;


    void closeEvent(QCloseEvent*);
*/
void slotAggiungiVeicolo() const;
void slotShowInserisci() const;


};

#endif // CONTROLLER_H
