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
    scegliFoto(new QLabel("Scegli Foto",this)),
    descTipoVeicolo(new QLabel("",this)),
    descMarca(new QLabel("Marca",this)),
    descModello(new QLabel("Modello",this)),
    descNumeroTelaio(new QLabel("Numero Telaio",this)),
    descColore(new QLabel("Colore",this)),
    descLunghezza(new QLabel("Lunghezza",this)),
    descNumeroMotore(new QLabel("Numero Motore",this)),
    descCilindrata(new QLabel("Cilindrata",this)),
    descCavalli(new QLabel("Cavalli",this)),
    descAlimentazione(new QLabel("Alimentazione",this)),
    descTarga(new QLabel("Targa",this)),
    descPrezzo(new QLabel("Prezzo €",this)),
    descMassa(new QLabel("Massa",this)),
    descNumeroPosti(new QLabel("Numeri Posti",this)),
    descSegmento(new QLabel("Segmento",this)),
    descNumeroAssi(new QLabel("Numero Assi",this)),
    descClasseEmissioni(new QLabel("Classe Emissione",this)),
    descTipoMoto(new QLabel("Tipo Moto",this)),

    marca(new QLineEdit(this)),
    modello(new QLineEdit(this)),
    numeroTelaio(new QLineEdit(this)),
    cambio(new QCheckBox("Cambio Automatico",this)),
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

    marca->setPlaceholderText("Marca");
    form->addWidget(descMarca,1,0);
    form->addWidget(marca,2,0);

    modello->setPlaceholderText("Modello");
    form->addWidget(descModello,3,0);
    form->addWidget(modello,4,0);


    numeroTelaio->setPlaceholderText("Numero Telaio");
    form->addWidget(descNumeroTelaio,5,0);
    form->addWidget(numeroTelaio,6,0);

    form->addWidget(cambio,8,0);


    colore->setPlaceholderText("Colore");
    form->addWidget(descColore,9,0);
    form->addWidget(colore,10,0);

    lunghezza->setPlaceholderText("Lunghezza");
    form->addWidget(descLunghezza,11,0);
    form->addWidget(lunghezza,12,0);

    numeroMotore->setPlaceholderText("Numero Motore");
    form->addWidget(descNumeroMotore,13,0);
    form->addWidget(numeroMotore,14,0);

    cilindrata->setPlaceholderText("Cilindrata");
    form->addWidget(descCilindrata,15,0);
    form->addWidget(cilindrata,16,0);

    cavalli->setPlaceholderText("Cavalli");
    form->addWidget(descCavalli,1,1);
    form->addWidget(cavalli,2,1);

    form->addWidget(descAlimentazione,3,1);
    form->addWidget(alimentazione,4,1);

    targa->setPlaceholderText("Targa");
    form->addWidget(descTarga,5,1);
    form->addWidget(targa,6,1);

    prezzo->setPlaceholderText("Prezzo");
    form->addWidget(descPrezzo,7,1);
    form->addWidget(prezzo,8,1);

    massa->setPlaceholderText("Massa");
    form->addWidget(descMassa,9,1);
    form->addWidget(massa,10,1);

    numeroPosti->setPlaceholderText("Numero Posti");
    form->addWidget(descNumeroPosti,11,1);
    form->addWidget(numeroPosti,12,1);


    form->addWidget(descSegmento,13,1);
    form->addWidget(segmento,14,1);

    form->addWidget(autocarro,16,1);

    numeroAssi->setPlaceholderText("Numero Assi");
    form->addWidget(descNumeroAssi,13,1);
    form->addWidget(numeroAssi,14,1);

    form->addWidget(ribaltabile,16,1);

    form->addWidget(sidecar,14,1);

    classeEmissioni->setPlaceholderText("Classe Emissioni");
    form->addWidget(descClasseEmissioni,15,1);
    form->addWidget(classeEmissioni,16,1);


    form->addWidget(descTipoMoto,17,1);
    form->addWidget(tipoMoto,18,1);

    form->addWidget(AddButton,20,2);
    form->addWidget(saveEditButton,21,1);

    bottoneScegliFoto->setText("Carica Immagine");

    scegliFoto->hide();
    form->addWidget(scegliFoto,20,0);
    scegliFoto->hide();
    form->addWidget(bottoneScegliFoto,21,1);
    AddButton->hide();
    saveEditButton->hide();
    slotChangeFormLayout("motore");
    connect(tipoVeicolo,static_cast<void (QComboBox::*)(int index)>(&QComboBox::currentIndexChanged),[this]{
        slotChangeFormLayout(tipoVeicolo->currentText());
    });

    connect(bottoneScegliFoto,SIGNAL(clicked()),this,SLOT(slotScegliFoto()));
}

void InsertVeicolo::slotChangeFormLayout(QString typeveic)const{

    if(typeveic=="carrozzeria"){
        //show
        descMarca->show();
        descModello->show();
        descNumeroTelaio->show();
        descColore->show();
        descLunghezza->show();

        //hide
        descNumeroMotore->hide();
        descCilindrata->hide();
        descCavalli->hide();
        descAlimentazione->hide();

        descTarga->hide();
        descPrezzo->hide();
        descMassa->hide();
        descNumeroPosti->hide();
        descSegmento->hide();
        descNumeroAssi->hide();
        descClasseEmissioni->hide();
        descTipoMoto->hide();

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
    }
    if(typeveic=="motore"){
        descMarca->show();
        descModello->show();
        descNumeroMotore->show();
        descCilindrata->show();
        descCavalli->show();
        descAlimentazione->show();


        descNumeroTelaio->hide();
        descColore->hide();
        descLunghezza->hide();

        descTarga->hide();
        descPrezzo->hide();
        descMassa->hide();
        descNumeroPosti->hide();
        descSegmento->hide();
        descNumeroAssi->hide();
        descClasseEmissioni->hide();
        descTipoMoto->hide();

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
    }
    if(typeveic=="auto"){
        descMarca->show();
        descModello->show();
        descNumeroMotore->show();
        descCilindrata->show();
        descCavalli->show();
        descAlimentazione->show();
        descNumeroTelaio->show();
        descColore->show();
        descLunghezza->show();
        descTarga->show();
        descPrezzo->show();
        descMassa->show();
        descNumeroPosti->show();
        descSegmento->show();

        descNumeroAssi->hide();
        descClasseEmissioni->hide();
        descTipoMoto->hide();

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
    }
    if(typeveic=="moto"){

        descMarca->show();
        descModello->show();
        descNumeroMotore->show();
        descCilindrata->show();
        descCavalli->show();
        descAlimentazione->show();
        descNumeroTelaio->show();
        descColore->show();
        descLunghezza->show();
        descTarga->show();
        descPrezzo->show();
        descMassa->show();
        descNumeroPosti->show();
        descSegmento->hide();

        descNumeroAssi->hide();
        descClasseEmissioni->show();
        descTipoMoto->show();

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

    }
    if(typeveic=="camion"){

        descMarca->show();
        descModello->show();
        descNumeroMotore->show();
        descCilindrata->show();
        descCavalli->show();
        descAlimentazione->show();
        descNumeroTelaio->show();
        descColore->show();
        descLunghezza->show();
        descTarga->show();
        descPrezzo->show();
        descMassa->show();
        descNumeroPosti->show();
        descNumeroAssi->show();

        descSegmento->hide();
        descClasseEmissioni->hide();
        descTipoMoto->hide();

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
        numeroAssi->show();
        ribaltabile->show();

        //hide
        segmento->hide();
        autocarro->hide();
        sidecar->hide();
        classeEmissioni->hide();
        tipoMoto->hide();

    }
}

void InsertVeicolo::slotDisableForm(int i)const{

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

        default: break;
    }
}

VeicoloTypeBox* InsertVeicolo::getTipoVeicolo() const{
    return tipoVeicolo;
}
QLineEdit* InsertVeicolo::getMarca() const{
    return marca;
}
QLineEdit* InsertVeicolo::getModello() const{
    return modello ;
}
QLineEdit* InsertVeicolo::getNumeroTelaio() const{
    return  numeroTelaio;
}
QCheckBox* InsertVeicolo::getCambio() const{
    return cambio ;
}
QLineEdit* InsertVeicolo::getColore() const{
    return colore;
}
QLineEdit* InsertVeicolo::getLunghezza() const{
    return lunghezza;
}
QLineEdit* InsertVeicolo::getNumeroMotore() const{
    return numeroMotore ;
}
QLineEdit* InsertVeicolo::getCilindrata() const{
    return cilindrata;
}
QLineEdit* InsertVeicolo::getCavalli() const{
    return cavalli;
}
AlimTypeBox* InsertVeicolo::getAlimentazione() const{
    return  alimentazione;
}
QLineEdit* InsertVeicolo::getTarga() const{
    return targa ;
}
QLineEdit* InsertVeicolo::getPrezzo() const{
    return prezzo;
}
QLineEdit* InsertVeicolo::getMassa() const{
    return massa;
}
QLineEdit* InsertVeicolo::getNumeroPosti() const{
    return numeroPosti;
}
SegmentoTypeBox* InsertVeicolo::getSegmento() const{
    return segmento;
}
QCheckBox* InsertVeicolo::getAutocarro() const{
    return autocarro;
}
QLineEdit* InsertVeicolo::getNumeroAssi() const{
    return  numeroAssi;
}
QCheckBox* InsertVeicolo::getRibaltabile() const{
    return  ribaltabile;
}
QCheckBox* InsertVeicolo::getSidecar() const{
    return  sidecar;
}
QLineEdit* InsertVeicolo::getClasseEmissioni() const{
    return classeEmissioni;
}
TipomotoBox* InsertVeicolo::getTipoMoto() const{
    return  tipoMoto;
}

QPushButton* InsertVeicolo::getAddButton() const{
    return AddButton;
}

QPushButton* InsertVeicolo::getSaveEditButton()const {
    return saveEditButton;
}

void InsertVeicolo::slotScegliFoto(){
    QString file = QFileDialog::getOpenFileName(this,tr("Scegli Immagine"),"../immagini","Image file (*.jpg)" );
    QFileInfo relativePath(file);

    if(file!=""){
        QImage im(file);
        QByteArray array;
        QBuffer b(&array);
        im.save(&b,"JPG");
        scegliFoto->setPixmap(QPixmap::fromImage(im));
    }
}

void InsertVeicolo::slotResetForm()const{
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
    scegliFoto->setText("Scegli Foto");

}

void InsertVeicolo::setColore(string a ){
    colore->setText(QString::fromStdString(a));
}

void InsertVeicolo::hideButton(bool a){
    if(!a){//MODIFICA
        AddButton->hide();
        saveEditButton->show();
        scegliFoto->hide();
    }
    if(a){
        scegliFoto->hide();
        AddButton->show();
        saveEditButton->hide();
        tipoVeicolo->setDisabled(false);
        targa->setDisabled(false);
        numeroTelaio->setDisabled(false);
        numeroMotore->setDisabled(false);
    }
}

void InsertVeicolo::setTipoVeicolo(unsigned int i){
    tipoVeicolo->setCurrentIndex(i);
    tipoVeicolo->setDisabled(true);
}
void InsertVeicolo::setMarca(string a){
    marca->setText(QString::fromStdString(a));
}
void InsertVeicolo::setModello(string i) {
    modello->setText(QString::fromStdString(i));
}
void InsertVeicolo::setNumeroTelaio(unsigned int i){
    numeroTelaio->setText(QString::number(i));
    numeroTelaio->setDisabled(true);
}
void InsertVeicolo::setCambio(bool i){
    cambio->setChecked(i);
}
void InsertVeicolo::setLunghezza(double i){
    lunghezza->setText(QString::number(i));
}
void InsertVeicolo::setNumeroMotore(unsigned int i){
    numeroMotore->setText(QString::number(i));
    numeroMotore->setDisabled(true);
}
void InsertVeicolo::setCilindrata(unsigned int i) {
    cilindrata->setText(QString::number(i));
}
void InsertVeicolo::setCavalli(unsigned int i){
    cavalli->setText(QString::number(i));
}
void InsertVeicolo::setAlimentazione(int i){
    alimentazione->setCurrentIndex(i);
}
void InsertVeicolo::setTarga(string i){
    targa->setText(QString::fromStdString(i));
    targa->setDisabled(true);
}
void InsertVeicolo::setPrezzo(double i){
    prezzo->setText(QString::number(i));
}
void InsertVeicolo::setMassa(unsigned int i){
    massa->setText(QString::number(i));
}
void InsertVeicolo::setNumeroPosti(unsigned int i){
    numeroPosti->setText(QString::number(i));
}
void InsertVeicolo::setSegmento(unsigned int i){
    segmento->setCurrentIndex(i);
}
void InsertVeicolo::setAutocarro(bool i){
    autocarro->setChecked(i);
}
void InsertVeicolo::setNumeroAssi(unsigned int i){
    numeroAssi->setText(QString::number(i));
}
void InsertVeicolo::setRibaltabile(bool i){
    ribaltabile->setChecked(i);
}
void InsertVeicolo::setSidecar(bool i){
    sidecar->setChecked(i);
}
void InsertVeicolo::setClasseEmissioni(unsigned int i){
    classeEmissioni->setText(QString::number(i));
}
void InsertVeicolo::setTipoMoto(unsigned int i){
    tipoMoto->setCurrentIndex(i);
}

void InsertVeicolo::setFoto(QString i){


        scegliFoto->setText(i);



}

QLabel* InsertVeicolo::getScegliFoto() const{
    if(scegliFoto)
        return scegliFoto;
    return nullptr;
}





