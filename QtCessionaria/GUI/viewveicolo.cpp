
#include "viewveicolo.h"
#include "insertveicolo.h"

#include <QLabel>
#include <QFormLayout>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#include <QBuffer>
#include <hierarchy/veicolo.h>
#include <hierarchy/carrozzeria.h>
#include <hierarchy/motore.h>
#include <hierarchy/mezzo.h>
#include <hierarchy/moto.h>
#include <hierarchy/auto.h>
#include <hierarchy/camion.h>




ViewVeicolo::ViewVeicolo(PrintListView* a, QWidget* parent):
    listVeicoli(a),
    btnClose(new QPushButton("Chiudi Senza Salvare",parent)),
    salvaMod(new QPushButton("Salva Modifiche",parent)),
    veicolo(a->getItemAddress()),
    descrizione(new QTextEdit(parent))
{

    QVBoxLayout* mainLayout = new QVBoxLayout();

    descrizione->setText((QString::fromStdString(veicolo->getDetails())));
    mainLayout->addWidget(new QLabel("Descrizione: "));
    mainLayout->addWidget(descrizione);

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(salvaMod);
    btnLayout->addWidget(btnClose);

    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
    setModal(true);
    setFont(QFont("Times",14,3));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(salvaMod,SIGNAL(clicked()),this,SLOT(slotSalvaModifica()));
    connect(salvaMod,SIGNAL(clicked()),this,SLOT(close()));


}




void ViewVeicolo::slotSalvaModifica()const{



}
