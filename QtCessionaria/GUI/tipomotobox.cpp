#include "tipomotobox.h"

TipomotoBox::TipomotoBox(QWidget* parent):
    QComboBox (parent)
{
addItem("corsa");
addItem("custom");
addItem("naked");
addItem("cross");
}


