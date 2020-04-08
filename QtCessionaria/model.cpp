#include "model.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QSaveFile>
#include <hierarchy/veicolo.h>
#include "container/container.h"




Model::Model(string path):
    dbVeicoli(new Container<Veicolo*>),
    dbVenduti(new Container<Veicolo*>),
    searchRes(new Container<Veicolo*>),
    path(path),
    isDataSaved(true){}

Container<Veicolo*>::Iteratore Model::begin() const{
    return searchRes->begin();
}

Container<Veicolo*>::Iteratore Model::end() const{
    return searchRes->end();
}

//lavorano tutti su SearchRes, che all'inizio sarà una copia di dbveicoli
void Model::filterByMarca(string ma) const{
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getMarca()!=ma)
            searchRes->remove(ve);
    }
}


