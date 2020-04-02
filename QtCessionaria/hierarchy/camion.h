#ifndef CAMION_H
#define CAMION_H
#include "hierarchy/mezzo.h"
#include "exceptions/exceptions.h"

class Camion: public Mezzo{
private:
    unsigned int n_assi;
    bool ribaltabile;
public:
    Camion(string ="", string ="", unsigned int =0, bool =false, string ="", double =0, unsigned int =0, unsigned int =0, unsigned int =0, alimentazione =diesel, string ="", double =0, unsigned int =0, unsigned int =1, unsigned int =0, bool =false);
    Camion(const Camion& cam);
    Camion& operator=(const Camion& cam);
    bool operator==(const Camion& cam)const;
    bool operator!=(const Camion& cam)const;
    virtual ~Camion()=default;

    unsigned int getNumAssi()const;
    bool getRibaltabile()const;
};

#endif // CAMION_H

