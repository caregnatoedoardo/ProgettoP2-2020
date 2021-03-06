#ifndef INSERTVEICOLO_H
#define INSERTVEICOLO_H

#include <QComboBox>
#include <QString>
#include <QFormLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <QLabel>
#include <QObject>
#include "alimtypebox.h"
#include "segmentotypebox.h"
#include "tipomotobox.h"
#include "veicolotypebox.h"

class InsertVeicolo : public QWidget
{
    Q_OBJECT
 private:
    VeicoloTypeBox* tipoVeicolo;
    QLabel* scegliFoto;
    QLabel* descTipoVeicolo;
    QLabel* descMarca;
    QLabel* descModello;
    QLabel* descNumeroTelaio;
    QLabel* descCambio;
    QLabel* descColore;
    QLabel* descLunghezza;
    QLabel* descNumeroMotore;
    QLabel* descCilindrata;
    QLabel* descCavalli;
    QLabel* descAlimentazione;
    QLabel* descTarga;
    QLabel* descPrezzo;
    QLabel* descMassa;
    QLabel* descNumeroPosti;
    QLabel* descSegmento;
    QLabel* descAutocarro;
    QLabel* descNumeroAssi;
    QLabel* descRibaltabile;
    QLabel* descSidecar;
    QLabel* descClasseEmissioni;
    QLabel* descTipoMoto;

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
    QPushButton* saveEditButton;


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
     QLabel* getScegliFoto() const;
     QPushButton* getAddButton() const;
     QPushButton* getSaveEditButton() const;

     void hideButton(bool);

     void setTipoVeicolo(unsigned int) ;
     void setMarca(string) ;
     void setModello(string) ;
     void setNumeroTelaio(unsigned int) ;
     void setCambio(bool) ;
     void setColore(string) ;
     void setLunghezza(double) ;
     void setNumeroMotore(unsigned int) ;
     void setCilindrata(unsigned int) ;
     void setCavalli(unsigned int) ;
     void setAlimentazione(int) ;
     void setTarga(string) ;
     void setPrezzo(double) ;
     void setMassa(unsigned int) ;
     void setNumeroPosti(unsigned int) ;
     void setSegmento(unsigned int) ;
     void setAutocarro(bool) ;
     void setNumeroAssi(unsigned int) ;
     void setRibaltabile(bool) ;
     void setSidecar(bool) ;
     void setClasseEmissioni(unsigned int) ;
     void setTipoMoto(unsigned int) ;
     void setFoto(QString);

public slots:
     void slotDisableForm(int) const; // disabilita form sulla base del case dell'inseriemnto
     void slotChangeFormLayout(QString typeVeic)const;
     void slotScegliFoto();
     void slotResetForm()const;

signals:
    void signalDisableForm(int);
};

#endif // INSERTVEICOLO_H
