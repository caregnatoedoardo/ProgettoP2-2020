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
    connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotAggiungiVeicolo()));
   // connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotResetRicerca()));

    connect(ricercaView->getButtonElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));

    connect(ricercaView->getButtonRicerca(),SIGNAL(clicked()), this, SLOT(slotRicerca()));
    connect(ricercaView->getButtonReset(), SIGNAL(clicked()),this,SLOT(slotResetRicerca()));
    connect(ricercaView->getButtonReset(),SIGNAL(clicked()),ricercaView,SLOT(slotReset()));

}

void Controller::slotFlagDataChange(bool flag)const{
    menuUtente->getSalva()->setEnabled(flag);
}

Model* Controller::getModel(){
    return model;
}

void Controller::slotAggiungiVeicolo() const{
    //MOTORE        =0
    //CARROZZERIA   =1
    //AUTO          =2
    //MOTO          =3
    //CAMION        =4
    int tipo = inserisciVeicolo->getTipoVeicolo()->currentIndex(); //acquisisco index select
    try{
        string marca = inserisciVeicolo->getMarca()->text().toStdString();
        string modello = inserisciVeicolo->getModello()->text().toStdString();
        unsigned int numeroTelaio=0;
        int cambio_auto=0;
        string colore="";
        double lunghezza=0;
        unsigned int n_motore=0;
        unsigned int cilindrata=0;
        unsigned int cavalli=0;
        string alim="";
        string targa="";
        double prezzo=0;
        unsigned int massa=0;
        unsigned int numposti=0;
        string seg="";
        bool autocarro=false;
        bool sid=false;
        unsigned int clemiss=0;
        int nassi=0;
        bool rib=false;
        string tipomt="";
        string pathimg="";
        //CARROZZERIA
        if(tipo == 1 || tipo==2 || tipo==3 || tipo==4){
            numeroTelaio = inserisciVeicolo->getNumeroTelaio()->text().toInt();
            cambio_auto = inserisciVeicolo->getCambio()->isChecked();
            colore = inserisciVeicolo->getColore()->text().toStdString();
            lunghezza = inserisciVeicolo->getLunghezza()->text().toDouble();
        }
        //MOTORE
        if(tipo==0 || tipo==2 || tipo==3 || tipo==4){
            n_motore = inserisciVeicolo->getNumeroMotore()->text().toInt();
            cilindrata = inserisciVeicolo->getCilindrata()->text().toInt();
            cavalli = inserisciVeicolo->getCavalli()->text().toInt();
            alim = inserisciVeicolo->getAlimentazione()->currentText().toStdString();
        }

        //MEZZO
        if(tipo==2 || tipo==3 || tipo==4){
            targa = inserisciVeicolo->getTarga()->text().toStdString();
            prezzo = inserisciVeicolo->getPrezzo()->text().toDouble();
            massa = inserisciVeicolo->getMassa()->text().toInt();
            numposti = inserisciVeicolo->getNumeroPosti()->text().toInt();
        }

        //AUTO
        if(tipo==2){
             seg = inserisciVeicolo->getSegmento()->currentText().toStdString();
             autocarro = inserisciVeicolo->getAutocarro()->isChecked();

        }
        //MOTO
        if(tipo==3){
            sid=inserisciVeicolo->getSidecar()->isChecked();
            clemiss=inserisciVeicolo->getClasseEmissioni()->text().toInt();
            tipomt=inserisciVeicolo->getTipoMoto()->currentText().toStdString();
        }
        // CAMION
        if(tipo==4){
             nassi=inserisciVeicolo->getNumeroAssi()->text().toInt();
             rib=inserisciVeicolo->getRibaltabile()->isChecked();
        }
        //throw Exc();//da rivedere

        Veicolo* veic=nullptr;
        switch (tipo){
        case 0:{
            alimentazione al=model->convertToAlimentazione(alim);
            veic=new Motore(marca,modello,pathimg,n_motore,cilindrata,cavalli,al);
            break;
        }
        case 1:{
            veic=new Carrozzeria(marca,modello,pathimg,numeroTelaio,cambio_auto,colore,lunghezza);
            break;
        }
        case 2:{
            alimentazione al=model->convertToAlimentazione(alim);
            segmento sg=model->convertToSeg(seg);
            veic=new Auto(marca,modello,pathimg,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,al,targa,prezzo,massa,numposti,sg,autocarro);
            break;
        }
        case 3:{
            alimentazione al=model->convertToAlimentazione(alim);
            tipomoto tpm=model->convertToTipomoto(tipomt);
            veic=new Moto(marca,modello,pathimg,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,al,targa,prezzo,massa,numposti,sid,clemiss,tpm);
            break;
        }
        case 4:{
            alimentazione al=model->convertToAlimentazione(alim);
            veic=new Camion(marca,modello,pathimg,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,al,targa,prezzo,massa,numposti,nassi,rib);            break;
            break;
        }
        default: throw Exc(12);//da vedere se inserirla qui
        }
        model->push_end(veic);
        groupView->getList()->addVeicolo(veic);
        slotFlagDataChange(true);
        //popup da implementare con messaggio di effettivo inserimento.
    } catch (Exc){
        throw Exc(4,inserisciVeicolo->getTipoVeicolo()->currentText().toStdString());
    }
    return;
}



void Controller::slotSalva() const {
    if(!model->getFlagDataSaved())
        model->save();
    slotFlagDataChange(false);
}

void Controller::slotShowRicerca() const {
    groupView->hide();
    ricercaView->show();
    inserisciVeicolo->hide();
}

void Controller::slotRicerca() const {
    //bisogna resettare tutti i campi ricerca.
    //slotResetRicerca
    try{
        if(!model->getContainerSize())
            throw Exc();
        else{
            if(ricercaView->getCkTipo()->isChecked())
                model->filterByType(ricercaView->getBoxTipoVeicolo()->currentText().toStdString());

            if(ricercaView->getCkMarca()->isChecked())
                model->filterByMarca(ricercaView->getCercaMarca()->text().toStdString());

            if(ricercaView->getCkModello()->isChecked())
                model->filterByModello(ricercaView->getCercaModello()->text().toStdString());

            if(ricercaView->getCkNumeroTelaio()->isChecked())
                model->filterByNTelaio(ricercaView->getCercaNumeroTelaio()->text().toInt());

            if(ricercaView->getCkCambio()->isChecked())
                model->filterByCambio(ricercaView->getCkCambio()->isChecked());

            if(ricercaView->getCkColore()->isChecked())
                model->filterByColore(ricercaView->getCercaColore()->text().toStdString());

            if(ricercaView->getCkLunghezza()->isChecked())
                model->filterByLunghezza(ricercaView->getCercaLunghezza()->text().toDouble());

            if(ricercaView->getCkNumeroMotore()->isChecked())
                model->filterByNMotore(ricercaView->getCercaNumeroMotore()->text().toInt());

            if(ricercaView->getCkCilindrata()->isChecked())
                model->filterByCilindrata(ricercaView->getCercaCilindrata()->text().toInt());

            if(ricercaView->getCkCavalli()->isChecked())
                model->filterByCavalli(ricercaView->getCercaCavalli()->text().toInt());

            if(ricercaView->getCkAlimentazione()->isChecked())
                model->filterByAlim(ricercaView->getBoxAlimentazione()->currentText().toStdString());

            if(ricercaView->getCkTarga()->isChecked())
                model->filterByTarga(ricercaView->getCercaTarga()->text().toStdString());

            if(ricercaView->getCkPrezzo()->isChecked())
                model->filterByPrezzo(ricercaView->getCercaPrezzo()->text().toDouble());

            if(ricercaView->getCkMassa()->isChecked())
                model->filterByMassa(ricercaView->getCercaMassa()->text().toDouble());

            if(ricercaView->getCkNumeroPosti()->isChecked())
                model->filterByNPosti(ricercaView->getCercaNumeroPosti()->text().toInt());

            if(ricercaView->getCkSegmento()->isChecked())
                model->filterBySegmento(ricercaView->getBoxSegmento()->currentText().toStdString());

            if(ricercaView->getCkAutocarro()->isChecked())
                model->filterByAutocarro(ricercaView->getCkAutocarro()->isChecked());

            if(ricercaView->getCkNumeroAssi()->isChecked())
                model->filterByNAssi(ricercaView->getCercaNumeroAssi()->text().toInt());

            if(ricercaView->getCkRibaltabile()->isChecked())
                model->filterByRibaltabile(ricercaView->getCkRibaltabile()->isChecked());

            if(ricercaView->getCkSidecar()->isChecked())
                model->filterBySidecar(ricercaView->getCkSidecar()->isChecked());

            if(ricercaView->getCkClasseEmissioni()->isChecked())
                model->filterByClasseEmissioni(ricercaView->getCercaClasseEmissioni()->text().toInt());

            if(ricercaView->getCkTipoMoto()->isChecked())
                model->filterByTypeMoto(ricercaView->getCkTipoMoto()->text().toStdString());

            if(1==0) return ;
            else {
                for(auto it=model->begin(); it!=model->end();++it){
                    ricercaView->getListaVeic()->addVeicolo(*it);
                }
            }
        }
    }catch(Exc){
        Exc(7);
    }
    //ricercaView->getListaVeic()->clear();
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

void Controller::slotShowVisualizza()const{
    groupView->show();
    ricercaView->hide();
    inserisciVeicolo->hide();

}





Controller::~Controller(){
    model->save();
}


void Controller::closeEvent(QCloseEvent *event){
    // slotSalva();
    QWidget::closeEvent(event);
}
