#ifndef VEICOLO_H
#define VEICOLO_H
#include<string>
#include "exceptions/exceptions.h"

using std::string;

class Veicolo{
    string marca;
    string modello;
    string pathimg;
public:
    Veicolo(string ="", string ="", string="");
    Veicolo(const Veicolo& ve);//costruttore di copia profonda
    Veicolo& operator=(const Veicolo& ve);//assegnazione profonda
    virtual ~Veicolo()=0;//distruttore
    bool operator==(const Veicolo& ve)const;//overloading operatore di uguaglianza
    bool operator!=(const Veicolo& ve)const;//overloading operatore di disuguaglianza
    string getMarca()const;
    string getModello()const;
    string getPathImg()const;
    virtual string getTipo()const=0;
    virtual string getDetails()const;
};
#endif // VEICOLO_H
