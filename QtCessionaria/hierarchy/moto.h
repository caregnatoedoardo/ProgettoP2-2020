#ifndef MOTOVEICOLO_H
#define MOTOVEICOLO_H
#include "hierarchy/mezzo.h"
enum tipomoto{corsa, custom, naked, cross};

class Moto: public Mezzo{
private:
    bool sidecar;
    unsigned int classe_emissioni;
    tipomoto type;
public:
    bool getSidecar()const;
    unsigned int getClasseEmissioni()const;
    tipomoto getTipoMoto()const;
};

#endif // MOTOVEICOLO_H
