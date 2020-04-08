#ifndef INSERTVEICOLO_H
#define INSERTVEICOLO_H

#include "alimtipebox.h"
#include "segmentotipebox.h"
#include "tipomotobox.h"

#include <QComboBox>
#include <QFormLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <QLabel>
#include <QObject>



class InsertVeicolo : public QWidget
{

    Q_OBJECT

 private:
    QLineEdit* marca;
    QLineEdit* modello;
    QLineEdit* numeroTelaio;
    QCheckBox* cambio;
    QLineEdit* colore;
    QLineEdit* lunghezza;

    QLineEdit* numeroMotore;
    QLineEdit* cilindrata;
    QLineEdit* cavalli;
    AlimTipeBox* alimentazione;

    QLineEdit* targa;
    QLineEdit* prezzo;
    QLineEdit* massa;
    QLineEdit* numeroPosti;


    //AUTO

    SegmentoTipeBox* segmento;
    QCheckBox* autocarro;

    //CAMION

    QLineEdit* numeroAssi;
    QCheckBox* ribaltabile;


    //MOTO

    QCheckBox* sidecar;
    QLineEdit* classeEmissioni;
     TipomotoBox* tipoMoto;


public:
     InsertVeicolo(QWidget* = nullptr);








};

#endif // INSERTVEICOLO_H
