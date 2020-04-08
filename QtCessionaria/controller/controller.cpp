#include "controller.h"
using std::string;

#include <QHBoxLayout>


Controller::Controller(QWidget *parent):
    QWidget(parent),
    menuUtente(new Usermenu(this)),
    mainLayout(new QHBoxLayout(this))

{

    mainLayout->setMenuBar(menuUtente);


}

