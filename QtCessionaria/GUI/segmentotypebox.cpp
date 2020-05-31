#include "segmentotypebox.h"

SegmentoTypeBox::SegmentoTypeBox(QWidget* parent): QComboBox(parent)
{
addItem("berlina");
addItem("station");
addItem("suv");
addItem("coupe");
}

