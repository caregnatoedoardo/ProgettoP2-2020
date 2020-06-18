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
    flagsaved(true){}

bool Model::getFlagDataSaved() const{return flagsaved;}


void Model::save(){


    QSaveFile file(QString::fromStdString(path));
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

        //const QString tipologia;  (*it)->getTipologia()
        //const QString tipologia = QString::fromStdString((*it)->getTipo()); //bisogna avere la tipologia auto o camion o moto
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
        //const Veicolo* save = *it;

        //const QString tipologia;  (*it)->getTipologia()
        //const QString tipologia = QString::fromStdString((*it)->getTipo()); //bisogna avere la tipologia auto o camion o moto
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
        flagsaved=true;               // CAMBIO LA SENTINELLA, HO SALVATO!;)
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


                    if(db=="veicoli" && !push_end(toPush)){

                        throw Exc(11,"caricamento veicolo");
                        return;
                    }

                    else
                        if(db=="venduti" && !push_endVenduti(toPush)){

                            throw Exc(11,"caricamento veicolo");
                            return;
                        }



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
    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Veicolo* ve=dynamic_cast<Veicolo*>(*it);
        if(ve && ve->getTipo()!=ty)
            searchRes->remove(ve);
    }
    return;
}

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



void Model::filterByAlim(string al){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Motore* eng=dynamic_cast<Motore*>(*it);
        if(eng && eng->convertToAlim(eng->getAlimentazione())!=al)
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

void Model::filterBySegmento(string sg){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Auto* aut=dynamic_cast<Auto*>(*it);
        if(aut && aut->convertSegmento(aut->getSegmento())!=sg)
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

void Model::filterByTypeMoto(string tm){
    if(searchRes->isEmpty()) return;

    for(auto it=searchRes->begin();it!=searchRes->end();++it){
        Moto* mt=dynamic_cast<Moto*>(*it);
        if(mt && mt->convertToString(mt->getTipoMoto())!=tm)
            searchRes->remove(mt);
    }
    return;
}


bool Model::push_end(Veicolo* a){
    if(dbVeicoli->push_end(a)){
        if(!(searchRes==dbVeicoli))
            searchRes=dbVeicoli;
        flagsaved=false;
        return true;
    }
    return false;
}


bool Model::push_endVenduti(Veicolo* a){
    if(dbVenduti->push_end(a)){
        flagsaved=false;
        return true;
    }
    return false;
}



bool Model::remove(Veicolo* a){
    if(dbVeicoli->remove(a)){
        searchRes=dbVeicoli;
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
    if(search(dbVeicoli,a) && dbVenduti->push_begin(a) && dbVeicoli->cancella(a))
        return true;
    return false;
}

bool Model::nonVenduta(Veicolo* a){//verifica se un veicolo è presente nel Db dei venudti e, se presente, lo riporta nel db dei disponibili.
    if(search(dbVenduti, a) && dbVeicoli->push_begin(a) && dbVenduti->cancella(a))//se è presente all'interno del db venduti
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

    if(!(searchRes == dbVeicoli))
        searchRes = dbVeicoli;
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








