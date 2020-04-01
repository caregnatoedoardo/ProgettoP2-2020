#include "hierarchy/mezzo.h"


Mezzo::Mezzo(string mar, string mo, unsigned int ntel,bool ca,string co,double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int ma, unsigned int npos):
    Carrozzeria(mar,mo,ntel,ca,co,lung),Motore(mar,mo,nm,cil,cv,al), targa(ta),prezzo(pr),massa(ma),numposti(npos){}

Mezzo::Mezzo(const Mezzo& me):Veicolo(me), Carrozzeria(me), Motore(me), targa(me.targa),prezzo(me.prezzo),massa(me.massa),numposti(me.numposti){}

Mezzo& Mezzo::operator=(const Mezzo &me){
    if(this!=&me){
        //delete this ? (forse)
        Carrozzeria::operator=(me);
        Motore::operator=(me);
        targa=me.targa;
        prezzo=me.prezzo;
        massa=me.massa;
        numposti=me.numposti;
    }
    return *this;
}

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
    char alfabeto [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numeri[10]={'0','1','2','3','4','5','6','7','8','9'};
    if(targa.size()!=7) return false;

    for(int i=0;i<26;i++){                           //controllo del primo, secondo, sesto e settimo carattere della targa (lettere)
            if(targa[0]!=alfabeto[i] || targa[1]!=alfabeto[i] || targa[5]!=alfabeto[i] || targa[6]!=alfabeto[i]) return false;
    }
    for(int i=0;i<10;i++){                           //controllo del terzo, quarto, quinto carattere della targa (cifre)
        if(targa[2]!=numeri[i] || targa[3]!=numeri[i] || targa[4]!=numeri[i]) return false;
    }

    return true;
}





