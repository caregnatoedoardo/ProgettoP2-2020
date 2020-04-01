#ifndef MOTOVEICOLO_H
#define MOTOVEICOLO_H
#include "hierarchy/mezzo.h"
#include "exceptions/exceptions.h"

enum tipomoto{corsa, custom, naked, cross};

class Moto: public Mezzo{
private:
    bool sidecar;
    unsigned int classe_emissioni;
    tipomoto type;
public:
    Moto(string mar="", string mo="", unsigned int ntel=0,bool ca=false, string co="",double lung=0,unsigned int nm=0,unsigned int cil=0,unsigned int cv=0, alimentazione al=diesel, string ta="AA00000", double pr=0,unsigned int mas=0, unsigned int npos=1,bool sidec=false,unsigned int clem=0,tipomoto t=corsa);
    Moto(const Moto& mot);
    Moto& operator=(const Moto& mot);
    virtual ~Moto();

    bool operator==(const Moto& mot)const;
    bool operator!=(const Moto& mot)const;
    bool getSidecar()const;
    unsigned int getClasseEmissioni()const;
    tipomoto getTipoMoto()const;
    bool checkTipoMoto()const;
    string convertToString(tipomoto tm)const;
    bool checkTarga() const override;
};

#endif // MOTOVEICOLO_H
