#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QObject>
#include<QWidget>
#include "container/container.h"
#include "GUI/usermenu.h"
#include <QVBoxLayout>

class Controller:public QWidget{
private:
   Q_OBJECT

   Container<Veicolo*> *dbveicoli;
   Container<Veicolo*> *dbvenduti;

   Usermenu* menuUtente;
   QHBoxLayout* mainLayout;


public:
// Controller(Model*,QWidget* = nullptr);
   Controller(QWidget* = nullptr);

~Controller();

   string getTarga()const;


};

#endif // CONTROLLER_H
