#include "model.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QSaveFile>
#include <hierarchy/veicolo.h>
#include "container/container.h"
#include "exceptions/exceptions.h"
#include <QDebug>
#include <QMessageBox>
using std::cerr;
using std::endl;



Model::Model(string path):
    dbVeicoli(new Container<Veicolo*>),
    dbVenduti(new Container<Veicolo*>),
    searchRes(new Container<Veicolo*>),
    path(path),
    isDataSaved(true){}


void Model::save(){

    QSaveFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)){
        throw Exc(11,"file");
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("INIZIO SAVE FILE");
    writer.writeStartElement("root");

    auto it = dbVeicoli->begin();
    while(it!=dbVeicoli->end()){
       // const Veicolo* save = *it;

          const QString tipologia;
        //const QString tipologia = QString::fromStdString(save->) //bisogna avere la tipologia auto o camion o moto

        writer.writeAttribute("marca",QString::fromStdString((*it)->getMarca()));
        writer.writeAttribute("modello",QString::fromStdString((*it)->getModello()));

        Carrozzeria* veicoloCarrozzeria = dynamic_cast<Carrozzeria*>(*it);
        if(veicoloCarrozzeria){
        writer.writeAttribute("n_telaio",QString::number(veicoloCarrozzeria->getNTelaio()));
        writer.writeAttribute("cambio_auto",veicoloCarrozzeria->getCambio()? "Si" : "No");
        writer.writeAttribute("colore",QString::fromStdString(veicoloCarrozzeria->getColore()));
        writer.writeAttribute("lunghezza",QString::number(veicoloCarrozzeria->getLunghezza()));
            }

        Motore* veicoloMotore = dynamic_cast<Motore*>(*it);
        if(veicoloMotore){
        writer.writeAttribute("n_motore",QString::number(veicoloMotore->getNMotore()));
        writer.writeAttribute("cilindrata",QString::number(veicoloMotore->getCilindrata()));
        writer.writeAttribute("cavalli",QString::number(veicoloMotore->getCavalli()));
        writer.writeAttribute("alim",QString::fromStdString(veicoloMotore->convertToAlim(veicoloMotore->getAlimentazione())));
           }

        Mezzo* veicoloMezzo = dynamic_cast<Mezzo*>(*it);
        if(veicoloMezzo){
        writer.writeAttribute("targa",QString::fromStdString(veicoloMezzo->getTarga()));
        writer.writeAttribute("prezzo",QString::number(veicoloMezzo->getPrezzo()));
        writer.writeAttribute("massa",QString::number(veicoloMezzo->getMassa()));
        writer.writeAttribute("numposti",QString::number(veicoloMezzo->getNumPosti()));
        }


        Auto* isAuto = dynamic_cast<Auto*>(*it);
        if(isAuto) {
            writer.writeAttribute("seg",QString::fromStdString(isAuto->convertSegmento()));
            writer.writeAttribute("autocarro",isAuto->getAutocarro()? "Si" : "No");
        }

        Camion* isCamion = dynamic_cast<Camion*>(*it);
        if(isCamion){
            writer.writeAttribute("n_assi",QString::number(isCamion->getNumAssi()));
            writer.writeAttribute("ribaltabile",isCamion->getRibaltabile()? "Si" : "No");
        }

        Moto* isMoto = dynamic_cast<Moto*>(*it);
        if(isMoto){
            writer.writeAttribute("sidecar",isMoto->getSidecar()? "Si" : "No");
            writer.writeAttribute("classe_emissioni",QString::number(isMoto->getClasseEmissioni()));
            writer.writeAttribute("type",QString::fromStdString(isMoto->convertToString(isMoto->getTipoMoto())));
        }

        if(writer.hasError()) throw Exc(11,"file");
        ++it;
    }
        writer.writeEndElement();
        writer.writeEndDocument();
        isDataSaved=true;               // CAMBIO LA SENTINELLA, HO SALVATO!;)
}


void Model::load(){

    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly)){
        throw Exc(11,"file");
    }

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                const QXmlStreamAttributes att =reader.attributes();

                string marca = att.hasAttribute("marca")? att.value("marca").toString().toStdString():"";
                string modello = att.hasAttribute("modello")? att.value("modello").toString().toStdString():"";
                unsigned int n_telaio = att.hasAttribute("n_telaio")? att.value("n_telaio").toInt(): 0;
                bool cambio_auto = att.hasAttribute("cambio_auto")? att.value("cambio_auto").toString()=="Si" ? true:false:false;
                string colore = att.hasAttribute("colore")? att.value("colore").toString().toStdString():"";
                double  lunghezza = att.hasAttribute("lunghezza")? att.value("lunghezza").toDouble():1;

                unsigned int n_motore = att.hasAttribute("n_motore")? att.value("n_motore").toInt(): 0;
                unsigned int cilindrata = att.hasAttribute("cilindrata")? att.value("cilindrata").toInt(): 0;
                unsigned int cavalli = att.hasAttribute("cavalli")? att.value("cavalli").toInt(): 0;
                string alimentazione = att.hasAttribute("alim")? att.value("alim").toString().toStdString():"";

                string targa = att.hasAttribute("targa")? att.value("targa").toString().toStdString():"";
                double  prezzo = att.hasAttribute("prezzo")? att.value("prezzo").toDouble():1;
                unsigned int massa = att.hasAttribute("massa")? att.value("massa").toInt(): 0;
                unsigned int numposti = att.hasAttribute("numposti")? att.value("numposti").toInt(): 0;


                Veicolo* toPush = nullptr;
                if(reader.name() == "auto"){

                    string seg = att.hasAttribute("seg")? att.value("seg").toString().toStdString():"";
                    bool autocarro = att.hasAttribute("autocarro")? att.value("autocarro").toString()=="Si" ? true:false:false;


                } else if(reader.name()=="camion"){



                } else if(reader.name() =="moto"){


                } if(toPush!= nullptr){
                    push_end(toPush);
                } else throw std::exception();

                if(!reader.isEndDocument())
                    reader.skipCurrentElement();

            }
        }
    }

    file.close();
    isDataSaved=true;

}







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
        if(car && car->getCambio()!=gbx)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByColore(string col){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getColore()!=col)
            searchRes->remove(car);
    }
    return;
}

void Model::filterByLunghezza(double lun){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);
        if(car && car->getLunghezza()>=lun)
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
        if(mz && mz->getPrezzo()>=pr)
            searchRes->remove(mz);
    }
    return;
}

void Model::filterByMassa(unsigned int ma){
        if(searchRes->isEmpty()) return;

        for(auto it=searchRes->begin();it!=searchRes->end();++it){
            Mezzo* mz=dynamic_cast<Mezzo*>(*it);
            if(mz && mz->getMassa()>=ma)
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


void Model::push_end(Veicolo *a){

    dbVeicoli->push_end(a);
    if(!(*searchRes==*dbVeicoli))
        *searchRes=*dbVeicoli;
    isDataSaved=false;
}


