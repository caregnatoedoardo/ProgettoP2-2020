#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>

#include "container/container.h"
#include "GUI/usermenu.h"
#include "GUI/insertveicolo.h"
#include "GUI/groupview.h"
#include "GUI/viewveicolo.h"
#include "GUI/ricerca.h"
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
   GroupView* vendutiView;
   InsertVeicolo* dialog;
public:
   Controller(Model*,QWidget* = nullptr);
   Model *getModel();
   ~Controller()=default;
   string getTarga()const;
   string getRawData(const QImage);
public slots:

    void closeEvent(QCloseEvent*);
    void slotShowRicerca() const;
    void slotRicerca()const;
    void slotEliminaElemento() const;
    void slotEliminaElementoVenduto() const;
    void slotSalva() const;
    void slotLoad();
    bool slotAggiungiVeicolo() const;
    void slotFlagDataChange(bool flag)const;
    void slotShowInserisci() const;
    void slotShowVisualizza() const;
    void slotShowVisualizzaVenduti() const;
    void slotShowModifica();
    void slotSaveModifica();
    void slotResetRicerca() const;
    void slotVendi();
};

#endif // CONTROLLER_H
