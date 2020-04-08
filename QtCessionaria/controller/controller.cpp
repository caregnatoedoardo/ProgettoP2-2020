#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBuffer>
using std::string;




Controller::Controller(Model*m, QWidget *parent):
    QWidget(parent),
    menuUtente(new Usermenu(this)),
    model(m),
    mainLayout(new QHBoxLayout(this))

{

    mainLayout->setMenuBar(menuUtente);


}

