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
    Moto(string mar="", string mo="", unsigned int ntel=0,bool ca=false, string co="",double lung=0,unsigned int nm=0,unsigned int cil=0,unsigned int cv=0, alimentazione al=diesel, string ta="", double pr=0,unsigned int mas=0, unsigned int npos=1,bool sidec=false,unsigned int clem=0,tipomoto t=corsa);
    Moto(const Moto& mot);
    Moto& operator=(const Moto& mot);
    ~Moto()=0;

    bool operator==(const Moto& mot)const;
    bool getSidecar()const;
    unsigned int getClasseEmissioni()const;
    tipomoto getTipoMoto()const;
};

#endif // MOTOVEICOLO_H
