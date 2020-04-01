#include "hierarchy/moto.h"

Moto::Moto(string mar, string mo, unsigned int ntel,bool ca, string co, double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int mas, unsigned int npos,bool sidec, unsigned int clem,tipomoto t):
    Mezzo(mar,mo,ntel,ca,co,lung,nm,cil,cv,al,ta,pr,mas,npos), sidecar(sidec),classe_emissioni(clem),type(t){}

Moto::Moto(const Moto& mot):Mezzo(mot), sidecar(mot.sidecar),classe_emissioni(mot.classe_emissioni),type(mot.type){}

Moto& Moto::operator=(const Moto& mot){
    if(this!=&mot){
        Mezzo::operator=(mot);
        sidecar=mot.sidecar;
        classe_emissioni=mot.classe_emissioni;
        type=mot.type;
    }
    return *this;
}

bool Moto::operator==(const Moto& mot) const{
    return (Mezzo::operator==(mot) && sidecar==mot.sidecar && classe_emissioni==mot.classe_emissioni && type==mot.type);
}

bool Moto::getSidecar() const{return sidecar;}
unsigned int Moto::getClasseEmissioni() const{return classe_emissioni;}
tipomoto Moto::getTipoMoto() const{return type;}


