#include "hierarchy/mezzo.h"

//Richiamare gli opportuni metodi di Veicolo

Mezzo::Mezzo(string mar, string mo, string pt, unsigned int ntel,bool ca,string co,double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int ma, unsigned int npos):
     Veicolo(mar,mo,pt), Carrozzeria(mar,mo,pt,ntel,ca,co,lung),Motore(mar,mo,pt,nm,cil,cv,al), targa(ta),prezzo(pr),massa(ma),numposti(npos){}

Mezzo::Mezzo(const Mezzo& me): Veicolo(me), Carrozzeria(me), Motore(me), targa(me.targa),prezzo(me.prezzo),massa(me.massa),numposti(me.numposti){}

Mezzo& Mezzo::operator=(const Mezzo &me){
    if(this!=&me){
        Carrozzeria::operator=(me);
        Motore::operator=(me);
        targa=me.targa;
        prezzo=me.prezzo;
        massa=me.massa;
        numposti=me.numposti;
    }
    return *this;
}

Mezzo::~Mezzo(){}

bool Mezzo::operator==(const Mezzo &me) const{
    return (Carrozzeria::operator==(me) && Motore::operator==(me) && targa==me.targa && prezzo==me.prezzo && massa==me.massa && numposti==me.numposti);
}

bool Mezzo::operator!=(const Mezzo &me) const{
    return !(Carrozzeria::operator==(me) && Motore::operator==(me) && targa==me.targa && prezzo==me.prezzo && massa==me.massa && numposti==me.numposti);
}

string Mezzo::getTarga() const{return targa;}
double Mezzo::getPrezzo() const{return prezzo;}
unsigned int Mezzo::getMassa() const{return massa;}
unsigned int Mezzo::getNumPosti() const{return numposti;}

bool Mezzo::checkTarga()const{//funzione valida solamente per auto e camion. Sarà ridefinita per moto
    char alfabeto [26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char numeri[10]={'0','1','2','3','4','5','6','7','8','9'};
    if(targa.size()!=7) return false;

    for(int i=0;i<10;i++){                           //controllo del primo, secondo, sesto e settimo carattere della targa (lettere)
        if(targa[0]==numeri[i] || targa[1]==numeri[i] || targa[5]==numeri[i] || targa[6]==numeri[i])
            return false;
    }

    for(int i=0;i<26;i++){                          //controllo del terzo, quarto, quinto carattere della targa (cifre)
        if(targa[2]==alfabeto[i] || targa[3]==alfabeto[i] || targa[4]==alfabeto[i])
            return false;
    }
    return true;
}


string Mezzo::getDetails() const{
    return Carrozzeria::getDetails()+"NUMERO MOTORE: "+std::to_string(Motore::getNMotore())+" \nCILINDRATA: "+std::to_string(Motore::getCilindrata())+" \nCAVALLI: "+std::to_string(Motore::getCavalli())+" \nALIMENTAZIONE: "+Motore::convertToAlim(getAlimentazione())+" \nTARGA: "+targa+" \nPREZZO: "+std::to_string(prezzo)+" \nMASSA: "+std::to_string(massa)+" \nNUM POSTI: "+std::to_string(numposti)+" \n";
    //non richiamo Motore::getDetails() per non avere i doppi dettagli di veicolo (marca e modello).
}

