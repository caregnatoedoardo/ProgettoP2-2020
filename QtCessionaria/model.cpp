#include "model.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QsaveFile>
#include <hierarchy/veicolo.h>




Model::Model(string path):
    dbVeicoli(new Container<Veicolo*>),
    dbVenduti(new Container<Veicolo*>),
    searchRes(new Container<Veicolo*>),
    path(path),
    isDataSaved(true){}


