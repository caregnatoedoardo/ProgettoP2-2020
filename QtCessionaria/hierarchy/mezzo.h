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
    string getTarga()const;
    double getPrezzo()const;
    unsigned int getMassa()const;
    unsigned int getNumPosti()const;

};

#endif // MEZZO_H
