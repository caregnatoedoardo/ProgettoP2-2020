#ifndef MODEL_H
#define MODEL_H

#include <QFileDialog>
#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QBuffer>
#include "container/container.h"
#include "hierarchy/auto.h"
#include "hierarchy/moto.h"
#include "hierarchy/camion.h"




class Model{

private:
    Container<Veicolo*>* dbVeicoli=nullptr;//Container che rappresenta tutti i veicoli disponibili (tranne quelli già venduti)
    Container<Veicolo*>* dbVenduti=nullptr;//Container che rappresenta i veicoli venduti
    Container<Veicolo*>* searchRes=nullptr;//Container temporaneo che servirà a contenere i risultati di ricerca dell'utente
    string path;                   //Percorso dei file di salvataggio/caricamento
    bool flagsaved;
public:
    Model(string="../QtCessionaria/dati.xml");
    //Model(string ="/Users/edoardocaregnato/Documents/C++ Projects/ProgettoP2-2020/dati.xml");

    ~Model();


    Container<Veicolo*>::Iteratore begin()const;
    Container<Veicolo*>::Iteratore end()const;
    void save(string path="");
    void load(string path="");
    void erase ();
    void erase (Veicolo*);
    unsigned int getContainerSize()const;
    unsigned int getContainerVendutiSize() const;
    bool push_begin(Container<Veicolo*>*&, Veicolo*);
    bool push(Veicolo*);
    bool push_end(Container<Veicolo*>*&, Veicolo*);
    bool remove(Veicolo*);
    bool removeVenduti(Veicolo*);
    void clearRicerca();
    bool search(Container<Veicolo*>*&, Veicolo*)const;
    bool vendi(Veicolo*);
    bool nonVenduta(Veicolo*);
    static std::string getRawData(const QImage&);
    bool isEmptyVenduti()const;
    bool isEmptyDisponibili()const;

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
    Veicolo* getElementoByPosition(unsigned int i)const;
    Veicolo* getElementoVendutoByPosition(unsigned int i)const;
    static QPixmap getImage(const std::string&);


    bool checkDuplicatePlate(Container<Veicolo*>*&ct, const Veicolo*)const;
    bool checkPlate(const Veicolo*) const;
    bool checkDuplicateEngine(Container<Veicolo*>*&ct, const Veicolo*)const;
    bool checkDuplicateChassis(Container<Veicolo*>*&ct, const Veicolo*)const;
    bool isDuplicate(Container<Veicolo*>*&ct, const Veicolo*)const;
    string getTipoVeicolo(const Veicolo*)const;


    bool defaultSearchRes();



};

#endif // MODEL_H
