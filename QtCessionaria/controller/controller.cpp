#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <istream>
#include<QMessageBox>
#include <QFileDialog>
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
    connect(groupView->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));
    connect(groupView->getBtnModifica(),SIGNAL(clicked()),this,SLOT(slotShowModifica()));
    connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotAggiungiVeicolo()));
    connect(inserisciVeicolo->getAddButton(),SIGNAL(clicked()),this,SLOT(slotResetRicerca()));

    connect(inserisciVeicolo->getSaveEditButton(),SIGNAL(clicked()),this,SLOT(slotSaveModifica()));
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

bool Controller::slotAggiungiVeicolo() const{
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
        bool campidati=true;
        if(tipo == 1 || tipo==2 || tipo==3 || tipo==4){
            numeroTelaio = inserisciVeicolo->getNumeroTelaio()->text().toInt();
            if(numeroTelaio==0) campidati=false;
            cambio_auto = inserisciVeicolo->getCambio()->isChecked();
            colore = inserisciVeicolo->getColore()->text().toStdString();
            lunghezza = inserisciVeicolo->getLunghezza()->text().toDouble();
        }
        //MOTORE
        if(campidati && (tipo==0 || tipo==2 || tipo==3 || tipo==4)){
            n_motore = inserisciVeicolo->getNumeroMotore()->text().toInt();
            if(!n_motore) campidati=false;
            cilindrata = inserisciVeicolo->getCilindrata()->text().toInt();
            cavalli = inserisciVeicolo->getCavalli()->text().toInt();
            alim = inserisciVeicolo->getAlimentazione()->currentText().toStdString();
        }

        //MEZZO
        if(campidati && (tipo==2 || tipo==3 || tipo==4)){
            targa = inserisciVeicolo->getTarga()->text().toStdString();
            if(targa=="") campidati=false;
            prezzo = inserisciVeicolo->getPrezzo()->text().toDouble();
            massa = inserisciVeicolo->getMassa()->text().toInt();
            numposti = inserisciVeicolo->getNumeroPosti()->text().toInt();
        }

        //AUTO
        if(campidati && (tipo==2)){
             seg = inserisciVeicolo->getSegmento()->currentText().toStdString();
             autocarro = inserisciVeicolo->getAutocarro()->isChecked();

        }
        //MOTO
        if(campidati && (tipo==3)){
            sid=inserisciVeicolo->getSidecar()->isChecked();
            clemiss=inserisciVeicolo->getClasseEmissioni()->text().toInt();
            tipomt=inserisciVeicolo->getTipoMoto()->currentText().toStdString();
        }
        // CAMION
        if(campidati && (tipo==4)){
             nassi=inserisciVeicolo->getNumeroAssi()->text().toInt();
             rib=inserisciVeicolo->getRibaltabile()->isChecked();
        }
        if(!campidati){
            QMessageBox avviso;
            avviso.information(0,"AVVISO","ERRORE CAMPI DATI MANCANTI!");
            return false;
        }

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
        default:{throw Exc(12);
            return false;
            }
        }//end switch
        if(model->push_end(veic)){
            groupView->getList()->addVeicolo(veic);
            slotFlagDataChange(true);
            inserisciVeicolo->slotResetForm();
            return true;
        }
        //popup da implementare con messaggio di effettivo inserimento.
    }catch (Exc){
        throw Exc(4,inserisciVeicolo->getTipoVeicolo()->currentText().toStdString());
    }
    return false;
}

void Controller::slotShowModifica(){


  dialog = inserisciVeicolo;


 if(groupView->getList()->currentItem()!=nullptr){
     dialog->hideButton(false);
  if(groupView->getList()->currentItem()->getItemAddress()->getTipo() == "motore"){
      Motore* a = dynamic_cast<Motore*>(groupView->getList()->currentItem()->getItemAddress());
      dialog->setTipoVeicolo(0);
      dialog->setMarca(a->getMarca());
      dialog->setModello(a->getModello());
      dialog->setNumeroMotore(a->getNMotore());
      dialog->setCilindrata(a->getCilindrata());
      dialog->setCavalli(a->getCavalli());
      dialog->setAlimentazione(a->getAlimentazione());

  }

  if(groupView->getList()->currentItem()->getItemAddress()->getTipo() == "carrozzeria"){
   Carrozzeria* a = dynamic_cast<Carrozzeria*>(groupView->getList()->currentItem()->getItemAddress());
    dialog->setTipoVeicolo(1);
   dialog->setMarca(a->getMarca());
   dialog->setModello(a->getModello());
   dialog->setNumeroTelaio(a->getNTelaio());
   dialog->setCambio(a->getCambio());
   dialog->setColore(a->getColore());


  }

  if(groupView->getList()->currentItem()->getItemAddress()->getTipo() == "auto"){
   Auto* a = dynamic_cast<Auto*>(groupView->getList()->currentItem()->getItemAddress());
   dialog->setTipoVeicolo(2);
   dialog->setMarca(a->getMarca());
   dialog->setModello(a->getModello());
   dialog->setNumeroTelaio(a->getNTelaio());
   dialog->setCambio(a->getCambio());
   dialog->setColore(a->getColore());
   dialog->setTarga(a->getTarga());
   dialog->setLunghezza(a->getLunghezza());
   dialog->setPrezzo(a->getPrezzo());
   dialog->setNumeroMotore(a->getNMotore());
   dialog->setMassa(a->getMassa());
   dialog->setCilindrata(a->getCilindrata());
   dialog->setNumeroPosti(a->getNumPosti());
   dialog->setCavalli(a->getCavalli());
   dialog->setSegmento(a->getSegmento());
   dialog->setAlimentazione(a->getAlimentazione());
   dialog->setAutocarro(a->getAutocarro());





  }


    dialog->show();
    slotFlagDataChange(true);
 }

}

void Controller::slotSaveModifica(){

  // Veicolo* a= groupView->getList()->currentItem()->getItemAddress();
  // model->remove(a);
   slotEliminaElemento();

    groupView->getList()->update();
    inserisciVeicolo->hideButton(true);

    if(slotAggiungiVeicolo())
        dialog->hide();
}



void Controller::slotSalva() const {
    if(!model->getFlagDataSaved())
        model->save();
    slotFlagDataChange(false);
    QMessageBox info;
   info.information(0,"avviso", "salvato");

}

void Controller::slotLoad(){

    groupView->getList()->clear();
    model->load();
    try{
    if(model->getContainerSize()==0){
        throw Exc();

    } else {
        for(unsigned int i=0; i<model->getContainerSize();i++)
           // groupView->getList()->addVeicolo(model->elementAt(i));

        slotShowVisualizza();
        slotFlagDataChange(false);
    }


}
    catch (Exc){
        if (model->getContainerSize()==0) Exc(9);
    }



}


void Controller::slotShowRicerca() const {
    groupView->hide();
    ricercaView->show();
    inserisciVeicolo->hide();
}

void Controller::slotResetRicerca()const{
    //CHIAMATA CHE RI-SETTA I RISULTATI DI RICERCA = TUTTO IL VECTOR
    model->clearRicerca();
}




void Controller::slotRicerca() const {

    slotResetRicerca();
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
        model->remove(item->getItemAddress());

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

    slotSalva();
    QWidget::closeEvent(event);
}



