#ifndef MOTORE_H
#define MOTORE_H
#include "hierarchy/veicolo.h"
#include "exceptions/exceptions.h"

enum alimentazione{diesel, benzina, elettrico, gpl, metano};

class Motore: virtual public Veicolo{
private:
    unsigned int n_motore;
    unsigned int cilindrata;
    unsigned int cavalli;
    alimentazione alim;
public:
    Motore(string ma="", string mo="", unsigned int nm=0, unsigned int cil=0, unsigned int cv=0, alimentazione al=diesel);
    Motore(const Motore& mo);
    Motore& operator=(const Motore& mo);
    bool operator==(const Motore& mo)const;
    bool operator!=(const Motore& mo)const;
    virtual ~Motore()=default;

    unsigned int getNMotore()const;
    unsigned int getCilindrata()const;
    unsigned int getCavalli()const;
    alimentazione getAlimentazione()const;
    bool checkAlimentazione(string al)const;
    string convertToAlim(alimentazione al)const;

};

#endif // MOTORE_H
