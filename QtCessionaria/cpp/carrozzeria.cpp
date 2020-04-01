#include "hierarchy/carrozzeria.h"

Carrozzeria::Carrozzeria(string ma, string mo, unsigned int nt, bool ca, string co, double lung):Veicolo(ma,mo),n_telaio(nt), cambio(ca), colore(co), lunghezza(lung){}

Carrozzeria::Carrozzeria(const Carrozzeria& ca):Veicolo(ca),n_telaio(ca.n_telaio), cambio(ca.cambio), colore(ca.colore), lunghezza(ca.lunghezza){}

Carrozzeria& Carrozzeria::operator=(const Carrozzeria &ca){
    if(this != &ca){
        //delete this;
        Veicolo::operator=(ca);
        n_telaio=ca.n_telaio;
        cambio=ca.cambio;
        colore=ca.colore;
        lunghezza=ca.lunghezza;
    }
    return *this;
}

bool Carrozzeria::operator==(const Carrozzeria &ca) const{
    return (Veicolo::operator==(ca) && n_telaio==ca.n_telaio &&
            cambio==ca.cambio && colore==ca.colore &&
            lunghezza==ca.lunghezza);
}
bool Carrozzeria::operator!=(const Carrozzeria &ca) const{
    return !(Veicolo::operator==(ca) && n_telaio==ca.n_telaio &&
             cambio==ca.cambio && colore==ca.colore &&
             lunghezza==ca.lunghezza);
}

unsigned int Carrozzeria::getNTelaio() const{return n_telaio;}
bool Carrozzeria::getCambio() const{return cambio;}
string Carrozzeria::getColore() const{return colore;}
double Carrozzeria::getLunghezza() const{return lunghezza;}

Carrozzeria::~Carrozzeria(){delete this;}//implementato distruttore sennò non compila!!!!!
