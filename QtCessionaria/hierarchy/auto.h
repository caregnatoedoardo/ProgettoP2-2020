#ifndef AUTO_H
#define AUTO_H
#include "mezzo.h"

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
    ~Auto()=0;

    segmento getSegmento()const;
    bool getAutocarro()const;
};

#endif // AUTO_H
