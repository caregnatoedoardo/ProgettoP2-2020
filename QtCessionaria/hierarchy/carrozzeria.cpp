#include "hierarchy/carrozzeria.h"

Carrozzeria::Carrozzeria(string ma, string mo, string pt, unsigned int nt, bool ca, string co, double lung):Veicolo(ma,mo,pt),n_telaio(nt), cambio_auto(ca), colore(co), lunghezza(lung){}

Carrozzeria::Carrozzeria(const Carrozzeria& ca):Veicolo(ca),n_telaio(ca.n_telaio), cambio_auto(ca.cambio_auto), colore(ca.colore), lunghezza(ca.lunghezza){}

Carrozzeria& Carrozzeria::operator=(const Carrozzeria &ca){
    if(this != &ca){
        //delete this;
        Veicolo::operator=(ca);
        n_telaio=ca.n_telaio;
        cambio_auto=ca.cambio_auto;
        colore=ca.colore;
        lunghezza=ca.lunghezza;
    }
    return *this;
}

bool Carrozzeria::operator==(const Carrozzeria &ca) const{
    return (Veicolo::operator==(ca) && n_telaio==ca.n_telaio &&
            cambio_auto==ca.cambio_auto && colore==ca.colore &&
            lunghezza==ca.lunghezza);
}
bool Carrozzeria::operator!=(const Carrozzeria &ca) const{
    return !(Veicolo::operator==(ca) && n_telaio==ca.n_telaio &&
             cambio_auto==ca.cambio_auto && colore==ca.colore &&
             lunghezza==ca.lunghezza);
}

unsigned int Carrozzeria::getNTelaio() const{return n_telaio;}
bool Carrozzeria::getCambio() const{return cambio_auto;}
string Carrozzeria::getColore() const{return colore;}
double Carrozzeria::getLunghezza() const{return lunghezza;}
string Carrozzeria::getTipo() const{return "carrozzeria";}
