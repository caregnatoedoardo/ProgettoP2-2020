#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H
#include "Carrozzeria.h"
#include "Motore.h"

class Autoveicolo: public Carrozzeria, public Motore{
private:
    string targa;
    unsigned int prezzo;
    unsigned int massa;
    unsigned int persone_trasp;
public:

};

#endif // AUTOVEICOLO_H
