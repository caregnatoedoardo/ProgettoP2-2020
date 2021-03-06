#include "hierarchy/motore.h"

Motore::Motore(string ma, string mo, string pt, unsigned int nm, unsigned int cil, unsigned int cv, alimentazione al):Veicolo(ma,mo,pt), n_motore(nm), cilindrata(cil), cavalli(cv), alim(al){}

Motore::Motore(const Motore& mo):Veicolo(mo), n_motore(mo.n_motore), cilindrata(mo.cilindrata), cavalli(mo.cavalli),alim(mo.alim){}

Motore& Motore::operator=(const Motore &mo){
    if(this != &mo){
        Veicolo::operator=(mo);//operatore di assegnazione di Veicolo
        n_motore=mo.n_motore;
        cilindrata=mo.cilindrata;
        cavalli=mo.cavalli;
        alim=mo.alim;
    }
    return *this;
}

bool Motore::operator==(const Motore& mo)const{
    return (Veicolo::operator==(mo) && n_motore==mo.n_motore && cilindrata==mo.cilindrata && cavalli==mo.cavalli && alim==mo.alim);
}

bool Motore::operator!=(const Motore &mo) const{
    return !(Veicolo::operator==(mo) && n_motore==mo.n_motore && cilindrata==mo.cilindrata && cavalli==mo.cavalli && alim==mo.alim);
}


unsigned int Motore::getNMotore() const{return n_motore;}
unsigned int Motore::getCilindrata() const{return cilindrata;}
unsigned int Motore::getCavalli() const{return cavalli;}
string Motore::getTipo() const{return "motore";}
alimentazione Motore::getAlimentazione() const{return alim;}
bool Motore::checkAlimentazione(string al) const{
    return((al == "diesel") || (al== "benzina") || (al == "elettrico") || (al == "gpl") || (al == "metano"));
}

string Motore::convertToAlim(alimentazione al) const{
    try{
        if(al==diesel) return "diesel";
        if(al==benzina) return "benzina";
        if(al==elettrica) return "elettrica";
        if(al==gpl) return "gpl";
        if(al==metano) return "metano";
        throw Exc();

    }catch(Exc){
        Exc(5);
    }
    return "";
}

string Motore::getDetails() const{
    return Veicolo::getDetails()+"\nNUMERO MOTORE: "+ std::to_string(n_motore)+" \nCILINDRATA: "+std::to_string(cilindrata)+" \nCAVALLI: "+std::to_string(cavalli)+" \nALIMENTAZIONE: "+convertToAlim(alim)+" ";
}



