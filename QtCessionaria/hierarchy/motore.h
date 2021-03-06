#ifndef MOTORE_H
#define MOTORE_H
#include "hierarchy/veicolo.h"

enum alimentazione{diesel, benzina, elettrica, gpl, metano};

class Motore: virtual public Veicolo{
private:
    unsigned int n_motore;
    unsigned int cilindrata;
    unsigned int cavalli;
    alimentazione alim;
public:
    Motore(string ="", string ="", string ="", unsigned int =0, unsigned int =0, unsigned int =0, alimentazione =diesel);
    Motore(const Motore& mo);
    Motore& operator=(const Motore& mo);
    bool operator==(const Motore& mo)const;
    bool operator!=(const Motore& mo)const;
    virtual ~Motore()=default;

    unsigned int getNMotore()const;
    unsigned int getCilindrata()const;
    unsigned int getCavalli()const;
    alimentazione getAlimentazione()const;
    bool checkAlimentazione(string al)const;
    string convertToAlim(alimentazione al)const;
    virtual string getTipo() const override;
    virtual string getDetails() const override;

};

#endif // MOTORE_H
