#ifndef VEICOLO_H
#define VEICOLO_H
#include<string>
using std::string;

class Veicolo{
private:
    string marca;
    string modello;
public:
    Veicolo(string ma="", string mo="");
    Veicolo(const Veicolo& ve);//costruttore di copia profonda
    Veicolo& operator=(const Veicolo& ve);//assegnazione profonda
    virtual ~Veicolo()=0;//distruzione profonda
    bool operator==(const Veicolo& ve)const;//operatore di uguaglianza

    virtual Veicolo * clone()const=0;
    string getMarca()const;
    string getModello()const;
};
#endif // VEICOLO_H
