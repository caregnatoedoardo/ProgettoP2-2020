#ifndef MEZZO_H
#define MEZZO_H
#include "hierarchy/motore.h"
#include "hierarchy/carrozzeria.h"


class Mezzo: public Motore, public Carrozzeria{
private:
    string targa;
    double prezzo;
    unsigned int massa;
    unsigned int numposti;
public:
    Mezzo(string mar="", string mo="", unsigned int ntel=0,bool ca=false,string co="",double lung=0,unsigned int nm=0,unsigned int cil=0,unsigned int cv=0, alimentazione al=diesel, string ta="", double pr=0,unsigned int mas=0, unsigned int npos=1);
    Mezzo(const Mezzo& me);//copia profonda
    Mezzo& operator=(const Mezzo& me);//assegnazione profonda
    bool operator==(const Mezzo& me)const;
    ~Mezzo()=0;

    string getTarga()const;
    double getPrezzo()const;
    unsigned int getMassa()const;
    unsigned int getNumPosti()const;

};

#endif // MEZZO_H
