#include "hierarchy/camion.h"

Camion::Camion(string mar, string mo, unsigned int ntel,bool ca, string co, double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int mas, unsigned int npos, unsigned int nass, bool rib):
    Mezzo(mar,mo,ntel,ca,co,lung,nm,cil,cv,al,ta,pr,mas,npos), n_assi(nass),ribaltabile(rib){}

Camion::Camion(const Camion& cam):Mezzo(cam), n_assi(cam.n_assi),ribaltabile(cam.ribaltabile){}

Camion& Camion::operator=(const Camion &cam){
    if(this!=&cam){
        Mezzo::operator=(cam);
        n_assi=cam.n_assi;
        ribaltabile=cam.ribaltabile;
    }
    return *this;
}

bool Camion::operator==(const Camion &cam) const{
    return (Mezzo::operator==(cam) && n_assi==cam.n_assi && ribaltabile==cam.ribaltabile);
}

unsigned int Camion::getNumAssi() const{return n_assi;}
bool Camion::getRibaltabile() const{return ribaltabile;}


