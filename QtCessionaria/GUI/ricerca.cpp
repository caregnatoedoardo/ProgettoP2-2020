#include "ricerca.h"
#include <qlabel.h>
#include "hierarchy/auto.h"
#include "hierarchy/camion.h"
#include "hierarchy/moto.h"

Ricerca::Ricerca(QWidget *p):
    QWidget(p),

    ckTipo(new QCheckBox("Tipo",this)),
    boxTipoVeicolo(new VeicoloTypeBox(this)),

    ckMarca(new QCheckBox("Marca",this)),
    cercaMarca(new QLineEdit(this)),
    ckModello(new QCheckBox("Modello",this)),
    cercaModello(new QLineEdit(this)),
    ckNumeroTelaio(new QCheckBox("Numero Telaio",this)),
    cercaNumeroTelaio(new QLineEdit(this)),
    ckCambio(new QCheckBox("Cambio Automatico",this)),
    ckColore(new QCheckBox("Colore",this)),
    cercaColore(new QLineEdit(this)),
    ckLunghezza(new QCheckBox("Lunghezza",this)),
    cercaLunghezza(new QLineEdit(this)),
    ckNumeroMotore(new QCheckBox("Numero Motore",this)),
    cercaNumeroMotore(new QLineEdit(this)),
    ckCilindrata(new QCheckBox("Cilindrata",this)),
    cercaCilindrata(new QLineEdit(this)),
    ckCavalli(new QCheckBox("Cavalli",this)),
    cercaCavalli(new QLineEdit(this)),
    ckAlimentazione(new QCheckBox("Alimentazione",this)),
    boxAlimentazione(new AlimTypeBox(this)),
    ckTarga(new QCheckBox("Targa",this)),
    cercaTarga(new QLineEdit(this)),
    ckPrezzo(new QCheckBox("Prezzo",this)),
    cercaPrezzo(new QLineEdit(this)),
    ckMassa(new QCheckBox("Massa",this)),
    cercaMassa(new QLineEdit(this)),
    ckNumeroPosti(new QCheckBox("Numero Posti",this)),
    cercaNumeroPosti(new QLineEdit(this)),
    ckSegmento(new QCheckBox("Segmento",this)),
    boxSegmento(new SegmentoTypeBox(this)),
    ckAutocarro(new QCheckBox("Autocarro",this)),
    ckNumeroAssi(new QCheckBox("Numero Assi",this)),
    cercaNumeroAssi(new QLineEdit(this)),
    ckRibaltabile(new QCheckBox("Ribaltabile",this)),
    ckSidecar(new QCheckBox("Sidecar",this)),
    ckClasseEmissioni(new QCheckBox("Classe Emissioni",this)),
    cercaClasseEmissioni(new QLineEdit(this)),
    ckTipoMoto(new QCheckBox("Tipo Moto",this)),
    boxTipoMoto(new TipomotoBox(this)),

    //BOTTONI
    cerca(new QPushButton("CERCA",this)),
    elimina(new QPushButton("ELIMINA TUTTI I RISULTATI",this)),
    reset(new QPushButton("RESET RICERCA",this))

{

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* form = new QFormLayout();


    form->addRow(ckTipo,boxTipoVeicolo);
    form->addRow(ckMarca,cercaMarca);
    form->addRow(ckModello,cercaModello);
    form->addRow(ckNumeroTelaio,cercaNumeroTelaio);
    form->addRow(ckCambio);
    form->addRow(ckColore,cercaColore);
    form->addRow(ckLunghezza,cercaLunghezza);
    form->addRow(ckNumeroMotore,cercaNumeroMotore);
    form->addRow(ckCilindrata,cercaCilindrata);
    form->addRow(ckCavalli,cercaCavalli);
    form->addRow(ckAlimentazione,boxAlimentazione);
    form->addRow(ckTarga,cercaTarga);
    form->addRow(ckPrezzo,cercaPrezzo);
    form->addRow(ckMassa,cercaMassa);
    form->addRow(ckNumeroPosti,cercaNumeroPosti);
    form->addRow(ckSegmento,boxSegmento);
    form->addRow(ckAutocarro);
    form->addRow(ckNumeroAssi,cercaNumeroAssi);
    form->addRow(ckRibaltabile);
    form->addRow(ckSidecar);
    form->addRow(ckClasseEmissioni,cercaClasseEmissioni);
    form->addRow(ckTipoMoto,boxTipoMoto);

    form->addRow(cerca,reset);

    mainLayout->addLayout(form);
    //list
    mainLayout->addWidget(elimina);


}


void Ricerca::slotDisableElements() const
{

 ckTipo->isChecked()?
             boxTipoVeicolo->setEnabled(true):
             boxTipoVeicolo->setEnabled(false);

 ckMarca->isChecked()?
             cercaMarca->setEnabled(true):
             cercaMarca->setEnabled(false);

 ckModello->isChecked()?
             cercaModello->setEnabled(true):
             cercaModello->setEnabled(false);

 ckNumeroTelaio->isChecked()?
             cercaNumeroTelaio->setEnabled(true):
             cercaNumeroTelaio->setEnabled(false);

 ckColore->isChecked()?
             cercaColore->setEnabled(true):
             cercaColore->setEnabled(false);

 ckLunghezza->isChecked()?
             cercaLunghezza->setEnabled(true):
             cercaLunghezza->setEnabled(false);

 ckNumeroMotore->isChecked()?
             cercaNumeroMotore->setEnabled(true):
             cercaNumeroMotore->setEnabled(false);

 ckCilindrata->isChecked()?
             cercaCilindrata->setEnabled(true):
             cercaCilindrata->setEnabled(false);

 ckCavalli->isChecked()?
             cercaCavalli->setEnabled(true):
             cercaCavalli->setEnabled(false);

 ckAlimentazione->isChecked()?
             boxAlimentazione->setEnabled(true):
             boxAlimentazione->setEnabled(false);

 ckTarga->isChecked()?
             cercaTarga->setEnabled(true):
             cercaTarga->setEnabled(false);

 ckPrezzo->isChecked()?
             cercaPrezzo->setEnabled(true):
             cercaPrezzo->setEnabled(false);

 ckMassa->isChecked()?
             cercaMassa->setEnabled(true):
             cercaMassa->setEnabled(false);

 ckNumeroPosti->isChecked()?
             cercaNumeroPosti->setEnabled(true):
             cercaNumeroPosti->setEnabled(false);

 ckSegmento->isChecked()?
             boxSegmento->setEnabled(true):
             boxSegmento->setEnabled(false);

 ckNumeroAssi->isChecked()?
             cercaNumeroAssi->setEnabled(true):
             cercaNumeroAssi->setEnabled(false);

 ckClasseEmissioni->isChecked()?
             cercaClasseEmissioni->setEnabled(true):
             cercaClasseEmissioni->setEnabled(false);

 ckTipoMoto->isChecked()?
             boxTipoMoto->setEnabled(true):
             boxTipoMoto->setEnabled(false);
}

//GET ricerca:

QLineEdit* Ricerca::getCercaMarca() const{return cercaMarca;}
QLineEdit* Ricerca::getCercaModello() const{return cercaModello;}
QLineEdit* Ricerca::getCercaNumeroTelaio() const{return cercaNumeroTelaio;}
QLineEdit* Ricerca::getCercaColore() const{return cercaColore;}
QLineEdit* Ricerca::getCercaLunghezza() const{return cercaLunghezza;}
QLineEdit* Ricerca::getCercaNumeroMotore() const{return cercaNumeroMotore;}
QLineEdit* Ricerca::getCercaCilindrata() const{return cercaCilindrata;}
QLineEdit* Ricerca::getCercaCavalli() const{return cercaCavalli;}
QLineEdit* Ricerca::getCercaTarga() const{return cercaTarga;}
QLineEdit* Ricerca::getCercaPrezzo() const{return cercaPrezzo;}
QLineEdit* Ricerca::getCercaMassa() const{return cercaMassa;}
QLineEdit* Ricerca::getCercaNumeroPosti() const{return cercaNumeroPosti;}
QLineEdit* Ricerca::getCercaNumeroAssi() const{return cercaNumeroAssi;}
QLineEdit* Ricerca::getCercaClasseEmissioni() const{return cercaClasseEmissioni;}
QCheckBox* Ricerca::getCkTipo() const{return ckTipo;}
QCheckBox* Ricerca::getCkMarca() const{return ckMarca;}
QCheckBox* Ricerca::getCkModello() const{return ckModello;}
QCheckBox* Ricerca::getCkNumeroTelaio() const{return ckNumeroTelaio;}
QCheckBox* Ricerca::getCkCambio() const{return ckCambio;}
QCheckBox* Ricerca::getCkColore() const{return ckColore;}
QCheckBox* Ricerca::getCkLunghezza() const{return ckLunghezza;}
QCheckBox* Ricerca::getCkNumeroMotore() const{return ckNumeroMotore;}
QCheckBox* Ricerca::getCkCilindrata() const{return ckCilindrata;}
QCheckBox* Ricerca::getCkCavalli() const{return ckCavalli;}
QCheckBox* Ricerca::getCkAlimentazione() const{return ckAlimentazione;}
QCheckBox* Ricerca::getCkTarga() const{return ckTarga;}
QCheckBox* Ricerca::getCkPrezzo() const{return ckPrezzo;}
QCheckBox* Ricerca::getCkMassa() const{return ckMassa;}
QCheckBox* Ricerca::getCkNumeroPosti() const{return ckNumeroPosti;}
QCheckBox* Ricerca::getCkSegmento() const{return ckSegmento;}
QCheckBox* Ricerca::getCkAutocarro() const{return ckAutocarro;}
QCheckBox* Ricerca::getCkNumeroAssi() const{return ckNumeroAssi;}
QCheckBox* Ricerca::getCkRibaltabile() const{return ckRibaltabile;}
QCheckBox* Ricerca::getCkSidecar() const{return ckSidecar;}
QCheckBox* Ricerca::getCkClasseEmissioni() const{return ckClasseEmissioni;}
QCheckBox* Ricerca::getCkTipoMoto() const{return ckTipoMoto;}
VeicoloTypeBox* Ricerca::getBoxTipoVeicolo() const{return boxTipoVeicolo;}
AlimTypeBox* Ricerca::getBoxAlimentazione() const{return boxAlimentazione;}
SegmentoTypeBox* Ricerca::getBoxSegmento() const{return boxSegmento;}
TipomotoBox* Ricerca::getBoxTipoMoto() const{return boxTipoMoto;}
ListViewWidget* Ricerca::getListaVeic() const{return listaveic;}

QPushButton* Ricerca::getButtonRicerca() const{
    return  cerca;

}
QPushButton* Ricerca::getButtonElimina() const{
    return elimina;

}
QPushButton* Ricerca::getButtonReset() const{
    return reset;

}





