#ifndef AUTO_H
#define AUTO_H
#include "hierarchy/mezzo.h"
#include "hierarchy/veicolo.h"
#include "exceptions/exceptions.h"

enum segmento{berlina, station, coupe, suv};

class Auto: public Mezzo{
private:
    segmento seg;
    bool autocarro;
public:
    Auto(string ="", string ="", unsigned int =0,bool =false, string ="", double =0, unsigned int =0, unsigned int =0, unsigned int =0, alimentazione =diesel, string ="", double =0, unsigned int =0, unsigned int =1, segmento =coupe, bool =false);
    Auto(const Auto& au);
    Auto& operator=(const Auto& au);
    bool operator==(const Auto& au)const;
    bool operator!=(const Auto& au)const;
    virtual ~Auto()=default;
    segmento getSegmento()const;
    bool getAutocarro()const;

    bool checkSegmento(string segmento)const;
    string convertSegmento()const;

};

#endif // AUTO_H
