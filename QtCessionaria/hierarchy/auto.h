#ifndef AUTO_H
#define AUTO_H
#include "hierarchy/mezzo.h"
#include "exceptions/exceptions.h"

enum segmento{berlina, station, coupe, suv};
class Auto: public Mezzo{
private:
    segmento seg;
    bool autocarro;
public:
    Auto(string mar="", string mo="", unsigned int ntel=0,bool ca=false, string co="",double lung=0,unsigned int nm=0,unsigned int cil=0,unsigned int cv=0, alimentazione al=diesel, string ta="", double pr=0,unsigned int mas=0, unsigned int npos=1, segmento se=coupe, bool autocar=false);
    Auto(const Auto& au);
    Auto& operator=(const Auto& au);
    bool operator==(const Auto& au)const;
    bool operator!=(const Auto& au)const;
    virtual ~Auto()override=default;

    segmento getSegmento()const;
    bool getAutocarro()const;

    bool checkSegmento(string segmento)const;
    string convertSegmento()const;
};

#endif // AUTO_H
