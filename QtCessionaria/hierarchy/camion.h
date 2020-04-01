#ifndef CAMION_H
#define CAMION_H
#include "hierarchy/mezzo.h"
#include "exceptions/exceptions.h"

class Camion: public Mezzo{
private:
    unsigned int n_assi;
    bool ribaltabile;
public:
    Camion(string mar="", string mo="", unsigned int ntel=0,bool ca=false, string co="",double lung=0,unsigned int nm=0,unsigned int cil=0,unsigned int cv=0, alimentazione al=diesel, string ta="", double pr=0,unsigned int mas=0, unsigned int npos=1, unsigned int nass=0,bool rib=false);
    Camion(const Camion& cam);
    Camion& operator=(const Camion& cam);
    bool operator==(const Camion& cam)const;
    bool operator!=(const Camion& cam)const;
    virtual ~Camion();

    unsigned int getNumAssi()const;
    bool getRibaltabile()const;
};

#endif // CAMION_H

