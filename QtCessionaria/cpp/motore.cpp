#include "hierarchy/motore.h"

Motore::Motore(string ma, string mo, unsigned int nm, unsigned int cil, unsigned int cv, alimentazione al):Veicolo(ma,mo), n_motore(nm), cilindrata(cil), cavalli(cv), alim(al){}

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

unsigned int Motore::getNMotore() const{return n_motore;}
unsigned int Motore::getCilindrata() const{return cilindrata;}
unsigned int Motore::getCavalli() const{return cavalli;}
alimentazione Motore::getAlimentazione() const{return alim;}
