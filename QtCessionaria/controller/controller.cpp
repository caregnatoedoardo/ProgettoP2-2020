#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBuffer>
using std::string;




Controller::Controller(Model*m, QWidget *parent):
    QWidget(parent),
    model(m),
    menuUtente(new Usermenu(this)),
    mainLayout(new QHBoxLayout(this)),
    inserisciVeicolo(new InsertVeicolo(this))


{

    mainLayout->setMenuBar(menuUtente);
    mainLayout->addWidget(inserisciVeicolo);




}


void Controller::slotShowInserisci()const{

    inserisciVeicolo->show();

}
