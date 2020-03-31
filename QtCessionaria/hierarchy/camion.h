#ifndef CAMION_H
#define CAMION_H
#include "hierarchy/mezzo.h"

class Camion: public Mezzo{
private:
    unsigned int n_assi;
    bool ribaltabile;
public:
    unsigned int getNumAssi()const;
    bool getRibaltabile()const;
};

#endif // CAMION_H
