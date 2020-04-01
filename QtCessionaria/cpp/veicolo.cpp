#include "hierarchy/veicolo.h"
#include "exceptions/exceptions.h"
using std::string;


Veicolo::Veicolo(string ma, string mo):marca(ma),modello(mo){
    //implementare il controllo di marca e modello con le eccezioni
}

Veicolo::Veicolo(const Veicolo& ve):marca(ve.marca), modello(ve.modello){}

Veicolo& Veicolo::operator=(const Veicolo& ve){
    if(this != &ve){
        //delete this; ---> da vedere
        marca=ve.marca;
        modello=ve.modello;
    }
    return *this;
}


bool Veicolo::operator==(const Veicolo &ve)const{
    return (marca == ve.marca && modello==ve.modello);
}

bool Veicolo::operator!=(const Veicolo &ve) const{
    return !(marca == ve.marca && modello==ve.modello);
}

string Veicolo::getMarca() const{return marca;}
string Veicolo::getModello() const{return modello;}

