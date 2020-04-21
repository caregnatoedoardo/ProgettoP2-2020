#ifndef RICERCA_H
#define RICERCA_H

#include <QObject>
#include <QWidget>
#include "veicolotipebox.h"
#include "alimtipebox.h"
#include "tipomotobox.h"
#include "segmentotipebox.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include <QRadioButton>
#include <model.h>


class Ricerca : public QWidget
{
    Q_OBJECT

private:
    QCheckBox* ckTipo;
    VeicoloTipeBox* boxTipoVeicolo;

    QCheckBox* ckMarca;
    QLineEdit* cercaMarca;

    QCheckBox* ckModello;
    QLineEdit* cercaModello;

    QCheckBox* ckNumeroTelaio;
    QLineEdit* cercaNumeroTelaio;

    QCheckBox* ckCambio;

    QCheckBox* ckColore;
    QLineEdit* cercaColore;

    QCheckBox* ckLungehzza;
    QLineEdit* cercaLunghezza;

    QCheckBox* ckNumeroMotore;
    QLineEdit* cercaNumeroMotore;

    QCheckBox* ckCilindrata;
    QLineEdit* cercaCilindrata;

    QCheckBox* ckCavalli;
    QLineEdit* cercaCavalli;

    QCheckBox* ckAlimentazione;
    AlimTipeBox* boxAlimentazione;

    QCheckBox* ckTarga;
    QLineEdit* cercaTarga;

    QCheckBox* ckPrezzo;
    QLineEdit* cercaPrezzo;

    QCheckBox* ckMassa;
    QLineEdit* cercaMassa;

    QCheckBox* ckNumeroPosti;
    QLineEdit* cercaNumeroPosti;

    QCheckBox* ckSegmento;
    SegmentoTipeBox* boxSegmento;

    QCheckBox* ckAutocarro;

    QCheckBox* ckNumeroAssi;
    QLineEdit* cercaNumeroAssi;

    QCheckBox* ckRibaltabile;

    QCheckBox* ckSidecar;

    QCheckBox* ckClasseEmissioni;
    QLineEdit* cercaClasseEmissioni;

    QCheckBox* ckTipoMoto;
    TipomotoBox* boxTipoMoto;



public:

    Ricerca(QWidget* = nullptr);

    QCheckBox* getCkTipo() const;
    VeicoloTipeBox* getBoxTipoVeicolo() const;
    QCheckBox* getCkMarca()const;
    QLineEdit* getCercaMarca()const;
    QCheckBox* getCkModello()const;
    QLineEdit* getCercaModello()const;
    QCheckBox* getCkNumeroTelaio()const;
    QLineEdit* getCercaNumeroTelaio()const;
    QCheckBox* getCkCambio()const;
    QCheckBox* getCkColore()const;
    QLineEdit* getCercaColore()const;
    QCheckBox* getCkLungehzza()const;
    QLineEdit* getCercaLunghezza()const;
    QCheckBox* getCkNumeroMotore()const;
    QLineEdit* getCercaNumeroMotore()const;
    QCheckBox* getCkCilindrata()const;
    QLineEdit* getCercaCilindrata()const;
    QCheckBox* getCkCavalli()const;
    QLineEdit* getCercaCavalli()const;
    QCheckBox* getCkAlimentazione()const;
    AlimTipeBox* getBoxAlimentazione()const;
    QCheckBox* getCkTarga()const;
    QLineEdit* getCercaTarga()const;
    QCheckBox* getCkPrezzo()const;
    QLineEdit* getCercaPrezzo()const;
    QCheckBox* getCkMassa()const;
    QLineEdit* getCercaMassa()const;
    QCheckBox* getCkNumeroPosti()const;
    QLineEdit* getCercaNumeroPosti()const;
    QCheckBox* getCkSegmento()const;
    SegmentoTipeBox* getBoxSegmento()const;
    QCheckBox* getCkAutocarro()const;
    QCheckBox* getCkNumeroAssi()const;
    QLineEdit* getCercaNumeroAssi()const;
    QCheckBox* getCkRibaltabile()const;
    QCheckBox* getCkSidecar()const;
    QCheckBox* getCkClasseEmissioni()const;
    QLineEdit* getCercaClasseEmissioni()const;
    QCheckBox* getCkTipoMoto()const;
    TipomotoBox* getBoxTipoMoto()const;


private slots:

   // void slotDisableElements() const;

public slots:

   // void slotReset() const;

signals:

   // void signalDelete(Model*);
};

#endif // RICERCA_H
