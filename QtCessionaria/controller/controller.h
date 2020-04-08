#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QObject>
#include "container/container.h"

class QtCessionaria_Controller:public QObject{
private:
   Container<Veicolo*> *dbveicoli;
   Container<Veicolo*> *dbvenduti;
public:
   //Costruttore del Controller?????

   string getTarga()const;


};

#endif // CONTROLLER_H
