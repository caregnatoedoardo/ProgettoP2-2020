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

Model::Model(Container<Veicolo*>* dbVei, Container<Veicolo*>* dbVen, Container<Veicolo*>* sRes, string path):
    dbVeicoli(dbVei),
    dbVenduti(dbVen),
    searchRes(sRes),
    path(path),
    flagsaved(false){}

bool Model::getFlagDataSaved() const{return flagsaved;}


void Model::save(string p){
    QSaveFile file(QString::fromStdString(p));
    try{
        if(!file.open(QIODevice::WriteOnly)){
            throw Exc();
        }
        }catch(Exc){
            Exc(11,"scrittura");
            return;
        }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("INIZIO SAVE FILE");
    writer.writeStartElement("root");

    auto it = dbVeicoli->begin();

     /* -------- SALVATAGGIO DB VEICOLI ------- */
    while(it!=dbVeicoli->end()){
        //const Veicolo* save = *it;

        writer.writeEmptyElement(QString::fromStdString((*it)->getTipo()));
        writer.writeAttribute("db","veicoli");
        writer.writeAttribute("marca",QString::fromStdString((*it)->getMarca()));
        writer.writeAttribute("modello",QString::fromStdString((*it)->getModello()));
        writer.writeAttribute("pathimg",QString::fromStdString((*it)->getPathImg()));

        Carrozzeria* veicoloCarrozzeria = dynamic_cast<Carrozzeria*>(*it);
        if(veicoloCarrozzeria){//in alternativa if(tipo=="carrozzeria")
        writer.writeAttribute("n_telaio",QString::number(veicoloCarrozzeria->getNTelaio()));
        writer.writeAttribute("cambio_auto",veicoloCarrozzeria->getCambio()? "Si" : "No");
        writer.writeAttribute("colore",QString::fromStdString(veicoloCarrozzeria->getColore()));
        writer.writeAttribute("lunghezza",QString::number(veicoloCarrozzeria->getLunghezza()));
            }

        Motore* veicoloMotore = dynamic_cast<Motore*>(*it);
        if(veicoloMotore){//in alternativa if(tipo=="motore")
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
        if(isAuto) {//in alternativa if(tipo=="auto")
            writer.writeAttribute("seg",QString::fromStdString(isAuto->convertSegmento(isAuto->getSegmento())));
            writer.writeAttribute("autocarro",isAuto->getAutocarro()? "Si" : "No");
        }

        Camion* isCamion = dynamic_cast<Camion*>(*it);
        if(isCamion){//in alternativa if(tipo=="camion")
            writer.writeAttribute("n_assi",QString::number(isCamion->getNumAssi()));
            writer.writeAttribute("ribaltabile",isCamion->getRibaltabile()? "Si" : "No");
        }

        Moto* isMoto = dynamic_cast<Moto*>(*it);
        if(isMoto){//in alternativa if(tipo=="camion")
            writer.writeAttribute("sidecar",isMoto->getSidecar()? "Si" : "No");
            writer.writeAttribute("classe_emissioni",QString::number(isMoto->getClasseEmissioni()));
            writer.writeAttribute("type",QString::fromStdString(isMoto->convertToString(isMoto->getTipoMoto())));
        }

        if(writer.hasError()) throw Exc(11,"salvataggio");
        ++it;
    }

     /* -------- FINE SALVATAGGIO DB VEICOLI ------- */

    /* -------- SALVATAGGIO DB VENDUTI ------- */

    auto it2 = dbVenduti->begin();
    while(it2!=dbVenduti->end()){

        writer.writeEmptyElement(QString::fromStdString((*it2)->getTipo()));
        writer.writeAttribute("db","venduti");
        writer.writeAttribute("marca",QString::fromStdString((*it2)->getMarca()));
        writer.writeAttribute("modello",QString::fromStdString((*it2)->getModello()));
        writer.writeAttribute("pathimg",QString::fromStdString((*it2)->getPathImg()));

        Carrozzeria* veicoloCarrozzeria = dynamic_cast<Carrozzeria*>(*it2);
        if(veicoloCarrozzeria){//in alternativa if(tipo=="carrozzeria")
        writer.writeAttribute("n_telaio",QString::number(veicoloCarrozzeria->getNTelaio()));
        writer.writeAttribute("cambio_auto",veicoloCarrozzeria->getCambio()? "Si" : "No");
        writer.writeAttribute("colore",QString::fromStdString(veicoloCarrozzeria->getColore()));
        writer.writeAttribute("lunghezza",QString::number(veicoloCarrozzeria->getLunghezza()));
            }

        Motore* veicoloMotore = dynamic_cast<Motore*>(*it2);
        if(veicoloMotore){//in alternativa if(tipo=="motore")
        writer.writeAttribute("n_motore",QString::number(veicoloMotore->getNMotore()));
        writer.writeAttribute("cilindrata",QString::number(veicoloMotore->getCilindrata()));
        writer.writeAttribute("cavalli",QString::number(veicoloMotore->getCavalli()));
        writer.writeAttribute("alim",QString::fromStdString(veicoloMotore->convertToAlim(veicoloMotore->getAlimentazione())));
           }

        Mezzo* veicoloMezzo = dynamic_cast<Mezzo*>(*it2);
        if(veicoloMezzo){
        writer.writeAttribute("targa",QString::fromStdString(veicoloMezzo->getTarga()));
        writer.writeAttribute("prezzo",QString::number(veicoloMezzo->getPrezzo()));
        writer.writeAttribute("massa",QString::number(veicoloMezzo->getMassa()));
        writer.writeAttribute("numposti",QString::number(veicoloMezzo->getNumPosti()));
        }


        Auto* isAuto = dynamic_cast<Auto*>(*it2);
        if(isAuto) {//in alternativa if(tipo=="auto")
            writer.writeAttribute("seg",QString::fromStdString(isAuto->convertSegmento(isAuto->getSegmento())));
            writer.writeAttribute("autocarro",isAuto->getAutocarro()? "Si" : "No");
        }

        Camion* isCamion = dynamic_cast<Camion*>(*it2);
        if(isCamion){//in alternativa if(tipo=="camion")
            writer.writeAttribute("n_assi",QString::number(isCamion->getNumAssi()));
            writer.writeAttribute("ribaltabile",isCamion->getRibaltabile()? "Si" : "No");
        }

        Moto* isMoto = dynamic_cast<Moto*>(*it2);
        if(isMoto){//in alternativa if(tipo=="camion")
            writer.writeAttribute("sidecar",isMoto->getSidecar()? "Si" : "No");
            writer.writeAttribute("classe_emissioni",QString::number(isMoto->getClasseEmissioni()));
            writer.writeAttribute("type",QString::fromStdString(isMoto->convertToString(isMoto->getTipoMoto())));
        }

        if(writer.hasError()) throw Exc(11,"salvataggio");
        ++it2;
    }

     /* --------  FINE SALVATAGGIO DB VENDUTI ------- */

        writer.writeEndElement();
        writer.writeEndDocument();
        flagsaved=true;
        file.commit();
}


void Model::load(string path){

    QFile file(QString::fromStdString(path));
    try{
        if(!file.open(QIODevice::ReadOnly)){
            throw Exc();
        }
        }catch(Exc){
            Exc(11,"sola lettura");
            return;
    }
    dbVeicoli->erase();
    dbVenduti->erase();
    searchRes->erase();

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                const QXmlStreamAttributes att =reader.attributes();
                //VEICOLO
                string db = att.hasAttribute("db")? att.value("db").toString().toStdString():"";
                string marca = att.hasAttribute("marca")? att.value("marca").toString().toStdString():"";
                string modello = att.hasAttribute("modello")? att.value("modello").toString().toStdString():"";
                string path = att.hasAttribute("pathimg")?att.value("pathimg").toString().toStdString():"";
                unsigned int numeroTelaio=0;
                int cambio_auto=0;
                string colore="";
                double lunghezza=0;
                unsigned int n_motore=0;
                unsigned int cilindrata=0;
                unsigned int cavalli=0;
                alimentazione alim=diesel;
                string targa="";
                double prezzo=0;
                unsigned int massa=0;
                unsigned int numposti=0;
                segmento seg;
                bool autocarro=false;
                bool sid=false;
                unsigned int clemiss=0;
                int nassi=0;
                bool rib=false;
                tipomoto tpm;
                string tipomt="";

                string nomereader=reader.name().toString().toStdString();
                Veicolo* toPush = nullptr;

                if(reader.name()=="carrozzeria" || reader.name()=="auto" || reader.name()=="camion" || reader.name()=="moto"){
                    numeroTelaio = att.hasAttribute("n_telaio")? att.value("n_telaio").toInt(): 0;
                    cambio_auto = att.hasAttribute("cambio_auto")? att.value("cambio_auto").toString()=="Si" ? true:false:false;
                    colore = att.hasAttribute("colore")? att.value("colore").toString().toStdString():"";
                    lunghezza = att.hasAttribute("lunghezza")? att.value("lunghezza").toDouble():1;
                    if(reader.name()=="carrozzeria")
                        toPush=new Carrozzeria(marca,modello,path,numeroTelaio,cambio_auto,colore,lunghezza);
                }

                //MOTORE if(motore,auto,camion,moto)
                if(reader.name()=="motore" || reader.name()=="auto" || reader.name()=="camion" || reader.name()=="moto"){
                    n_motore = att.hasAttribute("n_motore")? att.value("n_motore").toInt(): 0;
                    cilindrata = att.hasAttribute("cilindrata")? att.value("cilindrata").toInt(): 0;
                    cavalli = att.hasAttribute("cavalli")? att.value("cavalli").toInt(): 0;
                    if(reader.name()=="motore")
                        toPush=new Motore(marca,modello,path,n_motore,cilindrata,cavalli);
                }
                if(reader.name()=="auto" || reader.name()=="camion" || reader.name()=="moto"){
                    alim = convertToAlimentazione(att.hasAttribute("alim")? att.value("alim").toString().toStdString():"");
                    targa = att.hasAttribute("targa")? att.value("targa").toString().toStdString():"";
                    prezzo = att.hasAttribute("prezzo")? att.value("prezzo").toDouble():1;
                    massa = att.hasAttribute("massa")? att.value("massa").toInt(): 0;
                    numposti = att.hasAttribute("numposti")? att.value("numposti").toInt(): 0;
                }
                if(reader.name() == "auto"){
                    seg = convertToSeg(att.hasAttribute("seg")? att.value("seg").toString().toStdString():"");
                    autocarro = att.hasAttribute("autocarro")? att.value("autocarro").toString()=="Si" ? true:false:false;
                    toPush = new Auto(marca,modello,path,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,alim,targa,prezzo,massa,numposti,seg,autocarro);

                } else if(reader.name()=="camion"){
                    nassi = att.hasAttribute("n_assi")? att.value("n_assi").toDouble():1;
                    rib = att.hasAttribute("ribaltabile")? att.value("ribaltabile").toString()=="Si" ? true:false:false;
                    toPush = new Camion(marca,modello,path,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,alim,targa,prezzo,massa,numposti,nassi,rib);


                } else if(reader.name() =="moto"){
                     sid = att.hasAttribute("sidecar")? att.value("sidecar").toString()=="Si" ? true:false:false;
                     clemiss = att.hasAttribute("classe_emissioni")? att.value("classe_emissioni").toInt(): 0;
                     tpm=convertToTipomoto(att.hasAttribute("type")? att.value("type").toString().toStdString():"");
                     toPush = new Moto(marca,modello,path,numeroTelaio,cambio_auto,colore,lunghezza,n_motore,cilindrata,cavalli,alim,targa,prezzo,massa,numposti,sid,clemiss,tpm);

                } if(toPush!= nullptr){


                    if(db=="veicoli" && !push_end(dbVeicoli, toPush)){

                        throw Exc(11,"caricamento veicolo");
                        return;
                    }

                    else
                        if(db=="venduti" && !push_end(dbVenduti,toPush)){

                            throw Exc(11,"caricamento veicolo");
                            return; }

                } else throw std::exception();

                if(reader.hasError()){
                    throw Exc(11,"caricamento");
                    return;
                }
                if(!reader.isEndDocument())
                    reader.skipCurrentElement();
            }
        }
    }
    file.close();
    flagsaved=true;
}

void Model::erase(){
    flagsaved = false;
    dbVeicoli->erase();
}

unsigned int Model::getContainerSize() const{
    return dbVeicoli->getSize();
}

unsigned int Model::getContainerVendutiSize() const{
    return dbVenduti->getSize();
}

Container<Veicolo*>::Iteratore Model::begin() const{
    return searchRes->begin();
}

Container<Veicolo*>::Iteratore Model::end() const{
    return searchRes->end();
}

//lavorano tutti su SearchRes, che all'inizio sarà una copia di dbveicoli

void Model::filterByType(string ty){
    if(searchRes->isEmpty()) return;
    for(auto it=searchRes->begin();it!=searchRes->end();){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve->getTipo()!=ty){
            ++it;
            searchRes->remove(ve);}else ++it;

    }
    return;
}

void Model::filterByMarca(string ma){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getMarca()!=ma){
            ++it;
            searchRes->remove(ve);} else ++it;
    }
    return;
}

void Model::filterByModello(string mo){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getModello()!=mo){
            ++it;
            searchRes->remove(ve);} else ++it;
    }
    return;
}

void Model::filterByNTelaio(unsigned int nt){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);

    if(car){
        if(car->getNTelaio()!=nt){
          ++it;
          searchRes->remove(car);
        }

        if(car->getNTelaio()==nt){
            ++it;
        }
    }
    if (!car){
        Veicolo* ve = dynamic_cast<Veicolo*>(*it);
         ++it;
        searchRes->remove(ve);
    }
    }


    return;
}

void Model::filterByCambio(bool gbx){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);

        if(car){
            if(car->getCambio()!=gbx){
              ++it;
              searchRes->remove(car);
            }

            if(car->getCambio()==gbx){
                ++it;
            }
        }
        if (!car){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
        }

    return;
}

void Model::filterByColore(string col){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);

        if(car){
            if(car->getColore()!=col){
              ++it;
              searchRes->remove(car);
            } else ++it;
        }
        if (!car){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
        }

    return;
}

void Model::filterByLunghezza(double lun){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Carrozzeria* car=dynamic_cast<Carrozzeria*>(*it);

        if(car){
            if(car->getLunghezza()!=lun){
              ++it;
              searchRes->remove(car);
            } else ++it;
        }
        if (!car){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
        }
    return;
}

void Model::filterByNMotore(unsigned int nm){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Motore* eng=dynamic_cast<Motore*>(*it);

        if(eng){
            if(eng->getNMotore()!=nm){
              ++it;
              searchRes->remove(eng);
            } else ++it;
        }
        if (!eng){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }



    }
    return;
}

void Model::filterByCilindrata(unsigned int cc){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Motore* eng=dynamic_cast<Motore*>(*it);

        if(eng){
            if(eng->getCilindrata()!=cc){
              ++it;
              searchRes->remove(eng);
            } else ++it;
        }
        if (!eng){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }

    }
    return;
}

void Model::filterByCavalli(unsigned int cv){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Motore* eng=dynamic_cast<Motore*>(*it);

        if(eng){
            if(eng->getCavalli()!=cv){
              ++it;
              searchRes->remove(eng);
            } else ++it;
        }
        if (!eng){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}



void Model::filterByAlim(string al){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Motore* eng=dynamic_cast<Motore*>(*it);


        if(eng){
            if(eng->convertToAlim(eng->getAlimentazione())!=al){
              ++it;
              searchRes->remove(eng);
            } else ++it;
        }
        if (!eng){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }

    }
    return;
}

void Model::filterByTarga(string pl){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);

        if(mz){
            if(mz->getTarga()!=pl){
              ++it;
              searchRes->remove(mz);
            } else ++it;
        }
        if (!mz){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }

    }
    return;
}

void Model::filterByPrezzo(double pr){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);

        if(mz){
            if(mz->getPrezzo()>=pr){
              ++it;
              searchRes->remove(mz);
            } else ++it;
        }
        if (!mz){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByMassa(unsigned int ma){
        if(searchRes->isEmpty()) return;

        for(auto it=searchRes->begin();it!=searchRes->end();){
            Mezzo* mz=dynamic_cast<Mezzo*>(*it);


            if(mz){
                if(mz->getMassa()>=ma){
                  ++it;
                  searchRes->remove(mz);
                } else ++it;
            }
            if (!mz){
                Veicolo* ve = dynamic_cast<Veicolo*>(*it);
                 ++it;
                searchRes->remove(ve);
            }
        }
        return;
}

void Model::filterByNPosti(unsigned int np){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Mezzo* mz=dynamic_cast<Mezzo*>(*it);
        if(mz){
            if(mz->getNumPosti()!=np){
              ++it;
              searchRes->remove(mz);
            }

            if(mz->getNumPosti()==np){
                ++it;
            }
        }
        if (!mz){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterBySegmento(string sg){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Auto* aut=dynamic_cast<Auto*>(*it);


        if(aut){
            if(aut->convertSegmento(aut->getSegmento())!=sg){
              ++it;
              searchRes->remove(aut);
            } else ++it;
        }
        if (!aut){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByAutocarro(bool au){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Auto* aut=dynamic_cast<Auto*>(*it);

        if(aut){
            if(aut->getAutocarro()!=au){
              ++it;
              searchRes->remove(aut);
            } else ++it;
        }
        if (!aut){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByNAssi(unsigned int na){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Camion* cmi=dynamic_cast<Camion*>(*it);

        if(cmi){
            if(cmi->getNumAssi()!=na){
              ++it;
              searchRes->remove(cmi);
            } else ++it;
        }
        if (!cmi){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByRibaltabile(bool rib){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Camion* cmi=dynamic_cast<Camion*>(*it);

        if(cmi){
            if(cmi->getRibaltabile()!=rib){
              ++it;
              searchRes->remove(cmi);
            } else ++it;
        }
        if (!cmi){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterBySidecar(bool sid){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Moto* mt=dynamic_cast<Moto*>(*it);
        if(mt && mt->getSidecar()!=sid){
            ++it;
            searchRes->remove(mt);} else ++it;

        if(mt){
            if(mt->getSidecar()!=sid){
              ++it;
              searchRes->remove(mt);
            } else ++it;
        }
        if (!mt){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByClasseEmissioni(unsigned int ce){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Moto* mt=dynamic_cast<Moto*>(*it);

        if(mt){
            if(mt->getClasseEmissioni()!=ce){
              ++it;
              searchRes->remove(mt);
            } else ++it;
        }
        if (!mt){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

void Model::filterByTypeMoto(string tm){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();){
        Moto* mt=dynamic_cast<Moto*>(*it);

        if(mt){
            if(mt->convertToString(mt->getTipoMoto())!=tm){
              ++it;
              searchRes->remove(mt);
            } else ++it;
        }
        if (!mt){
            Veicolo* ve = dynamic_cast<Veicolo*>(*it);
             ++it;
            searchRes->remove(ve);
        }
    }
    return;
}

bool Model::push_begin(Container<Veicolo *>*& ct, Veicolo *a){
    bool correctplate=checkPlate(a);
    bool duplicate=isDuplicate(ct,a);
    bool duplicateEngine=checkDuplicateEngine(ct,a);
    bool duplicateChassis=checkDuplicateChassis(ct,a);
    bool duplicatePlate=checkDuplicatePlate(ct,a);
    try{
        if(correctplate && !duplicate && !duplicateEngine && !duplicateChassis && !duplicatePlate)
            if(ct->push_begin(a))
                return true;
        throw Exc();
    }catch(Exc){
        if(duplicate) Exc(6,"duplicato");
        if(duplicateEngine) Exc(6,"N motore duplicato");
        if(duplicateChassis) Exc(6,"N chassis duplicato");
        if(duplicatePlate) Exc(13);
        if(!correctplate) Exc(3);
    }
    return false;
}



bool Model::push(Veicolo *a){
    bool correctplate=checkPlate(a);
    bool duplicate=isDuplicate(dbVeicoli,a);
    bool duplicateEngine=checkDuplicateEngine(dbVeicoli,a);
    bool duplicateChassis=checkDuplicateChassis(dbVeicoli,a);
    bool duplicatePlate=checkDuplicatePlate(dbVeicoli,a);
    try{
        if(correctplate && !duplicate && !duplicateEngine && !duplicateChassis && !duplicatePlate)
            if(dbVeicoli->push_begin(a))
                return true;
        throw Exc();
    }catch(Exc){
        if(duplicate) Exc(6,"duplicato");
        if(duplicateEngine) Exc(6,"N motore duplicato");
        if(duplicateChassis) Exc(6,"N chassis duplicato");
        if(duplicatePlate) Exc(13);
        if(!correctplate) Exc(3);
    }
    return false;
}


bool Model::push_end(Container<Veicolo*>*& ct, Veicolo* a){
    bool correctplate=checkPlate(a);
    bool duplicate=isDuplicate(ct,a);
    bool duplicateEngine=checkDuplicateEngine(ct,a);
    bool duplicateChassis=checkDuplicateChassis(ct,a);
    bool duplicatePlate=checkDuplicatePlate(ct,a);
    try{
        if(correctplate && !duplicate && !duplicateEngine && !duplicateChassis && !duplicatePlate)
            if(ct->push_end(a)){
                flagsaved=false;
                return true;
            }
        throw Exc();
    }catch(Exc){
        if(duplicate) Exc(6,"duplicato");
        if(duplicateEngine) Exc(6,"N motore duplicato");
        if(duplicateChassis) Exc(6,"N chassis duplicato");
        if(duplicatePlate) Exc(13);
        if(!correctplate) Exc(3);
    }
    return false;
}

bool Model::modify(Veicolo* nuovo,Veicolo* elim){
    if(!nuovo || !elim) return false;
    return dbVeicoli->modify(nuovo,elim);
}



bool Model::remove(Veicolo* a){
    if(dbVeicoli->remove(a)){

        return true;
    }
    return false;
}

bool Model::removeVenduti(Veicolo* a){
    if(dbVenduti->remove(a)){
        return true;
    }
    return false;
}


bool Model::search(Container<Veicolo*>*& ct, Veicolo* a) const{//effettua la ricerca di un Veicolo dentro un Container.
    return(ct->search(a));
}

bool Model::vendi(Veicolo* a){
    if(search(dbVeicoli,a) && push_begin(dbVenduti,a) && dbVeicoli->remove(a))
        return true;
    return false;
}

bool Model::nonVenduta(Veicolo* a){//verifica se un veicolo è presente nel Db dei venduti e, se presente, lo riporta nel db dei disponibili.
    if(search(dbVenduti, a) && push_begin(dbVeicoli,a) && dbVeicoli->remove(a))//se è presente all'interno del db venduti
        return true;
    return false;
}

tipomoto Model::convertToTipomoto(const string st)const{
        if(st=="corsa") return corsa;
        if(st=="custom") return custom;
        if(st=="naked") return naked;
        if(st=="cross") return cross;

        throw Exc(4);
}


segmento Model::convertToSeg(const string st) const{
    if(st=="berlina") return berlina;
    if(st=="station") return station;
    if(st=="coupe") return coupe;
    if(st=="suv") return suv;

    throw Exc(4);
}


alimentazione Model::convertToAlimentazione(const string al)const{
    if(al=="diesel") return diesel;
    if(al=="benzina") return benzina;
    if(al=="elettrica") return elettrica;
    if(al=="gpl") return gpl;
    if(al=="metano") return metano;

    throw Exc(5);
}



std::string Model::getRawData(const QImage &q)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    q.save(&buffer, "PNG");

    return QString(byteArray.toBase64()).toStdString();
}

QPixmap Model::getImage(const std::string &i){
    QImage* image= new QImage;
    QByteArray array= QByteArray(i.data());
    image->loadFromData(QByteArray::fromBase64(array), "PNG");

    QPixmap p=QPixmap::fromImage(*image);
    return p.scaled(500,600,Qt::AspectRatioMode::KeepAspectRatio);
}


void Model::clearRicerca()  {

    defaultSearchRes();

    QMessageBox info;
    info.information(0,"avviso", "RESET OK");

}

bool Model::isEmptyVenduti() const{
    return !dbVenduti->isEmpty();
}

bool Model::isEmptyDisponibili() const{
    return !dbVeicoli->isEmpty();
}

Veicolo* Model::getElementoByPosition(unsigned int i) const{return dbVeicoli->getVeicolo(i);}
Veicolo* Model::getElementoVendutoByPosition(unsigned int i) const{return dbVenduti->getVeicolo(i);}


bool Model::checkDuplicatePlate(Container<Veicolo*>*&ct, const Veicolo* a)const{
    if(ct->isEmpty()) return false;
    bool trovato=false;
    Mezzo* me = dynamic_cast<Mezzo*>(const_cast<Veicolo*>(a));
    if(me){
        for(auto it = ct->begin();it!=ct->end();++it){
            Mezzo* mz=dynamic_cast<Mezzo*>((*it));
            if(me && mz && (mz->getTarga()==me->getTarga()))
                trovato=true;
        }
    }
    return trovato;

}
bool Model::checkPlate(const Veicolo* a) const{
    Moto*mt=dynamic_cast<Moto*>(const_cast<Veicolo*>(a));
    if(mt) return mt->checkTarga();

    Mezzo*mz=dynamic_cast<Mezzo*>(const_cast<Veicolo*>(a));
    if(mz) return mz->checkTarga();
    return true;
}

bool Model::checkDuplicateEngine(Container<Veicolo*>*&ct, const Veicolo* a)const{

    if(ct->isEmpty()) return false;

    bool trovato=false;

    Motore* mt = dynamic_cast<Motore*>(const_cast<Veicolo*>(a));
    if(mt){
        for(auto it=ct->begin();it!=ct->end();++it){
            Motore* mttemp=dynamic_cast<Mezzo*>((*it));
            if(mttemp && mt->getNMotore()==mttemp->getNMotore()) trovato= true;
        }
    }
    return trovato;
}

bool Model::checkDuplicateChassis(Container<Veicolo*>*&ct, const Veicolo* a)const{

    if(ct->isEmpty()) return false;
    bool trovato=false;

    Carrozzeria* cr=dynamic_cast<Carrozzeria*>(const_cast<Veicolo*>(a));
    if(cr){
        for(auto it = ct->begin();it!=ct->end();++it){
            Carrozzeria* crtemp=dynamic_cast<Carrozzeria*>((*it));
            if(crtemp && cr->getNTelaio()==crtemp->getNTelaio()) trovato=true;
        }
    }
    return trovato;
}


bool Model::isDuplicate(Container<Veicolo*>*&ct, const Veicolo* t)const{
    if(ct->isEmpty()) return false;

    for(auto it=ct->begin();it!=ct->end();++it)
        if((*it)==t) return true;

    return false;
}


string Model::getTipoVeicolo(const Veicolo* a)const{

    try{
        Carrozzeria*cr=dynamic_cast<Carrozzeria*>(const_cast<Veicolo*>(a));
        if(cr) return "carrozzeria";

        Motore* mt=dynamic_cast<Motore*>(const_cast<Veicolo*>(a));
        if(mt) return "motore";

        Auto* au=dynamic_cast<Auto*>(const_cast<Veicolo*>(a));
        if(au) return "auto";

        Camion* cm=dynamic_cast<Camion*>(const_cast<Veicolo*>(a));
        if(cm) return "camion";

        Moto* mto=dynamic_cast<Moto*>(const_cast<Veicolo*>(a));
        if(mto) return "moto";
        throw Exc();
    }catch(Exc){
         Exc(4,"non valido");
    }
    return "auto";//return di default solo per far scoparire il warning
}


bool Model::defaultSearchRes(){
     auto it = dbVeicoli->begin();
     searchRes->erase();
     for(;it!=dbVeicoli->end();++it){
         searchRes->push_begin(*it);
     }
     return true;
}
