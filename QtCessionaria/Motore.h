#ifndef MOTORE_H
#define MOTORE_H
#include "Veicolo.h"

enum alimentazione{diesel, benzina, elettrico, gpl, metano};

class Motore: virtual public Veicolo{
private:
    unsigned int n_motore;
    unsigned int cilindrata;
    unsigned int cavalli;
    alimentazione alim;
public:

};

#endif // MOTORE_H
