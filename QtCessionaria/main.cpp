#include "mainwindow.h"
#include "hierarchy/veicolo.h"
#include "hierarchy/carrozzeria.h"
#include "hierarchy/motore.h"
#include "hierarchy/mezzo.h"
#include "hierarchy/auto.h"
#include "hierarchy/camion.h"
#include "hierarchy/moto.h"
#include "container/container.h"
#include <QApplication>
#include <iostream>
#include "controller/controller.h"
#include "model.h"
using std::cout;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w(new Model());
    w.setFixedSize(1024,768);
    w.show();
    return a.exec();
}
