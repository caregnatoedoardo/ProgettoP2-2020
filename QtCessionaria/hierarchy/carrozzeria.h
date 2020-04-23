#ifndef CARROZZERIA_H
#define CARROZZERIA_H
#include "hierarchy/veicolo.h"
#include "exceptions/exceptions.h"

class Carrozzeria: virtual public Veicolo{
private:
    unsigned int n_telaio;
    bool cambio_auto;
    string colore;
    double lunghezza;
public:
    Carrozzeria(string ="", string ="", string="", unsigned int =0, bool =false, string ="", double =0);
    Carrozzeria(const Carrozzeria& ca);
    Carrozzeria& operator=(const Carrozzeria& ca);
    bool operator==(const Carrozzeria& ca)const;
    bool operator!=(const Carrozzeria& ca)const;
    virtual ~Carrozzeria()=default;

    unsigned int getNTelaio()const;
    bool getCambio()const;
    string getColore()const;
    double getLunghezza()const;
    virtual string getTipo() const override;
};

#endif // CARROZZERIA_H
