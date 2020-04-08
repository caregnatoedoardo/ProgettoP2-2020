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

}
