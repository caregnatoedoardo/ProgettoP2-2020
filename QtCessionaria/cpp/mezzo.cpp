#include "hierarchy/mezzo.h"


Mezzo::Mezzo(string mar, string mo, unsigned int ntel,bool ca,string co,double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int ma, unsigned int npos):
    Carrozzeria(mar,mo,ntel,ca,co,lung),
    Motore(mar,mo,nm,cil,cv,al), targa(ta),prezzo(pr),massa(ma),numposti(npos){}

Mezzo::Mezzo(const Mezzo& me):Carrozzeria(me),Motore(me),targa(me.targa),prezzo(me.prezzo),massa(me.massa),numposti(me.numposti){}

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

string Mezzo::getTarga() const{return targa;}
double Mezzo::getPrezzo() const{return prezzo;}
unsigned int Mezzo::getMassa() const{return massa;}
unsigned int Mezzo::getNumPosti() const{return numposti;}




