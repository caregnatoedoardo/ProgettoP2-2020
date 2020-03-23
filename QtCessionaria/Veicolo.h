#ifndef VEICOLO_H
#define VEICOLO_H
#include<string>
using std::string;

class Veicolo{
private:
    string marca;
    string modello;
public:
    virtual ~Veicolo()=0;
    virtual Veicolo * clone()const=0;
    string getMarca()const;
    string getModello()const;
};
#endif // VEICOLO_H
