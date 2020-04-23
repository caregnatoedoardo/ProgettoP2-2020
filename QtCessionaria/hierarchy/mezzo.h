#ifndef MEZZO_H
#define MEZZO_H
#include "hierarchy/motore.h"
#include "hierarchy/carrozzeria.h"


class Mezzo: public Carrozzeria, public Motore{
private:
    string targa;
    double prezzo;
    unsigned int massa;
    unsigned int numposti;
public:
    Mezzo(string ="", string ="", string="", unsigned int =0,bool =false,string ="",double =0,unsigned int =0,unsigned int =0,unsigned int =0, alimentazione =diesel, string ="AA000AA", double =0,unsigned int =0, unsigned int =1);
    Mezzo(const Mezzo& me);//copia profonda
    Mezzo& operator=(const Mezzo& me);//assegnazione profonda
    bool operator==(const Mezzo& me)const;
    bool operator!=(const Mezzo& me)const;
    virtual ~Mezzo()=0;

    string getTarga()const;
    double getPrezzo()const;
    unsigned int getMassa()const;
    unsigned int getNumPosti()const;

    virtual bool checkTarga()const;

};

#endif // MEZZO_H
