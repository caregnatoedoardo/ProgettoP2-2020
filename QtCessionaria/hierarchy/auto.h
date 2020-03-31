#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include "mezzo.h"

enum segmento{berlina, station, coupe, suv};
class Auto: public Mezzo{
private:
    segmento seg;
    bool autocarro;
public:
    segmento getSegmento()const;
    bool getAutocarro()const;
};

#endif // AUTOMOBILE_H
