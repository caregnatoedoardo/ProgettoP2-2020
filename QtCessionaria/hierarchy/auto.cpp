#include "hierarchy/auto.h"

Auto::Auto(string mar, string mo, unsigned int ntel,bool ca, string co, double lung,unsigned int nm,unsigned int cil,unsigned int cv, alimentazione al, string ta, double pr,unsigned int mas, unsigned int npos, segmento se, bool autocar):
    Veicolo(mar,mo), Mezzo(mar,mo,ntel,ca,co,lung,nm,cil,cv,al,ta,pr,mas,npos), seg(se),autocarro(autocar){}

Auto::Auto(const Auto& au): Veicolo(au), Mezzo(au), seg(au.seg),autocarro(au.autocarro){}

Auto& Auto::operator=(const Auto &au){
    if(this!=&au){
        Mezzo::operator=(au);
        seg=au.seg;
        autocarro=au.autocarro;
    }
    return *this;
}

bool Auto::operator==(const Auto &au) const{
    return (Mezzo::operator==(au) && seg==au.seg && autocarro==au.autocarro);
}

bool Auto::operator!=(const Auto &au) const{
    return !(Mezzo::operator==(au) && seg==au.seg && autocarro==au.autocarro);
}

segmento Auto::getSegmento() const{return seg;}
bool Auto::getAutocarro() const{return autocarro;}



string Auto::convertSegmento() const{//converte l'enum segmento in stringa
    if(seg==berlina) return "berlina";
    if(seg==station) return "station";
    if(seg==coupe) return "coupe";
    if(seg==suv) return "suv";

    throw Exc(4);
}



bool Auto::checkSegmento(string segmento) const{
    return ((segmento == "suv") || (segmento== "berlina") || (segmento == "station") || (segmento== "coupe"));
}

