#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cerr;

class Exc{
private:
    int cod;
    string stringaerr;
public:
    Exc(int z=0, string t=""):cod(z),stringaerr(t){
        switch (z){
        case 0:{
            cerr<<"E' stato rilevato un errore all'interno del programma! Il testo dell'errore è il seguente:";
            break;
        }
        case 1: {                                                                                                       //identifica errori dei parametri nei costruttori.
            cerr<<"Errore nel costruttore! Rilevato parametro ->"<<t<<"<- non valido. Nessuna operazione eseguita.";
            break;
        }
        case 2:{                                                                                                        //identifica errori nelle eliminazioni.
            cerr<<"Errore nella eliminazione del ->"<<t<<"<- selezionato. Nessuna operazione eseguita.";
            break;
        }
        case 3:{                                                                                                         //identifica errori nelle targhe.
            cerr<<"Errore! Rilevata targa ->"<<t<<"<- mal formata. La targa è una stringa avente solo questo formato: AA000AA. Nessuna operazione eseguita.";
            break;
        }
        case 4:{                                                                                                        //identifica errori nel segmento.
            cerr<<"Errore! Rilevato segmento ->"<<t<<"<- non valido. Nessuna operazione eseguita.";
            break;
        }
        case 5:{                                                                                                        //identifica errori nell'alimentazione.
            cerr<<"Errore! Rilevata alimentazione ->"<<t<<"<- non valida. Nessuna operazione eseguita.";
            break;
        }
        case 6:{                                                                                                        //identifica errori nell'inserimento dei veicoli nel Qontainer.
            cerr<<"Errore! Rilevato veicolo ->"<<t<<"<-. Nessuna operazione eseguita.";
            break;
        }
        case 7:{                                                                                                        //identifica il qontainer vuoto!
            cerr<<"Errore! Rilevato container vuoto! Nessuna operazione eseguita.";
            break;
        }
        case 8:{                                                                                                        //identifica un errore nella struttura del file.
            cerr<<"Errore nella ->"<<t<<"<- del file. Nessuna operazione eseguita.";
            break;
        }
        case 9:{                                                                                                        //identifica un file in caricamento vuoto.
            cerr<<"Errore! Rilevato file vuoto! Nessuna operazione eseguita.";
            break;
        }
        case 10:{
            cerr<<"Errore nel parametro ->"<<t<<"<- out of range";
            break;
        }
        case 11:{
            cerr<<"Errore di acquisizione del lock del file in "<<t<<".";
            break;
        }
        case 12:{
            cerr<<"Errore di inserimento del veicolo "<<t<<".";
            break;
        }

        case 13:{
            cerr<<"Errore:"<<t<<".";
            break;
        }
        default: cerr<<"Errore generale!"; break;
        }
    }
};

#endif // EXCEPTIONS_H
