#include "veicolotypebox.h"

VeicoloTypeBox::VeicoloTypeBox(QWidget* parent):
    QComboBox (parent){
        addItem("motore");
        addItem("carrozzeria");
        addItem("auto");
        addItem("moto");
        addItem("camion");
}
