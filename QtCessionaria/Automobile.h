#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include "Autoveicolo.h"

enum segmento{berlina, station, coupe, suv};
class Automobile: public Autoveicolo{
private:
    segmento seg;
    bool autocarro;
};

#endif // AUTOMOBILE_H
