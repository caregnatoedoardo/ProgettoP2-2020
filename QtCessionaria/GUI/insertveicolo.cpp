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
    tipoVeicolo(new VeicoloTypeBox(this)),
    scegliFoto(new QLabel(this)),
    marca(new QLineEdit(this)),
    modello(new QLineEdit(this)),
    numeroTelaio(new QLineEdit(this)),
    cambio(new QCheckBox("Cambio",this)),
    colore(new QLineEdit(this)),
    lunghezza(new QLineEdit(this)),
    numeroMotore(new QLineEdit(this)),
    cilindrata(new QLineEdit(this)),
    cavalli(new QLineEdit(this)),
    alimentazione(new AlimTypeBox(this)),
    targa(new QLineEdit(this)),
    prezzo(new QLineEdit(this)),
    massa(new QLineEdit(this)),
    numeroPosti(new QLineEdit(this)),

    segmento(new SegmentoTypeBox(this)),
    autocarro(new QCheckBox("Autocarro",this)),
    numeroAssi(new QLineEdit(this)),
    ribaltabile(new QCheckBox("Ribaltabile",this)),

     sidecar(new QCheckBox("Sidecar",this)),
        classeEmissioni(new QLineEdit(this)),
         tipoMoto(new TipomotoBox(this)),
         bottoneScegliFoto(new QPushButton(this)),
         AddButton(new QPushButton("Aggiungi",this) ),
         saveEditButton(new QPushButton("Salva Modifiche",this))

{
    QGridLayout* form = new QGridLayout(this);

    form->addWidget(tipoVeicolo,0,0);

    bottoneScegliFoto->setText("Carica Immagine");

    form->addWidget(scegliFoto,5,5);
    form->addWidget(bottoneScegliFoto,5,6);


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
    form->addWidget(saveEditButton,6,3);
    saveEditButton->hide();



    connect(tipoVeicolo,static_cast<void (QComboBox::*)(int index)>(&QComboBox::currentIndexChanged),[this]{
        slotChangeFormLayout(tipoVeicolo->currentText());
    });

    connect(bottoneScegliFoto,SIGNAL(clicked()),this,SLOT(slotScegliFoto()));


}

void InsertVeicolo::slotChangeFormLayout(QString typeveic)const{


    if(typeveic=="carrozzeria"){
        //show

        marca->show();
        modello->show();
        numeroTelaio->show();
        cambio->show();
        colore->show();
        lunghezza->show();
        //hide
        numeroMotore->hide();
        cilindrata->hide();
        cavalli->hide();
        alimentazione->hide();
        lunghezza->hide();
        targa->hide();
        prezzo->hide();
        massa->hide();
        numeroPosti->hide();
        segmento->hide();
        autocarro->hide();
        numeroAssi->hide();
        ribaltabile->hide();
        sidecar->hide();
        classeEmissioni->hide();
        tipoMoto->hide();

        AddButton->show();

    }
    if(typeveic=="motore"){
        //show
        marca->show();
        modello->show();
        numeroMotore->show();
        cilindrata->show();
        cavalli->show();
        alimentazione->show();
        //hide
        numeroTelaio->hide();
        cambio->hide();
        colore->hide();
        lunghezza->hide();
        targa->hide();
        prezzo->hide();
        massa->hide();
        numeroPosti->hide();
        segmento->hide();
        autocarro->hide();
        numeroAssi->hide();
        ribaltabile->hide();
        sidecar->hide();
        classeEmissioni->hide();
        tipoMoto->hide();

        AddButton->show();
    }
    if(typeveic=="auto"){
        //show
        marca->show();
        modello->show();
        numeroTelaio->show();
        cambio->show();
        colore->show();
        lunghezza->show();
        numeroMotore->show();
        cilindrata->show();
        cavalli->show();
        alimentazione->show();
        targa->show();
        prezzo->show();
        massa->show();
        numeroPosti->show();
        segmento->show();
        autocarro->show();
        //hide
        numeroAssi->hide();
        ribaltabile->hide();
        sidecar->hide();
        classeEmissioni->hide();
        tipoMoto->hide();

        AddButton->show();

    }
    if(typeveic=="moto"){
        //show
        marca->show();
        modello->show();
        numeroTelaio->show();
        cambio->show();
        colore->show();
        lunghezza->show();
        numeroMotore->show();
        cilindrata->show();
        cavalli->show();
        alimentazione->show();
        targa->show();
        prezzo->show();
        massa->show();
        numeroPosti->show();
        sidecar->show();
        classeEmissioni->show();
        tipoMoto->show();
        //hide
        segmento->hide();
        autocarro->hide();
        numeroAssi->hide();
        ribaltabile->hide();

        AddButton->show();
    }
    if(typeveic=="camion"){
        //show
        marca->show();
        modello->show();
        numeroTelaio->show();
        cambio->show();
        colore->show();
        lunghezza->show();
        numeroMotore->show();
        cilindrata->show();
        cavalli->show();
        alimentazione->show();
        targa->show();
        prezzo->show();
        massa->show();
        numeroPosti->show();
        //hide
        segmento->hide();
        autocarro->hide();
        sidecar->hide();
        classeEmissioni->hide();
        tipoMoto->hide();

        AddButton->show();
    }
}

void InsertVeicolo::slotDisableForm(int i) const {

    switch(i){
    case 1: //AUTO

        numeroAssi->setEnabled(false);
        ribaltabile->setEnabled(false);
        sidecar->setEnabled(false);
        classeEmissioni->setEnabled(false);
        tipoMoto->setEnabled(false);
         break;

    case 2: //CAMION

        segmento->setEnabled(false);
        autocarro->setEnabled(false);
        numeroAssi->setEnabled(true);
        ribaltabile->setEnabled(true);
        sidecar->setEnabled(false);
        classeEmissioni->setEnabled(false);
        tipoMoto->setEnabled(false);
        break;


    case 3: //MOTO

         segmento->setEnabled(false);
         autocarro->setEnabled(false);
         numeroAssi->setEnabled(true);
         ribaltabile->setEnabled(true);
         sidecar->setEnabled(true);
         classeEmissioni->setEnabled(true);
         tipoMoto->setEnabled(true);


        break;
    }
}







VeicoloTypeBox* InsertVeicolo::getTipoVeicolo() const
{
    return tipoVeicolo;
}
QLineEdit* InsertVeicolo::getMarca() const
{
    return marca;
}
QLineEdit* InsertVeicolo::getModello() const
{
    return modello ;
}
QLineEdit* InsertVeicolo::getNumeroTelaio() const
{
    return  numeroTelaio;
}
QCheckBox* InsertVeicolo::getCambio() const
{
    return cambio ;
}
QLineEdit* InsertVeicolo::getColore() const
{
    return colore;
}
QLineEdit* InsertVeicolo::getLunghezza() const
{
    return lunghezza;
}
QLineEdit* InsertVeicolo::getNumeroMotore() const
{
    return numeroMotore ;
}
QLineEdit* InsertVeicolo::getCilindrata() const
{
    return cilindrata;
}
QLineEdit* InsertVeicolo::getCavalli() const
{
    return cavalli;
}
AlimTypeBox* InsertVeicolo::getAlimentazione() const
{
    return  alimentazione;
}
QLineEdit* InsertVeicolo::getTarga() const
{
    return targa ;
}
QLineEdit* InsertVeicolo::getPrezzo() const
{
    return prezzo;
}
QLineEdit* InsertVeicolo::getMassa() const
{
    return massa;
}
QLineEdit* InsertVeicolo::getNumeroPosti() const
{
    return numeroPosti;
}
SegmentoTypeBox* InsertVeicolo::getSegmento() const
{
    return segmento;
}
QCheckBox* InsertVeicolo::getAutocarro() const
{
    return autocarro;
}
QLineEdit* InsertVeicolo::getNumeroAssi() const
{
    return  numeroAssi;
}
QCheckBox* InsertVeicolo::getRibaltabile() const
{
    return  ribaltabile;
}
QCheckBox* InsertVeicolo::getSidecar() const
{
    return  sidecar;
}
QLineEdit* InsertVeicolo::getClasseEmissioni() const
{
    return classeEmissioni;
}
TipomotoBox* InsertVeicolo::getTipoMoto() const
{
    return  tipoMoto;
}

QPushButton* InsertVeicolo::getAddButton() const
{
    return AddButton;
}

QPushButton* InsertVeicolo::getSaveEditButton()const {
    return saveEditButton;
}


void InsertVeicolo::slotScegliFoto(){
    QString file = QFileDialog::getOpenFileName(
                this,
                tr("Scegli Immagine"),
            "../immagini",
            "Image file (*.jpg)" );
    QFileInfo relativePath(file);

    if(file!=""){
        QImage im(file);
        QByteArray array;
        QBuffer b(&array);
       im.save(&b,"JPG");
       scegliFoto->setPixmap(QPixmap::fromImage(im));
    }
}


void InsertVeicolo::slotResetForm()const {

    marca->clear();
    modello->clear();
    numeroTelaio->clear();
    cambio->setChecked(false);
    colore->clear();
    lunghezza->clear();
    numeroMotore->clear();
    cilindrata->clear();
    cavalli->clear();
    alimentazione->setCurrentIndex(0);
    lunghezza->clear();
    targa->clear();
    prezzo->clear();
    massa->clear();
    numeroPosti->clear();
    segmento->setCurrentIndex(0);
    autocarro->setChecked(false);
    numeroAssi->clear();
    ribaltabile->setChecked(false);
    sidecar->setChecked(false);
    classeEmissioni->clear();
    tipoMoto->setCurrentIndex(0);



}

void InsertVeicolo::setColore(string a ){
    colore->setText(QString::fromStdString(a));
}


void InsertVeicolo::hideButton(bool a){
    if(!a){
        AddButton->hide();
        saveEditButton->show();

    }

    if(a){
        AddButton->show();
        saveEditButton->hide();
        tipoVeicolo->setDisabled(false);
    }
}


void InsertVeicolo::setTipoVeicolo(unsigned int i){

 tipoVeicolo->setCurrentIndex(i);
 tipoVeicolo->setDisabled(true);
}
void InsertVeicolo::setMarca(string a) {
    marca->setText(QString::fromStdString(a));
}
void InsertVeicolo::setModello(string i) {

    modello->setText(QString::fromStdString(i));

}
void InsertVeicolo::setNumeroTelaio(unsigned int i) {

    numeroTelaio->setText(QString::number(i));

}
void InsertVeicolo::setCambio(bool i) {

    cambio->setChecked(i);

}
void InsertVeicolo::setLunghezza(double i) {

    lunghezza->setText(QString::number(i));

}
void InsertVeicolo::setNumeroMotore(unsigned int i) {

    numeroMotore->setText(QString::number(i));

}
void InsertVeicolo::setCilindrata(unsigned int i) {

    cilindrata->setText(QString::number(i));


}
void InsertVeicolo::setCavalli(unsigned int i) {

    cavalli->setText(QString::number(i));
}
void InsertVeicolo::setAlimentazione(int i) {

    alimentazione->setCurrentIndex(i);


}
void InsertVeicolo::setTarga(string i) {

    targa->setText(QString::fromStdString(i));
}
void InsertVeicolo::setPrezzo(double i) {

    prezzo->setText(QString::number(i));
}
void InsertVeicolo::setMassa(unsigned int i) {

    massa->setText(QString::number(i));
}
void InsertVeicolo::setNumeroPosti(unsigned int i) {

    numeroPosti->setText(QString::number(i));
}
void InsertVeicolo::setSegmento(unsigned int i) {

    segmento->setCurrentIndex(i);
}
void InsertVeicolo::setAutocarro(bool i) {
    autocarro->setChecked(i);
}
void InsertVeicolo::setNumeroAssi(unsigned int i) {

    numeroAssi->setText(QString::number(i));
}
void InsertVeicolo::setRibaltabile(bool i) {

    ribaltabile->setChecked(i);
}
void InsertVeicolo::setSidecar(bool i) {

    sidecar->setChecked(i);
}
void InsertVeicolo::setClasseEmissioni(unsigned int i) {

    classeEmissioni->setText(QString::number(i));
}
void InsertVeicolo::setTipoMoto(unsigned int i) {

    tipoMoto->setCurrentIndex(i);
}


