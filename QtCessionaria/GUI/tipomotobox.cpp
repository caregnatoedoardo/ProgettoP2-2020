#include "tipomotobox.h"

TipomotoBox::TipomotoBox(QWidget* parent):
    QComboBox (parent)
{
addItem("Corsa");
addItem("Custom");
addItem("Naked");
addItem("Cross");
}


