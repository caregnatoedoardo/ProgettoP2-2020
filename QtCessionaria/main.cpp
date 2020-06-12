#include "mainwindow.h"
#include "hierarchy/veicolo.h"
#include "hierarchy/carrozzeria.h"
#include "hierarchy/motore.h"
#include "hierarchy/mezzo.h"
#include "hierarchy/auto.h"
#include "hierarchy/camion.h"
#include "hierarchy/moto.h"
#include "container/container.h"
#include <QApplication>
#include <iostream>
#include "controller/controller.h"
#include "model.h"
using std::cout;

int main(int argc, char *argv[])
{
    /*Auto* lf=new Auto("Lancia","Fulvia","",1234,false,"marrone",4,56789,1296,90, benzina, "CA456AC",17000, 1200, 4, berlina, false);
    Camion* ca=new Camion ("Man", "TVX","",123,false,"nero",1,456,6800,400,benzina,"GA456DS",456,6,1,0,true);
    Moto* mt = new Moto("Honda", "CBR","",123,true,"rosso",1,456,600,60,benzina,"AB12345",17000,400,1,false,6,corsa);

    Auto* lf2= new Auto("Lancsia","Fulvia","",1234,false,"marrone",4,56789,1296,90, benzina, "CA451AC",17000, 1200, 4, berlina, false);
    Camion* ca2 = new Camion("Man", "TVX","",123,false,"nero",1,456,6800,400,benzina,"AA009AV",49000,6,1,0,false);
    Moto* mt2 = new Moto("Honda", "CBR","",123,true,"rosso",1,456,600,60,benzina,"AB12045",17000,400,1,false,6,corsa);
    Camion* ca3 = new Camion("IVECO", "STRALIS","",123,false,"nero",1,456,6800,400,benzina,"IV333C4",456,6,1,0,false);

    Container<Veicolo*> *ctveic= new Container<Veicolo*>;//Veicolo deve rimanere * perchè è astratta!!!
    ctveic->push_end(lf);
    ctveic->push_end(ca);
    ctveic->push_end(ca2);
    ctveic->push(mt,0);
    //ctveic->push_end(lf2);

    for(auto it=ctveic->begin();it!=ctveic->end();++it){
        cout<<"CIAO";
    }

    //ctveic->erase();

    //Container<Veicolo*> *ctcopia= new Container<Veicolo*>;
    //ctcopia=ctveic->getVehicleByType("camion");
    //ctcopia->remove(lf);
    //ctcopia->copy(*ctveic);

    //ctveic->modify(mt,ca3);


    //ctveic->remove(mt);
    if(lf2==lf) cout<<"MACCHINE UGUALI\n";
    if(ca2==ca) cout<<"CAMION UGUALI\n";
    if(mt2==mt) cout<<"MOTO UGUALI\n";


    cout<<std::endl;
    cout<<lf->getDetails();
    cout<<std::endl;
    cout<<ca2->getDetails();
    cout<<std::endl;
    cout<<mt->getDetails();//*/


    //cout<<"END\n";
    /*Veicolo* veic;
    veic=ctveic->getVeicolo(1);*/

    //DOPO PRIMO INSERIMENTO -> RESET DEI CAMPI DATI ANCHE DI ALIMENTAZIONE E SEGMENTO, senza possibilità di selezionarli in quanto rimossi dal menu a tendina
    //CORRETTO
    //CORRETTO ERRORE IN INSERIMENTO ALIMENTAZIONE NON ESISTENTE (elettricA)
    //Tipo Veicolo non più modificabile dopo Visualizza -> Modifica

    QApplication a(argc, argv);
    Controller w(new Model());
    w.setFixedSize(1024,768);
    w.show();
    return a.exec();
}
