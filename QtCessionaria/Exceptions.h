#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <iostream>
using std::string;
using std::cout;

class Exc{
private:
    int cod;
    string stringaerr;
public:
    Exc(int z=0, string t=""):cod(z),stringaerr(t){
        switch (z){
        case 1: {                                                                                                       //identifica errori dei parametri nei costruttori.
            cout<<"Errore nel costruttore! Rilevato parametro ->"<<t<<"<- non valido. Nessuna operazione eseguita.";
            break;
        }
        case 2:{                                                                                                        //identifica errori nelle eliminazioni.
            cout<<"Errore nella eliminazione del ->"<<t<<"<- selezionato. Nessuna operazione eseguita.";
            break;
        }
        case 3:{                                                                                                         //identifica errori nelle targhe.
            cout<<"Errore! Rilevata targa ->"<<t<<"<- mal formata. La targa è una stringa avente solo questo formato: AA000AA. Nessuna operazione eseguita.";
            break;
        }
        case 4:{                                                                                                        //identifica errori nel segmento.
            cout<<"Errore! Rilevato segmento ->"<<t<<"<- non valido. Nessuna operazione eseguita.";
            break;
        }
        case 5:{                                                                                                        //identifica errori nell'alimentazione.
            cout<<"Errore! Rilevata alimentazione ->"<<t<<"<- non valida. Nessuna operazione eseguita.";
            break;
        }
        case 6:{                                                                                                        //identifica errori nell'inserimento dei veicoli nel Qontainer.
            cout<<"Errore! Rilevato veicolo ->"<<t<<"<-. Nessuna operazione eseguita.";
            break;
        }
        case 7:{                                                                                                        //identifica il qontainer vuoto!
            cout<<"Errore! Rilevato container vuoto! Nessuna operazione eseguita.";
            break;
        }
        case 8:{                                                                                                        //identifica un errore nella struttura del file.
            cout<<"Errore nella ->"<<t<<"<- del file. Nessuna operazione eseguita.";
            break;
        }
        case 9:{                                                                                                        //identifica un file in caricamento vuoto.
            cout<<"Errore! Rilevato file vuoto! Nessuna operazione eseguita.";
            break;
        }
        default: cout<<"Errore generale!"; break;
        }
    }
};

#endif // EXCEPTIONS_H
