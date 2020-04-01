#ifndef VEICOLO_H
#define VEICOLO_H
#include<string>
#include "exceptions/exceptions.h"

using std::string;

class Veicolo{
private:
    string marca;
    string modello;
public:
    Veicolo(string ma="", string mo="");
    Veicolo(const Veicolo& ve);//costruttore di copia profonda
    Veicolo& operator=(const Veicolo& ve);//assegnazione profonda
    virtual ~Veicolo()=0;//distruttore
    bool operator==(const Veicolo& ve)const;//overloading operatore di uguaglianza
    bool operator!=(const Veicolo& ve)const;//overloading operatore di disuguaglianza

    string getMarca()const;
    string getModello()const;
};
#endif // VEICOLO_H
