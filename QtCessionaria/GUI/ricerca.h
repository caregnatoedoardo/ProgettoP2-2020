#ifndef RICERCA_H
#define RICERCA_H

#include "veicolotypebox.h"
#include "alimtypebox.h"
#include "tipomotobox.h"
#include "segmentotypebox.h"
#include "listviewwidget.h"
#include <QObject>
#include <QWidget>
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
    VeicoloTypeBox* boxTipoVeicolo;

    QCheckBox* ckMarca;
    QLineEdit* cercaMarca;

    QCheckBox* ckModello;
    QLineEdit* cercaModello;

    QCheckBox* ckNumeroTelaio;
    QLineEdit* cercaNumeroTelaio;

    QCheckBox* ckCambio;

    QCheckBox* ckColore;
    QLineEdit* cercaColore;

    QCheckBox* ckLunghezza;
    QLineEdit* cercaLunghezza;

    QCheckBox* ckNumeroMotore;
    QLineEdit* cercaNumeroMotore;

    QCheckBox* ckCilindrata;
    QLineEdit* cercaCilindrata;

    QCheckBox* ckCavalli;
    QLineEdit* cercaCavalli;

    QCheckBox* ckAlimentazione;
    AlimTypeBox* boxAlimentazione;

    QCheckBox* ckTarga;
    QLineEdit* cercaTarga;

    QCheckBox* ckPrezzo;
    QLineEdit* cercaPrezzo;

    QCheckBox* ckMassa;
    QLineEdit* cercaMassa;

    QCheckBox* ckNumeroPosti;
    QLineEdit* cercaNumeroPosti;

    QCheckBox* ckSegmento;
    SegmentoTypeBox* boxSegmento;

    QCheckBox* ckAutocarro;

    QCheckBox* ckNumeroAssi;
    QLineEdit* cercaNumeroAssi;

    QCheckBox* ckRibaltabile;

    QCheckBox* ckSidecar;

    QCheckBox* ckClasseEmissioni;
    QLineEdit* cercaClasseEmissioni;

    QCheckBox* ckTipoMoto;
    TipomotoBox* boxTipoMoto;

    QPushButton* cerca;
    QPushButton* elimina;
    QPushButton* reset;

    ListViewWidget* listaveic;

public:

    Ricerca(QWidget* = nullptr);

    QCheckBox* getCkTipo() const;
    VeicoloTypeBox* getBoxTipoVeicolo() const;
    QCheckBox* getCkMarca()const;
    QLineEdit* getCercaMarca()const;
    QCheckBox* getCkModello()const;
    QLineEdit* getCercaModello()const;
    QCheckBox* getCkNumeroTelaio()const;
    QLineEdit* getCercaNumeroTelaio()const;
    QCheckBox* getCkCambio()const;
    QCheckBox* getCkColore()const;
    QLineEdit* getCercaColore()const;
    QCheckBox* getCkLunghezza()const;
    QLineEdit* getCercaLunghezza()const;
    QCheckBox* getCkNumeroMotore()const;
    QLineEdit* getCercaNumeroMotore()const;
    QCheckBox* getCkCilindrata()const;
    QLineEdit* getCercaCilindrata()const;
    QCheckBox* getCkCavalli()const;
    QLineEdit* getCercaCavalli()const;
    QCheckBox* getCkAlimentazione()const;
    AlimTypeBox* getBoxAlimentazione()const;
    QCheckBox* getCkTarga()const;
    QLineEdit* getCercaTarga()const;
    QCheckBox* getCkPrezzo()const;
    QLineEdit* getCercaPrezzo()const;
    QCheckBox* getCkMassa()const;
    QLineEdit* getCercaMassa()const;
    QCheckBox* getCkNumeroPosti()const;
    QLineEdit* getCercaNumeroPosti()const;
    QCheckBox* getCkSegmento()const;
    SegmentoTypeBox* getBoxSegmento()const;
    QCheckBox* getCkAutocarro()const;
    QCheckBox* getCkNumeroAssi()const;
    QLineEdit* getCercaNumeroAssi()const;
    QCheckBox* getCkRibaltabile()const;
    QCheckBox* getCkSidecar()const;
    QCheckBox* getCkClasseEmissioni()const;
    QLineEdit* getCercaClasseEmissioni()const;
    QCheckBox* getCkTipoMoto()const;
    TipomotoBox* getBoxTipoMoto()const;

    QPushButton* getButtonRicerca() const;
    QPushButton* getButtonElimina() const;
    QPushButton* getButtonReset() const;

    ListViewWidget* getListaVeic()const;

private slots:

    void slotDisableElements() const;

public slots:

   // void slotReset() const;

signals:

   // void signalDelete(Model*);
};

#endif // RICERCA_H
