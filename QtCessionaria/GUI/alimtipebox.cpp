#include "alimtipebox.h"


AlimTipeBox::AlimTipeBox(QWidget* parent):
    QComboBox (parent)
{
    addItem("benzina");
    addItem("diesel");
    addItem("elettrica");
    addItem("gpl");
    addItem("metano");
}
