#ifndef CARROZZERIA_H
#define CARROZZERIA_H
#include "hierarchy/veicolo.h"

class Carrozzeria: virtual public Veicolo{
private:
    unsigned int n_telaio;
    bool cambio;
    string colore;
    double lunghezza;
public:
    Carrozzeria(string ma="", string mo="", unsigned int nt=0, bool ca=false, string co="", double lung=0);
    Carrozzeria(const Carrozzeria& ca);
    Carrozzeria& operator=(const Carrozzeria& ca);
    bool operator==(const Carrozzeria& ca)const;
    ~Carrozzeria()=0;

    unsigned int getNTelaio()const;
    bool getCambio()const;
    string getColore()const;
    double getLunghezza()const;
};

#endif // CARROZZERIA_H
