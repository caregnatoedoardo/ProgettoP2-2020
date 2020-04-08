#ifndef MODEL_H
#define MODEL_H

#include <container/container.h>
#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <hierarchy/veicolo.h>



class Model{

private:
    Container<Veicolo*>* dbVeicoli;//Container che rappresenta tutti i veicoli disponibili (tranne quelli già venduti)
    Container<Veicolo*>* dbVenduti;//Container che rappresenta i veicoli venduti
    Container<Veicolo*>* searchRes;//Container temporanto che servirà a contenere i risultati di ricerca dell'utente
    string path;                   //Percorso dei file di salvataggio/caricamento
    bool isDataSaved;


public:
    Model(string="../dati.xml"); //file di salvataggio locale
    ~Model();
    Container<Veicolo*>::Iteratore begin()const;
    Container<Veicolo*>::Iteratore end()const;

    //implementazione di tutti i filtri di ricerca
    void filterByMarca(string="")const;
    void filterByModello(string="")const;
    void filterByNTelaio(unsigned int=0)const;
    void filterByCambio(bool=false)const;
    void filterByColore(string="")const;
    void filterByLunghezza(double=0)const;

};

#endif // MODEL_H
