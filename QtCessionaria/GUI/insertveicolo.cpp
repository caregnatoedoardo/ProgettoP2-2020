#include "insertveicolo.h"


#include <QPushButton>
#include <qlabel.h>
#include <QString>
#include <QAction>
#include <iostream>
#include <qmessagebox.h>
#include <QFileDialog>
#include <QBuffer>


InsertVeicolo::InsertVeicolo(QWidget*p):
    QWidget(p),
    tipoVeicolo(new VeicoloTipeBox(this)),
    marca(new QLineEdit(this)),
    modello(new QLineEdit(this)),
    numeroTelaio(new QLineEdit(this)),
    cambio(new QCheckBox("Cambio",this)),
    colore(new QLineEdit(this)),
    lunghezza(new QLineEdit(this)),
    numeroMotore(new QLineEdit(this)),
    cilindrata(new QLineEdit(this)),
    cavalli(new QLineEdit(this)),
    alimentazione(new AlimTipeBox(this)),
    targa(new QLineEdit(this)),
    prezzo(new QLineEdit(this)),
    massa(new QLineEdit(this)),
    numeroPosti(new QLineEdit(this)),

    segmento(new SegmentoTipeBox(this)),
    autocarro(new QCheckBox("Autocarro",this)),
    numeroAssi(new QLineEdit(this)),
    ribaltabile(new QCheckBox("Ribaltabile",this)),

     sidecar(new QCheckBox("Sidecar",this)),
        classeEmissioni(new QLineEdit(this)),
         tipoMoto(new TipomotoBox(this))

{
    QGridLayout* form = new QGridLayout(this);

    form->addWidget(tipoVeicolo,0,0);

    marca->setPlaceholderText("MARCA");
    form->addWidget(marca,1,0);

    modello->setPlaceholderText("Modello");
    form->addWidget(modello,2,0);

    numeroTelaio->setPlaceholderText("Numero Telaio");
    form->addWidget(numeroTelaio,3,0);

    form->addWidget(cambio,4,0);

    colore->setPlaceholderText("Colore");
    form->addWidget(colore,1,1);

    lunghezza->setPlaceholderText("Lunghezza");
    form->addWidget(lunghezza,2,1);

    numeroMotore->setPlaceholderText("Numero Motore");
    form->addWidget(numeroMotore,3,1);

    cilindrata->setPlaceholderText("Cilindrata");
    form->addWidget(cilindrata,4,1);

    cavalli->setPlaceholderText("Cavalli");
    form->addWidget(cavalli,5,1);

    form->addWidget(alimentazione,6,1);

    targa->setPlaceholderText("Targa");
    form->addWidget(targa,1,2);

    prezzo->setPlaceholderText("Prezzo");
    form->addWidget(prezzo,2,2);

    massa->setPlaceholderText("Massa");
    form->addWidget(massa,3,2);

    numeroPosti->setPlaceholderText("Numero Posti");
    form->addWidget(numeroPosti,4,2);

    form->addWidget(segmento,5,2);
    form->addWidget(autocarro,6,2);

    numeroAssi->setPlaceholderText("Numero Assi");
    form->addWidget(numeroAssi,1,3);

    form->addWidget(ribaltabile,2,3);

    form->addWidget(sidecar,3,3);
    classeEmissioni->setPlaceholderText("Classe Emissioni");
    form->addWidget(classeEmissioni,4,3);

    form->addWidget(tipoMoto,5,3);

    form->addWidget(AddButton,6,3);



}
