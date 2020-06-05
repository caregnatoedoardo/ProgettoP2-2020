#include "hierarchy/veicolo.h"
#include "exceptions/exceptions.h"
using std::string;


Veicolo::Veicolo(string ma, string mo, string pt):marca(ma),modello(mo),pathimg(pt){
    //implementare il controllo di marca e modello con le eccezioni
}

Veicolo::Veicolo(const Veicolo& ve):marca(ve.marca), modello(ve.modello), pathimg(ve.pathimg){}

Veicolo& Veicolo::operator=(const Veicolo& ve){
    if(this != &ve){
        marca=ve.marca;
        modello=ve.modello;
        pathimg=ve.pathimg;
    }
    return *this;
}

Veicolo::~Veicolo(){}

bool Veicolo::operator==(const Veicolo &ve)const{
    return (marca == ve.marca && modello==ve.modello && pathimg==ve.pathimg);
}

bool Veicolo::operator!=(const Veicolo &ve) const{
    return !(marca == ve.marca && modello==ve.modello && pathimg==ve.pathimg);
}

string Veicolo::getMarca() const{return marca;}
string Veicolo::getModello() const{return modello;}
string Veicolo::getPathImg() const{return pathimg;}

string Veicolo::getDetails()const{
    return "MARCA: "+marca+"\n MODELLO: "+modello+"\n ";
}
