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
void Model::filterByMarca(string ma){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getMarca()!=ma)
            searchRes->remove(ve);
    }
    return;
}

void Model::filterByModello(string mo){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getModello()!=mo)
            searchRes->remove(ve);
    }
    return;
}

void Model::filterByNTelaio(unsigned int nt){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getNTelaio()!=nt)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByCambio(bool gbx){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getCambio()==gbx)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByColore(string col){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getColore()==col)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByLunghezza(double lun){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getLunghezza()!=lun)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByNMotore(unsigned int nm){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Motore* eng=dynamic_cast<Motore*>(*it);
        if(eng && eng->getNMotore()!=nm)
            searchRes->remove(eng);
    }
    return;
}

void Model::filterByCilindrata(unsigned int cc){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Motore* eng=dynamic_cast<Motore*>(*it);
        if(eng && eng->getCilindrata()!=cc)
            searchRes->remove(eng);
    }
    return;
}

void Model::filterByCavalli(unsigned int cv){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Motore* eng=dynamic_cast<Motore*>(*it);
        if(eng && eng->getCavalli()!=cv)
            searchRes->remove(eng);
    }
    return;
}

void Model::filterByAlim(alimentazione al){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Motore* eng=dynamic_cast<Motore*>(*it);
        if(eng && eng->getAlimentazione()!=al)
            searchRes->remove(eng);
    }
    return;
}

void Model::filterByTarga(string pl){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);
        if(mz && mz->getTarga()!=pl)
            searchRes->remove(mz);
    }
    return;
}

void Model::filterByPrezzo(double pr){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);
        if(mz && mz->getPrezzo()!=pr)
            searchRes->remove(mz);
    }
    return;
}

void Model::filterByMassa(unsigned int ma){
        if(searchRes->isEmpty()) return;

        for(auto it=searchRes->begin();it!=searchRes->end();++it){
            Mezzo* mz=dynamic_cast<Mezzo*>(*it);
            if(mz && mz->getMassa()!=ma)
                searchRes->remove(mz);
        }
        return;
}

void Model::filterByNPosti(unsigned int np){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);
        if(mz && mz->getNumPosti()!=np)
            searchRes->remove(mz);
    }
    return;
}

void Model::filterBySegmento(segmento sg){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Auto* aut=dynamic_cast<Auto*>(*it);
        if(aut && aut->getSegmento()!=sg)
            searchRes->remove(aut);
    }
    return;
}

void Model::filterByAutocarro(bool au){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Auto* aut=dynamic_cast<Auto*>(*it);
        if(aut && aut->getAutocarro()!=au)
            searchRes->remove(aut);
    }
    return;
}

void Model::filterByNAssi(unsigned int na){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Camion* cmi=dynamic_cast<Camion*>(*it);
        if(cmi && cmi->getNumAssi()!=na)
            searchRes->remove(cmi);
    }
    return;
}

void Model::filterByRibaltabile(bool rib){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Camion* cmi=dynamic_cast<Camion*>(*it);
        if(cmi && cmi->getRibaltabile()!=rib)
            searchRes->remove(cmi);
    }
    return;
}

void Model::filterBySidecar(bool sid){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Moto* mt=dynamic_cast<Moto*>(*it);
        if(mt && mt->getSidecar()!=sid)
            searchRes->remove(mt);
    }
    return;
}

void Model::filterByClasseEmissioni(unsigned int ce){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Moto* mt=dynamic_cast<Moto*>(*it);
        if(mt && mt->getClasseEmissioni()!=ce)
            searchRes->remove(mt);
    }
    return;
}

void Model::filterByType(tipomoto tm){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Moto* mt=dynamic_cast<Moto*>(*it);
        if(mt && mt->getTipoMoto()!=tm)
            searchRes->remove(mt);
    }
    return;
}

