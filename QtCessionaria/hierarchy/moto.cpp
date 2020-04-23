#include "hierarchy/moto.h"

Moto::Moto(string mar, string mo, string pt, unsigned int ntel,bool ca, string co, double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int mas, unsigned int npos,bool sidec, unsigned int clem,tipomoto t):
    Veicolo(mar,mo,pt), Mezzo(mar,mo,pt,ntel,ca,co,lung,nm,cil,cv,al,ta,pr,mas,npos), sidecar(sidec),classe_emissioni(clem),type(t){}

Moto::Moto(const Moto& mot):Veicolo(mot), Mezzo(mot), sidecar(mot.sidecar),classe_emissioni(mot.classe_emissioni),type(mot.type){}

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

bool Moto::operator!=(const Moto& mot) const{
    return !(Mezzo::operator==(mot) && sidecar==mot.sidecar && classe_emissioni==mot.classe_emissioni && type==mot.type);
}

bool Moto::getSidecar() const{return sidecar;}
unsigned int Moto::getClasseEmissioni() const{return classe_emissioni;}
tipomoto Moto::getTipoMoto() const{return type;}
bool Moto::checkTipoMoto() const{
    return (type==corsa || type==custom || type==naked || type== cross);
}

string Moto::convertToString(tipomoto tm) const{
    if(tm==corsa) return "corsa";
    if(tm==custom) return "custom";
    if(tm==naked) return "naked";
    if(tm==cross) return "cross";

    throw Exc(4);
}



bool Moto::checkTarga() const{
    string targa=getTarga();
    char alfabeto [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numeri[10]={'0','1','2','3','4','5','6','7','8','9'};
    if(targa.size()!=7) return false;

    for(int i=0;i<26;i++){                           //controllo del primo, secondo carattere della targa (lettere)
            if(targa[0]!=alfabeto[i] || targa[1]!=alfabeto[i]) return false;
    }
    for(int i=0;i<10;i++){                           //controllo del terzo, quarto, quinto, sesto e settimo carattere della targa (cifre)
        if(targa[2]!=numeri[i] || targa[3]!=numeri[i] || targa[4]!=numeri[i] || targa[5]!=numeri[i] || targa[6]!=numeri[i]) return false;
    }

    return true;
}

string Moto::getTipo() const{return "moto";}
