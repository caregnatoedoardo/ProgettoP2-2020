#include "alimtipebox.h"


AlimTipeBox::AlimTipeBox(QWidget* parent):
    QComboBox (parent)
{
addItem("benzina");
addItem("disel");
addItem("elettrica");
addItem("gpl");
addItem("metano");
}
