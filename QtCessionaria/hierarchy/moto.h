#ifndef MOTO_H
#define MOTO_H
#include "hierarchy/mezzo.h"
#include "exceptions/exceptions.h"

enum tipomoto{corsa, custom, naked, cross};

class Moto: public Mezzo{
private:
    bool sidecar;
    unsigned int classe_emissioni;
    tipomoto type;
public:
    Moto(string ="", string ="", unsigned int =0, bool =false, string ="", double =0, unsigned int =0, unsigned int =0, unsigned int =0, alimentazione =diesel, string ="AA00000", double =0, unsigned int =0, unsigned int =1, bool =false, unsigned int =0, tipomoto =corsa);
    Moto(const Moto& mot);
    Moto& operator=(const Moto& mot);
    virtual ~Moto()=default;

    bool operator==(const Moto& mot)const;
    bool operator!=(const Moto& mot)const;
    bool getSidecar()const;
    unsigned int getClasseEmissioni()const;
    tipomoto getTipoMoto()const;
    bool checkTipoMoto()const;
    string convertToString(tipomoto tm)const;

    bool checkTarga() const override;

};

#endif // MOTO_H
