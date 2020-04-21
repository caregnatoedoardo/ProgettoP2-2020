#ifndef INSERTVEICOLO_H
#define INSERTVEICOLO_H

#include "alimtipebox.h"
#include "segmentotipebox.h"
#include "tipomotobox.h"
#include "veicolotipebox.h"

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
    VeicoloTipeBox* tipoVeicolo;
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

     QPushButton* AddButton;


public:
     InsertVeicolo(QWidget* = nullptr);

     VeicoloTipeBox* getTipoVeicolo() const;
     QLineEdit* getMarca() const;
     QLineEdit* getModello() const;
     QLineEdit* getNumeroTelaio() const;
     QCheckBox* getCambio() const;
     QLineEdit* getColore() const;
     QLineEdit* getLunghezza() const;
     QLineEdit* getNumeroMotore() const;
     QLineEdit* getCilindrata() const;
     QLineEdit* getCavalli() const;
     AlimTipeBox* getAlimentazione() const;
     QLineEdit* getTarga() const;
     QLineEdit* getPrezzo() const;
     QLineEdit* getMassa() const;
     QLineEdit* getNumeroPosti() const;
     SegmentoTipeBox* getSegmento() const;
     QCheckBox* getAutocarro() const;
     QLineEdit* getNumeroAssi() const;
     QCheckBox* getRibaltabile() const;
     QCheckBox* getSidecar() const;
     QLineEdit* getClasseEmissioni() const;
     TipomotoBox* getTipoMoto() const;

     QPushButton* getAddButton() const;



public slots:
    // void slotDisableForm(int) const; // disabilita form sulla base del case dell'inseriemnto

signals:
   //  void signalDisableForm(int);





};

#endif // INSERTVEICOLO_H
