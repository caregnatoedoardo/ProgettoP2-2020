#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBuffer>
using std::string;




Controller::Controller(Model*m, QWidget *parent):
    QWidget(parent),
    model(m),
    menuUtente(new Usermenu(this)),
    mainLayout(new QHBoxLayout(this)),
    inserisciVeicolo(new InsertVeicolo(this))


{

    mainLayout->setMenuBar(menuUtente);
    mainLayout->addWidget(inserisciVeicolo);

}

Model* Controller::getModel(){
    return model;
}



void Controller:: slotAggiungiVeicolo() const{
    try{

        string marca = inserisciVeicolo->getMarca()->text().toStdString();
        string modello = inserisciVeicolo->getModello()->text().toStdString();

        //CARROZZERIA
        unsigned int numeroTelaio = inserisciVeicolo->getNumeroTelaio()->text().toInt();
        int cambio_auto = inserisciVeicolo->getCambio()->isChecked();
        string colore = inserisciVeicolo->getColore()->text().toStdString();
        double lunghezza = inserisciVeicolo->getLunghezza()->text().toDouble();


        //MOTORE

        unsigned int n_motore = inserisciVeicolo->getNumeroMotore()->text().toInt();
        unsigned int cilindrata = inserisciVeicolo->getCilindrata()->text().toInt();
        unsigned int cavalli = inserisciVeicolo->getCavalli()->text().toInt();
        //alimentazione alim = inserisciVeicolo->getAlimentazione();

        //MEZZO

        string targa = inserisciVeicolo->getTarga()->text().toStdString();
        double prezzo = inserisciVeicolo->getPrezzo()->text().toDouble();
        unsigned int massa = inserisciVeicolo->getMassa()->text().toInt();
        unsigned int numposti = inserisciVeicolo->getNumeroPosti()->text().toInt();

        //AUTO
       // segmento seg = inserisciVeicolo->getSegmento();
        int autocarro = inserisciVeicolo->getAutocarro()->isChecked();







    } catch (std::exception e){

    }
}


void Controller::slotShowInserisci()const{

    inserisciVeicolo->show();

}

Controller::~Controller(){
    model->save();
}
