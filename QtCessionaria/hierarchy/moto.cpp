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
bool Moto::checkTipoMoto() const{return (type==corsa || type==custom || type==naked || type==cross);}

string Moto::convertToString(tipomoto tm) const{
    try{
        if(tm==corsa) return "corsa";
        if(tm==custom) return "custom";
        if(tm==naked) return "naked";
        if(tm==cross) return "cross";
        throw Exc();
    }
    catch(Exc){
        Exc(4);
    }
    return "";
}

bool Moto::checkTarga() const{
    string targa=getTarga();
    char alfabeto [26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char numeri[10]={'0','1','2','3','4','5','6','7','8','9'};
    if(targa.size()!=7) return false;

    for(int i=0;i<10;i++){                           //controllo del primo, secondo carattere della targa (lettere)
        if(targa[0]==numeri[i] || targa[1]==numeri[i])
            return false;
    }
    for(int i=0;i<26;i++){                           //controllo del terzo, quarto, quinto, sesto e settimo carattere della targa (cifre)
        if(targa[2]==alfabeto[i] || targa[3]==alfabeto[i] ||  targa[4]==alfabeto[i]  || targa[5]==alfabeto[i] || targa[6]==alfabeto[i])
            return false;
    }
    return true;
}

string Moto::getTipo() const{return "moto";}

string Moto::getDetails() const{
    return Mezzo::getDetails()+"SIDECAR: "+(sidecar?"Sì":"No")+"\nCLASSE EMISSIONI: "+std::to_string(classe_emissioni)+"\nTIPO: "+convertToString(type)+"\n";
}
