#include "alimtypebox.h"


AlimTypeBox::AlimTypeBox(QWidget* parent):QComboBox (parent){
    addItem("benzina");
    addItem("diesel");
    addItem("elettrica");
    addItem("gpl");
    addItem("metano");
}
