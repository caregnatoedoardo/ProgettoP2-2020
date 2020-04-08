#include "alimtipebox.h"


AlimTipeBox::AlimTipeBox(QWidget* parent):
    QComboBox (parent)
{
addItem("Benzina");
addItem("Disel");
addItem("Elettrica");
addItem("GPL");
addItem("Metano");
}
