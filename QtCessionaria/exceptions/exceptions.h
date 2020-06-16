#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <iostream>
#include <QMessageBox>
using std::string;
using std::cout;
using std::cerr;

class Exc{
private:
    int cod;
    string stringaerr;
public:
    Exc(int z=0, string t=""):cod(z),stringaerr(t){
        QMessageBox info;

        switch (z){
        case 0:{
            info.information(0,"avviso", "E' stato rilevato un errore all'interno del programma! Il testo dell'errore è il seguente:");
            cerr<<"E' stato rilevato un errore all'interno del programma! Il testo dell'errore è il seguente: ";
            break;
        }
        case 1: {                                                                                                       //identifica errori dei parametri nei costruttori.
            info.information(0,"avviso", QString::fromStdString("Rilevato parametro "+t+" non valido. Nessuna operazione eseguita."));
            cerr<<"Errore nel costruttore! Rilevato parametro "<<t<<" non valido. Nessuna operazione eseguita.";
            break;
        }
        case 2:{                                                                                                        //identifica errori nelle eliminazioni.
            info.information(0,"avviso", QString::fromStdString("Errore nella eliminazione del "+t+" selezionato. Nessuna operazione eseguita."));
            cerr<<"Errore nella eliminazione del "<<t<<" selezionato. Nessuna operazione eseguita.";
            break;
        }
        case 3:{                                                                                                         //identifica errori nelle targhe.
            info.information(0,"avviso", QString::fromStdString("Errore! Rilevata targa "+t+" mal formata. La targa è una stringa avente solo questo formato: AA000AA per i veicoli, o AA00000 per i motoveicoli. Nessuna operazione eseguita."));
            cerr<<"Errore! Rilevata targa "<<t<<" mal formata. La targa è una stringa avente solo questo formato: AA000AA per i veicoli, o AA00000 per i motoveicoli. Nessuna operazione eseguita.";
            break;
        }
        case 4:{                                                                                                        //identifica errori nel segmento.
            info.information(0,"avviso", QString::fromStdString("Errore! Rilevato segmento "+t+" non valido. Nessuna operazione eseguita."));
            cerr<<"Errore! Rilevato segmento "<<t<<" non valido. Nessuna operazione eseguita.";
            break;
        }
        case 5:{                                                                                                        //identifica errori nell'alimentazione.
            info.information(0,"avviso", QString::fromStdString("Errore! Rilevata alimentazione "+t+" non valida. Nessuna operazione eseguita."));
            cerr<<"Errore! Rilevata alimentazione "<<t<<" non valida. Nessuna operazione eseguita.";
            break;
        }
        case 6:{                                                                                                        //identifica errori nell'inserimento dei veicoli nel Qontainer.
            info.information(0,"avviso", QString::fromStdString("Errore! Rilevato veicolo "+t+". Nessuna operazione eseguita."));
            cerr<<"Errore! Rilevato veicolo "<<t<<". Nessuna operazione eseguita.";
            break;
        }
        case 7:{                                                                                                        //identifica il qontainer vuoto!
            info.information(0,"avviso", "Errore! Rilevato container vuoto! Nessuna operazione eseguita.");
            cerr<<"Errore! Rilevato container vuoto! Nessuna operazione eseguita.";
            break;
        }
        case 8:{                                                                                                        //identifica un errore nella struttura del file.
            info.information(0,"avviso", QString::fromStdString("Errore nella "+t+" del file. Nessuna operazione eseguita."));
            cerr<<"Errore nella "<<t<<" del file. Nessuna operazione eseguita.";
            break;
        }
        case 9:{                                                                                                        //identifica un file in caricamento vuoto.
            info.information(0,"avviso", "Errore! Rilevato file vuoto! Nessuna operazione eseguita.");
            cerr<<"Errore! Rilevato file vuoto! Nessuna operazione eseguita.";
            break;
        }
        case 10:{
            info.information(0,"avviso", QString::fromStdString("Errore nel parametro "+t+" out of range."));
            cerr<<"Errore nel parametro "<<t<<" out of range.";
            break;
        }
        case 11:{
            info.information(0,"avviso", QString::fromStdString("Errore di acquisizione del lock del file in "+t+"."));
            cerr<<"Errore di acquisizione del lock del file in "<<t<<".";
            break;
        }
        case 12:{
            info.information(0,"avviso", QString::fromStdString("Errore di inserimento del veicolo "+t+"."));
            cerr<<"Errore di inserimento del veicolo "<<t<<".";
            break;
        }
        case 13:{
            info.information(0,"avviso", QString::fromStdString("Errore! Rilevata targa duplicata. Nessuna operazione eseguita."+t+"."));
            cerr<<"Errore! Rilevata targa duplicata. Nessuna operazione eseguita."<<t<<".";
            break;
        }
        case 14:{
            info.information(0,"avviso", QString::fromStdString("Errore:"+t+"."));
            cerr<<"Errore:"<<t<<".";
            break;
        }
        default: cerr<<"Errore generale!"; break;
        }
    }
};

#endif // EXCEPTIONS_H
