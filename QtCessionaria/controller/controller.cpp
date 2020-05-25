#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBuffer>
#include <hierarchy/veicolo.h>
#include <hierarchy/carrozzeria.h>
#include <hierarchy/motore.h>
#include <hierarchy/mezzo.h>
#include <hierarchy/auto.h>
#include <hierarchy/moto.h>
#include <hierarchy/camion.h>


using std::string;




Controller::Controller(Model*m, QWidget *parent):
    QWidget(parent),
    model(m),
    menuUtente(new Usermenu(this)),
    mainLayout(new QHBoxLayout(this)),
    inserisciVeicolo(new InsertVeicolo(this)),
    ricercaView(new Ricerca(this)),
    groupView(new GroupView(this)),
    dialog(nullptr)


{

    mainLayout->setMenuBar(menuUtente);
    mainLayout->addWidget(ricercaView);
    mainLayout->addWidget(groupView);
    mainLayout->addWidget(inserisciVeicolo);

    slotShowInserisci();
     //connect(groupView->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));
    //connect(groupView->getBtnModifica(),SIGNAL(clicked()),this,SLOT(slotShowModifica()));
    //connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotAggiungiVeicolo()));
   // connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotResetRicerca()));

    connect(ricercaView->getButtonElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));

    connect(ricercaView->getButtonRicerca(),SIGNAL(clicked()), this, SLOT(slotRicerca()));
    connect(ricercaView->getButtonReset(), SIGNAL(clicked()),this,SLOT(slotResetRicerca()));
    connect(ricercaView->getButtonReset(),SIGNAL(clicked()),ricercaView,SLOT(slotReset()));








}

Model* Controller::getModel(){
    return model;
}



void Controller:: slotAggiungiVeicolo() const{
    try{

        int tipo = inserisciVeicolo->getTipoVeicolo()->currentIndex(); //acquisisco index select
        //if(tipo == 0) throw Exception errore tipologia veicolo

        string marca = inserisciVeicolo->getMarca()->text().toStdString();
        string modello = inserisciVeicolo->getModello()->text().toStdString();

        //CARROZZERIA
        if(tipo == 1 || 2 || 3 || 4){
        unsigned int numeroTelaio = inserisciVeicolo->getNumeroTelaio()->text().toInt();
        int cambio_auto = inserisciVeicolo->getCambio()->isChecked();
        string colore = inserisciVeicolo->getColore()->text().toStdString();
        double lunghezza = inserisciVeicolo->getLunghezza()->text().toDouble();
        }

        //MOTORE
        if(tipo == 1 || 2 || 3 || 5){
        unsigned int n_motore = inserisciVeicolo->getNumeroMotore()->text().toInt();
        unsigned int cilindrata = inserisciVeicolo->getCilindrata()->text().toInt();
        unsigned int cavalli = inserisciVeicolo->getCavalli()->text().toInt();
        //alimentazione alim = inserisciVeicolo->getAlimentazione();
        }

        //MEZZO
        if(tipo == 1 || 2 || 3){
        string targa = inserisciVeicolo->getTarga()->text().toStdString();
        double prezzo = inserisciVeicolo->getPrezzo()->text().toDouble();
        unsigned int massa = inserisciVeicolo->getMassa()->text().toInt();
        unsigned int numposti = inserisciVeicolo->getNumeroPosti()->text().toInt();
        }

        //AUTO
        if(tipo == 1){
            // segmento seg = inserisciVeicolo->getSegmento();
             int autocarro = inserisciVeicolo->getAutocarro()->isChecked();

        }
        // CAMION
        if (tipo == 2){


        }

        //MOTO
        if (tipo == 3){


        }






    } catch (std::exception e){

    }
}


void Controller::slotSalva() const {
    //if(!model->getIsDataSaved()){
    model->save();
    //slotDataChanged(false);

}

void Controller::slotShowRicerca() const {
    groupView->hide();
    ricercaView->show();
    inserisciVeicolo->hide();

}

void Controller::slotRicerca() const {

}



void Controller::slotEliminaElemento() const {
    if(groupView->getList()->count() && groupView->getList()->currentItem()!=nullptr){
        PrintListView* item = groupView->getList()->takeItem(groupView->getList()->currentRow());
        // ERRORE SU CONTAINER model->erase(item->getItemAddress());
        delete item;
        groupView->getList()->reset();
        //slotdatachanged(true);

    }
}


void Controller::slotShowInserisci()const{
    groupView->hide();
    ricercaView->hide();
    inserisciVeicolo->show();

}

Controller::~Controller(){
    model->save();
}


void Controller::closeEvent(QCloseEvent *event){
   // slotSalva();
    QWidget::closeEvent(event);

}
