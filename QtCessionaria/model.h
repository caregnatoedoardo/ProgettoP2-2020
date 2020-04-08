#ifndef MODEL_H
#define MODEL_H

#include <container/container.h>
#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <hierarchy/veicolo.h>



class Model{

private:
    Container<Veicolo*>* dbVeicoli;
    Container<Veicolo*>* dbVenduti;
    Container<Veicolo*>* searchRes;
    string path;
    bool isDataSaved;

public:
     Model(string="../dati.xml"); //file di salvataggio locale
    ~Model();
};

#endif // MODEL_H
