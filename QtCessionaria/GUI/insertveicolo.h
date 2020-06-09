#ifndef INSERTVEICOLO_H
#define INSERTVEICOLO_H

#include "alimtypebox.h"
#include "segmentotypebox.h"
#include "tipomotobox.h"
#include "veicolotypebox.h"

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
    VeicoloTypeBox* tipoVeicolo;
    QLabel* scegliFoto;
    QLineEdit* marca;
    QLineEdit* modello;

    QLineEdit* numeroTelaio;
    QCheckBox* cambio;
    QLineEdit* colore;
    QLineEdit* lunghezza;

    QLineEdit* numeroMotore;
    QLineEdit* cilindrata;
    QLineEdit* cavalli;
    AlimTypeBox* alimentazione;

    QLineEdit* targa;
    QLineEdit* prezzo;
    QLineEdit* massa;
    QLineEdit* numeroPosti;


    //AUTO

    SegmentoTypeBox* segmento;
    QCheckBox* autocarro;

    //CAMION

    QLineEdit* numeroAssi;
    QCheckBox* ribaltabile;


    //MOTO

    QCheckBox* sidecar;
    QLineEdit* classeEmissioni;
     TipomotoBox* tipoMoto;

     QPushButton* bottoneScegliFoto;
     QPushButton* AddButton;


public:
     InsertVeicolo(QWidget* = nullptr);

     VeicoloTypeBox* getTipoVeicolo() const;
     QLineEdit* getMarca() const;
     QLineEdit* getModello() const;
     QLineEdit* getNumeroTelaio() const;
     QCheckBox* getCambio() const;
     QLineEdit* getColore() const;
     QLineEdit* getLunghezza() const;
     QLineEdit* getNumeroMotore() const;
     QLineEdit* getCilindrata() const;
     QLineEdit* getCavalli() const;
     AlimTypeBox* getAlimentazione() const;
     QLineEdit* getTarga() const;
     QLineEdit* getPrezzo() const;
     QLineEdit* getMassa() const;
     QLineEdit* getNumeroPosti() const;
     SegmentoTypeBox* getSegmento() const;
     QCheckBox* getAutocarro() const;
     QLineEdit* getNumeroAssi() const;
     QCheckBox* getRibaltabile() const;
     QCheckBox* getSidecar() const;
     QLineEdit* getClasseEmissioni() const;
     TipomotoBox* getTipoMoto() const;

     QPushButton* getScegliFoto() const;

     QPushButton* getAddButton() const;



public slots:
     void slotDisableForm(int) const; // disabilita form sulla base del case dell'inseriemnto
     void slotChangeFormLayout(QString typeVeic)const;
     void slotScegliFoto();

signals:
    void signalDisableForm(int);





};

#endif // INSERTVEICOLO_H
