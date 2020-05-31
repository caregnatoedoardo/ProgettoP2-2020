#ifndef MODEL_H
#define MODEL_H

#include "container/container.h"
#include <QCoreApplication>
#include <QDir>
#include <QString>
#include "hierarchy/auto.h"
#include "hierarchy/moto.h"
#include "hierarchy/camion.h"




class Model{

private:
    Container<Veicolo*>* dbVeicoli;//Container che rappresenta tutti i veicoli disponibili (tranne quelli già venduti)
    Container<Veicolo*>* dbVenduti;//Container che rappresenta i veicoli venduti
    Container<Veicolo*>* searchRes;//Container temporaneo che servirà a contenere i risultati di ricerca dell'utente
    string path;                   //Percorso dei file di salvataggio/caricamento
    bool flagsaved;
public:
    Model(string="../dati.xml"); //file di salvataggio locale
    ~Model();
    Container<Veicolo*>::Iteratore begin()const;
    Container<Veicolo*>::Iteratore end()const;

    void save();
    void load();

    void erase (unsigned int);
    void erase (Veicolo*);

    unsigned int getContainerSize()const;

    void push_end(Veicolo*);

    //implementazione di tutti i filtri di ricerca
    void filterByType(string ="auto");
    void filterByMarca(string="");
    void filterByModello(string="");
    void filterByNTelaio(unsigned int=0);
    void filterByCambio(bool=false);
    void filterByColore(string="");
    void filterByLunghezza(double=0);
    void filterByNMotore(unsigned int =0);
    void filterByCilindrata(unsigned int =0);
    void filterByCavalli(unsigned int =0);
    void filterByAlim(string ="");
    void filterByTarga(string="");
    void filterByPrezzo(double=0);
    void filterByMassa(unsigned int=0);
    void filterByNPosti(unsigned int=0);
    void filterBySegmento(string="suv");
    void filterByAutocarro(bool=false);
    void filterByNAssi(unsigned int =0);
    void filterByRibaltabile(bool=false);
    void filterBySidecar(bool=false);
    void filterByClasseEmissioni(unsigned int);
    void filterByTypeMoto(string="corsa");
    tipomoto convertToTipomoto(const string st)const;
    segmento convertToSeg(const string)const;
    alimentazione convertToAlimentazione(const string)const;
    bool getFlagDataSaved()const;
};

#endif // MODEL_H
